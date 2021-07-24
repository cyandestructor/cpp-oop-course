#pragma once

// Podemos incluir cualquier archivo de código que necesitemos, incluidos los
// de la librería estándar de C++
#include <iostream>
#include <string>

/*
* En el archivo de encabezado '.h' se escribe la declaración de la clase,
* es decir, el nombre de la clase, sus atributos y métodos. En el caso
* de los métodos, se escribe únicamente su declaración, posteriormente
* se agrega su implementación o definición
*/
class Enemy
{
protected:
	int hp;
	int attack;
	int defense;
	std::string name;
public:

	// Métodos como los contructores
	// y destructores que no tengan implementación se pueden deja en el .h
	Enemy()
		: hp(0), attack(0), defense(0), name("Enemigo") {}

	Enemy(int hp, int attack, int defense, const std::string& name)
		: hp(hp), attack(attack), defense(defense), name(name) {}

	Enemy(int hp, int attack, int defense)
		: Enemy(hp, attack, defense, "Enemigo") {}

	virtual ~Enemy() {}

	// Las declaraciones de métodos no tienen cuerpo, sólo el nombre, tipo de retorno,
	// parámetros, si es constante, etcétera
	int GetHp() const;

	void SetHp(int hp);

	int GetAttack() const;

	void SetAttack(int attack);

	int GetDefense() const;

	void SetDefense(int defense);

	virtual void Attack();
};

// Consulta el archivo Enemy.cpp