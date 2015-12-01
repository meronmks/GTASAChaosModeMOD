#include "Actor.h"
#include <random>
#include "SA Plugin SDK/plugin/plugin.h"

Actor::Actor()
{
}


Actor::~Actor()
{
}

void Actor::GetActor()
{
	DWORD actorPointer = *((DWORD *)0xB74490);
	actorPointer += 0x4;
	actorPointer = *((DWORD *)actorPointer);
	for (DWORD i = 0; i < 35584; i += 0x100)
	{
		DWORD actor = *((DWORD *)actorPointer);	//�s���擾
		actorPointer += 0x1;	//�|�C���^�̈ʒu���炵
		if (0x80 > actor && actor >= 0x00)
		{
			actor += i;
			if (*((DWORD *)actor) > 0)
			{
				ActorArray.push_back(actor);
			}
		}
	}
}

void Actor::CheckDefinedActor()
{
	std::list<DWORD>::iterator iterator = ActorArray.begin(); // �C�e���[�^
	while (iterator != ActorArray.end())
	{
		if (*iterator > 0)
		{
			ActorArray.remove(*iterator);	//�폜
			iterator = ActorArray.begin(); // �C�e���[�^�̍X�V
		}
		++iterator;  // �C�e���[�^���P�i�߂�
	}
}

void Actor::GiveWeapon()
{
	
}

void Actor::ActorArmament()
{
	std::list<DWORD>::iterator iterator = ActorArray.begin(); // �C�e���[�^
	//������������
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand100(0, 100);
	while (iterator != ActorArray.end())
	{
		if (30 <= rand100(mt)) continue;
		GiveWeapon();
		++iterator;  // �C�e���[�^���P�i�߂�
	}
}
