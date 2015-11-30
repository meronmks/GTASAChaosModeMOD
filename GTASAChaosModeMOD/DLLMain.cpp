#include <windows.h>
#include "Actor.h"

BOOL isGameRunning;	//GTASA���N�����Ă��邩�ǂ����̔���ϐ�
Actor actors;	//Actor�֘A

//�����Ƀ��C���ŌĂяo���������̂�S������
DWORD WINAPI ScriptMain(void *parameter)
{
	while (isGameRunning)
	{
		
	}
	ExitThread(0);	//�X���b�h�I���ʒm
}

//���ӂ̎s�����擾������
DWORD WINAPI GetActorThread(void *parameter)
{
	while (isGameRunning)
	{
		actors.GetActor();
	}
	ExitThread(0);	//�X���b�h�I���ʒm
}

//List�ɓ��ꂽ�s�����g�p�ł��邩�m���߂�
DWORD WINAPI CheckDefinedActorThread(void *parameter)
{
	while (isGameRunning)
	{
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