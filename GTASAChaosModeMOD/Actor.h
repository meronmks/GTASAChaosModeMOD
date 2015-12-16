#pragma once
#include <Windows.h>
#include "SA Plugin SDK/game_sa/eWeaponType.h"
#include <vector>


class Actor
{
private:
	//市民などを格納しておくList
	std::vector<DWORD> ActorArray;
public:
	Actor();
	~Actor();
	//ActorをListへ格納
	void GetActor();
	//List内にいるActorが使用可能か調べる
	void CheckDefinedActor();
	//市民に武器を持たせる;
	void GiveWeapon(DWORD actor, eWeaponType weaponType, unsigned int ammo, bool likeUnused);
	//市民を武装させる
	void ActorArmament();
};

