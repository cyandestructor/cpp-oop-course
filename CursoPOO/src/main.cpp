#include <iostream>
#include <string>

/*
* Abstracción:
* 
* El principio de abstracción en la Programación Orientada a Objetos
* puede entenderse de dos manera
* 
* La primera es la abstracción de conceptos de la vida real, a datos que
* una computadora, a través de la programación, puede entender
* 
* Por ejemplo, un Enemigo, para un videojuego, tiene puntos de salud, estadísticas de
* ataque y defensa, además puede atacar y morir
* 
* Al convertir todas esas características y comportamientos en código para
* un lenguaje de programación, estamos abstrayendo el concepto de Enemigo
* a sus componentes más básicos, y utilizando sólo los que son relevantes para
* nuestra aplicación
* 
* La segunda forma de entender la abstracción es como una manera de
* simplificar un proceso complejo y resumirlo a una acción sencilla
* 
* Por ejemplo, al encender tu computadora, tú estás haciendo algo tan
* sencillo como presionar el botón de encendido, pero no eres consciente
* (y puede que ni siquiera sea relevante para ti) del complejo proceso de fondo:
* consumir la energía, encender el procesador, iniciar el sistema operativo, etcétera
*/

// Primera forma de abstracción: Reducimos un Enemigo a sus componentes y comportamientos básicos
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
	* Segunda forma de abstracción, reducimos un proceso complejo
	* como el ataque de un enemigo, que muestra animaciones, partículas y afecta
	* las estadísticas del enemigo, a una acción sencilla que es el método Attack()
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

	// El complejo proceso del ataque se redujo a un simple método que el usuario puede utilizar
	enemigoA.Attack();
	
	std::cout << "El enemigo A tiene " << enemigoA.GetDefense() << " de defensa" << std::endl;
}