#include <iostream>
#include <string>

/*
* Amistad:
* 
* La amistad entre clases es un concepto que existe en C++
* 
* �sta consiste en que una clase le concede a otra la posibilidad
* de acceder a todos sus miembros, independientemente del modificador de acceso.
* Esta clase que obtiene acceso se vuelve amiga de la primera clase
* 
* La amistad es un concepto poco com�n, que si bien ayuda a resolver ciertos
* problemas, puede llegar a considerse que rompe algunos principios de la
* Programaci�n Orientada a Objetos, por lo que es recomendable usarla s�lo
* en casos muy espec�ficos
* 
* La amistad tiene las siguientes caracter�sticas:
* 
*	NO es rec�proca
*		Si una Clase A declara una Clase B como su amiga, A no es
*		necesariamente amiga de B
* 
*	NO es heredable
*		Si una Clase A declara una Clase B como su amiga, las clases
*		derivadas de A, no necesariamente tienen a B como su amiga
* 
*	NO se comparte
*		Si una Clase A declara una Clase B como su amiga, y una Clase C
*		declara B como su amiga, no existe ninguna relaci�n entre A y C
* 
* Una funci�n tambi�n puede ser amiga de una clase, y tiene el mismo efecto,
* esta funci�n podr� acceder a todos los miembros de esa clase
*/

class Soldier
{
	// Declaramos una clase Medic como amiga de Soldier, Medic puede acceder a Soldier pero no al rev�s
	friend class Medic;
	// Declaramos la funci�n ReviveSoldier como amiga de Soldier, ReviveSoldier puede acceder a Soldier
	friend void ReviveSoldier(Soldier& soldier, int hp);
public:
	Soldier(int hp)
		:hp(hp)
	{
	}

	int GetHp()
	{
		return hp;
	}

private:
	int hp;
};

class Medic
{
	// Medic es amiga de Soldier, pero Soldier no es amiga de Medic
public:
	void Heal(Soldier& soldier, int hp)
	{
		soldier.hp += hp; // Como Medic es amiga de Soldier, puede acceder a sus miembros privados
	}
};

void ReviveSoldier(Soldier& soldier, int hp)
{
	// Como ReviveSoldier es amiga de Soldier, puede acceder a sus miembros privados
	if (soldier.hp <= 0)
	{
		soldier.hp = hp;
	}
}

int main()
{
	Soldier soldado(5);
	Medic medico;

	std::cout << "La vida del soldado es " << soldado.GetHp() << std::endl;

	std::cout << "El medico cura al soldado 5 de HP" << std::endl;

	medico.Heal(soldado, 5);

	std::cout << "La vida del soldado es " << soldado.GetHp() << std::endl << std::endl;

	////////////////

	Soldier soldadoB(0);
	std::cout << "La vida del soldado B es " << soldadoB.GetHp() << std::endl;
	
	std::cout << "Reviviendo al soldado B con 10 Hp" << std::endl;
	ReviveSoldier(soldadoB, 10);

	std::cout << "La vida del soldado B es " << soldadoB.GetHp() << std::endl;
}

/*
* �Cu�ndo usar amistad?
* 
* Muchos cuestionan si es correcto o no utilizar la amistad.
* Fuera de cualquier discusi�n, lo cierto es que es una estrategia v�lida,
* aunque debe moderarse su utilizaci�n
* 
* Si se opta por utilizar amistad, es recomendable que se utilice s�lamente
* con clases estrechamente relacionadas. Tal vez, un sistema
* complejo es mejor dividirlo en algunas clases; sin embargo, formar�n parte
* de una unidad, y no son piezas independientes, pero al mismo tiempo
* se quiere aislar al sistema de lo que hay fuera de �l y sus clases.
* En estos casos es v�lido utilizar la amistad
*/
