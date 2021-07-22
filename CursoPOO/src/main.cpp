#include <iostream>
#include <string>

/*
* Las clases tienen un método que se ejecuta cuando se crea la instancia, llamado 'constructor'
* También tienen un método que se ejecuta antes de que se destruya la instancia, llamado 'destructor'
* 
* El constructor tiene las siguientes reglas:
*	+ No retorna un valor
*	+ Tiene el mismo nombre que la clase
*	+ Una clase puede tener varios constructores
* 
* El destructor tiene las siguientes reglas:
*	+ No retorna un valor
*	+ No tiene parámetros
*	+ Tiene el mismo nombre que la clase, precedido por una '~'
*	+ Una clase sólo puede tener un destructor
* 
* Si no definimos un constructor o un destructor, por defecto
* existe un constructor y destructor ocultos.
* 
* El constructor por defecto no tiene parámetros
* 
* Si definimos un constructor, el constructor por defecto desaparece,
* por lo que si queremos un constructor sin parámetros, también debemos
* definirlo
*/
class Enemy
{
public:
	int Hp;
	int AttackPower;
	int Defense;
	std::string Name;

	// Definimos un constructor con parámetros
	Enemy(int hp, int attack, int defense)
	{
		std::cout << "Ejecutando el constructor" << std::endl;
		
		Hp = hp;
		AttackPower = attack;
		Defense = defense;
		Name = "Enemigo";
	}
	
	// Puedo tener múltiples constructores
	Enemy(int hp, int attack, int defense, const std::string& name)
	{
		std::cout << "Ejecutando el constructor" << std::endl;

		Hp = hp;
		AttackPower = attack;
		Defense = defense;
		Name = name;
	}

	// Si aún queremos tener un constructor con parámetros, debemos definirlo tambien
	Enemy()
	{
		std::cout << "Ejecutando el constructor" << std::endl;

		Hp = 0;
		AttackPower = 0;
		Defense = 0;
		Name = "Enemigo";
	}

	// Defino un constructor personalizado
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
	// Instanciamos un enemigo usando un constructor con parámetros
	{
		Enemy enemigoA = Enemy(100, 20, 5);

		enemigoA.Attack();
		enemigoA.Die();
	} // Como enemigoA existe en este scope, al terminarse, se destruye y ejecuta el destructor

	std::cout << std::endl;
	std::cout << "Enemigo B" << std::endl;

	Enemy* enemigoB = new Enemy(0, 35, 10, "Paul");
	
	enemigoB->Attack();
	enemigoB->Die();

	delete enemigoB; // Al liberar la memoria, se ejecuta el destructor para enemigoB
	
	Enemy* enemigoC; // Como no es instancia, no se ejecuta el constructor
}