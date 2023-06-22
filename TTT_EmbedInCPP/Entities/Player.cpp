#include "Player.h"

void Player::AddDamage(float dmg) {
	this->damage += dmg;
}

void Player::RemoveHearts(int hearts) {
	this->redHearts -= hearts;
}