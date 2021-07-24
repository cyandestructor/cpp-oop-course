#include "Mummy.h"

int Mummy::GetMana() const
{
	return mana;
}

void Mummy::SetMana(int mana)
{
	if (mana < 0)
		return;

	this->mana = mana;
}

void Mummy::Attack()
{
	if (mana > 0) {
		std::cout << "The Mummy " << name << " fires magic with " << attack << " of power" << std::endl;
		mana--;
	}
}