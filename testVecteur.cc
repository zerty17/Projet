
#include "Vecteur.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// TEST
int main(){
	
	/*Vecteur vect1;
	Vecteur vect2;
	vect1.set_coord(1, 2.0);
	vect1.augmente(1.0); 
	
	vect1.augmente(2.0); vect1.augmente(-0.1);
	vect2.augmente(2.6); vect2.augmente(3.5); vect2.augmente(4.1);
	Vecteur vect3(vect1.addition(vect2));
	cout<< "vect3 :" << endl;
	vect3.affiche();
	Vecteur vecnul;
	vecnul.augmente(0.0); vecnul.augmente(0.0); vecnul.augmente(0.0);
	Vecteur vect4;
	cout<< "soustraction de vec1 avec vecnul" << endl;
	vect4 = vect1.soustraction(vecnul);
	vect1.affiche();

	vect4.affiche();*/

Vecteur vect1({1.0,2.0,-0.1});

cout << " sa mere "<< endl;
Vecteur vect2({2.6,3.5,4.1});
Vecteur vect3(0);
//vect3 = vect1.addition(vect2);
vect3 = vect1 + vect2;
cout << "vect3 = vect1 +vect2 = " << endl;
vect3.affiche();
cout << vect3 << endl;
cout << "okkkkk"<< endl;
cout << vect1<< endl;
Vecteur vect0(3);

Vecteur vect4(0);
vect4 = vect1.soustraction(vect0);
cout << "vect1 est " << endl;
cout << "vect1 - vect0 est = " << endl;
vect4.affiche();
vect4 = vect1.soustraction(vect2);
cout << " vect1 - vect2 est = " << endl;
vect4.affiche();
cout << " la soustraction d'un vect par lui meme i.e. vect1- vect1 est = " << endl;
vect4 = vect1.soustraction(vect1);
vect4.affiche();
Vecteur vect5({2.0,3.0});

cout << "on essaye de faire un prod-vect de 2 vect de dimension differentes : " << endl;
vect5.prod_vect(vect1);
vect4 = vect1.oppose();
cout << "l'oppose du vect1 est = " << endl;
vect4.affiche();
cout << "l'addition d'un opposer est = "<< endl;
vect2.addition(vect4);
vect2.affiche();
cout << "la soustraction est = " << endl;
vect2.soustraction(vect1);
vect2.affiche();
double n;
n= vect1.norme2();
cout << "norme au carré de vec1 :" << n << endl;

/*
/ Cette partie
* (1) pourrait être écrite autrement, par exemple avec des
* manipulateurs (set_coord()) ;
* (2) sera revue dans 2 semaines (constructeurs, surcharge des opérateurs).
*/
/*
// v1 = (1.0, 2.0, -0.1)
vect1.augmente(1.0); vect1.augmente(0.0); vect1.augmente(-0.1);
vect1.set_coord(1, 2.0); // pour tester set_coord()
// v2 = (2.6, 3.5, 4.1)
vect2.augmente(2.6); vect2.augmente(3.5); vect2.augmente(4.1);
vect3 = vect1;
cout << "Vecteur 1 : ";
vect1.affiche();
cout << endl;
cout << "Vecteur 2 : ";
vect2.affiche();
cout << endl;
cout << "Le vecteur 1 est ";
if (vect1.compare(vect2)) {
cout << "égal au";
} else {
cout << "différent du";
}
cout << " vecteur 2," << endl << "et est ";
if (not vect1.compare(vect3)) {
cout << "différent du";
} else {
cout << "égal au";
}
cout << " vecteur 3." << endl;
*/
//FIN DU TEST
/*
double n(9);

Vecteur vec1;
Vecteur vec2;
Vecteur vecf;
vec1.augmente(1);
vec1.augmente(2);
vec2.augmente(1);
vec2.augmente(2);
//vec2.augmente(3);
//vec1.augmente(3);
//vecf=vec1.soustraction(vec2);
n = vec1.prod_scal(vec2);
//cout << n << endl;
//vecf.affiche();
 */
return 0; 
}

