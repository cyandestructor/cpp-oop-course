// Lo primero que hay que hacer en el archivo de c�digo o .cpp de una
// clase es incluir su archivo de Encabezado para acceder a su declaraci�n
#include "Enemy.h"

// Se escriben ahora s� los cuerpos de los m�todos
// Es importante especificar que pertenecen a la clase esperada, en este caso Enemy
int Enemy::GetHp() const
{
	// En el cuerpo o definici�n de la funci�n ahora s� se escribe la l�gica del m�todo
	return hp;
}

void Enemy::SetHp(int hp)
{
	if (hp < 0)
		return;

	this->hp = hp;
}

int Enemy::GetAttack() const
{
	return attack;
}

void Enemy::SetAttack(int attack)
{
	if (attack < 0)
		return;

	this->attack = attack;
}

int Enemy::GetDefense() const
{
	return defense;
}

void Enemy::SetDefense(int defense)
{
	if (defense < 0)
		return;

	this->defense = defense;
}

void Enemy::Attack()
{
	std::cout << "The Enemy " << name << " attacks with " << attack << " of power" << std::endl;
}