#include <iostream>
#include <string>

/*
* Interfaces:
* 
* Las interfaces son casos especiales de clases. En algunos lenguajes
* de programaci�n, incluso son considerados conceptos distintos
* 
* En C++, las interfaces son clases que �nicamente tienen m�todos
* virtuales puros y p�blicos
* 
* Si bien, en cuesti�n de sintaxis, una clase hereda de una interfaz
* como cualquier otra clase, el t�rmino correcto es 'implementar'. Una
* clase implementa una interfaz
* 
* La interfaces funcionan como un contrato, al cual se suscriben
* las clases que las implementan. El contrato obliga a las clases
* a implementar todos los m�todos de la interfaz
* 
* El polimorfismo tambi�n ocurre a trav�s de interfaces, pues
* para el lenguaje de programaci�n es una clase como cualquier otra
* 
* En C++ existe la herencia m�ltiple, pero no es recomendable utilizarla
* con clases normales o abstractas. No obstante, implementar m�ltiples
* interfaces es com�n en la Programaci�n Orientada a Objetos
*/

// Crearemos una interfaz: Drawable
// �sta compuesta �nicamente de m�todos virtuales puros y p�blicos
class Drawable
{
public:
	virtual void Draw() = 0;
};

// Segundo ejemplo de interfaz
class Printable
{
public:
	virtual std::string Print() = 0;
};

/*
* Ahora haremos que una clase, Model implemente las interfaces Drawable y Printable
* 
* Model tiene que implementar los m�todos de las interfaces
* 
* Nota c�mo funciona la herencia m�ltiple, simplemente separando cada herencia con una coma.
* Recuerda que �sto s�lamente es recomendable para implementar m�ltiples interfaces
*/
class Model : public Drawable, public Printable
{
	virtual void Draw() override
	{
		std::cout << "Drawing model" << std::endl;
	}

	virtual std::string Print() override
	{
		return "Model";
	}
};

// Segundo ejemplo de una clase que implementa las interfaces
class Terrain : public Drawable, public Printable
{
	virtual void Draw() override
	{
		std::cout << "Drawing terrain" << std::endl;
	}

	virtual std::string Print() override
	{
		return "Terrain";
	}
};

int main()
{
	Model model;
	Terrain terrain;

	// Creamos un arreglo de referencias (punteros), para todos los drawable y printable
	Drawable* drawables[] { &model, &terrain };
	Printable* printables[] { &model, &terrain };

	// Nota c�mo en los siguientes ejemplos, el polimorfismo funciona igual a los ejemplos anteriores
	std::cout << "Dibujando:" << std::endl;
	for (Drawable* drawable : drawables)
	{
		drawable->Draw();
	}

	std::cout << std::endl << "Imprimiendo:" << std::endl;
	for (Printable* printable : printables)
	{
		std::cout << "Imprimiendo: " << printable->Print() << std::endl;
	}
}
