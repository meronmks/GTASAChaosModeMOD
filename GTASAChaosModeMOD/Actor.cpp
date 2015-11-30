#include "Actor.h"

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
		DWORD actor = *((DWORD *)actorPointer);	//市民取得
		actorPointer += 0x1;	//ポインタの位置ずらし
		if (0x80 >= actor && actor >= 0x00)
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
	std::list<DWORD>::iterator iterator = ActorArray.begin(); // イテレータ
	while (iterator != ActorArray.end())
	{
		if (*iterator > 0)
		{
			ActorArray.remove(*iterator);
			iterator = ActorArray.begin(); // イテレータの更新
		}
		++iterator;  // イテレータを１つ進める
	}
}
