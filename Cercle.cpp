#include <iostream>
#include <cmath>
#include "Cercle.hpp"

Cercle::Cercle(ulong color, int thick, bool remplir, uint x, uint y, uint _diametre)
	: Forme(color, thick, remplir, x, y), diametre(_diametre), radius(_diametre/2)
{
//	cerr << "Construction d'un Cercle " << perimetre() << endl;
}

Cercle::Cercle(istream &is)
	: Forme(is), diametre(0)
{
    is >> diametre;
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
	if(isActive || getRemplir()) w.fillCircle(_x-diametre, _y-diametre, _x+diametre, _y+diametre);
	else w.drawCircle(_x-diametre, _y-diametre, _x+diametre, _y+diametre);
}

void Cercle::ecrire(ostream &os) const
{
    os << "Cercle " << getCouleur() << " " << getThickness() << " " << getRemplir() << " " << getAncre().getx() << " " << getAncre().gety() << " " << diametre;
}
