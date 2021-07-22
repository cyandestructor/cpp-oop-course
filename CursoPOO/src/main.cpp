#include <iostream>
#include <string>

/*
* En C++, la palabra reservada 'this', puede utilizarse dentro
* de una clase y es un miembro privado y oculto que viene por
* defecto con todas la clases
*
* Se trata de un puntero que hace referencia a la dirección de
* memoria de la instancia actual
*/
class Enemy
{
private:
	int hp;
	int attack;
	int defense;
	std::string name;
public:
	Enemy()
		: hp(0), attack(0), defense(0), name("Enemigo")
	{
	}

	Enemy(int hp, int attack, int defense, const std::string& name)
		: hp(hp), attack(attack), defense(defense), name(name)
	{
	}

	Enemy(int hp, int attack, int defense)
		: Enemy(hp, attack, defense, "Enemigo")
	{
	}

	int GetHp()
	{
		return hp;
	}
	
	void SetHp(int hp)
	{
		if (hp < 0)
			return;
		
		// 'this' nos puede ser útil para distinguir entre los parámetros y los atributos de la clase
		// hp = hp; // CONFUSIÓN! ¿Qué está pasando?
		this->hp = hp; // Ya no hay confusión, pues el 'this' se refiere a la instancia actual
	}

	int GetAttack()
	{
		return attack;
	}

	void SetAttack(int attack)
	{
		if (attack < 0)
			return;
		
		this->attack = attack;
	}

	int GetDefense()
	{
		return defense;
	}

	void SetDefense(int defense)
	{
		if (defense < 0)
			return;

		this->defense = defense;
	}

	void Attack()
	{
		std::cout << "The Enemy " << name << " attacks with " << attack << " of power" << std::endl;
	}

	void Die()
	{
		if (hp <= 0)
		{
			std::cout << "The Enemy " << name << " dies" << std::endl;
		}
		else
		{
			std::cout << "The Enemy " << name << " has " << hp << " HP" << std::endl;
		}
	}
};

int main()
{
	Enemy enemigoA = Enemy(100, 20, 5, "Paul");

	enemigoA.Attack();
	enemigoA.Die();
	
	enemigoA.SetAttack(100);
	enemigoA.SetDefense(-5);
	enemigoA.SetHp(0);

	std::cout << "El enemigo A tiene " << enemigoA.GetDefense() << " de defensa" << std::endl;

	enemigoA.Attack();
	enemigoA.Die();
}