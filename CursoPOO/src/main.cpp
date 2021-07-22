#include <iostream>
#include <string>

/*
* Pilares de la Programación Orientada a Objetos:
*	+ Encapsulamiento
*	+ Abstracción
*	+ Herencia
*	+ Polimorfismo
* 
* Se tratan de conceptos base de la POO, que describen
* qué se puede hacer y cómo se sugiere usar este paradigma de programación
*/

/*
* Encapsulamiento:
* 
* Este pilar de la Programación orientada a objetos se refiere
* a las medidas que debemos tomar para cuidar el estado interno
* de nuestros objetos
* 
* El estado interno se refiere a los datos internos que afectan el
* funcionamiento de nuestros objetos, usualmente los atributos
* 
* Cuidar el estado interno se refiere a mantener los valores
* de estos datos en valores válidos o esperados, para evitar
* errores. Esto vuelve a nuestro código más robusto
* 
* Por ejemplo, una clase Enemy, tiene un atributo Hp. En este caso
* cuidar su estado interno sería evitar que en cualquier momento el
* valor del Hp sea negativo
* 
* Mantener el estado interno se logra a través de dos estrategias:
* 'Data Hiding' u 'Ocultación de Información', y 'Data Protection' o
* 'Protección de Información'
* 
* 'Data Hiding' se logra cuando los atributos de una clase están
* ocultos o privados, y sólo es posible acceder a ellos a través de
* una llamada intermedia, como un método público
* 
* Estos métodos públicos que sirven como intermediarios para
* acceder a los atributos privados son comúnmente llamados 'getters'
* y 'setters'
* 
* Los 'getters' sirven para obtener (get) la información, los 'setters'
* sirven para modificar (set) la información.
* 
* Finalmente, 'Data Protection' se trata de acciones a tomar para
* mantener los atributos siempre en valores válidos, usualmente
* usando lógica de validación en los métodos 'setters'
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

	// Definimos los getters y setters públicos para los atributos
	// Podemos escribir ambos para cada atributo, o sólo uno si
	// queremos que sea sólo lectura o sólo escritura
	// El estándar es usar la nomenclatura Get[Atributo] y Set[Atributo]

	int GetHp()
	{
		return hp;
	}
	
	// Nota que usamos el guión bajo como prefijo para evitar confusiones entre el parámetro y el atributo
	void SetHp(int _hp)
	{
		// Mira cómo usamos Data Protection para evitar que el Hp sea menor a 0
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

	// Accedemos a sus atributos usando los métodos públicos
	
	enemigoA.SetAttack(100);
	enemigoA.SetDefense(-5);
	enemigoA.SetHp(0);

	std::cout << "El enemigo A tiene " << enemigoA.GetDefense() << " de defensa" << std::endl;

	enemigoA.Attack();
	enemigoA.Die();
}