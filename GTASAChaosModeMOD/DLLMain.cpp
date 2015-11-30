#include <windows.h>
#include "Actor.h"

BOOL isGameRunning;	//GTASAが起動しているかどうかの判定変数
Actor actors;	//Actor関連

//ここにメインで呼び出したいものを全部書く
DWORD WINAPI ScriptMain(void *parameter)
{
	while (isGameRunning)
	{
		
	}
	ExitThread(0);	//スレッド終了通知
}

//周辺の市民を取得するやつ
DWORD WINAPI GetActorThread(void *parameter)
{
	while (isGameRunning)
	{
		actors.GetActor();
	}
	ExitThread(0);	//スレッド終了通知
}

//Listに入れた市民が使用できるか確かめる
DWORD WINAPI CheckDefinedActorThread(void *parameter)
{
	while (isGameRunning)
	{
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
		CreateThread(0, 0, GetActorThread, 0, 0, 0);
		CreateThread(0, 0, CheckDefinedActorThread, 0, 0, 0);
		break;
	case DLL_PROCESS_DETACH:
		isGameRunning = false;
		break;
	default:
		break;
	}
	return TRUE;
}