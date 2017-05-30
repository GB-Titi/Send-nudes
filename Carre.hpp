#ifndef CARRE_HPP
#define CARRE_HPP

#include "Forme.hpp"

class Carre : public Forme {

  private :
		uint cote;
		void ecrire (ostream &os) const override;

  public :
		Carre(ulong color, int thick, bool remplir, uint x, uint y, uint cote);
        Carre(istream &is);
        ~Carre();
        virtual void dessiner(EZWindow &w, bool isActive = false) const;
  		//inline void setRemplir() {if (remplir) remplir = false; else remplir = true;}


        inline uint getCote() const {return cote;}
        inline void setCote (uint _cote) { cote = _cote;}
        double perimetre() const override;
};

#endif
