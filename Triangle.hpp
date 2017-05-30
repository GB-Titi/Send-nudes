#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Forme.hpp"

class Triangle : public Forme
{
	private :
		uint height;
		uint width;
		void ecrire (ostream &os) const override;

	public :
		Triangle(ulong color, int thick, bool remplir, uint x, uint y, uint x2, uint y2, uint x3, uint y3);
		Triangle(istream &is);
		~Triangle();
		virtual void dessiner (EZWindow &fenetre, bool isActive = false) const;
		//inline void setRemplir() {if (remplir) remplir = false; else remplir = true;}
		inline uint getWidth () const {return width;}
		inline void setWidth (uint _width) { width = _width; }
		inline uint getHeight () const { return height; }
		inline void setHeight (uint _height) { height = _height; }
		double perimetre () const override;
};
#endif
