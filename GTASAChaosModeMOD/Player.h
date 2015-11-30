#pragma once
#include <Windows.h>
class Player
{
private:
	//Playerの取得（存在しなかったら0)
	DWORD getPlayer();
public:
	Player();
	~Player();
	//Playerが存在するかを返す
	BOOL playerDefined();
	//Playerが生きているかどうかを返す
	BOOL playerAlive();
};

