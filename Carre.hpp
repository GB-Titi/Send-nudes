#ifndef CARRE_HPP
#define CARRE_HPP

#include "Forme.hpp"

class Carre : public Forme {

  private :
		uint cote; // Côté du carré.
		void ecrire (ostream &os) const override;

  public :
		Carre(ulong color, int thick, bool remplir, uint x, uint y, uint cote);
        Carre(istream &is);
        ~Carre();
        
        // Fonction dessiner pour l'ellipse.
		//
        virtual void dessiner(EZWindow &w/*, bool isActive = false*/) const;

		// Fonction retournant la valeur du côté du carré.
		//
		inline uint getCote() const {return cote;}		
		
		// Fonction permettant de modifier la valeur du côté du carré.
		//
        inline void setCote (uint _cote) { cote = _cote;}
        
        double perimetre() const override;
};

#endif
