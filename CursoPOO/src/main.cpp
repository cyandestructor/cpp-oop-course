#include <iostream>
#include <string>

/*
* Polimorfismo:
* 
* El último principio de la Programación Orientada a Objetos es
* el Polimorfismo
* 
* La raíz etimológica de Polimorfismo es la siguiente:
* Poli - múltiple
* Morfismo - forma
* Es decir, múltiples formas
* 
* El polimorfismo se refiere a que un objeto de una clase derivada
* puede ser usado de otra forma como un objeto de alguna de las clases
* que están por encima suyo en la jerarquía de clases
* 
* Para lograr que esto funcione, es clave entender el principio
* de herencia que ya hemos visto anteriormente
* 
* Para alcanzar el máximo potencial del polimorfismo, utilizamos
* métodos virtuales y la sobreescritura de métodos
* 
* Sobreescribir un método es la acción de crear un método en una
* clase derivada que tenga el mismo nombre, tipo de retorno y
* parámetros, que otro método de su clase base
* 
* Con el polimorfismo, un método de una clase base puede
* tener una diferente implementación si una clase derivada
* lo sobreescribe
* 
* Básicamente, si un método es virtual y es sobreescrito,
* se ejecutará la sobreescritura por encima del método original,
* si no hubiera una sobreescritura, se ejecutaría el método original
*/

/*
* Destructores virtuales:
* 
* Los destructores virtuales son muy importantes para
* implementar correctamente el polimorfismo
* 
* Cuando tratamos un objeto de una clase derivada, como
* uno de su clase base (polimorfismo), si éste objeto se destruye,
* por defecto únicamente se destruye la parte que corresponde
* a la clase base, por lo que no se libera la memoria
* reservada para la parte de la clase derivada
* 
* Lo anterior puede causar 'memory leaks' o fugas de memoria
* en nuestro programa, es decir, cuando una memoria que
* reservamos no es propiamente liberada
* 
* Al hacer el destructor de la clase base un destructor virtual,
* ahora cuando un objeto se destruya de manera polimórfica,
* la memoria se liberara correctamente, ejecutando además
* del destructor base, el destructor derivado
*/

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

	// Para hacer un destructor virtual, simplemente usamos la palabra reservada 'virtual'
	virtual ~Enemy()
	{
		std::cout << "Destructor de Enemy" << std::endl;
	}

	// Intercambia ambas versiones del destructor para ver el comportamiento de un caso frente a otro
	/*~Enemy()
	{
		std::cout << "Destructor de Enemy" << std::endl;
	}*/

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

	// Los métodos que queramos que una clase derivada pueda sobreescribir
	// deben ser definidos con la palabra reservada 'virtual'
	virtual void Attack()
	{
		// Si una clase derivada ejecuta de manera polimórfica este método
		// Ejecutará el original si la clase no lo sobreescribió o
		// Ejecutará la sobreescritura
		std::cout << "The Enemy " << name << " attacks with " << attack << " of power" << std::endl;
	}

	// Intercambia ambas versiones del método para ver el comportamiento de un caso frente a otro
	/*void Attack()
	{
		std::cout << "The Enemy " << name << " attacks with " << attack << " of power" << std::endl;
	}*/
};

class Skeleton : public Enemy
{
private:
	int arrows;

public:
	Skeleton()
		:arrows(0)
	{
		std::cout << "Constructor de Skeleton" << std::endl;
	}

	Skeleton(int hp, int attack, int defense, const std::string& name)
		:Enemy(hp, attack, defense, name), arrows(0)
	{
		std::cout << "Constructor de Skeleton" << std::endl;
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

	// Estamos sobreescribiendo el método Attack() de Enemy para que tenga una diferente implementación
	void Attack()
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
		std::cout << "Constructor de Mummy" << std::endl;
	}

	Mummy(int hp, int attack, int defense, const std::string& name)
		:Enemy(hp, attack, defense, name), mana(0)
	{
		std::cout << "Constructor de Mummy" << std::endl;
	}

	~Mummy()
	{
		std::cout << "Destructor de Mummy" << std::endl;
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

	// Otra forma de sobreescribir un método es la siguiente:
	// 
	// Con la palabra reservada 'virtual', que sólo es un indicador, pues de cualquier forma se vuelve
	// un método virtual por defecto

	// Con la palabra resevada 'override', que de nuevo es sólo un indicador, pues es opcional
	// 'override' es útil, pues marca un error de compilación si queremos sobreescribir un método
	// que de principio no es virtual o no pertenece a la clase base
	virtual void Attack() override
	{
		if (mana > 0) {
			std::cout << "The Mummy " << name << " fires magic with " << attack << " of power" << std::endl;
			mana--;
		}
	}
};

void EjemploDestructores()
{
	std::cout << "Constructor:" << std::endl;
	// Observa el orden en que se ejecutan el constructor de la clase base y la derivada
	Enemy* momia = new Mummy(100, 40, 20, "Momia");
	// Observa el orden en que se ejecutan el destructor de la clase base y la derivada
	std::cout << std::endl << "Destructor:" << std::endl;
	delete momia;
}

void EjemploPolimorfismo()
{
	// *** Creamos "referencias" a instancias de una clase derivada
	Mummy* momia = new Mummy(100, 40, 20, "Momia");
	momia->SetMana(5);

	Skeleton* esqueleto = new Skeleton(100, 20, 5, "Esqueleto");
	esqueleto->SetArrows(50);
	// ***

	// Podemos ver que una "referencia" a una instancia de una clase base,
	// también puede hacer referencia a un objeto de una clase derivada
	Enemy* enemigos[2];
	enemigos[0] = momia;
	enemigos[1] = esqueleto;

	for (int i = 0; i < 2; i++)
	{
		// Estamos ejecutando el método Attack() de manera polimórfica
		// Si una clase derivada sobreescribió el método virtual Attack(),
		// ejecutará esa versión, en cambio, ejecutará el método original
		enemigos[i]->Attack();
	}

	delete momia;
	delete esqueleto;
}

int main()
{
	EjemploDestructores();
	// EjemploPolimorfismo();
}
