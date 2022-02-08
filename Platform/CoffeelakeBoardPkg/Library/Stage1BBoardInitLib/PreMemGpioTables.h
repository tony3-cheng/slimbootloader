/** @file

  Copyright (c) 2017 - 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Library/GpioLib.h>
#include <GpioConfig.h>
#include <GpioPinsCnlH.h>
#include <GpioPinsCnlLp.h>



static GPIO_INIT_CONFIG mGpioTableSOM6882[] =
{
//                      Pmode,  GPI_IS,  GpioDir,  GPIOTxState,  RxEvCfg,  GPIRoutConfig,  PadRstCfg,  Term,
//  {GPIO_CNL_LP_GPP_A0,  { GpioPadModeNotUsed,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},
//  {GPIO_CNL_LP_GPP_A1,  { GpioPadModeNative2,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //eSPI_IO_0
//  {GPIO_CNL_LP_GPP_A2,  { GpioPadModeNative2,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //eSPI_IO_1
//  {GPIO_CNL_LP_GPP_A3,  { GpioPadModeNative2,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //eSPI_IO_2
//  {GPIO_CNL_LP_GPP_A4,  { GpioPadModeNative2,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //eSPI_IO_2
//  {GPIO_CNL_LP_GPP_A5,  { GpioPadModeNative2,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //eSPI_CSB
//  {GPIO_CNL_LP_GPP_A6,  { GpioPadModeNotUsed,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //GPPC_A6_SERIRQ
  // TPM interrupt
  {GPIO_CNL_LP_GPP_A7,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntLevel | GpioIntApic, GpioHostDeepReset, GpioTermWpu20K, GpioPadConfigUnlock }},  //PIRQA#_TPM
  //Native F1 if eSPI or LPC pin strap = LPC //{GPIO_CNL_LP_GPP_A8,  { GpioPadModeNotUsed,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},
  //Native F1 if eSPI or LPC pin strap = LPC //(Default HW)  {GPIO_CNL_LP_GPP_A9,  { GpioPadModeNative2,  GpioHostOwnGpio,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //eSPI_CLK
  //Native F1 if eSPI or LPC pin strap = LPC //{GPIO_CNL_LP_GPP_A10,  { GpioPadModeNotUsed,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},
  //adv_todo? //Native F1 if eSPI or LPC pin strap = LPC //{GPIO_CNL_LP_GPP_A11,  { GpioPadModeGpio,  GpioHostOwnGpio,  GpioDirInInv,  GpioOutDefault,  GpioIntLevel|GpioIntSci,  GpioHostDeepReset,  GpioTermWpu20K, GpioPadConfigUnlock }},  //PME#
  {GPIO_CNL_LP_GPP_A12, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  //Native F1 if eSPI or LPC pin strap = LPC {GPIO_CNL_LP_GPP_A13, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioPlatformReset, GpioTermNone } },  //DGPU_SEL_SLOT1
  //Native F1 if eSPI or LPC pin strap = LPC //(Default HW)  {GPIO_CNL_LP_GPP_A14,  { GpioPadModeNative2,  GpioHostOwnGpio,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //eSPI_Reset
  //Native F1 if eSPI or LPC pin strap = LPC {GPIO_CNL_LP_GPP_A15,  { GpioPadModeGpio,  GpioHostOwnGpio,  GpioDirOut,  GpioOutHigh,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //SPKR_PD_N
  {GPIO_CNL_LP_GPP_A16, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  //(RC control) {GPIO_CNL_LP_GPP_A17,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirIn,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //SD_PWREN
  {GPIO_CNL_LP_GPP_A18, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_A19, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_A20, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_A21, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_A22, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_A23, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_B0,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_B1,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_B2,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_B3,  { GpioPadModeGpio , GpioHostOwnGpio , GpioDirOut , GpioOutLow , GpioIntDefault , GpioPlatformReset , GpioTermNone, GpioOutputStateUnlock}},  //PTN3460_CFG
  {GPIO_CNL_LP_GPP_B4,  { GpioPadModeGpio , GpioHostOwnGpio , GpioDirOut , GpioOutHigh, GpioIntDis , GpioHostDeepReset , GpioTermNone, GpioOutputStateUnlock}},//LVDS_RST#_3.3
  //(RC control) {GPIO_CNL_LP_GPP_B5,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //WWAN_CLK_REQ
  //(RC control) {GPIO_CNL_LP_GPP_B6,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //PCIE_NAND_CLK_REQ
  //(RC control) {GPIO_CNL_LP_GPP_B7,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //LAN_CLK_REQ
  //(RC control) {GPIO_CNL_LP_GPP_B8,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //WLAN_CLK_REQ
  //(RC control) {GPIO_CNL_LP_GPP_B9,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //PCIE_SLOT1_CLK_REQ
  //(RC control) {GPIO_CNL_LP_GPP_B10,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //PCIE_SLOT2_CLK_REQ
  {GPIO_CNL_LP_GPP_B11,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  //(Default HW)  {GPIO_CNL_LP_GPP_B12,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNone }},  //PM_SLP_S0_N
  //(Default HW)  {GPIO_CNL_LP_GPP_B13,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNone }},  //PLT_RST_N
  {GPIO_CNL_LP_GPP_B14, { GpioPadModeNative1 , GpioHostOwnDefault , GpioDirDefault , GpioOutDefault , GpioIntDefault , GpioHostDeepReset , GpioTermNone }},  //SPKR
  {GPIO_CNL_LP_GPP_B15, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_B16, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_B17, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_B18, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_B19, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_B20, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_B21, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_B22, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_B23, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  //Native F1 {GPIO_CNL_LP_GPP_C0,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //SMB_CLK
  //Native F1 {GPIO_CNL_LP_GPP_C1,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //SMB_DATA
  {GPIO_CNL_LP_GPP_C2,  { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv, GpioOutDefault, GpioIntLevel|GpioIntSci, GpioPlatformReset, GpioTermNone, GpioPadConfigUnlock}},//SMB_ALT_PCH#
  //Native F1 {GPIO_CNL_LP_GPP_C3,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //SML0_CLK
  //Native F1 {GPIO_CNL_LP_GPP_C4,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //SML0_DATA
  //adv_todo? >>
  {GPIO_CNL_LP_GPP_C5,  { GpioPadModeNative1 , GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone}},  //SML0ALERT#
  //adv_todo? <<
  {GPIO_CNL_LP_GPP_C6,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_C7,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_C8,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  //adv_todo? {GPIO_CNL_LP_GPP_C9, { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv, GpioOutDefault, GpioIntEdge | GpioIntSci, GpioPlatformReset, GpioTermWpu20K, GpioPadConfigUnlock }},  //TBT_CIO_PLUG_EVENT_N
  //adv_todo? {GPIO_CNL_LP_GPP_C10,  { GpioPadModeGpio,  GpioHostOwnGpio,  GpioDirOut,  GpioOutLow,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone, GpioPadUnlock }},  //TBT_FORCE_PWR
  {GPIO_CNL_LP_GPP_C11, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_C12, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_C13, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_C14, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_C15, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  //(RC control) {GPIO_CNL_LP_GPP_C16,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //I2C0_SDA
  //(RC control) {GPIO_CNL_LP_GPP_C17,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //I2C0_SCL
  //(RC control) {GPIO_CNL_LP_GPP_C18,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //I2C1_SDA
  //(RC control) {GPIO_CNL_LP_GPP_C19,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //I2C1_SCL
  //(RC control) {GPIO_CNL_LP_GPP_C20,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //UART2_RXD
  //(RC control) {GPIO_CNL_LP_GPP_C21,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //UART2_TXD
  //(RC control) {GPIO_CNL_LP_GPP_C22,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //UART2_RTS
  //(RC control) {GPIO_CNL_LP_GPP_C23,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirInOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //UART2_CTS
  {GPIO_CNL_LP_GPP_D0,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D1,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D2,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D3,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D4,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D5,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D6,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D7,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D8,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D9,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D10, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D11, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D12, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D13, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D14, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D15, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D16, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D17, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D18, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D19, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D20, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D21, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D22, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_D23, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_E0,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_E1,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_E2,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  //adv_todo? >>
  //{GPIO_CNL_LP_GPP_E3,  { GpioPadModeGpio,  GpioHostOwnAcpi,  GpioDirIn,  GpioOutDefault,  GpioIntEdge|GpioIntSmi,  GpioPlatformReset,  GpioTermNone, GpioPadUnlock}},  //EC_NMI
  //adv_todo? <<
  {GPIO_CNL_LP_GPP_E4,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_E5,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_E6,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_E7,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDis , GpioPlatformReset , GpioTermNone, GpioOutputStateUnlock}},  //GPP_E22_SYSTEM_OK
  //(RC control) {GPIO_CNL_LP_GPP_E8,  { GpioPadModeGpio,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //SATA_LED_N
  //(RC control) {GPIO_CNL_LP_GPP_E9,  { GpioPadModeGpio,  GpioHostOwnDefault,  GpioDirIn,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //BSSB_CLK
  //(RC control) {GPIO_CNL_LP_GPP_E10,  { GpioPadModeGpio,  GpioHostOwnDefault,  GpioDirIn,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //BSSB_DI
  //(RC control) {GPIO_CNL_LP_GPP_E11,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //USB_OC_2
  //(RC control) {GPIO_CNL_LP_GPP_E12,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermNone }},  //USB_OC_3
  //(RC control) {GPIO_CNL_LP_GPP_E13,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //DDI1_HPD
  //(RC control) {GPIO_CNL_LP_GPP_E14,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //DDI2_HPD_EC
//  {GPIO_CNL_LP_GPP_E15, { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirIn,  GpioOutDefault,  GpioIntEdge | GpioIntSmi,  GpioPlatformReset,  GpioTermNone, GpioPadConfigUnlock}},  //EC_SMI#
  {GPIO_CNL_LP_GPP_E16, { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv,  GpioOutDefault,  GpioIntLevel | GpioIntSci,  GpioPlatformReset,  GpioTermWpu20K, GpioPadConfigUnlock}},  //EC_SCI#
  //(RC control) {GPIO_CNL_LP_GPP_E17,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //EDP_HPD
  //(RC control) {GPIO_CNL_LP_GPP_E18,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //DDI1_CTRL_CLK
  //(RC control) {GPIO_CNL_LP_GPP_E19,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //DDI1_CTRL_DATA
  //(RC control) {GPIO_CNL_LP_GPP_E20,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //DDI2_CTRL_CLK
  //(RC control) {GPIO_CNL_LP_GPP_E21,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //DDI2_CTRL_DATA
  {GPIO_CNL_LP_GPP_E22, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_E23, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_F0,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_F1,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_F2,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_F3,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_F4,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_F5,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_F6,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_F7,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_F8,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_F9,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_F10, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  //(RC control)  {GPIO_CNL_LP_GPP_F11,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //GPP_F11_EMMC_CMD
  //(RC control)  {GPIO_CNL_LP_GPP_F12,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //GPP_F12_EMMC_DATA0
  //(RC control)  {GPIO_CNL_LP_GPP_F13,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //GPP_F13_EMMC_DATA1
  //(RC control)  {GPIO_CNL_LP_GPP_F14,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //GPP_F14_EMMC_DATA2
  //(RC control)  {GPIO_CNL_LP_GPP_F15,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //GPP_F15_EMMC_DATA3
  //(RC control)  {GPIO_CNL_LP_GPP_F16,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //GPP_F16_EMMC_DATA4
  //(RC control)  {GPIO_CNL_LP_GPP_F17,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //GPP_F17_EMMC_DATA5
  //(RC control)  {GPIO_CNL_LP_GPP_F18,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //GPP_F18_EMMC_DATA6
  //(RC control)  {GPIO_CNL_LP_GPP_F19,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //GPP_F19_EMMC_DATA7
  //(RC control)  {GPIO_CNL_LP_GPP_F20,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //GPP_F20_EMMC_RCLK
  //(RC control)  {GPIO_CNL_LP_GPP_F21,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //GPP_F21_EMMC_CLK
  //(RC control)  {GPIO_CNL_LP_GPP_F22,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //GPP_F22_EMMC_RESETB
  {GPIO_CNL_LP_GPP_F23, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  //(RC control)  {GPIO_CNL_LP_GPP_G0,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNative }},  //GPP_G_0_SD3_CMD
  //(RC control)  {GPIO_CNL_LP_GPP_G1,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNative }},  //GPP_G_1_SD3_D0_SD4_RCLK_P
  //(RC control)  {GPIO_CNL_LP_GPP_G2,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNative }},  //GPP_G_2_SD3_D1_SD4_RCLK_N
  //(RC control)  {GPIO_CNL_LP_GPP_G3,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNative }},  //GPP_G_3_SD3_D2
  //(RC control)  {GPIO_CNL_LP_GPP_G4,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNative }},  //GPP_G_4_SD3_D3
  {GPIO_CNL_LP_GPP_G5,  { GpioHardwareDefault,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermWpu20K }},  //GPP_G_5_SD3_CDB
  //(Default HW)  {GPIO_CNL_LP_GPP_G6,  { GpioPadModeNative1,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNone }},  //GPP_G_6_SD3_CLK
  {GPIO_CNL_LP_GPP_G7,  { GpioHardwareDefault,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermWpd20K }},  //GPP_G_7_SD3_WP
  {GPIO_CNL_LP_GPP_H0,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H1,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H2,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H3,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H4,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H5,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H6,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H7,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H8,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H9,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H10, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H11, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H12, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H13, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H14, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H15, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H16, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H17, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  //(Default HW)  {GPIO_CNL_LP_GPP_H18,  { GpioPadModeNative1,  GpioHostOwnGpio,  GpioDirOut,  GpioOutDefault,  GpioIntDefault,  GpioPlatformReset,  GpioTermNone }},  //VCCIO_LPM
  {GPIO_CNL_LP_GPP_H19, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H20, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H21, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H22, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPP_H23, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  //(Default HW)  {GPIO_CNL_LP_GPD0,  { GpioPadModeNative1,  GpioHostOwnGpio,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNone }},  //PM_BATLOW_N
  //(Default HW)  {GPIO_CNL_LP_GPD1,  { GpioPadModeNative1,  GpioHostOwnGpio,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNone }},  //BC_ACOK
  //(Default HW)  {GPIO_CNL_LP_GPD2,  { GpioPadModeNative1,  GpioHostOwnGpio,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNone }},  //LAN_WAKE
  //(Default HW)  {GPIO_CNL_LP_GPD3,  { GpioPadModeNative1,  GpioHostOwnGpio,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNone }},  //PM_PWRBTN_N
  //(Default HW)  {GPIO_CNL_LP_GPD4,  { GpioPadModeNative1,  GpioHostOwnGpio,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNone }},  //PM_SLP_S3_N
  //(Default HW)  {GPIO_CNL_LP_GPD5,  { GpioPadModeNative1,  GpioHostOwnGpio,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNone }},  //PM_SLP_S4_N
  {GPIO_CNL_LP_GPD6, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  //{GPIO_CNL_LP_GPD7,  { GpioPadModeNotUsed,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNone }},  //GPD_7
  {GPIO_CNL_LP_GPD8, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  {GPIO_CNL_LP_GPD9, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutLow , GpioIntDis , GpioHostDeepReset , GpioTermNone}},  //Not Used
  //(Default HW)  {GPIO_CNL_LP_GPD10,  { GpioPadModeNative1,  GpioHostOwnGpio,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNone }},  //PM_SLP_S5_N
  //(Default HW)  {GPIO_CNL_LP_GPD11,  { GpioPadModeNative1,  GpioHostOwnGpio,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioResetDefault,  GpioTermNone }},  //LANPHY_EN
  {GPIO_CNL_LP_PECI,  { GpioHardwareDefault,  GpioHostOwnDefault,  GpioDirDefault,  GpioOutDefault,  GpioIntDefault,  GpioHostDeepReset,  GpioTermWpd20K }}, // 20K PD for PECI
};


//
// CFL S 82 UDIMM GPIO TBL
//
static GPIO_INIT_CONFIG mGpioTableCflS82Ddr4PreMem[] =
{
  // PEG slot
  {GPIO_CNL_H_GPP_F22,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//GPIO_PEG SLOT_RESET
  // turn on power in premem after reset asserted
  {GPIO_CNL_H_GPP_F8,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//DGPU_PWR_EN_N
  {GPIO_CNL_H_GPP_K22,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioPlatformReset, GpioTermNone }},//PCH_PEGSLOT1_PWREN
  {GPIO_CNL_H_GPP_K10,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioHostDeepReset, GpioTermNone }},//PCH_RST_GPIO for PEG aux power
  // Titan Ridge
  {GPIO_CNL_H_GPP_K1,  { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDefault, GpioHostDeepReset, GpioTermWpu2K, GpioPadConfigLock }},//PLX_SX_ENTRY_G1_PCH_N
  //Asserting power pin enable in pre-mem phase to solve some NVMe devices cannot be detected.
  {GPIO_CNL_H_GPP_I10, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh,    GpioIntDefault, GpioPlatformReset, GpioTermNone }},//GPP_I_10_DDPD_CTRLDATA
};

//
// WHL ERB GPIO TBL
//
static GPIO_INIT_CONFIG mGpioTableCnlUDdr4PreMem[] =
{
  {GPIO_CNL_LP_GPP_C15,  { GpioPadModeGpio,  GpioHostOwnAcpi,  GpioDirOut,  GpioOutLow,  GpioIntDis,  GpioPlatformReset,  GpioTermNone}},   //SLOT1_RST_N
  {GPIO_CNL_LP_GPP_C14,  { GpioPadModeGpio,  GpioHostOwnAcpi,  GpioDirOut,  GpioOutLow,  GpioIntDis,  GpioPlatformReset,  GpioTermNone}},   //SLOT1_PWREN_N
  {GPIO_CNL_LP_GPP_C12,  { GpioPadModeGpio,  GpioHostOwnAcpi,  GpioDirOut,  GpioOutLow,  GpioIntDis,  GpioPlatformReset,  GpioTermNone}},   //PCIE_NAND_RST_N
  {GPIO_CNL_LP_GPP_C13,  { GpioPadModeGpio,  GpioHostOwnAcpi,  GpioDirOut,  GpioOutHigh, GpioIntDis,  GpioPlatformReset,  GpioTermNone}},   //PCIE_NAND_PWREN_N
};

static GPIO_INIT_CONFIG mGpioTableWhlUDdr4WwanPreMem[] =
{
  // Turn on WWAN power and assert reset pins by default
  {GPIO_CNL_LP_GPP_A11,  { GpioPadModeGpio,  GpioHostOwnGpio,  GpioDirInInv, GpioOutDefault, GpioIntLevel|GpioIntSci, GpioHostDeepReset, GpioTermWpu20K, GpioPadConfigUnlock}},   //WWAN_WAKE_N
  {GPIO_CNL_LP_GPP_D13,  { GpioPadModeGpio,  GpioHostOwnGpio,  GpioDirOut,   GpioOutHigh,    GpioIntDis,              GpioResumeReset,   GpioTermNone,   GpioOutputStateUnlock}}, //WWAN_FCP_OFF
  {GPIO_CNL_LP_GPP_D16,  { GpioPadModeGpio,  GpioHostOwnGpio,  GpioDirOut,   GpioOutHigh,    GpioIntDis,              GpioResumeReset,   GpioTermNone,   GpioOutputStateUnlock}}, //EN_V3.3A_WWAN_LS
  {GPIO_CNL_LP_GPP_E15,  { GpioPadModeGpio,  GpioHostOwnGpio,  GpioDirOut,   GpioOutHigh,    GpioIntDis,              GpioResumeReset,   GpioTermNone,   GpioOutputStateUnlock}}, //WWAN_PERST
  {GPIO_CNL_LP_GPP_F1,   { GpioPadModeGpio,  GpioHostOwnGpio,  GpioDirOut,   GpioOutLow,     GpioIntDis,              GpioResumeReset,   GpioTermNone,   GpioOutputStateUnlock}}, //WWAN_RST_N
  {GPIO_CNL_LP_GPP_H16,  { GpioPadModeGpio,  GpioHostOwnGpio,  GpioDirOut,   GpioOutHigh,    GpioIntDis,              GpioResumeReset,   GpioTermNone,   GpioOutputStateUnlock}}, //WWAN_WAKE_CTRL
  {GPIO_CNL_LP_GPP_H17,  { GpioPadModeGpio,  GpioHostOwnGpio,  GpioDirOut,   GpioOutHigh,    GpioIntDis,              GpioResumeReset,   GpioTermNone,   GpioOutputStateUnlock}}, //WWAN_DISABLE_N
};


//
// CFL H DDR4 GPIO TBL
//
static GPIO_INIT_CONFIG mGpioTableCoffeelakeHDdr4PreMem[] =
{
  // M.2 SSD1
  // pull low first in premem and pull high in postmem
  {GPIO_CNL_H_GPP_C14,  {GpioPadModeGpio , GpioHostOwnGpio , GpioDirOut , GpioOutLow , GpioIntDis , GpioPlatformReset , GpioTermNone }}, // SSD1_RESET
  // turn on power in premem after reset asserted
  {GPIO_CNL_H_GPP_K8,   {GpioPadModeGpio , GpioHostOwnGpio , GpioDirOut , GpioOutHigh , GpioIntDis , GpioPlatformReset , GpioTermNone }}, // SSD1_PWREN

  // M.2 SSD2
  // pull low first in premem and pull high in postmem
  {GPIO_CNL_H_GPP_C15,  {GpioPadModeGpio , GpioHostOwnGpio , GpioDirOut , GpioOutLow , GpioIntDis , GpioPlatformReset , GpioTermNone }}, // SSD2_RESET
  // turn on power in premem after reset asserted
  {GPIO_CNL_H_GPP_K9,   {GpioPadModeGpio , GpioHostOwnGpio , GpioDirOut , GpioOutHigh , GpioIntDis , GpioPlatformReset , GpioTermNone }}, // SSD2_PWREN

  // x4 SLOT2
  // do not reset SLOT2 due to TR AIC card cannot be reset in S3 resume.
  // {GPIO_CNL_H_GPP_F4,   {GpioPadModeGpio , GpioHostOwnGpio , GpioDirOut , GpioOutLow , GpioIntDefault , GpioPlatformReset , GpioTermNone }}, // SLOT2_RST_N
  // turn on power
  {GPIO_CNL_H_GPP_H18,  {GpioPadModeGpio , GpioHostOwnGpio , GpioDirOut , GpioOutLow , GpioIntDis , GpioPlatformReset , GpioTermNone }}, // SLOT2_PWREN

  // PEG slot
  // PEG couldn't assert reset in premem and de-assert in postmem because SA RC detect PEG card in premem phase. Leave PEG reset pin by platform RESET
  // {GPIO_CNL_H_GPP_F9,   {GpioPadModeGpio , GpioHostOwnGpio , GpioDirOut , GpioOutLow , GpioIntDis , GpioPlatformReset , GpioTermNone }}, // PEG_SLOT_RST
  // turn on power
  {GPIO_CNL_H_GPP_F8,   {GpioPadModeGpio , GpioHostOwnGpio , GpioDirOut , GpioOutHigh , GpioIntDis , GpioPlatformReset , GpioTermNone }}, // PEG_SLOT_PWREN

};

GPIO_INIT_CONFIG mGpioTableEMMC[] =
{
  {GPIO_CNL_LP_GPP_F11, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_CMD
  {GPIO_CNL_LP_GPP_F12, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA0
  {GPIO_CNL_LP_GPP_F13, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA1
  {GPIO_CNL_LP_GPP_F14, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA2
  {GPIO_CNL_LP_GPP_F15, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA3
  {GPIO_CNL_LP_GPP_F16, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA4
  {GPIO_CNL_LP_GPP_F17, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA5
  {GPIO_CNL_LP_GPP_F18, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA6
  {GPIO_CNL_LP_GPP_F19, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_DATA7
  {GPIO_CNL_LP_GPP_F20, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_RCLK
  {GPIO_CNL_LP_GPP_F21, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_CLK
  {GPIO_CNL_LP_GPP_F22, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,  GpioOutDefault, GpioIntDis, GpioHostDeepReset,  GpioTermNone}},//EMMC_RESETB
};
