rem copia las dlls en caso de que sean nuevas -noexistan- o se hayan modificado. Version inicial 2.01.08

rem SDL
xcopy ..\Motor\dependencies\SDL2\Buildx86\SDL2.dll ..\bin\ /s /d /y

rem FMOD
xcopy ..\Motor\dependencies\Fmod\Buildx86\fmod.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\Fmod\Buildx86\fmodL.dll ..\bin\ /s /d /y

rem OGRE
rem copia las dlls implicitas a bin
xcopy ..\Motor\dependencies\Ogre\Build32\bin\debug\OgreMain_d.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build32\bin\release\OgreMain.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build32\bin\release\zlib.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build32\bin\debug\OgreRTShaderSystem_d.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build32\bin\release\OgreRTShaderSystem.dll ..\bin\ /s /d /y

rem copia las dlls explicitas de los plugins a bin\Ogre[Debug/Release]
xcopy ..\Motor\dependencies\Ogre\Build32\bin\debug\Codec_STBI_d.dll ..\bin\OgreDEBUG\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build32\bin\debug\RenderSystem_Direct3d11_d.dll ..\bin\OgreDEBUG\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build32\bin\release\Codec_STBI.dll ..\bin\OgreRELEASE\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build32\bin\release\RenderSystem_Direct3d11.dll ..\bin\OgreRELEASE\ /s /d /y

exit 0