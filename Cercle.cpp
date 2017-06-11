#include <iostream>
#include "Cercle.hpp"

Cercle::Cercle(ulong color, int thick, bool remplir, uint x, uint y, uint _diametre)
	: Forme(color, thick, remplir, x, y), diametre(_diametre)
{
//	cerr << "Construction d'un Cercle " << perimetre() << endl;
}

Cercle::Cercle(istream &is)
	: Forme(is), diametre(0)
{
    bool _thickness = false;
	uint _remplir = 0;
    is >> diametre >> _thickness >> _remplir;
	setThickness(_thickness);
	setRemplir(_remplir);
}

Cercle::~Cercle()
{
//	cerr << "Destruction de Cercle" << endl;
}

double Cercle::perimetre() const
{
    return (3.14159265358979323846*diametre);
}

void Cercle::dessiner(EZWindow &w/*, bool isActive*/) const
{
	Forme::dessiner(w);
	Point ancre = getAncre();
	uint _x = ancre.getx();
	uint _y = ancre.gety();
	if(getRemplir()) w.fillCircle(_x-diametre, _y-diametre, _x+diametre, _y+diametre);
	else w.drawCircle(_x-diametre, _y-diametre, _x+diametre, _y+diametre);
}

void Cercle::ecrire(ostream &os) const
{
    os << "Cercle " << getCouleur() << " " << getAncre().getx() << " " << getAncre().gety() << " " << diametre;
}
