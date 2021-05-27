#include "Engine.h"
#include "Exceptions.h"
#include "Logger.h"

#if (defined _DEBUG) || !(defined _WIN32)
int main() {
#else
#include <Windows.h>
int WINAPI
WinMain(HINSTANCE zhInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow) {
#endif

	Engine::CreateInstance();
	Engine* prueba = Engine::getInstance();
	prueba->init("Assets/resources.cfg", "Assets/Levels");
	prueba->disableShadows();
	prueba->changeScene("menu.lua");
	prueba->run();

	return 0;
}