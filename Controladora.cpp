#include "Controladora.h"
#include "stdlib.h"

Controladora::Controladora()
{
	System::Random^ r = gcnew System::Random();
	int cantidad = r->Next(10, 21);
	for (int i = 0; i < cantidad; i++)
		naves_enemigas.push_back(new Nave_Enemiga(r->Next(100, 500), r->Next(5, 220), 1, 1));
	objNP = new Nave_Principal(320, 400, 20, 20);
	delete r;
}

Controladora::~Controladora()
{
	for (int i = 0; i < naves_enemigas.size(); i++)
		delete naves_enemigas.at(i);
	delete objNP;
}

void Controladora::Dibujar_NaveE(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < naves_enemigas.size(); i++)
	{
		naves_enemigas.at(i)->Dibujar_desImagen(g, bmp);
		naves_enemigas.at(i)->Mover(g);
	}
}

void Controladora::Dibujar_Nave(Graphics^ g, Bitmap^ bmp)
{
	objNP->Dibujar_desImagen(g, bmp);
	objNP->Mover(g);
	Colision1();
	Colision2();
}

void Controladora::Desplazar_Nave(direccion nuevo)
{
	objNP->Desplazamiento(nuevo);
}

bool Controladora::Colision1()
{
	Rectangle rnave = objNP->retonar_rectangle();
	bool resultado_colision1 = false;
	for (int i = 0; !resultado_colision1 && i < objNP->retornar_cant_balas(); i++)
	{
		Rectangle rbalas = objNP->retornar_bala_eninidice(i)->retonar_rectangle();
		for (int j = 0; !resultado_colision1 && j < naves_enemigas.size(); j++)
		{
			Rectangle rnavesenemigas = naves_enemigas.at(j)->retonar_rectangle();
			if (rbalas.IntersectsWith(rnavesenemigas))
			{
				resultado_colision1 = true;
				objNP->retornar_bala_eninidice(i)->cambiar_eliminar(true);
				naves_enemigas.erase(naves_enemigas.begin() + j);
			}
		}
	}
	
	return resultado_colision1;

}

bool Controladora::Colision2()
{
	Rectangle rnave = objNP->retonar_rectangle();
	bool resultado_colision2 = false;
	for (int j = 0; !resultado_colision2 && j < naves_enemigas.size(); j++)
	{
		Rectangle rnavesenemigas = naves_enemigas.at(j)->retonar_rectangle();
		if (rnave.IntersectsWith(rnavesenemigas))
		{
			resultado_colision2 = true;
			
		}
	}
	return resultado_colision2;
}

void Controladora::Disparar()
{
	objNP->Disparar();
}

void Controladora::Dibujar_Bala(Graphics^ g, Bitmap^ bmp)
{
	objNP->Mover_balas(g, bmp);
}
