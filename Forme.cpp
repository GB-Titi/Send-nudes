#include "Forme.hpp"
#include <stdexcept>
#include "Rectangle.hpp"
#include "Cercle.hpp"
#include "Carre.hpp"
#include "Ellipse.hpp"

Forme::Forme (ulong _couleur, uint _thickness, uint _x, uint _y)
	: couleur(_couleur), thickness(_thickness), ancre(_x, _y)
{}

Forme::Forme (const Forme &orig)
	: Forme (orig.couleur, orig.thickness, orig.ancre.getx(), orig.ancre.gety())
{
//	cerr << "Construction par recopie de Forme";
}

Forme::Forme(istream &is)
	: couleur(0), thickness(0), ancre(0,0)
{
	is >> couleur >> thickness >> ancre;
}

Forme::~Forme()
{
	//cerr << "Destruction de Forme" << endl;
}

//Autres constructeurs

/*

Forme::Forme (const uint _couleur, const Point &_p)
	:couleur(_couleur), ancre(_p)
{
	cerr << "Construction complete de Forme par une Point";
}

Forme::Forme (const uint _couleur, uint _x, uint _y)
	: Forme (_c, Point (_x, _y))
{
	cerr << "Construction complete de Forme"
}

Forme::Forme (const Forme &f)
	: Forme (f.couleur, f.ancre)
{
	cerr << "Construction par recopie de Forme"
}

*/

void Forme::setAncre(uint _x, uint _y)
{
	ancre.setxy(_x,_y);
}

bool Forme::isOver(uint x, uint y)
{
	return ancre.isOver(x,y);
}

void Forme::dessiner(EZWindow &w, bool isActive) const
{
	w.setDoubleBuffer(1);
	w.setColor(ez_black);
	w.setThick(1);
	ancre.dessiner(w, isActive);
	w.setColor(couleur);
	w.setThick(thickness);
}

void Forme::ecrire(ostream &os) const
{
	os << couleur << " " << thickness << " " << ancre;
}

ostream &operator<<(ostream &os, const Forme &f)
{
	f.ecrire(os);
	return os;
}

Forme *Forme::charger(istream &is)
{
	string type_forme;
	is >> type_forme;
	if (type_forme == "Rectangle")
		return new Rectangle(is);
	else if (type_forme == "Ellipse")
		return new Ellipse(is);
	else if (type_forme == "Carre")
		return new Carre(is);
	else if (type_forme == "Cercle")
		return new Cercle(is);
	else
		throw runtime_error ("Type de forme inconnu");
}
