#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "Forme.hpp"

class Ellipse : public Forme {
	private :
		uint demiHauteur; // Demi-hauteur de l'ellipse.
		uint demiLargeur; // Demi-largeur de l'ellipse.
		void ecrire (ostream &os) const override;

	public :
		Ellipse(ulong color, int thick, bool remplir, uint x, uint y, uint demiHauteur, uint demiLargeur);
		Ellipse(istream &is);
		~Ellipse();
		
		// Fonction dessiner pour l'ellipse.
		//
		virtual void dessiner (EZWindow &fenetre/*, bool isActive = false*/) const;
		
		// Fonction retournant la demi-hauteur de l'ellipse.
		//
		inline uint getDemiHauteur () const { return demiHauteur; }
		
		// Fonction permettant de modifier la demi-hauteur de l'ellipse.
		//
		inline void setDemiHauteur (uint _demiHauteur) { demiHauteur = _demiHauteur; }
		
		// Fonction retournant la demi-largeur de l'ellipse.
		//
		inline uint getDemiLargeur () const {return demiLargeur;}
		
		// Fonction permettant de modifier la demi-largeur de l'ellipse.
		//
		inline void setDemiLargeur (uint _demiLargeur) { demiLargeur = _demiLargeur; }
		
		double perimetre () const override;
};
#endif
