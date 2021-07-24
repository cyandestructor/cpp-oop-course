#pragma once

#include "Enemy.h"

class Mummy : public Enemy
{
private:
	int mana;

public:
	Mummy()
		:mana(0)
	{
	}

	Mummy(int hp, int attack, int defense, const std::string& name)
		:Enemy(hp, attack, defense, name), mana(0)
	{
	}

	int GetMana() const;

	void SetMana(int mana);

	virtual void Attack() override;
};