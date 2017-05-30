#include <iostream>
#include <cmath>
#include "Cercle.hpp"

Cercle::Cercle(ulong color, int thick, bool remplir, uint x, uint y, uint _side)
	: Forme(color, thick, remplir, x, y), side(_side), radius(_side/2)
{
//	cerr << "Construction d'un Cercle " << perimetre() << endl;
}

Cercle::Cercle(istream &is)
	: Forme(is), side(0)
{
    is >> side;
}

Cercle::~Cercle()
{
//	cerr << "Destruction de Cercle" << endl;
}

double Cercle::perimetre() const
{
    return (2*M_PI*radius);
}

void Cercle::dessiner(EZWindow &w, bool isActive) const
{
	Forme::dessiner(w);
	Point ancre = getAncre();
	uint _x = ancre.getx();
	uint _y = ancre.gety();
	if(isActive || getRemplir()) w.fillCircle(_x-side, _y-side, _x+side, _y+side);
	else w.drawCircle(_x-side, _y-side, _x+side, _y+side);
}

void Cercle::ecrire(ostream &os) const
{
    os << side;
}
