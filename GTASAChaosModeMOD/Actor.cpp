#include "Actor.h"

Actor::Actor()
{
}


Actor::~Actor()
{
}

void Actor::ActorArmament()
{
	//óêêîê∂ê¨èÄîı
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand100(0, 100);
	if (CPools::ms_pPedPool == NULL) return;
	auto pedCount = CPools::ms_pPedPool->m_Size;
	for (int i = 0; i < pedCount; i++)
	{
		if (40 < rand100(mt)) continue;
		auto ped = CPools::ms_pPedPool->GetAt(i);
		if (ped == NULL || ped->IsPlayer()) return;
		eWeaponType weapon;
		if(ped->m_pedState == PEDSTATE_DRIVING)
		{
			weapon = GiveRandomDriveByWeapon();
		}else
		{
			weapon = GiveRandomWeapon();
		}
		if (!ped->DoWeHaveWeaponAvailable(weapon))
		{
			ped->ClearWeapons();
			ped->GiveWeapon(weapon, 9999, false);
			ped->SetCurrentWeapon(weapon);
		}
	}
}

eWeaponType Actor::GiveRandomWeapon()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand100(0, 500);
	switch (rand100(mt) % 16)
	{
	case 0:
		return WEAPON_RLAUNCHER;
	case 1:
		return WEAPON_M4;
	case 2:
		return WEAPON_BASEBALLBAT;
	case 3:
		return WEAPON_DESERT_EAGLE;
	case 4:
		return WEAPON_MICRO_UZI;
	case 5:
		return WEAPON_TEC9;
	case 6:
		return WEAPON_MINIGUN;
	case 7:
		return WEAPON_RLAUNCHER_HS;
	case 8:
		return WEAPON_SNIPERRIFLE;
	case 9:
		return WEAPON_MOLOTOV;
	case 10:
		return WEAPON_GRENADE;
	case 11:
		return WEAPON_CHAINSAW;
	case 12:
		return WEAPON_SAWNOFF;
	case 13:
		return WEAPON_MP5;
	case 14:
		return WEAPON_KNIFE;
	default:
		return WEAPON_RLAUNCHER;
	}
}

eWeaponType Actor::GiveRandomDriveByWeapon()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand100(0, 500);
	switch (rand100(mt) % 17)
	{
	case 0:
		return WEAPON_MICRO_UZI;
	case 1:
		return WEAPON_TEC9;
	case 2:
		return WEAPON_SNIPERRIFLE;
	case 3:
		return WEAPON_MP5;
	default:
		return WEAPON_MICRO_UZI;
	}
}