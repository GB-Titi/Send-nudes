#include <iostream>
#include "Point.hpp"

Point::Point(uint _x, uint _y)
	: x(_x), y(_y)
{}

Point::Point(const Point &orig)
	: Point (orig.x, orig.y)
{}

Point::Point(istream &is)
	: x(0), y(0)
{
	is >> x >> y;
}

Point::~Point()
{}

void Point::setxy(uint _x, uint _y)
{
	x =_x;
	y =_y;
}

bool Point::isOver(uint _x, uint _y)
{
	uint dx = (x < _x ? _x - x : x - _x);
	uint dy = (y < _y ? _y - y : y - _y);

	return (dx <= taille && dy <= taille);
}

void Point::dessiner(EZWindow &w, bool isActive) const
{
	if (isActive)
		w.fillCircle(x-taille, y-taille, x+taille, y+taille);
	else
		w.drawCircle(x-taille, y-taille, x+taille, y+taille);
}

ostream &operator<< (ostream &os, const Point &p)
{
	os << p.x << " " << p.y;
	return os;
}

istream &operator>> (istream &is, Point &p)
{
	is >> p.x >> p.y;
	return is;
}

Point &Point::operator= (const Point &src)
{
	x = src.x;
	y = src.y;
	return *this;
}
