#pragma once
#include <Windows.h>
#include "SA Plugin SDK/game_sa/eWeaponType.h"
#include "SA Plugin SDK/game_sa/CPools.h"
#include "SA Plugin SDK/game_sa/CVehicle.h"
#include <vector>
#include <random>


class Actor
{
private:
	//�����_���ȕ����I������
	eWeaponType GiveRandomWeapon();
	//�����_���Ɏs�����h���C�u�o�C�\�ȕ����I������
	eWeaponType GiveRandomDriveByWeapon();
public:
	Actor();
	~Actor();
	//�s���𕐑�������
	void ActorArmament();
};

