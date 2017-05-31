#ifndef CERCLE_HPP
#define CERCLE_HPP

#include "Forme.hpp"

class Cercle : public Forme {

	private :
		uint diametre;
		uint radius;
		void ecrire (ostream &os) const override;

	public :
		Cercle(ulong color, int thick, bool remplir, uint x, uint y, uint diametre);
		Cercle(istream &is);
		~Cercle();
		virtual void dessiner(EZWindow &w, bool isActive = false) const;
		inline uint getRadius() const {return radius;}
		inline uint getDiametre() const {return diametre;}
		inline void setDiametre (uint _diametre) { diametre = _diametre;}
		//inline void setRemplir() {if (remplir) remplir = false; else remplir = true;}
		double perimetre() const override;
};

#endif
