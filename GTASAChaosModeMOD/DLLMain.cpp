#include <windows.h>
#include "Actor.h"
#include <process.h>

Actor actors;	//Actor関連
HANDLE hTh;

//ここにカオス処理メインで呼び出したいものを全部書く
unsigned __stdcall ScriptMain(LPVOID parameter)
{
	while (1)
	{
		actors.ActorArmament();
		Sleep(500);	//フリーズ回避用
	}
}

int WINAPI DllMain(HINSTANCE hInst, DWORD fdReason, PVOID pvReserved)
{
	switch (fdReason) {
	case DLL_PROCESS_ATTACH:
		hTh = (HANDLE)_beginthreadex(NULL, 0, ScriptMain, NULL, 0, NULL);
		break;
	case DLL_PROCESS_DETACH:
		if (hTh != NULL) {
			CloseHandle(hTh);
		}
		break;
	default:
		break;
	}
	return TRUE;
}