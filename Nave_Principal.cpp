#include "Nave_Principal.h"

Nave_Principal::Nave_Principal()
{
}

Nave_Principal::Nave_Principal(int px, int py, int pw, int ph):Base(px, py, pw, ph, 1,1, 0, 0)
{
	fraccion_movimientoX = 2;
	fraccion_movimientoY = 2;
	orientacion = direccion::derecha;
}

Nave_Principal::~Nave_Principal()
{
}

void Nave_Principal::Disparar()
{
	balas.push_back(new Bala(x + w / 2, y, 1, 1));
}

void Nave_Principal::Mover_balas(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < balas.size(); i++)
	{
		balas.at(i)->Dibujar_desImagen(g, bmp);
		balas.at(i)->Mover(g);
	}
	for (int i = 0; i < balas.size(); i++)
	{
		if (balas.at(i)->retornar_eliminar() == true)
			balas.erase(balas.begin()+i);
	}

}

void Nave_Principal::Mover(Graphics^ g)
{
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width)dx = 0;
	if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height)dx = 0;
	x += dx;
	y += dy;
}

vector<Bala*> Nave_Principal::retornar_bala()
{
	return balas;
}

int Nave_Principal::retornar_cant_balas()
{
	return balas.size();
}

Bala* Nave_Principal::retornar_bala_eninidice(int indice)
{
	return balas.at(indice);
}
