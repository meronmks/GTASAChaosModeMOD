#pragma once
#include <Windows.h>
#include <list>

class Actor
{
private:
	//市民などを格納しておくList
	std::list<DWORD> ActorArray;
public:
	Actor();
	~Actor();
	//ActorをListへ格納
	void GetActor();
	//List内にいるActorが使用可能か調べる
	void CheckDefinedActor();
	//市民に武器を持たせる;
	void GiveWeapon();
	//市民を武装させる
	void ActorArmament();
};

