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
		DWORD actor = *((DWORD *)actorPointer);	//�s���擾
		actorPointer += 0x1;	//�|�C���^�̈ʒu���炵
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
	std::list<DWORD>::iterator iterator = ActorArray.begin(); // �C�e���[�^
	while (iterator != ActorArray.end())
	{
		if (*iterator > 0)
		{
			ActorArray.remove(*iterator);
			iterator = ActorArray.begin(); // �C�e���[�^�̍X�V
		}
		++iterator;  // �C�e���[�^���P�i�߂�
	}
}
