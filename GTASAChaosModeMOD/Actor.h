#pragma once
#include <Windows.h>
#include <list>

class Actor
{
private:
	//�s���Ȃǂ��i�[���Ă���List
	std::list<DWORD> ActorArray;
public:
	Actor();
	~Actor();
	//Actor��List�֊i�[
	void GetActor();
	//List���ɂ���Actor���g�p�\�����ׂ�
	void CheckDefinedActor();
	//�s���ɕ������������;
	void GiveWeapon();
	//�s���𕐑�������
	void ActorArmament();
};

