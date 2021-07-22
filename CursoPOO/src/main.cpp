#include <iostream>
#include <string>

/*
* Pilares de la Programaci�n Orientada a Objetos:
*	+ Encapsulamiento
*	+ Abstracci�n
*	+ Herencia
*	+ Polimorfismo
* 
* Se tratan de conceptos base de la POO, que describen
* qu� se puede hacer y c�mo se sugiere usar este paradigma de programaci�n
*/

/*
* Encapsulamiento:
* 
* Este pilar de la Programaci�n orientada a objetos se refiere
* a las medidas que debemos tomar para cuidar el estado interno
* de nuestros objetos
* 
* El estado interno se refiere a los datos internos que afectan el
* funcionamiento de nuestros objetos, usualmente los atributos
* 
* Cuidar el estado interno se refiere a mantener los valores
* de estos datos en valores v�lidos o esperados, para evitar
* errores. Esto vuelve a nuestro c�digo m�s robusto
* 
* Por ejemplo, una clase Enemy, tiene un atributo Hp. En este caso
* cuidar su estado interno ser�a evitar que en cualquier momento el
* valor del Hp sea negativo
* 
* Mantener el estado interno se logra a trav�s de dos estrategias:
* 'Data Hiding' u 'Ocultaci�n de Informaci�n', y 'Data Protection' o
* 'Protecci�n de Informaci�n'
* 
* 'Data Hiding' se logra cuando los atributos de una clase est�n
* ocultos o privados, y s�lo es posible acceder a ellos a trav�s de
* una llamada intermedia, como un m�todo p�blico
* 
* Estos m�todos p�blicos que sirven como intermediarios para
* acceder a los atributos privados son com�nmente llamados 'getters'
* y 'setters'
* 
* Los 'getters' sirven para obtener (get) la informaci�n, los 'setters'
* sirven para modificar (set) la informaci�n.
* 
* Finalmente, 'Data Protection' se trata de acciones a tomar para
* mantener los atributos siempre en valores v�lidos, usualmente
* usando l�gica de validaci�n en los m�todos 'setters'
*/
class Enemy
{
private:
	// Como parte del principio de encapsulamiento, los atributos se vuelven privados
	int hp;
	int attack;
	int defense;
	std::string name;
public:
	Enemy()
		: hp(0), attack(0), defense(0), name("Enemigo")
	{
	}

	Enemy(int hp, int attack, int defense, const std::string& name)
		: hp(hp), attack(attack), defense(defense), name(name)
	{
	}

	Enemy(int hp, int attack, int defense)
		: Enemy(hp, attack, defense, "Enemigo")
	{
	}

	// Definimos los getters y setters p�blicos para los atributos
	// Podemos escribir ambos para cada atributo, o s�lo uno si
	// queremos que sea s�lo lectura o s�lo escritura
	// El est�ndar es usar la nomenclatura Get[Atributo] y Set[Atributo]

	int GetHp()
	{
		return hp;
	}
	
	// Nota que usamos el gui�n bajo como prefijo para evitar confusiones entre el par�metro y el atributo
	void SetHp(int _hp)
	{
		// Mira c�mo usamos Data Protection para evitar que el Hp sea menor a 0
		if (_hp < 0)
			return; // Si el Hp que recibe es menor a 0, retorna sin modificar el atributo
		
		hp = _hp;
	}

	int GetAttack()
	{
		return attack;
	}

	void SetAttack(int _attack)
	{
		if (_attack < 0)
			return;
		
		attack = _attack;
	}

	int GetDefense()
	{
		return defense;
	}

	void SetDefense(int _defense)
	{
		if (_defense < 0)
			return;

		defense = _defense;
	}

	void Attack()
	{
		std::cout << "The Enemy " << name << " attacks with " << attack << " of power" << std::endl;
	}

	void Die()
	{
		if (hp <= 0)
		{
			std::cout << "The Enemy " << name << " dies" << std::endl;
		}
		else
		{
			std::cout << "The Enemy " << name << " has " << hp << " HP" << std::endl;
		}
	}
};

int main()
{
	Enemy enemigoA = Enemy(100, 20, 5, "Paul");

	enemigoA.Attack();
	enemigoA.Die();

	// Accedemos a sus atributos usando los m�todos p�blicos
	
	enemigoA.SetAttack(100);
	enemigoA.SetDefense(-5);
	enemigoA.SetHp(0);

	std::cout << "El enemigo A tiene " << enemigoA.GetDefense() << " de defensa" << std::endl;

	enemigoA.Attack();
	enemigoA.Die();
}