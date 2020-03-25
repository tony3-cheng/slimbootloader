@echo off
@IF "%1"=="clean" goto buildclean
@IF "%1"=="-?" goto helpmsg
@IF "%1"=="cfl" goto cfl
@IF "%1"=="apl" goto apl
@goto helpmsg

:buildclean
python BuildLoader.py clean -d
@goto exit

:cfl
@goto buildcfl
:cflback
@goto buildcflstitch
:cflstitchback
@goto exit

:buildcfl
::python BuildLoader.py build cfl -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_RELEASE.fd:UEFI:Lzma"
python BuildLoader.py build cfl -p "OsLoader.efi:LLDR:Lz4"
@goto cflback

:buildcflstitch
::python Platform/CoffeelakeBoardPkg/Script/StitchLoader.py -i CRB.bin -s Outputs/cfl/Stitch_Components.zip -o Build/sbl_cfl_ifwi.bin
::python Platform/CoffeelakeBoardPkg/Script/StitchLoader.py -i CRB.bin -s Outputs/cfl/SlimBootloader.bin -o Build/sbl_cfl_ifwi.bin
::python Platform/CoffeelakeBoardPkg/Script/StitchLoader.py -i Platform/CoffeelakeBoardPkg/BiosBin/WHL_RVP_U_B_Cons_Prod.bin -s Outputs/cfl/SlimBootloader.bin -o Build/sbl_cfl_ifwib.bin
python Platform/CoffeelakeBoardPkg/Script/StitchLoader.py -i Platform/CoffeelakeBoardPkg/BiosBin/6882000U160X010.bin -s Outputs/cfl/SlimBootloader.bin -o Build/6882001U160X010.bin -p AA000214
@goto cflstitchback

:apl
@goto buildapl
:aplback
@goto buildstitchapl
:aplstitchback
@goto exit

:buildapl
python BuildLoader.py build apl -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_RELEASE.fd:UEFI:Lzma"
@goto aplback

:buildstitchapl
python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i Platform/ApollolakeBoardPkg/BiosBin/25690000I60V111.bin -s Outputs/apl/Stitch_Components.zip -o Build/25690010I60X001.bin -p AA000010
python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i Platform/ApollolakeBoardPkg/BiosBin/35690000I60V400.bin -s Outputs/apl/Stitch_Components.zip -o Build/35690010I60X001.bin -p AA000011
python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i Platform/ApollolakeBoardPkg/BiosBin/68690000I60V300.bin -s Outputs/apl/Stitch_Components.zip -o Build/68690010I60X001.bin -p AA000012
python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i Platform/ApollolakeBoardPkg/BiosBin/75690000I60V300.bin -s Outputs/apl/Stitch_Components.zip -o Build/75690010I60X001.bin -p AA000013
::python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i Platform/ApollolakeBoardPkg/BiosBin/35690000I60V400.bin -s Outputs/apl/Stitch_Components.zip -o Build/35690010I60X001.bin -p AA000211
@goto aplstitchback

:helpmsg
@echo Build Slim BootLoader 
@echo       -?      help the message  
@echo       apl     build Apollo Lake
@echo       cfl     build Coffer Lake
@echo       clean   only clean
@goto exit

:exit
@echo on


