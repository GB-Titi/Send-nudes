#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Forme.hpp"

class Triangle : public Forme
{
	private :
		Point ancre2; // Deuxième point du triangle.
		Point ancre3; // Troisième point du triangle.
		void ecrire (ostream &os) const override;

	public :
		Triangle(ulong color, int thick, bool remplir, uint x, uint y, uint x2, uint y2, uint x3, uint y3);
		Triangle(istream &is);
		~Triangle();
		virtual void dessiner (EZWindow &fenetre/*, bool isActive = false*/) const;
		inline const Point &getAncre2() const {return ancre2;}
		inline const Point &getAncre3() const {return ancre3;}		
		inline void setAncre2(uint _x, uint _y) {ancre2.setxy(_x,_y);}
		inline void setAncre3(uint _x, uint _y) {ancre3.setxy(_x,_y);}
		
		double perimetre () const override;
};
#endif
