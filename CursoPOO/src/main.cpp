#include <iostream>

/*
* La clase es la unidad de c�digo de la programaci�n orientada a objetos
* 
* Para declarar una clase en C++ usamos la palabra reservada 'class'
* 
* Los miembros de una clase son todos los datos y funciones dentro del cuerpo de la clase
* 
* A diferencia de las estructuras, los miembros de una clase en C++ son privados
* por defecto, eso quiere decir que no son accesibles a menos que se declaren
* como p�blicos (M�s adelante entraremos con m�s detalle en los modificadores de acceso)
*/
class Enemy
{
public: // Modificador de acceso p�blico, necesario para acceder a los miembros de la clase

	// *** Miembros de la clase
	
	// Atributos
	int Hp;
	int AttackPower;
	int Defense;

	// M�todos
	void Attack()
	{
		// Desde los m�todos podemos acceder a los atributos de la clase
		std::cout << "The Enemy attacks with " << AttackPower << " of power" << std::endl;
	}

	void Die()
	{
		if (Hp <= 0)
		{
			std::cout << "The Enemy dies" << std::endl;
		}
		else
		{
			std::cout << "The Enemy has " << Hp << " HP" << std::endl;
		}
	}
	// ***
};

int main()
{
	// La clase s�lo es una plantilla que podemos usar para crear objetos
	// La clase se utiliza como si fuera un tipo de dato
	
	// Aqu� estamos instanciando la clase, lo que crea una instancia u objeto
	// enemigoA es un objeto de la clase Enemy
	Enemy enemigoA;

	// Otra forma de instanciar es en el Heap con el operador new
	// enemigoB es un objeto de la clase Enemy
	Enemy* enemigoB = new Enemy();

	// Una instancia s�lo ocurre cuando se est� reservando memoria para el objeto
	// enemigoC NO es un objeto de la clase Enemy porque no se reserva memoria
	Enemy* enemigoC;

	// Podemos acceder a los miembros de un objeto a trav�s de la notaci�n de punto o flecha

	std::cout << "Enemigo A" << std::endl;
	// Notaci�n de punto
	enemigoA.Hp = 100;
	enemigoA.AttackPower = 20;
	enemigoA.Attack();
	enemigoA.Die();

	std::cout << std::endl;
	std::cout << "Enemigo B" << std::endl;
	// Notaci�n de flecha
	enemigoB->Hp = 0;
	enemigoB->AttackPower = 35;
	enemigoB->Attack();
	enemigoB->Die();

	// Error: enemigoC no es una instancia y por lo tanto no tiene memoria reservada
	// enemigoC->Hp = 5;

	/*
	* Nota que, aunque enemigoA y enemigoB sean de la misma clase
	* y compartan atributos, los valores de esos atributos
	* son �nicos para cada objeto
	* 
	* Si modifico el Hp de enemigoA, no afecta al Hp de enemigoB
	*/

	delete enemigoB; // Recuerda que es necesario liberar la memoria
}