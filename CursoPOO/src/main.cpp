#include <iostream>
#include <string>

/*
* Los miembros estáticos de una clase, a diferencia de los miembros normales,
* no están ligados a una instancia, sino a la clase en sí
* 
* Al estar ligados a la clase y no a una instancia, acceder a los miembros
* estáticos no requiere un objeto, se accede a ellos directamente a través de la clase
* 
* Además, si un método de una instancia afecta un atributo estático, este cambio
* se verá reflejado para todas las instancias
* 
* Al no depender de una instancia, los métodos estáticos de una clase no pueden
* acceder a los miembros no estáticos, ya sean atributos o métodos
*/
class Enemy
{
private:
	// Los miembros estáticos también son afectados por los modificadores de acceso
	// Para declarar un miembro estático se utiliza la palabra reservada 'static'
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
		Count++; // Los miembros no estáticos SÍ pueden acceder a los miembros estáticos
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

	// Los métodos estáticos también utilizan la palabra reservada 'static'
	static int GetTotalEnemies()
	{
		// ERROR: No se puede acceder a miembros no estáticos desde un método estático
		// defense = 30;
		// int hp = GetHp();
		return Count; // Los métodos estáticos pueden acceder a los atributos estáticos
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

// Los atributos estáticos deben inicializarse fuera del cuerpo de la clase
int Enemy::Count = 0;

int main()
{
	// Para acceder a los miembros estáticos se utiliza la clase en sí (Enemy), y el operador '::'
	std::cout << "Hay un total de " << Enemy::GetTotalEnemies() << " enemigos" << std::endl;

	Enemy enemigoA = Enemy(100, 20, 5);
	Enemy enemigoB = Enemy(100, 20, 5);
	
	// ERROR: Count es un atributo estático pero es privado también
	// std::cout << "Hay un total de " << Enemy::Count << " enemigos" << std::endl;
	std::cout << "Hay un total de " << Enemy::GetTotalEnemies() << " enemigos" << std::endl;

	{
		Enemy enemigoC = Enemy(100, 20, 5);
		Enemy enemigoD = Enemy(100, 20, 5);
		std::cout << "Hay un total de " << Enemy::GetTotalEnemies() << " enemigos" << std::endl;
	}
	
	std::cout << "Hay un total de " << Enemy::GetTotalEnemies() << " enemigos" << std::endl;
}