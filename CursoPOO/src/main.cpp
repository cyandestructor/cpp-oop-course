#include <iostream>
#include <string>

/*
* Abstracci�n:
* 
* El principio de abstracci�n en la Programaci�n Orientada a Objetos
* puede entenderse de dos manera
* 
* La primera es la abstracci�n de conceptos de la vida real, a datos que
* una computadora, a trav�s de la programaci�n, puede entender
* 
* Por ejemplo, un Enemigo, para un videojuego, tiene puntos de salud, estad�sticas de
* ataque y defensa, adem�s puede atacar y morir
* 
* Al convertir todas esas caracter�sticas y comportamientos en c�digo para
* un lenguaje de programaci�n, estamos abstrayendo el concepto de Enemigo
* a sus componentes m�s b�sicos, y utilizando s�lo los que son relevantes para
* nuestra aplicaci�n
* 
* La segunda forma de entender la abstracci�n es como una manera de
* simplificar un proceso complejo y resumirlo a una acci�n sencilla
* 
* Por ejemplo, al encender tu computadora, t� est�s haciendo algo tan
* sencillo como presionar el bot�n de encendido, pero no eres consciente
* (y puede que ni siquiera sea relevante para ti) del complejo proceso de fondo:
* consumir la energ�a, encender el procesador, iniciar el sistema operativo, etc�tera
*/

// Primera forma de abstracci�n: Reducimos un Enemigo a sus componentes y comportamientos b�sicos
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

	/*
	* Segunda forma de abstracci�n, reducimos un proceso complejo
	* como el ataque de un enemigo, que muestra animaciones, part�culas y afecta
	* las estad�sticas del enemigo, a una acci�n sencilla que es el m�todo Attack()
	*/
	void Attack()
	{
		std::cout << "The Enemy " << name << " attacks with " << attack << " of power" << std::endl;
		PlayAttackAnimation();
		DisplayAttackParticles();
		
		if (defense > 0)
			defense -= 1;
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
private:
	void PlayAttackAnimation()
	{
		std::cout << "Attack animation" << std::endl;
	}

	void DisplayAttackParticles()
	{
		std::cout << "Displaying particles" << std::endl;
	}
};

int main()
{
	Enemy enemigoA = Enemy(100, 20, 5, "Paul");

	std::cout << "El enemigo A tiene " << enemigoA.GetDefense() << " de defensa" << std::endl;

	// El complejo proceso del ataque se redujo a un simple m�todo que el usuario puede utilizar
	enemigoA.Attack();
	
	std::cout << "El enemigo A tiene " << enemigoA.GetDefense() << " de defensa" << std::endl;
}