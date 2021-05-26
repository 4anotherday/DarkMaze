cd Motor/
git checkout main
git pull
call Compile.bat
msbuild DarkMaze.sln /p:Configuration=Release /p:Platform=x64