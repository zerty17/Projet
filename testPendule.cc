#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "objetmobile.h"
#include "Balle.h"
#include "obstacle.h"
#include "constante.h"
#include "Pendule.h"
#include "ChampForces.h"
#include "integrateureuler.h"
using namespace std;

int main(){
	integrateur_euler_ch i(0.01);
	ChampForces f(g);
	Pendule p(1, 0.3/(4*M_PI),{0.0}, {0.4}, 0.2, 0.005, {0.0,2.0,1.0}, {0.0, 1.0, 0.0});
	cout<< f<<endl;
	f.agit_sur(p,false);
	cout<<p<<endl; 
	i.integre(p);
	cout<<p<<endl;
	i.integre(p);
	cout<<p<<endl;
	i.integre(p);
	cout<<p<<endl;
	i.integre(p);
	cout<<p<<endl;
	i.integre(p);
	cout<<p<<endl;
	
	
	return 0;
}
