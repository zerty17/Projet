#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "Balle.h"
#include "constante.h"
#include "ChampForces.h"
using namespace std;


void ChampForces::agit_sur(ObjetMobile& obj,bool test)const{
	Vecteur force(0);
		if (test) {
			force=g*(obj.get_m()-(4.0/3*M_PI*rhoair*(obj.get_rayon())*(obj.get_rayon())*(obj.get_rayon())));
			obj.ajoute_force(force);}
			
			else {
				force=g*obj.get_m();
				obj.ajoute_force(force);
			}
		}
ostream& operator<<(ostream& out, ChampForces const& champ){// en externe, on definit l'operateur d'affichage
	out << champ.get_intensite() <<"  ";
	/*out << endl;*/
	return out;
}
