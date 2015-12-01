#include <windows.h>
#include "Actor.h"

BOOL isGameRunning;	//GTASA���N�����Ă��邩�ǂ����̔���ϐ�
Actor actors;	//Actor�֘A

//�����ɃJ�I�X�������C���ŌĂяo���������̂�S������
DWORD WINAPI ScriptMain(void *parameter)
{
	while (isGameRunning)
	{
		actors.GetActor();
		actors.CheckDefinedActor();
	}
	ExitThread(0);	//�X���b�h�I���ʒm
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