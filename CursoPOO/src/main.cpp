#include <iostream>
#include <string>

/*
* Métodos constantes y atributos 'mutable':
* 
* Los métodos constantes son métodos que se pueden utilizar
* a través de un objeto o instancia constante de la clase,
* por lo tanto, pueden leer los atributos y ejecutar
* otros métodos constantes, pero no pueden modificar esos
* atributos, ni ejecutar métodos no constantes
* 
* Es recomendable siempre tener en cuenta qué métodos no
* alteran los datos de la instancia y marcarlos como constantes
* 
* Ahora bien, hay casos en los que en un método constante,
* se necesita modificar un valor que está dentro de la clase,
* pero que no necesariamente está relacionada a la instancia
* 
* Por ejemplo, para un debug, tal vez queremos tener
* una cuenta de cuántas veces se ejecutó determinado método
* que puede ser constante
* 
* En estos casos es conveniente declarar los atributos
* que se podrán modificar como 'mutable' es decir, como
* modificables. De esta forma se permitirá modificarlos
* en métodos constantes
*/

class Monster
{
public:
	Monster(int hp)
		:hp(hp), hpCounter(0) {}

	Monster()
		:Monster(0) {}

	void SetHp(int hp)
	{
		if (hp < 0)
			return;

		this->hp = hp;
	}

	// Para declarar un método como constante, usamos la palabra
	// reservada 'const' después de la declaración del método y antes del cuerpo
	int GetHp() const
	{
		// ERROR:
		// GetHp() es un método constante, por lo tanto no puede modificar los atributos
		// hp = 5;

		// Si queremos que modifique el valor de hpCounter, debemos declararlo como 'mutable'
		hpCounter++;
		return hp;
	}

	int GetHpCounter() const
	{
		return hpCounter;
	}

private:
	int hp;
	// Con la palabra reservada 'mutable' declaramos un atributo como modificable o mutable
	mutable int hpCounter;

	// Intercambia la declaración del atributo para ver la diferencia
	// int hpCounter;
};

int main()
{
	// Creamos una instancia constante de la clase Monster con la palabra reservada 'const'
	const Monster monster(50);

	// ERROR: A través de una instancia constante, no podemos acceder a métodos no constantes
	// monster.SetHp(60);

	// GetHP() es un método constante, por lo que se puede usar a través de una instancia constante
	std::cout << "El monstruo tiene " << monster.GetHp() << " de Hp" << std::endl;
	std::cout << "El monstruo tiene " << monster.GetHp() << " de Hp" << std::endl;
	std::cout << "El monstruo tiene " << monster.GetHp() << " de Hp" << std::endl;
	std::cout << "El monstruo tiene " << monster.GetHp() << " de Hp" << std::endl << std::endl;

	std::cout << "Se llamo el metodo GetHp() " << monster.GetHpCounter() << " veces" << std::endl;
}
