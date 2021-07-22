#include <iostream>
#include <string>

/*
* Modificador de acceso 'protected':
* 
* Ya hemos visto los modificadores de acceso 'private' y 'public',
* el tercer modificador de acceso en C++ es 'protected'
* 
* Los miembros protegidos de una clase no son accesibles a través de una instancia,
* fuera del código de la clase, pero sí son accesibles para sus clases derivadas
*/

class Enemy
{
protected: // Al cambiar el modificador de acceso, las clases derivadas tienen acceso a estos miembros
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

class Mummy : public Enemy
{
private:
	int mana;

public:
	Mummy()
		:mana(0)
	{
	}

	Mummy(int hp, int attack, int defense)
		:Enemy(hp, attack, defense), mana(0)
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

	/*
	* Supongamos que una momia tiene el poder de recuperar vida
	* a cambio de maná
	* 
	* Al ser Mummy una clase derivada de Enemy, y al ser hp un
	* atributo protegido (protected) de Enemy, Mummy puede acceder
	* a este atributo
	*/
	void Heal()
	{
		if (mana > 0)
		{
			mana--;
			hp++; // Accesible por ser atributo protegido de Enemy
		}
	}
};

int main()
{
	Mummy* mummy = new Mummy();

	// ERROR: hp es un miembro protegido de Enemy, por lo tanto es accesible dentro de Mummy
	// pero no fuera de esa clase por medio de una instancia
	// mummy->hp = 30;
	mummy->SetHp(30);
	mummy->SetMana(5);

	std::cout << "La momia tiene " << mummy->GetHp() << " de HP" << std::endl;
	std::cout << "La momia tiene " << mummy->GetMana() << " de Mana" << std::endl;
	
	std::cout << "Curando..." << std::endl;
	mummy->Heal();

	std::cout << "La momia tiene " << mummy->GetHp() << " de HP" << std::endl;
	std::cout << "La momia tiene " << mummy->GetMana() << " de Mana" << std::endl;

	delete mummy;
}

// TABLA DE ACCESO

/*
* MODIFICADOR DE ACCESO	|			ACCESIBLE DESDE...				|
* ----------------------+-------------------------------------------+
*						|	CLASE	|	HERENCIA	|	INSTANCIA	|
* ----------------------+-----------+---------------+---------------+
* public				|	O		|	O			|	O			|
* ----------------------+-----------+---------------+---------------+
* protected				|	O		|	O			|				|
* ----------------------+-----------+---------------+---------------+
* private				|	O		|				|				|
* ----------------------+-----------+---------------+---------------+
*/