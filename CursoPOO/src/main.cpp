#include <iostream>
#include <string>

/*
* Una forma más limpia y eficiente de inicializar los atributos
* de una clase es con una 'initializer list' o lista inicializadora
*/
class Enemy
{
public:
	int Hp;
	int AttackPower;
	int Defense;
	std::string Name;

	// Usamos una lista inicializadora para inicializar los atributos
	Enemy()
		: Hp(0), AttackPower(0), Defense(0), Name("Enemigo")
	{
		std::cout << "Ejecutando el constructor" << std::endl;

		// Ya no es necesario inicializarlos aquí
		/*Hp = 0;
		AttackPower = 0;
		Defense = 0;
		Name = "Enemigo";*/
	}

	// También se puede usar la lista inicializadora con los parámetros del constructor

	// Constructor A
	Enemy(int hp, int attack, int defense, const std::string& name)
		: Hp(hp), AttackPower(attack), Defense(defense), Name(name)
	{
		std::cout << "Ejecutando el constructor A" << std::endl;
	}

	// Además se puede llamar de un constructor a otro en la lista inicializadora

	// Constructor B
	Enemy(int hp, int attack, int defense)
		: Enemy(hp, attack, defense, "Enemigo")
	{
		std::cout << "Ejecutando el constructor B" << std::endl;
	}

	~Enemy()
	{
		std::cout << "Ejecutando el destructor" << std::endl;
	}

	void Attack()
	{
		std::cout << "The Enemy " << Name << " attacks with " << AttackPower << " of power" << std::endl;
	}

	void Die()
	{
		if (Hp <= 0)
		{
			std::cout << "The Enemy " << Name << " dies" << std::endl;
		}
		else
		{
			std::cout << "The Enemy " << Name << " has " << Hp << " HP" << std::endl;
		}
	}
};

int main()
{
	std::cout << "Enemigo A" << std::endl;
	{
		Enemy enemigoA = Enemy(100, 20, 5);

		enemigoA.Attack();
		enemigoA.Die();
	}

	std::cout << std::endl;
	std::cout << "Enemigo B" << std::endl;

	Enemy* enemigoB = new Enemy(0, 35, 10, "Paul");

	enemigoB->Attack();
	enemigoB->Die();

	delete enemigoB;
}