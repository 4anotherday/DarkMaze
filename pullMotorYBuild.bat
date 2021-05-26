cd Motor/
git checkout main
git pull
call Compile.bat
cd ../
msbuild DarkMaze.sln /p:Configuration=Release /p:Platform=x64