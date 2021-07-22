#include <iostream>
#include <string>

/*
* Los miembros est�ticos de una clase, a diferencia de los miembros normales,
* no est�n ligados a una instancia, sino a la clase en s�
* 
* Al estar ligados a la clase y no a una instancia, acceder a los miembros
* est�ticos no requiere un objeto, se accede a ellos directamente a trav�s de la clase
* 
* Adem�s, si un m�todo de una instancia afecta un atributo est�tico, este cambio
* se ver� reflejado para todas las instancias
* 
* Al no depender de una instancia, los m�todos est�ticos de una clase no pueden
* acceder a los miembros no est�ticos, ya sean atributos o m�todos
*/
class Enemy
{
private:
	// Los miembros est�ticos tambi�n son afectados por los modificadores de acceso
	// Para declarar un miembro est�tico se utiliza la palabra reservada 'static'
	static int Count;

	int hp;
	int attack;
	int defense;
	std::string name;
public:
	// Supongamos que queremos tener un contador del total de enemigos creados
	Enemy()
		: hp(0), attack(0), defense(0), name("Enemigo")
	{
		Count++; // Los miembros no est�ticos S� pueden acceder a los miembros est�ticos
	}

	Enemy(int hp, int attack, int defense, const std::string& name)
		: hp(hp), attack(attack), defense(defense), name(name)
	{
		Count++;
	}

	Enemy(int hp, int attack, int defense)
		: Enemy(hp, attack, defense, "Enemigo")
	{
	}

	~Enemy()
	{
		Count--;
	}

	// Los m�todos est�ticos tambi�n utilizan la palabra reservada 'static'
	static int GetTotalEnemies()
	{
		// ERROR: No se puede acceder a miembros no est�ticos desde un m�todo est�tico
		// defense = 30;
		// int hp = GetHp();
		return Count; // Los m�todos est�ticos pueden acceder a los atributos est�ticos
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

// Los atributos est�ticos deben inicializarse fuera del cuerpo de la clase
int Enemy::Count = 0;

int main()
{
	// Para acceder a los miembros est�ticos se utiliza la clase en s� (Enemy), y el operador '::'
	std::cout << "Hay un total de " << Enemy::GetTotalEnemies() << " enemigos" << std::endl;

	Enemy enemigoA = Enemy(100, 20, 5);
	Enemy enemigoB = Enemy(100, 20, 5);
	
	// ERROR: Count es un atributo est�tico pero es privado tambi�n
	// std::cout << "Hay un total de " << Enemy::Count << " enemigos" << std::endl;
	std::cout << "Hay un total de " << Enemy::GetTotalEnemies() << " enemigos" << std::endl;

	{
		Enemy enemigoC = Enemy(100, 20, 5);
		Enemy enemigoD = Enemy(100, 20, 5);
		std::cout << "Hay un total de " << Enemy::GetTotalEnemies() << " enemigos" << std::endl;
	}
	
	std::cout << "Hay un total de " << Enemy::GetTotalEnemies() << " enemigos" << std::endl;
}