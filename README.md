Slim Bootloader support FOR Advantech
=====================================

Base on: commit faa172e67e4e43416732b0b2d4c17a8383348257

Status:   

  *SOM-2569  Bringup   Todo: GPIOs, HSIO, SuperIO, GOP(VBT)

  *SOM-3569  Bringup   Todo: GPIOs, HSIO, SuperIO, GOP(VBT)

  *SOM-6869  Bringup   Todo: GPIOs, HSIO, SuperIO, GOP(VBT)

  *SOM-7569  Bringup   Todo: GPIOs, HSIO, SuperIO, GOP(VBT)

Build Environment
-----------------

Python 3.6 - C:\Python36

NASM 2.11 - C:\Nasm

IASL 20160422 - C:\ASL

OpenSSL - C:\openssl

    set OPENSSL_PATH=C:\Openssl

Download Slim Bootloader
------------------------

git clone https://github.com/Advgcipc/slimbootloader.git


Build Slim Bootloader
---------------------

python BuildLoader.py build apl

python BuildLoader.py clean -d

Build SBL: (Release mode)

python BuildLoader.py build apl -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_RELEASE.fd:UEFI:Lzma"

Build SBL: (Debug mode)

python BuildLoader.py build apl -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_DEBUG.fd:UEFI:Lzma"


Stitch Slim Bootloader
----------------------

python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i <BIOS_IMAGE_NAME> -s Outputs/apl/Stitch_Components.zip -o <SBL_IFWI_IMAGE_NAME>

Example:

python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i 35690000I60X402.bin -s Outputs/apl/Stitch_Components.zip -o 35690000S60X402.bin


Build UEFIPayload
-----------------

git clone --recurse-submodules https://github.com/tianocore/edk2.git edk2

git checkout 42d8be0eaac5e7e109f487d4e241847e815b077a

git submodule update ¡Vrecursive

edksetup.bat

build -a IA32 -a X64 -p UefiPayloadPkg\UefiPayloadPkgIa32X64.dsc -b DEBUG -t VS2017 -D BOOTLOADER=SBL

build -a IA32 -a X64 -p UefiPayloadPkg\UefiPayloadPkgIa32X64.dsc -b RELEASE -t VS2017 -D BOOTLOADER=SBL

Build Slim Bootloader with UEFIPayload
--------------------------------------

Put UEFIPAYLOAD.fd into $(SOURCE)\PayloadPkg\PayloadBins\
---------------------------------------------------------
Example:

copy edk2\Build\UefiPayloadPkgX64\DEBUG_VS2015x86\FV\UEFIPAYLOAD.fd sbl\PayloadPkg\PayloadBins\UEFIPAYLOAD.fd

Update .dlt file
----------------
Insert the following line to file sbl\Platform\ApollolakeBoardPkg\CfgData\CfgData_Int_LeafHill.dlt:

GEN_CFG_DATA.PayloadId                   | 'UEFI'

  Repeat *** Build Slim Bootloader *** and *** Stitch Slim Bootloader ***


Slim Bootloader
================

**Welcome to the Slim Bootloader project!**

Slim Bootloader is an open-source boot firmware solution, built from the
ground up to be secure, lightweight, and highly optimized while leveraging
robust tools and libraries from the [EDK II](https://www.tianocore.org/edk2/)
framework.

What is a Bootloader?
---------------------
Just like a typical [BIOS](https://en.wikipedia.org/wiki/BIOS), Slim Bootloader
is the piece of software responsible for initializing the core hardware
components of the system when it is powered on, followed by the loading and
launching of the desired operating system.

Slim Bootloader offers the flexibility for OEMs, device manufacturers, and hobbyists
to isolate, configure, and optimize for the the specific requirements of the system
thereby achieving unparalleled boot performance and minimizing firmware footprint.

Supported Platforms
-------------------
Please visit [Supported Hardware](https://slimbootloader.github.io/supported-hardware/index.html) page for a list of platforms supported by Slim Bootloader.

Getting Started
---------------
Documentation for compiling, using, and extending Slim Bootloader can be found
[here](https://slimbootloader.github.io/).

Mailing List
--------------
You can subscribe to our mailing list for questions or share your learnings:
https://lists.01.org/postorius/lists/sbl-devel.lists.01.org/

Archives: Â https://lists.01.org/hyperkitty/list/sbl-devel@lists.01.org/

License
-------
Slim Bootloader is released under the terms of the BSD-2-Clause Plus Patent License.
Please see the `LICENSE` file for the full terms of the license.
