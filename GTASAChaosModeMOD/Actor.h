#pragma once
#include <Windows.h>
#include "SA Plugin SDK/game_sa/eWeaponType.h"
#include <vector>


class Actor
{
private:
	//s–¯‚È‚Ç‚ğŠi”[‚µ‚Ä‚¨‚­List
	std::vector<DWORD> ActorArray;
public:
	Actor();
	~Actor();
	//Actor‚ğList‚ÖŠi”[
	void GetActor();
	//List“à‚É‚¢‚éActor‚ªg—p‰Â”\‚©’²‚×‚é
	void CheckDefinedActor();
	//s–¯‚É•Ší‚ğ‚½‚¹‚é;
	void GiveWeapon(DWORD actor, eWeaponType weaponType, unsigned int ammo, bool likeUnused);
	//s–¯‚ğ•‘•‚³‚¹‚é
	void ActorArmament();
};

