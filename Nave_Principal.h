#pragma once
#include <vector>
#include "Base.h"
#include "Bala.h"
using namespace std;
class Nave_Principal :
    public Base
{
private:
    vector<Bala*>balas;
public:
    Nave_Principal();
    Nave_Principal(int px, int py, int pw, int ph);
    ~Nave_Principal();
    void Disparar();
    void Mover_balas(Graphics^ g, Bitmap^ bmp);
    void Mover(Graphics^ g);
    vector<Bala*> retornar_bala();
    int retornar_cant_balas();
    Bala* retornar_bala_eninidice(int indice);
};

