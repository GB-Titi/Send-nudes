#ifndef FORME_HPP
#define FORME_HPP

#include "Point.hpp"

class Forme {
	
	private :
		ulong couleur;
		int thickness;
		bool remplir;
		Point ancre;
		bool selected;
		virtual void ecrire(ostream &os) const = 0;

	
	public :
		Forme (ulong color, uint _thickness, bool _remplir, uint x, uint y);
		Forme (const Forme &orig);
		Forme (istream &is);
		virtual ~Forme();
		inline ulong getCouleur() const {return couleur;}
		inline void setCouleur(ulong _couleur) {couleur= _couleur;}
		inline void addThick() {thickness += 1;}
		inline void subThick() {if (thickness>1) thickness -= 1;}
		inline int getThickness() const {return thickness;}
		inline void setThickness(int _thickness) {thickness = _thickness;}
		inline const Point &getAncre() const {return ancre;}
		void setAncre(uint x, uint y);
		bool isOver(uint x, uint y);
			
		virtual void dessiner(EZWindow &fenetre, bool active = false) const;
		inline void Remplir() {if (remplir) remplir = false; else remplir = true;}
		inline void setRemplir(bool _remplir) {remplir = _remplir;}
		inline bool getRemplir() const {return remplir;}
		
		virtual double perimetre () const = 0;
		
		friend ostream &operator<<(ostream &os, const Forme &forme);
		
		static Forme* charger(istream &is);
};

#endif
