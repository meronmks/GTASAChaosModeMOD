#pragma once
#include <Windows.h>
#include "SA Plugin SDK/game_sa/eWeaponType.h"
#include <vector>


class Actor
{
private:
	//ƒ‰ƒ“ƒ_ƒ€‚È•Ší‚ğ‘I‘ğ‚·‚é
	eWeaponType GiveRandomWeapon();
public:
	Actor();
	~Actor();
	//s–¯‚ğ•‘•‚³‚¹‚é
	void ActorArmament();
};

