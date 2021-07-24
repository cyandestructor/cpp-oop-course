#include <iostream>
#include <string>

/*
* M�todos constantes y atributos 'mutable':
* 
* Los m�todos constantes son m�todos que se pueden utilizar
* a trav�s de un objeto o instancia constante de la clase,
* por lo tanto, pueden leer los atributos y ejecutar
* otros m�todos constantes, pero no pueden modificar esos
* atributos, ni ejecutar m�todos no constantes
* 
* Es recomendable siempre tener en cuenta qu� m�todos no
* alteran los datos de la instancia y marcarlos como constantes
* 
* Ahora bien, hay casos en los que en un m�todo constante,
* se necesita modificar un valor que est� dentro de la clase,
* pero que no necesariamente est� relacionada a la instancia
* 
* Por ejemplo, para un debug, tal vez queremos tener
* una cuenta de cu�ntas veces se ejecut� determinado m�todo
* que puede ser constante
* 
* En estos casos es conveniente declarar los atributos
* que se podr�n modificar como 'mutable' es decir, como
* modificables. De esta forma se permitir� modificarlos
* en m�todos constantes
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

	// Para declarar un m�todo como constante, usamos la palabra
	// reservada 'const' despu�s de la declaraci�n del m�todo y antes del cuerpo
	int GetHp() const
	{
		// ERROR:
		// GetHp() es un m�todo constante, por lo tanto no puede modificar los atributos
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

	// Intercambia la declaraci�n del atributo para ver la diferencia
	// int hpCounter;
};

int main()
{
	// Creamos una instancia constante de la clase Monster con la palabra reservada 'const'
	const Monster monster(50);

	// ERROR: A trav�s de una instancia constante, no podemos acceder a m�todos no constantes
	// monster.SetHp(60);

	// GetHP() es un m�todo constante, por lo que se puede usar a trav�s de una instancia constante
	std::cout << "El monstruo tiene " << monster.GetHp() << " de Hp" << std::endl;
	std::cout << "El monstruo tiene " << monster.GetHp() << " de Hp" << std::endl;
	std::cout << "El monstruo tiene " << monster.GetHp() << " de Hp" << std::endl;
	std::cout << "El monstruo tiene " << monster.GetHp() << " de Hp" << std::endl << std::endl;

	std::cout << "Se llamo el metodo GetHp() " << monster.GetHpCounter() << " veces" << std::endl;
}
