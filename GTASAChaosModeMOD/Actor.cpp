#include "Actor.h"
#include "SA Plugin SDK/game_sa/CPools.h"
#include <random>

Actor::Actor()
{
}


Actor::~Actor()
{
}

void Actor::GetActor()
{
	auto actorPointer = *((CPed **)0xB74490);
	if (actorPointer == 0)return;
	actorPointer += 0x4;
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
	auto iterator = ActorArray.begin(); // �C�e���[�^
	while (iterator != ActorArray.end())
	{
		if (*iterator > 0)
		{
			ActorArray.erase(iterator);	//�폜
			iterator = ActorArray.begin(); // �C�e���[�^�̍X�V
		}
		++iterator;  // �C�e���[�^���P�i�߂�
	}
}


void Actor::ActorArmament()
{
	//������������
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand100(0, 100);
	if (CPools::ms_pPedPool == NULL) return;
	auto pedCount = CPools::ms_pPedPool->m_Size;
	for (int i = 0; i < pedCount; i++)
	{
		if (30 <= rand100(mt)) continue;
		auto ped = CPools::ms_pPedPool->GetAt(i);
		if (ped == NULL || ped->IsPlayer()) return;
		ped->GiveWeapon(WEAPON_RLAUNCHER, 9999, true);
		//ToDo::�s���ɕ��������������@�𒲂ׂ�
	}
}
