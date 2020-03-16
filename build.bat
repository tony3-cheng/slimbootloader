@echo off
@IF "%1"=="all" goto buildall
@IF "%1"=="clean" goto buildclean
@IF "%1"=="apl" goto buildapl
@IF "%1"=="stitch" goto buildstitch
@IF "%1"=="-?" goto helpmsg
@goto helpmsg

:buildall
python BuildLoader.py distclean
python BuildLoader.py build apl -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_RELEASE.fd:UEFI:Lzma"
@goto buildstitch
@goto exit

:buildclean
python BuildLoader.py clean
@goto exit

:buildapl
python BuildLoader.py build apl -r -p "OsLoader.efi:LLDR:Lz4;UEFIPAYLOAD_RELEASE.fd:UEFI:Lzma"
@goto exit

:buildstitch
python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i Platform/ApollolakeBoardPkg/BiosBin/25690000I60V111.bin -s Outputs/apl/Stitch_Components.zip -o Build/25690010I60X001.bin -p AA000010
python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i Platform/ApollolakeBoardPkg/BiosBin/35690000I60V400.bin -s Outputs/apl/Stitch_Components.zip -o Build/35690010I60X001.bin -p AA000011
python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i Platform/ApollolakeBoardPkg/BiosBin/68690000I60V300.bin -s Outputs/apl/Stitch_Components.zip -o Build/68690010I60X001.bin -p AA000012
python Platform/ApollolakeBoardPkg/Script/StitchLoader.py -i Platform/ApollolakeBoardPkg/BiosBin/75690000I60V300.bin -s Outputs/apl/Stitch_Components.zip -o Build/75690010I60X001.bin -p AA000013
@goto exit

:helpmsg
@echo Build Slim BootLoader 
@echo       -?      help the message  
@echo       all     rebuild all source code
@echo       clean   only clean
@echo       apl     only build again
@echo       stitch  only stich
@goto exit

:exit
@echo on


