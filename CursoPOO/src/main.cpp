#include <iostream>
#include <string>

/*
* Polimorfismo:
* 
* El �ltimo principio de la Programaci�n Orientada a Objetos es
* el Polimorfismo
* 
* La ra�z etimol�gica de Polimorfismo es la siguiente:
* Poli - m�ltiple
* Morfismo - forma
* Es decir, m�ltiples formas
* 
* El polimorfismo se refiere a que un objeto de una clase derivada
* puede ser usado de otra forma como un objeto de alguna de las clases
* que est�n por encima suyo en la jerarqu�a de clases
* 
* Para lograr que esto funcione, es clave entender el principio
* de herencia que ya hemos visto anteriormente
* 
* Para alcanzar el m�ximo potencial del polimorfismo, utilizamos
* m�todos virtuales y la sobreescritura de m�todos
* 
* Sobreescribir un m�todo es la acci�n de crear un m�todo en una
* clase derivada que tenga el mismo nombre, tipo de retorno y
* par�metros, que otro m�todo de su clase base
* 
* Con el polimorfismo, un m�todo de una clase base puede
* tener una diferente implementaci�n si una clase derivada
* lo sobreescribe
* 
* B�sicamente, si un m�todo es virtual y es sobreescrito,
* se ejecutar� la sobreescritura por encima del m�todo original,
* si no hubiera una sobreescritura, se ejecutar�a el m�todo original
*/

/*
* Destructores virtuales:
* 
* Los destructores virtuales son muy importantes para
* implementar correctamente el polimorfismo
* 
* Cuando tratamos un objeto de una clase derivada, como
* uno de su clase base (polimorfismo), si �ste objeto se destruye,
* por defecto �nicamente se destruye la parte que corresponde
* a la clase base, por lo que no se libera la memoria
* reservada para la parte de la clase derivada
* 
* Lo anterior puede causar 'memory leaks' o fugas de memoria
* en nuestro programa, es decir, cuando una memoria que
* reservamos no es propiamente liberada
* 
* Al hacer el destructor de la clase base un destructor virtual,
* ahora cuando un objeto se destruya de manera polim�rfica,
* la memoria se liberara correctamente, ejecutando adem�s
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

	// Los m�todos que queramos que una clase derivada pueda sobreescribir
	// deben ser definidos con la palabra reservada 'virtual'
	virtual void Attack()
	{
		// Si una clase derivada ejecuta de manera polim�rfica este m�todo
		// Ejecutar� el original si la clase no lo sobreescribi� o
		// Ejecutar� la sobreescritura
		std::cout << "The Enemy " << name << " attacks with " << attack << " of power" << std::endl;
	}

	// Intercambia ambas versiones del m�todo para ver el comportamiento de un caso frente a otro
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

	// Estamos sobreescribiendo el m�todo Attack() de Enemy para que tenga una diferente implementaci�n
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

	// Otra forma de sobreescribir un m�todo es la siguiente:
	// 
	// Con la palabra reservada 'virtual', que s�lo es un indicador, pues de cualquier forma se vuelve
	// un m�todo virtual por defecto

	// Con la palabra resevada 'override', que de nuevo es s�lo un indicador, pues es opcional
	// 'override' es �til, pues marca un error de compilaci�n si queremos sobreescribir un m�todo
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
	// tambi�n puede hacer referencia a un objeto de una clase derivada
	Enemy* enemigos[2];
	enemigos[0] = momia;
	enemigos[1] = esqueleto;

	for (int i = 0; i < 2; i++)
	{
		// Estamos ejecutando el m�todo Attack() de manera polim�rfica
		// Si una clase derivada sobreescribi� el m�todo virtual Attack(),
		// ejecutar� esa versi�n, en cambio, ejecutar� el m�todo original
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
