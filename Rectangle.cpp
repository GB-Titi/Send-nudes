#include <iostream>
#include "Rectangle.hpp"

Rectangle::Rectangle(ulong color, int thick, bool remplir, uint x, uint y, uint _hauteur, uint _largeur)
	: Forme(color, thick, remplir, x, y), hauteur(_hauteur), largeur(_largeur)
{
//	cerr << "Construction d'un Rectangle " << perimetre() << endl;
}

Rectangle::Rectangle(istream &is)
	: Forme(is), hauteur(0), largeur(0)
{
	is >> hauteur >> largeur;
}

Rectangle::~Rectangle()
{
//	cerr << "Destruction de Rectangle" << endl;
}

double Rectangle::perimetre() const
{
	return (hauteur+largeur)*2;
}

void Rectangle::dessiner(EZWindow &w,bool isActive) const
{
	Forme::dessiner(w);
	Point ancre = getAncre();
	uint x = ancre.getx();
	uint y = ancre.gety();
	if(isActive || getRemplir()) w.fillRectangle(x-largeur/2, y-hauteur/2, x+largeur/2, y+hauteur/2);
	else w.drawRectangle(x-largeur/2, y-hauteur/2, x+largeur/2, y+hauteur/2);
}

void Rectangle::ecrire(ostream &os) const
{
	os << hauteur << " " << largeur;
}