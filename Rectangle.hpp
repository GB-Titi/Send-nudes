#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Forme.hpp"

class Rectangle : public Forme
{
	private :
		uint hauteur; // Hauteur du rectangle.
		uint largeur; // Largeur du rectangle.
		void ecrire (ostream &os) const override;
		
	public :
		Rectangle(ulong color, int thick, bool remplir, uint x, uint y, uint largeur, uint hauteur);
		Rectangle(istream &is);
		~Rectangle();
		
		// Fonction dessiner pour le rectangle.
		//
		virtual void dessiner (EZWindow &fenetre/*, bool isActive = false*/) const;
		
		// Fonction retournant la hauteur du rectangle.
		//
		inline uint getHauteur () const { return hauteur; }
		
		// Fonction permettant de modifier la hauteur du rectangle.
		//
		inline void setHauteur (uint _hauteur) { hauteur = _hauteur; }
		
		// Fonction retournant la largeur du rectangle.
		//
		inline uint getLargeur () const {return largeur;}
		
		// Fonction permettant de modifier la largeur du rectangle.
		//
		inline void setLargeur (uint _largeur) { largeur = _largeur; }
		
		double perimetre () const override;
};
#endif
