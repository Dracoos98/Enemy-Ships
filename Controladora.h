#pragma once
#include <vector>
#include "Nave_Principal.h"
#include "Nave_Enemiga.h"
using namespace std;
class Controladora
{
private:
	vector<Base*> naves_enemigas;
	Nave_Principal* objNP;
	Bala* objB; 

public:
	Controladora();
	~Controladora();
	void Dibujar_NaveE(Graphics^ g, Bitmap^ bmp);
	void Dibujar_Nave(Graphics^ g, Bitmap^ bmp);
	void Desplazar_Nave(direccion nuevo);
	bool Colision1();
	bool Colision2();
	void Disparar();
	void Dibujar_Bala(Graphics^ g, Bitmap^ bmp);

};