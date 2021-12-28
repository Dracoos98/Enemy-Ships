#include "Nave_Enemiga.h"

Nave_Enemiga::Nave_Enemiga()
{
}

Nave_Enemiga::Nave_Enemiga(int px, int py, int pw, int ph) :Base(px, py, pw, ph, 3, 7, 0, 0)
{
	System::Random^ r = gcnew System::Random();
	dx = r->Next(10, 15);
	dy = r->Next(5, 20);
	delete r;
}

Nave_Enemiga::~Nave_Enemiga()
{
}
