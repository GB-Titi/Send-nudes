#ifndef CERCLE_HPP
#define CERCLE_HPP

#include "Forme.hpp"

class Cercle : public Forme {

	private :
		uint diametre; // Diamètre du cercle.
		void ecrire (ostream &os) const override;

	public :
		Cercle(ulong color, int thick, bool remplir, uint x, uint y, uint diametre);
		Cercle(istream &is);
		~Cercle();
		
		// Fonction dessiner pour l'ellipse.
		//
		virtual void dessiner(EZWindow &w/*, bool isActive = false*/) const;
		
		// Fonction retournant le diamètre du cercle.
		//
		inline uint getDiametre() const {return diametre;}
		
		// Fonction permettant de modifier le diamètre du cercle.
		//
		inline void setDiametre (uint _diametre) { diametre = _diametre;}
		
		double perimetre() const override;
};

#endif
