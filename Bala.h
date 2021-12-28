#pragma once
#include "Base.h"
class Bala :
    public Base
{
public:
    Bala();
    Bala(int px, int py, int pw, int ph);
    ~Bala();
    void Mover(Graphics^ g);
};

