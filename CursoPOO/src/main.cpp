/*
* En proyectos muy grandes, con gran cantidad de clases, lo más
* recomendable es separar el código en diferentes archivos
* 
* La forma estandarizada de separar el código de C++ para una aplicación
* orientada a objetos es separar cada clase en un par de archivos:
* La declaración de la clase en un archivo de encabezado '.h' y la
* implementación en un archivo de código '.cpp'
* 
* Es mejor que, tanto el archivo de encebezado, como el archivo de código de una clase,
* tengan ambos exactamente el mismo nombre que la clase en cuestión
* 
* Consulta el archivo Enemy.h y Enemy.cpp para ver
* el ejemplo comentado
*/

// Se incluyen con la directiva #include, únicamente los archivos de encabezado de las clases
// que necesitamos en este archivo
#include "Skeleton.h"
#include "Mummy.h"

int main()
{
	Mummy* momia = new Mummy(100, 40, 20, "Momia");
	momia->SetMana(5);

	Skeleton* esqueleto = new Skeleton(100, 20, 5, "Esqueleto");
	esqueleto->SetArrows(50);

	Enemy* enemigos[2];
	enemigos[0] = momia;
	enemigos[1] = esqueleto;

	for (int i = 0; i < 2; i++)
	{
		enemigos[i]->Attack();
	}

	delete momia;
	delete esqueleto;
}
