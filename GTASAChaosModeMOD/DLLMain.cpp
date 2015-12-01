#include <windows.h>
#include "Actor.h"

BOOL isGameRunning;	//GTASAが起動しているかどうかの判定変数
Actor actors;	//Actor関連

//ここにカオス処理メインで呼び出したいものを全部書く
DWORD WINAPI ScriptMain(void *parameter)
{
	while (isGameRunning)
	{
		actors.GetActor();
		actors.CheckDefinedActor();
	}
	ExitThread(0);	//スレッド終了通知
}

int WINAPI DllMain(HINSTANCE hInst, DWORD fdReason, PVOID pvReserved)
{
	switch (fdReason) {
	case DLL_PROCESS_ATTACH:
		isGameRunning = true;
		CreateThread(0, 0, ScriptMain, 0, 0, 0);
		break;
	case DLL_PROCESS_DETACH:
		isGameRunning = false;
		break;
	default:
		break;
	}
	return TRUE;
}