#pragma once

class Player
{
	private:
		int redHearts;
		float damage;
	public:
		int lastLevelSpecialSpawn;	// public for direct access - this makes for distinct testing scenarios compared to using a getter function

	public:
		int GetHearts(void);
	public:
		void AddDamage(float dmg);
		void RemoveHearts(int hearts);
};