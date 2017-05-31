#include <iostream>
#include "Carre.hpp"

Carre::Carre(ulong color, int thick, bool remplir, uint x, uint y, uint _cote)
	: Forme(color, thick, remplir, x, y), cote(_cote)
{
//	cerr << "Construction d'un Carre " << perimetre() << endl;
}

Carre::Carre(istream &is)
	: Forme(is), cote(0)
{
    is >> cote;
}

Carre::~Carre()
{
//	cerr << "Destruction de Carre" << endl;
}

double Carre::perimetre() const
{
    return (cote*4);
}

void Carre::dessiner(EZWindow &w, bool isActive) const
{
	Forme::dessiner(w);
	Point ancre = getAncre();
	uint _x = ancre.getx();
	uint _y = ancre.gety();
	if(isActive || getRemplir()) w.fillRectangle(_x-cote, _y-cote, _x+cote, _y+cote);
	else w.drawRectangle(_x-cote, _y-cote, _x+cote, _y+cote);
}

void Carre::ecrire(ostream &os) const
{
    os << "Carre " << getCouleur() << " " << getThickness() << " " << getRemplir() << " " << getAncre().getx() << " " << getAncre().gety() << " " << cote;
}
