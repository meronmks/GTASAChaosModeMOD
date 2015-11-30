#include "Player.h"

Player::Player()
{
}


Player::~Player()
{
}

BOOL Player::playerDefined(){
	return getPlayer() > 0;
}

DWORD Player::getPlayer(){
	return *((DWORD *)0xB6F5F0);
}

BOOL Player::playerAlive() {
	DWORD player = getPlayer();
	DWORD PlayerStatus; //ƒvƒŒƒCƒ„[‚ÌŒ»İ‚Ìó‘Ô
	if (player != 0) {
		player += 0x530;
		PlayerStatus = *((DWORD *)player);
		if (PlayerStatus == 54 || PlayerStatus == 55) {
			return false;
		}
	}
	return true; //‘¶İ‚µ‚È‚¢ê‡‚Í€‚ñ‚Å‚È‚¢ˆµ‚¢
}
