#include "Player.h"

int Player::GetHearts(void) {
	return this->redHearts;
}
 
void Player::AddDamage(float dmg) {
	this->damage += dmg;
}

void Player::RemoveHearts(int hearts) {
	this->redHearts -= hearts;
}