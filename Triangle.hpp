#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Forme.hpp"

class Triangle : public Forme
{
	private :
		Point ancre2; // Deuxième sommet du triangle.
		Point ancre3; // Troisième sommet du triangle.
		void ecrire (ostream &os) const override;

	public :
		Triangle(ulong color, int thick, bool remplir, uint x, uint y, uint x2, uint y2, uint x3, uint y3);
		Triangle(istream &is);
		~Triangle();
		
		// Fonction dessiner pour le triangle.
		//
		virtual void dessiner (EZWindow &fenetre/*, bool isActive = false*/) const;
		
		// Fonction retournant les coordonées du deuxième sommet du triangle.
		//
		inline const Point &getAncre2() const {return ancre2;}
		
		// Fonction retournant les coordonées du troisième sommet du triangle.
		//
		inline const Point &getAncre3() const {return ancre3;}
		
		// Fonction permettant de modifier les coordonées du deuxième sommet du triangle.
		//	
		inline void setAncre2(uint _x, uint _y) {ancre2.setxy(_x,_y);}
		
		// Fonction permettant de modifier les coordonées du troisième sommet du triangle.
		//
		inline void setAncre3(uint _x, uint _y) {ancre3.setxy(_x,_y);}
		
		double perimetre () const override;
};
#endif
