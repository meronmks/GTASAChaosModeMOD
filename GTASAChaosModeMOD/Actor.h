#pragma once
#include <Windows.h>
#include "SA Plugin SDK/game_sa/eWeaponType.h"
#include <vector>


class Actor
{
private:
	//�����_���ȕ����I������
	eWeaponType GiveRandomWeapon();
public:
	Actor();
	~Actor();
	//�s���𕐑�������
	void ActorArmament();
};

