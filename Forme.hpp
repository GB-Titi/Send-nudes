#ifndef FORME_HPP
#define FORME_HPP

#include "Point.hpp"

class Forme
{
	private :
		ulong couleur; // Détermine la couleur de la forme.
		int thickness; // Détermine l'épaisseur de la forme.
		bool remplir;  // Détermine si la forme est pleine ou vide.
		Point ancre; 
		virtual void ecrire(ostream &os) const = 0;

	
	public :
		// Constructeur.
		//
		Forme (ulong color, uint _thickness, bool _remplir, uint x, uint y);
		
		Forme (const Forme &orig);
		Forme (istream &is);
		
		// Destructeur.
		//
		virtual ~Forme();
		
		// Fonction permettant d'obtenir la couleur actuelle d'une forme.
		//
		inline ulong getCouleur() const {return couleur;}
				
		// Fonction permettant de changer la couleur d'une forme.
		//
		inline void setCouleur(ulong _couleur) {couleur= _couleur;}
		
		// Fonction permettant d'augmenter l'épaisseur d'une forme.
		//
		inline void addThick() {thickness += 1;}
		
		// Fonction permettant d'augmenter l'épaisseur d'une forme.
		//
		inline void subThick() {if (thickness>1) thickness -= 1;}
		
		// Fonction permettant d'obtenir l'épaisseur actuelle d'une forme.
		//
		inline int getThickness() const {return thickness;}
		
		// Fonction permettant d'attribuer une épaisseur à une forme.
		//
		inline void setThickness(int _thickness) {thickness = _thickness;}
		
		
		inline const Point &getAncre() const {return ancre;}
		void setAncre(uint x, uint y);
		bool isOver(uint x, uint y);
			
		virtual void dessiner(EZWindow &fenetre/*, bool active = false*/) const;
		
		// Fonction "interrupteur" permettant de remplir ou vider une forme.
		//
		inline void Remplir() {if (remplir) remplir = false; else remplir = true;} 
		
		// Fonction permettant d'attribuer une valeur au booléen "remplir" qui détermine si une forme est pleine ou vide.
		//
		inline void setRemplir(bool _remplir) {remplir = _remplir;} 
		
		// Fonction permettant d'obtenir la valeur actuelle du booléen "remplir" qui détermine si une forme est pleine ou vide.
		//
		inline bool getRemplir() const {return remplir;} 
		
		virtual double perimetre () const = 0;
		
		friend ostream &operator<<(ostream &os, const Forme &forme);
				
		static Forme* charger(istream &is);
};

#endif
