#include <iostream>
#include <cmath>
#include "Triangle.hpp"

Triangle::Triangle(ulong color, int thick, bool remplir, uint x, uint y, uint x2, uint y2, uint x3, uint y3)
	:Forme(color, thick, remplir, x, y), ancre2(x2, y2), ancre3(x3, y3)
{
//	cerr << "Construction d'un Triangle " << perimetre() << endl;
}

Triangle::Triangle(istream &is)
	:Forme(is), ancre2(0, 0), ancre3(0, 0)
{
	bool _thickness = false;
	uint _remplir = 0;
    is >> ancre2 >> ancre3 >> _thickness >> _remplir;
	setThickness(_thickness);
	setRemplir(_remplir);
}

Triangle::~Triangle()
{
//	cerr << "Destruction de Triangle" << endl;
}

double Triangle::perimetre() const
{
	uint x2 = ancre2.getx();
	uint y2 = ancre2.gety();
	uint x3 = ancre3.getx();
	uint y3 = ancre3.gety();
	return sqrt(pow(x2-x3,2)+pow(y2-y3,2)) * 3;
}

void Triangle::dessiner(EZWindow &w/*,bool isActive*/) const
{
	Forme::dessiner(w);
	Point ancre = getAncre();
	uint x = ancre.getx();
	uint y = ancre.gety();
	if(getRemplir()) w.fillTriangle(x, y, x-50, y+40, x+50, y+40);
	else w.drawTriangle(x, y, x-50, y+40, x+50, y+40);;
}


void Triangle::ecrire(ostream &os) const
{
    os << "Triangle " << getCouleur() << " " << getAncre().getx() << " " << getAncre().gety() << " " << getAncre2().getx() << " " << getAncre2().gety() << " " << getAncre3().getx() << " " << getAncre3().gety();//height << " " << width;
}
