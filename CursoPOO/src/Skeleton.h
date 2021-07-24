#pragma once

#include "Enemy.h"

class Skeleton : public Enemy
{
private:
	int arrows;

public:
	Skeleton()
		:arrows(0)
	{
	}

	Skeleton(int hp, int attack, int defense, const std::string& name)
		:Enemy(hp, attack, defense, name), arrows(0)
	{
	}

	int GetArrows() const;

	void SetArrows(int arrows);

	virtual void Attack() override;
};