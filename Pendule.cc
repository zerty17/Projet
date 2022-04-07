#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "Pendule.h"
using namespace std;

Vecteur Pendule::evolution(){
	//~ cout << "je suis la" << endl;
	//~ cout <<  -(get_Vitesse().get_valeur(0))*(get_frottement()/get_longueur())  << endl;
	double a(((get_force()*cos(get_position().get_valeur(0))*get_d() -sin(get_position().get_valeur(0))*get_force().get_valeur(2) -(get_Vitesse().get_valeur(0)))*(get_frottement()/get_longueur()))*((1.0/get_m())*get_longueur())); 
	Vecteur cop({a});
	
	return cop;
}

Vecteur Pendule::bout_pendule(){
	Vecteur retour(0);
	Vecteur pos3({0,0,1});
	retour = get_origine()+get_longueur()*cos(get_position().get_valeur(0))*pos3+get_longueur()*sin(get_position().get_valeur(0))*get_d();
	return retour;
}

std::ostream& operator <<(std::ostream& sortie, Pendule& p1){
	sortie << p1.get_m() <<" # masse pendule"<< endl;
    sortie << p1.get_longueur() << " # longueur pendule" <<endl;
    sortie << p1.get_frottement() <<" # frottement pendule"<< endl;
    sortie << p1.get_origine() << " # origine pendule" << endl;
    sortie << p1.get_d() <<" # direction pendule" << endl;
    sortie << p1.get_position() << "# theta pendule" << endl;
    sortie << p1.get_Vitesse() << "# theta point pendule" << endl;
    sortie << p1.evolution() << " # evolution pendule" << endl;
    sortie << p1.bout_pendule() <<" # position bout pendule" << endl;
    return sortie;
	
}
