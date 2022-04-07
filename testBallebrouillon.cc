#include <iostream>
#include <vector>
#include <initializer_list>
#include "Vecteur.h"
#include "Balle.cc"
/*#include "Objets.h"*/
using namespace std; 
 
int main() {
	Balle b1, b2({2.0, 3.0, 0.0}, {1.0, 1.5, 1.8}, 0.2, 2.0, {0.0, 0.0, 2.0})
	cout << "Balle 1 : " << endl << b1 << endl;
	cout << "Balle 2 : " << endl << b2 << endl;
	
	Vecteur df({0.5, 0.8, 1.5});
	cout << "Force à ajouter : " << df;
	b1.ajouter_force(df);
	cout << " Résultat : " << endl << b1 << endl << endl;
	
	/*ChampForces f1;
	cout << "Nous avons : " << endl
		 << "Un champ de force : " << endl << f1 << endl;
		 
	cout << "La gravité agit sur la balle 2 : " << endl;
	f1.agit_sur(b2);
	cout << b2 << endl;

	
	return 0;
}*/
