#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "Forme.hpp"

class Ellipse : public Forme {
	private :
		uint demiHauteur;
		uint demiLargeur;
		void ecrire (ostream &os) const override;

	public :
		Ellipse(ulong color, int thick, bool remplir, uint x, uint y, uint demiHauteur, uint demiLargeur);
		Ellipse(istream &is);
		~Ellipse();
		virtual void dessiner (EZWindow &fenetre, bool isActive = false) const;
		inline uint getDemiLargeur () const {return demiLargeur;}
		inline void setDemiLargeur (uint _demiLargeur) { demiLargeur = _demiLargeur; }
		inline uint getDemiHauteur () const { return demiHauteur; }
		inline void setDemiHauteur (uint _demiHauteur) { demiHauteur = _demiHauteur; }
		double perimetre () const override;
};
#endif
