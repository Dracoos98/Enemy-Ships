#include "Base.h"

Base::Base()
{
	eliminar = false;
	dx = dy = 0;
	orientacion = direccion::ninguno;
}

Base::Base(int px, int py, int pw, int ph)
{
	x = px;
	y = py;
	w = pw;
	h = ph;
	eliminar = false;
	dx = dy = 0;
	orientacion = direccion::ninguno;
}

Base::Base(int px, int py, int pw, int ph, int pmaxfil, int pmaxcol, int pfil, int pcol)
{
	x = px;
	y = py;
	w = pw;
	h = ph;
	eliminar = false;
	dx = dy = 0;
	orientacion = direccion::ninguno;
	max_col = pmaxcol;
	max_fil = pmaxfil;
	col = pcol;
	fil = pfil;
}

Base::~Base()
{
}

void Base::cambiar_x(int nuevo)
{
	x = nuevo;
}

void Base::cambiar_y(int nuevo)
{
	y = nuevo;
}

void Base::cambiar_h(int nuevo)
{
	h = nuevo;
}

void Base::cambiar_w(int nuevo)
{
	w = nuevo;
}

void Base::cambiar_dx(int nuevo)
{
	dx = nuevo;
}

void Base::cambiar_dy(int nuevo)
{
	dy = nuevo;
}

void Base::cambiar_max_fil(int nuevo)
{
	max_fil = nuevo;
}

void Base::cambiar_max_col(int nuevo)
{
	max_col = nuevo;
}

void Base::cambiar_col(int nuevo)
{
	col = nuevo;
}

void Base::cambiar_fil(int nuevo)
{
	fil = nuevo;
}

void Base::cambiar_eliminar(bool nuevo)
{
	eliminar = nuevo;
}

void Base::cambiar_fmx(int nuevo)
{
	fraccion_movimientoX = nuevo;
}

void Base::cambiar_fmy(int nuevo)
{
	fraccion_movimientoY = nuevo;
}

void Base::Desplazamiento(direccion nuevo)
{
	orientacion = nuevo;
	dx = dy = 0;
	if (orientacion == direccion::arriba) { dy = -(h/fraccion_movimientoY); fil =0; }
	if (orientacion == direccion::abajo) { dy = (h/fraccion_movimientoY); fil = 0;}
	if (orientacion == direccion::izquierda) {
		dx = -(w/fraccion_movimientoX); fil = 0;
	}
	if (orientacion == direccion::derecha) { dx = (w/fraccion_movimientoX); fil = 0; }
}

int Base::retornar_x()
{
	return x;
}

int Base::retornar_y()
{
	return y;
}

int Base::retornar_h()
{
	return h;
}

int Base::retornar_w()
{
	return w;
}

int Base::retornar_dx()
{
	return dx;
}

int Base::retornar_dy()
{
	return dy;
}

int Base::retornar_max_fil()
{
	return max_fil;
}

int Base::retornar_max_col()
{
	return max_col;
}

int Base::retornar_col()
{
	return col;
}

int Base::retornar_fil()
{
	return fil;
}

bool Base::retornar_eliminar()
{
	return eliminar;
}

int Base::retornar_fmx()
{
	return fraccion_movimientoX;
}

int Base::retornar_fmy()
{
	return fraccion_movimientoY;
}

Rectangle Base::retonar_rectangle()
{
	return Rectangle(x,y,w,h);
}

void Base::Mover(Graphics^ g)
{
	if (x + dx<1 || x + x + dx + w>g->VisibleClipBounds.Width)dx = dx * -1;
	if (y + dy<1 || y + y + dy + h>g->VisibleClipBounds.Height)dy = dy * -1;

	x += dx;
	y += dy;
}

void Base::Dibujar(Graphics^ g)
{
}

void Base::Dibujar_desImagen(Graphics^ g, Bitmap^ bmp)
{
	w = bmp->Width / max_col;

	h = bmp->Height / max_fil;

	Rectangle porcion = Rectangle(col * w, fil * h, w, h);

	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);

	col++;

	if (col == max_col)

		col = 0;
	fil++;
	if (fil = max_fil)
		fil = 0;

}

void Base::Borrar(Graphics^ g)
{
}
