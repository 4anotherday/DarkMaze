rem copia las dlls en caso de que sean nuevas -noexistan- o se hayan modificado. Version inicial 2.01.08
rem RELEASEx64
xcopy ..\Motor\dependencies\PhysX\Buildx64\release\glut32.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\PhysX\Buildx64\release\PhysX_64.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\PhysX\Buildx64\release\PhysXCommon_64.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\PhysX\Buildx64\release\PhysXCooking_64.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\PhysX\Buildx64\release\PhysXDevice64.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\PhysX\Buildx64\release\PhysXFoundation_64.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\PhysX\Buildx64\release\PhysXGpu_64.dll ..\bin\ /s /d /y
exit 0