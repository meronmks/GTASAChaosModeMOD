#pragma once
#include <Windows.h>
#include "SA Plugin SDK/game_sa/eWeaponType.h"
#include <vector>


class Actor
{
private:
	//�s���Ȃǂ��i�[���Ă���List
	std::vector<DWORD> ActorArray;
public:
	Actor();
	~Actor();
	//Actor��List�֊i�[
	void GetActor();
	//List���ɂ���Actor���g�p�\�����ׂ�
	void CheckDefinedActor();
	//�s���ɕ������������;
	void GiveWeapon(DWORD actor, eWeaponType weaponType, unsigned int ammo, bool likeUnused);
	//�s���𕐑�������
	void ActorArmament();
};

