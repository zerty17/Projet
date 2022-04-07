#include <iostream>
#include <vector>
#include <cmath>
#include "integrateur.h"
#include "Vecteur.h"
#include "Balle.h"
#include "objetmobile.h"
#include "ChampForces.h"
#include "integrateureuler.h"
using namespace std;

int main(){
	
	integrateur_euler_ch i(0.01);
	Balle b1(0.2, 3, {0.0, 0.1, 0.2}, {0, 0, 0});
	ChampForces f({0.0,0.0,-9.81});
	cout<<f<<endl;
	f.agit_sur(b1, true);
	cout<<b1<<endl;
	i.integre(b1);
	cout<<b1<<endl;
		i.integre(b1);
	cout<<b1<<endl;
		i.integre(b1);
	cout<<b1<<endl;
		i.integre(b1);
	cout<<b1<<endl;
	
	return 0;
};
