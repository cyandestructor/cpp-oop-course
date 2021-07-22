#include <iostream>
#include <string>

/*
* Herencia:
* 
* El concepto de herencia en la Programación Orientada a Objetos se puede
* describir como la posibilidad de crear jerarquías de clases, donde
* existen clases base o super clases, y clases derivadas o sub clases
* 
* Las clases derivadas heredan, es decir, reciben los atributos y métodos
* de su clase base. Esta característica permite la reutilización de código
*/

class Enemy // Clase Base
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
		std::cout << "Constructor de Enemy" << std::endl;
	}

	Enemy(int hp, int attack, int defense, const std::string& name)
		: hp(hp), attack(attack), defense(defense), name(name)
	{
		std::cout << "Constructor de Enemy" << std::endl;
	}

	Enemy(int hp, int attack, int defense)
		: Enemy(hp, attack, defense, "Enemigo")
	{
		std::cout << "Constructor de Enemy" << std::endl;
	}

	int GetHp()
	{
		return hp;
	}
	
	void SetHp(int hp)
	{
		if (hp < 0)
			return;
		
		this->hp = hp;
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

// Skeleton es una clase derivada de Enemy
// La sintaxis de la herencia es C++ es la siguiente:
// class Derived : public Base
class Skeleton : public Enemy
{
private:
	// La clase derivada puede tener sus propios atributos y métodos
	int arrows;

public:

	Skeleton()
		:arrows(0)
	{
		std::cout << "Constructor de Skeleton" << std::endl;
	}
	
	// Una clase derivada puede acceder al constructor de su clase base
	// a través de una lista inicializadora y además inicializar sus propios atributos
	Skeleton(int hp, int attack, int defense)
		:Enemy(hp, attack, defense), arrows(0)
	{
		std::cout << "Constructor de Skeleton" << std::endl;
	}

	int GetArrows()
	{
		return arrows;
	}

	void SetArrows(int arrows)
	{
		this->arrows = arrows;
	}

	void Shoot()
	{
		if (arrows > 0)
		{
			std::cout << "El Esqueleto dispara una flecha" << std::endl;
			arrows--;
		}
		else
		{
			std::cout << "El Esqueleto no tiene flechas" << std::endl;
			
			// ERROR: Skeleton SÍ hereda el atributo hp de Enemy, pero éste es private
			// por lo tanto NO es accesible
			// this->hp = 5;
			
			// CORRECTO: Skeleton hereda los métodos de Enemy, y al ser SetHp público, es accesible
			// SetHp(5);
		}
	}
};

int main()
{
	// Nota lo que pasa cuando se instancia la clase Skeleton
	// El constructor de Enemy se ejecuta primero y luego
	// el constructor de Skeleton
	Skeleton* esqueletoA = new Skeleton();

	// Con un objeto de la clase Skeleton, podemos acceder a miembros
	// tanto de Skeleton como de su clase base Enemy
	esqueletoA->SetAttack(30);
	esqueletoA->SetArrows(20);

	esqueletoA->Attack();
	esqueletoA->Shoot();

	delete esqueletoA;
}