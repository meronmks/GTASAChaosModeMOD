#include "Actor.h"

Actor::Actor()
{
}


Actor::~Actor()
{
}

void Actor::ActorArmament()
{
	if (CPools::ms_pPedPool == NULL) return;
	auto pedCount = CPools::ms_pPedPool->m_Size;
	for (int i = 0; i < pedCount; i++)
	{
		auto ped = CPools::ms_pPedPool->GetAt(i);
		if (ped == NULL || ped->IsPlayer() || !ped->IsAlive()) continue;
		if(ped->m_nActiveWeaponSlot == 0)
		{
			GiveRandomWeapon(ped);
			continue;
		}
		//乱数生成準備
		std::random_device rnd;
		std::mt19937 mt(rnd());
		std::uniform_int_distribution<> rand100(0, 100);
		if (10 < rand100(mt)) continue;
		if (ped->m_pedState == PEDSTATE_DRIVING)
		{
			 GiveRandomDriveByWeapon(ped);
		}
		else
		{
			 GiveRandomWeapon(ped);
		}
	}
}

void Actor::GiveRandomWeapon(CPed* ped)
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand100(0, 500);
	eWeaponType weapon;
	switch (rand100(mt) % 14)
	{
	case 0:
		weapon =  WEAPON_RLAUNCHER;
		break;
	case 1:
		weapon = WEAPON_M4;
		break;
	case 2:
		weapon = WEAPON_BASEBALLBAT;
		break;
	case 3:
		weapon = WEAPON_DESERT_EAGLE;
		break;
	case 4:
		weapon = WEAPON_MICRO_UZI;
		break;
	case 5:
		weapon = WEAPON_TEC9;
		break;
	case 6:
		weapon = WEAPON_MINIGUN;
		break;
	case 7:
		weapon = WEAPON_RLAUNCHER_HS;
		break;
	case 8:
		weapon = WEAPON_SNIPERRIFLE;
		break;
	case 9:
		weapon = WEAPON_MOLOTOV;
		break;
	case 10:
		weapon = WEAPON_GRENADE;
		break;
	case 11:
		weapon = WEAPON_CHAINSAW;
		break;
	case 12:
		weapon = WEAPON_SAWNOFF;
		break;
	case 13:
		weapon = WEAPON_MP5;
		break;
	case 14:
		weapon = WEAPON_KNIFE;
		break;
	default:
		weapon = WEAPON_RLAUNCHER;
		break;
	}
	CurrentWeapon(ped, weapon);
}

void Actor::GiveRandomDriveByWeapon(CPed* ped)
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand100(0, 500);
	eWeaponType weapon;
	switch (rand100(mt) % 4)
	{
	case 0:
		weapon = WEAPON_MICRO_UZI;
		break;
	case 1:
		weapon = WEAPON_TEC9;
		break;
	case 2:
		weapon = WEAPON_SNIPERRIFLE;
		break;
	case 3:
		weapon = WEAPON_MP5;
		break;
	default:
		weapon = WEAPON_MICRO_UZI;
		break;
	}
	CurrentWeapon(ped, weapon);
}

void Actor::CurrentWeapon(CPed* ped, eWeaponType weapon)
{
	ped->ClearWeapons();
	ped->GiveWeapon(weapon, 9999, true);
	auto weaponID = ped->GetWeaponSlot(weapon);
	ped->SetCurrentWeapon(weaponID);
	ped->SetWeaponSkill(weapon, (char)2);
}