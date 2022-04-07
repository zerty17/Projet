#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "Balle.h"
#include "objetmobile.h"
using namespace std;


double ObjetMobile::m()const{
	double m;
	m=((get_rayon())*(get_rayon())*(get_rayon())*(4.0/3)*M_PI*get_rho());		
	return m;
}

double ObjetMobile::get_rayon()const{
	return rayon;
}
	
double ObjetMobile::get_rho()const{
	return rho;
}

double ObjetMobile::get_m()const{
	return m();
}
Vecteur ObjetMobile::get_position() const{
	return P;
}
	
void ObjetMobile::ajoute_force(Vecteur const& df){
		Force += df; 		
}
Vecteur ObjetMobile::get_force() const{
	return Force;
}



//~ void ObjetMobile::set_dP(Vecteur vitesse){
	//~ dP = vitesse;
//~ }



std::ostream& operator<<(std::ostream& out, ObjetMobile const& b1){
	out<<b1.get_m()<< "# masse" << endl;
	out<<b1.get_rayon()<< "# rayon"<< endl;
	out<<b1.get_rho()<< "# masse volumique"<<endl;
	out<<b1.get_position()<< "# position"<< endl;
	out<<b1.get_Vitesse()<< "# vitesse"<<endl;
	out<<b1.get_force()<< "# force"<<endl;
	return out;
}



