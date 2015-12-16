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
		DWORD actor = *((DWORD *)actorPointer);	//市民取得
		actorPointer += 0x1;	//ポインタの位置ずらし
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
	auto iterator = ActorArray.begin(); // イテレータ
	while (iterator != ActorArray.end())
	{
		if (*iterator > 0)
		{
			ActorArray.erase(iterator);	//削除
			iterator = ActorArray.begin(); // イテレータの更新
		}
		++iterator;  // イテレータを１つ進める
	}
}


void Actor::ActorArmament()
{
	//乱数生成準備
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
		//ToDo::市民に武器をもたせる方法を調べる
	}
}
