#include <iostream>
#include <string>

/*
* Los modificadores de acceso son importantes para proteger los datos
* de nuestros objetos
* 
* En C++ existen tres modificadores de acceso:
*	+ public
*	+ private
*	+ protected
* 
* Revisaremos el modificador de acceso protected m�s adelante, vamos a enfocarnos en
* los dos principales, public y private
*/
class Enemy
{
private:
	/*
	* El modificador de acceso private vuelve los miembros privados,
	* lo que significa que s�lo se puede acceder a ellos dentro del c�digo
	* de la clase, como en sus m�todos
	* 
	* Los miembros private NO pueden ser accedidos a trav�s de un
	* objeto o instancia
	*/
	int Hp;
	int AttackPower;
	int Defense;
	std::string Name;
public:
	/*
	* El modificador de acceso public vuelve los miembros p�blicos,
	* lo que significa que se puede acceder a ellos desde dentro del
	* c�digo de la clase, o desde afuera a trav�s de una instancia
	* u objeto
	*/
	Enemy()
		: Hp(0), AttackPower(0), Defense(0), Name("Enemigo")
	{
		std::cout << "Ejecutando el constructor" << std::endl;
	}

	Enemy(int hp, int attack, int defense, const std::string& name)
		: Hp(hp), AttackPower(attack), Defense(defense), Name(name)
	{
		std::cout << "Ejecutando el constructor A" << std::endl;
	}

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
	Enemy enemigoA = Enemy(100, 20, 5);

	// Name es private, por lo que no se puede acceder a �l a trav�s de la instancia
	// enemigoA.Name = "Mike";

	// Attack() y Die() son miembros p�blicos, por lo que podemos acceder a ellos a trav�s del objeto
	enemigoA.Attack();
	enemigoA.Die();
}

// TABLA DE ACCESO

/*
* MODIFICADOR DE ACCESO	|	ACCESIBLE DESDE...		|
* ----------------------+---------------------------+
*						|	CLASE	|	INSTANCIA	|
* ----------------------+-----------+---------------+
* public				|	O		|	O			|
* private				|	O		|				|
*/