#include <iostream>
#include <cmath>
#include "Triangle.hpp"

Triangle::Triangle(ulong color, int thick, bool remplir, uint x, uint y, uint x2, uint y2, uint x3, uint y3)
	:Forme(color, thick, remplir, x, y), height(x2), width(y2)
{
//	cerr << "Construction d'un Triangle " << perimetre() << endl;
}

Triangle::Triangle(istream &is)
	:Forme(is), height(0), width(0)
{
	bool _thickness = false;
	uint _remplir = 0;
    is >> height >> width >> _thickness >> _remplir;
	setThickness(_thickness);
	setRemplir(_remplir);
}

Triangle::~Triangle()
{
//	cerr << "Destruction de Triangle" << endl;
}

double Triangle::perimetre() const
{
	return (sqrt((height*height)+(width/2)*(width/2))*2+width);
}

void Triangle::dessiner(EZWindow &w,bool isActive) const
{
	Forme::dessiner(w);
	Point ancre = getAncre();
	uint x = ancre.getx();
	uint y = ancre.gety();
	if(getRemplir()) w.fillTriangle(x-width/2, y, x+width/2, y, x, y-height);
	else w.drawTriangle(x-width/2, y, x+width/2, y, x, y-height);
}

void Triangle::ecrire(ostream &os) const
{
    os << "Triangle " << getCouleur() << " " << getAncre().getx() << " " << getAncre().gety() << " " << height << " " << width;
}
