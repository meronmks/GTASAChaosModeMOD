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
	//ランダムな武器を選択する
	void GiveRandomWeapon(CPed*);
	//ランダムに市民がドライブバイ可能な武器を選択する
	void GiveRandomDriveByWeapon(CPed*);
	//武器を装備させる
	void CurrentWeapon(CPed*, eWeaponType);
public:
	Actor();
	~Actor();
	//市民を武装させる
	void ActorArmament();
};

