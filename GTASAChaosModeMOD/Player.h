#pragma once
#include <Windows.h>
class Player
{
private:
	//Player‚Ìæ“¾i‘¶İ‚µ‚È‚©‚Á‚½‚ç0)
	DWORD getPlayer();
public:
	Player();
	~Player();
	//Player‚ª‘¶İ‚·‚é‚©‚ğ•Ô‚·
	BOOL playerDefined();
	//Player‚ª¶‚«‚Ä‚¢‚é‚©‚Ç‚¤‚©‚ğ•Ô‚·
	BOOL playerAlive();
};

