#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Vecteur.h"



class ObjetMobile {
	public : 
	// constructeurs
		ObjetMobile(double r, double mv, Vecteur dP, Vecteur f, Vecteur P)
			:rayon(r), rho(mv), dP(dP), Force(f), P(P){}
		ObjetMobile(double r, double mv, Vecteur dP, Vecteur P)
			:rayon(r), rho(mv), dP(dP),P(P),Force(3){}
	
			
	// operateurs
	
	//Modificateurs
		//~ void set_dP(Vecteur vitesse);
		void set_vitesse(Vecteur v) {
			dP=v;
		}
		void set_position(Vecteur p) {
			P=p;
		}
		virtual Vecteur evolution() =0;
		
	//accesseurs
		Vecteur get_Param()const{
			return P;
		}
		Vecteur get_Vitesse()const{
			return dP;
		}

		double get_rayon() const;
		double get_rho()const;
		double get_m()const;
		Vecteur get_force() const;
		void ajoute_force(Vecteur const& df);
		Vecteur get_position() const;
	
	private :
	//attributs
		double rayon;
		double rho;
		Vecteur dP;
		Vecteur Force;
		Vecteur P;
	// methodes
		double m()const;
};

//std::ostream& operator<<(std::ostream& out, ObjetMobile const& objet1);
std::ostream& operator<<(std::ostream& out, ObjetMobile const& b1);

