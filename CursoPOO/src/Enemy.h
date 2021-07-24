#pragma once

// Podemos incluir cualquier archivo de c�digo que necesitemos, incluidos los
// de la librer�a est�ndar de C++
#include <iostream>
#include <string>

/*
* En el archivo de encabezado '.h' se escribe la declaraci�n de la clase,
* es decir, el nombre de la clase, sus atributos y m�todos. En el caso
* de los m�todos, se escribe �nicamente su declaraci�n, posteriormente
* se agrega su implementaci�n o definici�n
*/
class Enemy
{
protected:
	int hp;
	int attack;
	int defense;
	std::string name;
public:

	// M�todos como los contructores
	// y destructores que no tengan implementaci�n se pueden deja en el .h
	Enemy()
		: hp(0), attack(0), defense(0), name("Enemigo") {}

	Enemy(int hp, int attack, int defense, const std::string& name)
		: hp(hp), attack(attack), defense(defense), name(name) {}

	Enemy(int hp, int attack, int defense)
		: Enemy(hp, attack, defense, "Enemigo") {}

	virtual ~Enemy() {}

	// Las declaraciones de m�todos no tienen cuerpo, s�lo el nombre, tipo de retorno,
	// par�metros, si es constante, etc�tera
	int GetHp() const;

	void SetHp(int hp);

	int GetAttack() const;

	void SetAttack(int attack);

	int GetDefense() const;

	void SetDefense(int defense);

	virtual void Attack();
};

// Consulta el archivo Enemy.cpp