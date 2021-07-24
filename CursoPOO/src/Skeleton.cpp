#include "Skeleton.h"

int Skeleton::GetArrows() const
{
	return arrows;
}

void Skeleton::SetArrows(int arrows)
{
	if (arrows < 0)
		return;

	this->arrows = arrows;
}

void Skeleton::Attack()
{
	if (arrows > 0) {
		std::cout << "The Skeleton " << name << " shoots with " << attack << " of power" << std::endl;
		arrows--;
	}
}