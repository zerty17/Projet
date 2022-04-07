#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "Balle.h"
#include "ChampForces.h"
using namespace std;
// TEST
int main(){
	Balle b1(0.2, 3, {0.0, 0.1, 0.2}, {1, 2, 3});
	Balle b2(0.1, 1.1, {0.0, 0.1, 0.0}, {-1, 1.2, 1.3});
	ChampForces c1({0.0,0.0,-9.81});
	cout<< "Nous avons :" << endl;
	cout<< "un champs de force :"<< endl;
	cout<<c1<<endl;
	cout<< "une balle :"<<endl;
	c1.agit_sur(b1,true);
	cout<<b1<<endl;
	cout<< "une autre balle :"<<endl;
	c1.agit_sur(b2, true);
	cout<<b2<<endl;
	

return 0;
}
