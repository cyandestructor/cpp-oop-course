#include <iostream>
#include <string>

/*
* Interfaces:
* 
* Las interfaces son casos especiales de clases. En algunos lenguajes
* de programación, incluso son considerados conceptos distintos
* 
* En C++, las interfaces son clases que únicamente tienen métodos
* virtuales puros y públicos
* 
* Si bien, en cuestión de sintaxis, una clase hereda de una interfaz
* como cualquier otra clase, el término correcto es 'implementar'. Una
* clase implementa una interfaz
* 
* La interfaces funcionan como un contrato, al cual se suscriben
* las clases que las implementan. El contrato obliga a las clases
* a implementar todos los métodos de la interfaz
* 
* El polimorfismo también ocurre a través de interfaces, pues
* para el lenguaje de programación es una clase como cualquier otra
* 
* En C++ existe la herencia múltiple, pero no es recomendable utilizarla
* con clases normales o abstractas. No obstante, implementar múltiples
* interfaces es común en la Programación Orientada a Objetos
*/

// Crearemos una interfaz: Drawable
// Ésta compuesta únicamente de métodos virtuales puros y públicos
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
* Model tiene que implementar los métodos de las interfaces
* 
* Nota cómo funciona la herencia múltiple, simplemente separando cada herencia con una coma.
* Recuerda que ésto sólamente es recomendable para implementar múltiples interfaces
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

	// Nota cómo en los siguientes ejemplos, el polimorfismo funciona igual a los ejemplos anteriores
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
