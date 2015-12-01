#pragma once
#include <Windows.h>
#include <list>

class Actor
{
private:
	//s–¯‚È‚Ç‚ğŠi”[‚µ‚Ä‚¨‚­List
	std::list<DWORD> ActorArray;
public:
	Actor();
	~Actor();
	//Actor‚ğList‚ÖŠi”[
	void GetActor();
	//List“à‚É‚¢‚éActor‚ªg—p‰Â”\‚©’²‚×‚é
	void CheckDefinedActor();
	//s–¯‚É•Ší‚ğ‚½‚¹‚é;
	void GiveWeapon();
	//s–¯‚ğ•‘•‚³‚¹‚é
	void ActorArmament();
};

