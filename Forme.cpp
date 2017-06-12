#include "Forme.hpp"
#include <stdexcept>
#include "Rectangle.hpp"
#include "Cercle.hpp"
#include "Carre.hpp"
#include "Ellipse.hpp"
#include "Triangle.hpp"

Forme::Forme (ulong _couleur, uint _thickness, bool _remplir, uint _x, uint _y)
	: couleur(_couleur), thickness(_thickness), remplir(_remplir), ancre(_x, _y)
{}

Forme::Forme (const Forme &orig)
	: Forme (orig.couleur, orig.thickness, orig.remplir, orig.ancre.getx(), orig.ancre.gety())
{}

Forme::Forme(istream &is)
	: couleur(0), ancre(0,0)
{
	is >> couleur >> ancre;
}

Forme::~Forme()
{}

void Forme::dessiner(EZWindow &w/*, bool isActive*/) const
{
	w.setDoubleBuffer(1);
	w.setColor(ez_black);
	w.setThick(1);
	ancre.dessiner(w/*, isActive*/);
	w.setColor(couleur);
	w.setThick(thickness);
}

void Forme::ecrire(ostream &os) const
{
	os << "Forme " << couleur << " " << ancre;
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
    else if (type_forme == "Triangle")
		return new Triangle(is);
    else
		throw runtime_error ("Type de forme inconnu");
}
