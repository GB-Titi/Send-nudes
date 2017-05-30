#ifndef CARRE_HPP
#define CARRE_HPP

#include "Forme.hpp"

class Carre : public Forme {

  private :
		uint cote;
		void ecrire (ostream &os) const override;

  public :
		Carre(ulong color, int thick, uint x, uint y, uint cote);
        Carre(istream &is);
        ~Carre();
        virtual void dessiner(EZWindow &w, bool isActive = false) const;

        inline uint getCote() const {return cote;}
        inline void setCote (uint _cote) { cote = _cote;}
        double perimetre() const override;
};

#endif
