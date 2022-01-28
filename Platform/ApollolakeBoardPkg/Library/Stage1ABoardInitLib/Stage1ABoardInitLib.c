/** @file

  Copyright (c) 2017 - 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <PiPei.h>
#include <Library/BaseLib.h>
#include <Library/BoardInitLib.h>
#include <Library/GpioLib.h>
#include <Library/SerialPortLib.h>
#include <Library/PlatformHookLib.h>
#include <Library/BootGuardLib20.h>
#include <Library/BootloaderCoreLib.h>
#include <FsptUpd.h>
#include <GpioDefines.h>
#include <PlatformData.h>
#include <ConfigDataDefs.h>
#include <RegAccess.h>
#include <Library/BootloaderCommonLib.h>
#include <Library/PcdLib.h>
#include <Library/SaCommonDefinitions.h>

const
FSPT_UPD TempRamInitParams = {
  .FspUpdHeader = {
    .Signature = FSPT_UPD_SIGNATURE,
    .Revision  = 1,
    .Reserved  = {0},
  },
  .FsptCommonUpd = {
    .Revision              = 1,
    .MicrocodeRegionBase   = 0,
    .MicrocodeRegionLength = 0,
    .CodeRegionBase        = 0xFFFE0000,
    .CodeRegionLength      = 0x00020000,
  },
  .UpdTerminator = 0x55AA,
};

//SOM3569X001 >>
BXT_GPIO_PAD_INIT  EarlyGpioInitTblLPC[] =
{
  /*            8      Group Pin#:  pad_name,    PMode,GPIO_Config,HostSw,GPO_STATE,INT_Trigger,  Wake_Enabled ,Term_H_L,Inverted, GPI_ROUT, IOSstae, IOSTerm,     MMIO_Offset  ,Community */
  BXT_GPIO_PAD_CONF (L"SMB_CLK",                    M1,     NA,   NA,  NA,   NA, Wake_Disabled, P_20K_H,    NA,    NA, IOS_Masked, SAME, GPIO_PADBAR + 0x0100,  SOUTHWEST),
  BXT_GPIO_PAD_CONF (L"SMB_DATA",                   M1,     NA,   NA,  NA,   NA, Wake_Disabled, P_20K_H,    NA,    NA, IOS_Masked, SAME, GPIO_PADBAR + 0x0108,  SOUTHWEST),
  BXT_GPIO_PAD_CONF (L"LPC_ILB_SERIRQ",             M1,     NA,   NA,  NA,   NA, Wake_Disabled, P_20K_H,    NA,    NA, IOS_Masked, SAME, GPIO_PADBAR + 0x0110,  SOUTHWEST),
  BXT_GPIO_PAD_CONF (L"LPC_CLKOUT0",                M1,     NA,   NA,  NA,   NA, Wake_Disabled, P_NONE,     NA,    NA, IOS_Masked, SAME, GPIO_PADBAR + 0x0118,  SOUTHWEST),
  BXT_GPIO_PAD_CONF (L"LPC_CLKOUT1",                M1,     NA,   NA,  NA,   NA, Wake_Disabled, P_NONE,     NA,    NA, IOS_Masked, SAME, GPIO_PADBAR + 0x0120,  SOUTHWEST),
  BXT_GPIO_PAD_CONF (L"LPC_AD0",                    M1,     NA,   NA,  NA,   NA, Wake_Disabled, P_20K_H,    NA,    NA, IOS_Masked, SAME, GPIO_PADBAR + 0x0128,  SOUTHWEST),
  BXT_GPIO_PAD_CONF (L"LPC_AD1",                    M1,     NA,   NA,  NA,   NA, Wake_Disabled, P_20K_H,    NA,    NA, IOS_Masked, SAME, GPIO_PADBAR + 0x0130,  SOUTHWEST),
  BXT_GPIO_PAD_CONF (L"LPC_AD2",                    M1,     NA,   NA,  NA,   NA, Wake_Disabled, P_20K_H,    NA,    NA, IOS_Masked, SAME, GPIO_PADBAR + 0x0138,  SOUTHWEST),
  BXT_GPIO_PAD_CONF (L"LPC_AD3",                    M1,     NA,   NA,  NA,   NA, Wake_Disabled, P_20K_H,    NA,    NA, IOS_Masked, SAME, GPIO_PADBAR + 0x0140,  SOUTHWEST),
  BXT_GPIO_PAD_CONF (L"LPC_CLKRUNB",                M1,     NA,   NA,  NA,   NA, Wake_Disabled, P_20K_H,    NA,    NA, IOS_Masked, SAME, GPIO_PADBAR + 0x0148,  SOUTHWEST),
  BXT_GPIO_PAD_CONF (L"LPC_FRAMEB",                 M1,     NA,   NA,  NA,   NA, Wake_Disabled, P_20K_H,    NA,    NA, IOS_Masked, SAME, GPIO_PADBAR + 0x0150,  SOUTHWEST),
  BXT_GPIO_PAD_CONF (L"GPIO_155 ISH_GPIO_9",        M2,     NA,   NA,  NA,   NA, Wake_Disabled, P_20K_L,    NA,    NA, IOS_Masked, SAME, GPIO_PADBAR+0x00C8,    WEST),
};

typedef struct _SIO_INIT_TABLE{
    UINT16      Index16;
    UINT8       Value8;
    UINT16      Data16;
    UINT8       Data8;
} SIO_INIT_TABLE;

#define SIO_LDN_PMC0	      0xc
#define SIO_LDN_PMC1	      0xd
#define SIO_LDN_CAN0	      0x18
#define SIO_LDN_CAN1	      0x19
#define SIO_LDN_I2C0	      0x20
#define SIO_LDN_I2C1	      0x21
#define SIO_LDN_SMBUS0	    0x22
#define SIO_LDN_SMBUS1	    0x23
#define SIO_LDN_PMCMB	      0xe
#define SIO_LDN_EC	        0xf
#define SIO_LDN_UART1	      0x2
#define SIO_LDN_UART1_SOM7569 0x8
#define SIO_LDN_UART2	      0x3
#define SIO_LDN_UART3	      0x4
#define SIO_LDN_UART4	      0x5
#define SIO_LDN_UART5	      0x6
#define SIO_LDN_UART6	      0x7
#define SIO_LDN_UART7	      0x8
#define SIO_LDN_UART8	      0x9
#define SIO_LDN_UART9	      0x10 


#define SIO_CONFIG_INDEX	  0x299
#define SIO_CONFIG_DATA	    0x29A
#define SIO_CONFIG_ENTER	  0x87
#define SIO_CONFIG_EXIT	    0xAA
#define SIO_LDN_ACTIVATE	  0x1
#define SIO_LDN_DEACTIVATE  0x0
#define SIO_LDN_SELECT	    0x7
#define SIO_ACTIVATE_REG    0x30
#define SIO_BASE1_HI_REG    0x60
#define SIO_BASE1_LO_REG    0x61
#define SIO_BASE2_HI_REG    0x62
#define SIO_BASE2_LO_REG    0x63
#define SIO_IRQ1_REG      	0x70
#define SIO_IRQ2_REG      	0x72
#define SIO_DMA1_REG      	0x74
#define SIO_DMA2_REG      	0x75 
#define SIO_PMC1_INDEX     	0x2F2
#define SIO_PMC1_DATA     	0x2F6
#define SIO_UART1_BASE     	0x3F8


SIO_INIT_TABLE SioInitTableSOM7569[]= {
  {SIO_CONFIG_INDEX, SIO_CONFIG_ENTER,  SIO_CONFIG_INDEX, SIO_CONFIG_ENTER},
  {SIO_CONFIG_INDEX, SIO_LDN_SELECT,    SIO_CONFIG_DATA,  SIO_LDN_PMC0},
  {SIO_CONFIG_INDEX, SIO_ACTIVATE_REG,  SIO_CONFIG_DATA,  SIO_LDN_ACTIVATE},

  {SIO_CONFIG_INDEX, SIO_LDN_SELECT,    SIO_CONFIG_DATA,  SIO_LDN_PMC1},
  {SIO_CONFIG_INDEX, SIO_BASE1_LO_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_PMC1_INDEX & 0xFF)},
  {SIO_CONFIG_INDEX, SIO_BASE1_HI_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_PMC1_INDEX >> 8)},
  {SIO_CONFIG_INDEX, SIO_BASE2_LO_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_PMC1_DATA & 0xFF)},
  {SIO_CONFIG_INDEX, SIO_BASE2_HI_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_PMC1_DATA >> 8)},
  {SIO_CONFIG_INDEX, SIO_ACTIVATE_REG,  SIO_CONFIG_DATA,  SIO_LDN_ACTIVATE},

  {SIO_CONFIG_INDEX, SIO_LDN_SELECT,    SIO_CONFIG_DATA,  SIO_LDN_UART1_SOM7569},
  {SIO_CONFIG_INDEX, SIO_BASE1_LO_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_UART1_BASE & 0xFF)},
  {SIO_CONFIG_INDEX, SIO_BASE1_HI_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_UART1_BASE >> 8)},
  {SIO_CONFIG_INDEX, SIO_ACTIVATE_REG,  SIO_CONFIG_DATA,  SIO_LDN_ACTIVATE},

  {SIO_CONFIG_INDEX, SIO_CONFIG_EXIT,   SIO_CONFIG_INDEX, SIO_CONFIG_EXIT},
};


SIO_INIT_TABLE SioInitTable[]= {
  {SIO_CONFIG_INDEX, SIO_CONFIG_ENTER,  SIO_CONFIG_INDEX, SIO_CONFIG_ENTER},
  {SIO_CONFIG_INDEX, SIO_LDN_SELECT,    SIO_CONFIG_DATA,  SIO_LDN_PMC0},
  {SIO_CONFIG_INDEX, SIO_ACTIVATE_REG,  SIO_CONFIG_DATA,  SIO_LDN_ACTIVATE},

  {SIO_CONFIG_INDEX, SIO_LDN_SELECT,    SIO_CONFIG_DATA,  SIO_LDN_PMC1},
  {SIO_CONFIG_INDEX, SIO_BASE1_LO_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_PMC1_INDEX & 0xFF)},
  {SIO_CONFIG_INDEX, SIO_BASE1_HI_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_PMC1_INDEX >> 8)},
  {SIO_CONFIG_INDEX, SIO_BASE2_LO_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_PMC1_DATA & 0xFF)},
  {SIO_CONFIG_INDEX, SIO_BASE2_HI_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_PMC1_DATA >> 8)},
  {SIO_CONFIG_INDEX, SIO_ACTIVATE_REG,  SIO_CONFIG_DATA,  SIO_LDN_ACTIVATE},

  {SIO_CONFIG_INDEX, SIO_LDN_SELECT,    SIO_CONFIG_DATA,  SIO_LDN_UART1},
  {SIO_CONFIG_INDEX, SIO_BASE1_LO_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_UART1_BASE & 0xFF)},
  {SIO_CONFIG_INDEX, SIO_BASE1_HI_REG,  SIO_CONFIG_DATA,  (UINT8)(SIO_UART1_BASE >> 8)},
  {SIO_CONFIG_INDEX, SIO_ACTIVATE_REG,  SIO_CONFIG_DATA,  SIO_LDN_ACTIVATE},

  {SIO_CONFIG_INDEX, SIO_CONFIG_EXIT,   SIO_CONFIG_INDEX, SIO_CONFIG_EXIT},
};

/**
  Enable UART in SIO chip.

**/
VOID
EarlySioInit (
  VOID
)
{
  UINT8                 Idx;
  UINT32                LpcBaseAddr;
  SIO_INIT_TABLE        *pSioTbl = SioInitTable;
  UINT32            PciData32;

    // Set SIO Mode GPIO pins
    GpioConfigurePads (ARRAY_SIZE(EarlyGpioInitTblLPC), (GPIO_INIT_CONFIG *)EarlyGpioInitTblLPC);

    // Enable SIO decoding
    LpcBaseAddr = MM_PCI_ADDRESS (0, 31, 0, 0);

    PciData32 = MmioRead32 (LpcBaseAddr+0x80);
    PciData32 = 0x3F0F0000;
    MmioWrite32 (LpcBaseAddr+0x80,  PciData32);
    
    PciData32 = MmioRead32 (LpcBaseAddr+0x80);
    
    PciData32 = MmioRead32 (LpcBaseAddr+0x84);
    PciData32 = 0x00FC0201;
    MmioWrite32 (LpcBaseAddr+0x84,  PciData32);

  if (GetPlatformId() == PLATFORM_ID_SOM7569) {
    // Init logic devices
    pSioTbl = SioInitTableSOM7569;
    for  (Idx = 0; Idx < sizeof(SioInitTableSOM7569)/sizeof(SIO_INIT_TABLE); Idx ++) {
      IoWrite8 (pSioTbl->Index16, pSioTbl->Value8 );
      IoWrite8 (pSioTbl->Data16, pSioTbl->Data8 );
      pSioTbl = pSioTbl+1;
    }
  } else {
    // Init logic devices
    pSioTbl = SioInitTable;
    for  (Idx = 0; Idx < sizeof(SioInitTable)/sizeof(SIO_INIT_TABLE); Idx ++) {
      IoWrite8 (pSioTbl->Index16, pSioTbl->Value8 );
      IoWrite8 (pSioTbl->Data16, pSioTbl->Data8 );
      pSioTbl = pSioTbl+1;
    }
  }

}

//SOM3569X001 >>

/**
  Stitching process might pass some specific plafform data to be
  consumed pretty early. This will be used to guide the platform initialization
  even before CFGDATA is available.

**/
VOID
EarlyPlatformDataCheck (
  VOID
)
{
  STITCH_DATA          *StitchData;

  // Stitching process might pass some plafform specific data.
  StitchData = (STITCH_DATA *)(UINTN)0xFFFFFFF4;
  if (StitchData->Marker != 0xAA) {
    // PlatformID will be deferred to be detected
    SetDebugPort ( PcdGet8 (PcdDebugPortNumber));
  } else {
    SetDebugPort  (StitchData->DebugUart);
    if ((StitchData->PlatformId > 0) && (StitchData->PlatformId < 32)) {
      SetPlatformId (StitchData->PlatformId);
    }
  }
//SOM3569X001 >>
//  switch (StitchData->PlatformId) {
//  case PLATFORM_ID_SOM2569:
//  case PLATFORM_ID_SOM3569:
//  case PLATFORM_ID_SOM6869:
//  case PLATFORM_ID_SOM7569:
//    GpioConfigurePads (ARRAY_SIZE(EarlyGpioInitTblLPC), (GPIO_INIT_CONFIG *) (UINTN) EarlyGpioInitTblLPC);
//    break;
//  default:
//    break;
//  }
//SOM3569X001 >>

}


/**
  Board specific hook points.

  Implement board specific initialization during the boot flow.

  @param[in] InitPhase             Current phase in the boot flow.

**/
VOID
EFIAPI
BoardInit (
  IN  BOARD_INIT_PHASE  InitPhase
  )
{
  PLATFORM_DATA   *PlatformData;

  switch (InitPhase) {
  case PostTempRamInit:
    DisableWatchDogTimer ();
    EarlyPlatformDataCheck ();
//SOM3569X001 >>
    EarlySioInit ();  
    PlatformHookSerialPortInitialize ();
    SerialPortInitialize ();
    PlatformData = (PLATFORM_DATA *)GetPlatformDataPtr ();
    if (PlatformData != NULL) {
      FetchPreRBPData (& (PlatformData->BtGuardInfo));
    }
    break;
  default:
    break;
  }
}

/**
  Get size of Platform Specific Data.

  @param[in] none

  @retval    UINT32     Size of Platform Specific Data

**/
UINT32
EFIAPI
GetPlatformDataSize (
  IN  VOID
  )
{
  return sizeof (PLATFORM_DATA);
}
