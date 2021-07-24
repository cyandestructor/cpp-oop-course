/*
* En proyectos muy grandes, con gran cantidad de clases, lo m�s
* recomendable es separar el c�digo en diferentes archivos
* 
* La forma estandarizada de separar el c�digo de C++ para una aplicaci�n
* orientada a objetos es separar cada clase en un par de archivos:
* La declaraci�n de la clase en un archivo de encabezado '.h' y la
* implementaci�n en un archivo de c�digo '.cpp'
* 
* Es mejor que, tanto el archivo de encebezado, como el archivo de c�digo de una clase,
* tengan ambos exactamente el mismo nombre que la clase en cuesti�n
* 
* Consulta el archivo Enemy.h y Enemy.cpp para ver
* el ejemplo comentado
*/

// Se incluyen con la directiva #include, �nicamente los archivos de encabezado de las clases
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
