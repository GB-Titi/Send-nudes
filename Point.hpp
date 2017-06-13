#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "ez-draw++.hpp"

using namespace std;
 
typedef unsigned int uint;
typedef unsigned long int ulong;
 
class Point {
	 
	private :
		static const uint taille = 3; // Est utilisé pour dessiner le point. 
		uint x, y; // Les coordonnées du point (x = abscisse, y = ordonnée).
	
	public :
		Point (uint x, uint y);
		Point (const Point &org);
		Point (istream &is);
		~Point();
		
		// Fonction retournant l'abscisse du point.
		//
		inline uint getx() const {return x;};
		
		// Fonction retournant l'ordonnée du point.
		//
		inline uint gety() const {return y;};
		
		// Fonction permettant de modifier les coordonnées d'un point.
		//
		void setxy (uint x, uint y);
		
		// Fonction retournant un booléen : vrai si les coordonnées passées en paramètre se situent à l'intérieur du cercle représentant un point et faux le cas contraire.
		//
		bool isOver (uint _x, uint _y);
		
		// Fonction permettant de représenter un point sous la forme d'un cercle.
		//
		void dessiner (EZWindow &w, bool isActive = false) const;
		
		// Opérateur << pour la classe Point.
		//
		friend ostream &operator<<(ostream &os, const Point &p);
		
		// Opérateur >> pour la classe Point.
		//
		friend istream &operator>>(istream &is, Point &p);
		
		// Opérateur = pour la classe Point.
		//
		Point &operator= (const Point &src);
};
#endif
