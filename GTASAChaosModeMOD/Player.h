#pragma once
#include <Windows.h>
class Player
{
private:
	//Player�̎擾�i���݂��Ȃ�������0)
	DWORD getPlayer();
public:
	Player();
	~Player();
	//Player�����݂��邩��Ԃ�
	BOOL playerDefined();
	//Player�������Ă��邩�ǂ�����Ԃ�
	BOOL playerAlive();
};

