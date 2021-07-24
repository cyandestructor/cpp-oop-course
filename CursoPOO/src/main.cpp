#include <iostream>
#include <string>

/*
* M�todos virtuales puros y Clases Abstractas:
* 
* Volvamos al ejemplo de los Enemigos, el Esqueleto y la Momia
* 
* Queremos tener Esqueletos y Momias, y que ambos puedan ser
* tratados como un Enemigo (polimorfismo). Por eso, Skeleton y Mummy
* son clases derivadas de Enemy
* 
* Sin embargo, no tiene sentido poder crear instancias de un Enemy, porque,
* �qu� es un Enemy? �C�mo se ve? �C�mo deber�a atacar?
* 
* A diferencia de Skeleton o Mummy, Enemy es un concepto abstracto. Queremos
* que clases puedan heredar atributos y comportamientos de Enemy, pero no
* queremos que existan objetos de Enemy como tal, pues no tiene sentido. Ah�
* es donde entran las clases abstractas
* 
* Para entender las clases abstractas tenemos que saber qu� es un m�todo virtual puro
* 
* Un m�todo virtual puro es un m�todo como cualquier otro, pero que no tiene un cuerpo,
* es decir, no se implementa. Es reponsabilidad de las clases derivadas implementar y darle
* un cuerpo a los m�todos virtuales puros que heredan
* 
* Es as� que una clase abstracta es una clase que tiene al menos un m�todo virtual puro.
* El efecto de esto es que no se puede instanciar una clase abstracta por s� misma, s�lo alguna
* clase derivada si es que implementa todos los m�todos virtuales puros de su base
* 
* Finalmente, es importante decir que, si una clase derivada no implementa alguno de
* los m�todos virtuales puros de su base, �sta clase derivada tambi�n ser� una clase abstracta
*/

// Vamos a convertir Enemy en una clase abstracta
class Enemy
{
protected:
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

	virtual ~Enemy()
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

	// Para declarar un m�todo virtual puro, usamos la palabra derivada 'virtual'
	// y adem�s, en vez de su cuerpo, escribimos '= 0;'
	virtual void Attack() = 0;
};

class Skeleton : public Enemy
{
private:
	int arrows;

public:
	Skeleton()
		:arrows(0)
	{
	}

	Skeleton(int hp, int attack, int defense, const std::string& name)
		:Enemy(hp, attack, defense, name), arrows(0)
	{
	}

	int GetArrows()
	{
		return arrows;
	}

	void SetArrows(int arrows)
	{
		if (arrows < 0)
			return;

		this->arrows = arrows;
	}

	// Implementamos el m�todo virtual puro Attack(), de lo contrario
	// Skeleton seguir� siendo una clase abstracta
	virtual void Attack() override
	{
		if (arrows > 0) {
			std::cout << "The Skeleton " << name << " shoots with " << attack << " of power" << std::endl;
			arrows--;
		}
	}
};

class Mummy : public Enemy
{
private:
	int mana;

public:
	Mummy()
		:mana(0)
	{
	}

	Mummy(int hp, int attack, int defense, const std::string& name)
		:Enemy(hp, attack, defense, name), mana(0)
	{
	}

	int GetMana()
	{
		return mana;
	}

	void SetMana(int mana)
	{
		if (mana < 0)
			return;

		this->mana = mana;
	}

	// Implementamos el m�todo virtual puro Attack(), de lo contrario
	// Mummy seguir� siendo una clase abstracta
	virtual void Attack() override
	{
		if (mana > 0) {
			std::cout << "The Mummy " << name << " fires magic with " << attack << " of power" << std::endl;
			mana--;
		}
	}
};

int main()
{
	// ERROR: No se puede instanciar una clase abstracta
	// Enemy* enemigo = new Enemy();

	// *** Ejemplo que ya vimos del polimorfismo
	Mummy* momia = new Mummy(100, 40, 20, "Momia");
	momia->SetMana(5);

	Skeleton* esqueleto = new Skeleton(100, 20, 5, "Esqueleto");
	esqueleto->SetArrows(50);

	Enemy* enemigos[2];
	enemigos[0] = momia;
	enemigos[1] = esqueleto;

	for (int i = 0; i < 2; i++)
	{
		enemigos[i]->Attack();
	}

	delete momia;
	delete esqueleto;
	// ***
}
