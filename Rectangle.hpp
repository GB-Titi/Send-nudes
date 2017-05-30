#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Forme.hpp"

class Rectangle : public Forme
{
	private :
		uint hauteur;
		uint largeur;
		void ecrire (ostream &os) const override;
		
	public :
		Rectangle(ulong color, int thick, bool remplir, uint x, uint y, uint largeur, uint hauteur);
		Rectangle(istream &is);
		~Rectangle();
		virtual void dessiner (EZWindow &fenetre, bool isActive = false) const;
		//inline void setRemplir() {if (remplir) remplir = false; else remplir = true;}
		inline uint getLargeur () const {return largeur;}
		inline void setLargeur (uint _largeur) { largeur = _largeur; }
		inline uint getHauteur () const { return hauteur; }
		inline void setHauteur (uint _hauteur) { hauteur = _hauteur; }
		double perimetre () const override;
};
#endif
