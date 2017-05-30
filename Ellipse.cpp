#include <iostream>
#include <cmath>
#include "Ellipse.hpp"

Ellipse::Ellipse(ulong color, int thick, bool remplir, uint x, uint y, uint _demiHauteur, uint _demiLargeur)
	: Forme(color, thick, remplir, x, y), demiHauteur(_demiHauteur), demiLargeur(_demiLargeur)
{
//	cerr << "Construction d'une Ellipse " << perimetre() << endl;
}

Ellipse::Ellipse(istream &is)
	: Forme(is), demiHauteur(0), demiLargeur(0)
{
    is >> demiHauteur >> demiLargeur;
}

Ellipse::~Ellipse()
{
//	cerr << "Destruction de Ellipse" << endl;
}

double Ellipse::perimetre() const
{
	return ((2*3.14159265359)*sqrt(0.5*(((demiHauteur/2)*(demiHauteur/2))+((demiLargeur/2)*(demiLargeur/2)))));
}

void Ellipse::dessiner(EZWindow &w,bool isActive) const
{
	Forme::dessiner(w);
	Point ancre = getAncre();
	uint _x = ancre.getx();
	uint _y = ancre.gety();
	if(isActive || getRemplir()) w.fillCircle(_x-demiLargeur, _y-demiHauteur, _x+demiLargeur, _y+demiHauteur);
	else w.drawCircle(_x-demiLargeur, _y-demiHauteur, _x+demiLargeur, _y+demiHauteur);
}

void Ellipse::ecrire(ostream &os) const
{
	os << demiHauteur << " " << demiLargeur;
}
