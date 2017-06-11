#ifndef CERCLE_HPP
#define CERCLE_HPP

#include "Forme.hpp"

class Cercle : public Forme {

	private :
		uint diametre;
		void ecrire (ostream &os) const override;

	public :
		Cercle(ulong color, int thick, bool remplir, uint x, uint y, uint diametre);
		Cercle(istream &is);
		~Cercle();
		virtual void dessiner(EZWindow &w/*, bool isActive = false*/) const;
		inline uint getDiametre() const {return diametre;}
		inline void setDiametre (uint _diametre) { diametre = _diametre;}
		double perimetre() const override;
};

#endif
