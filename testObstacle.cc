/*#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "objetmobile.h"
#include "Balle.h"
#include "ChampForces.h"
#include "obstacle.h"
#include "constante.h"
using namespace std;


int main(){
	// on cree une balle, un plan et un mur brique
	//~ un mur plan
	//~ 0 0 0 # origine plan
	//~ 0 0 1 # normale plan
	Plan p1({0,0,0},{0,0,1});
	//~ un mur brique
	//~ 0 0 0.5 # origine brique
	//~ 0 -0.6 0 # longueur brique
	//~ 0.8 0 0 # largeur brique
	//~ 0.5 # hauteur brique
	Brique br1({0, 0, 0.5}, {0, -0.6, 0}, {0.8, 0, 0}, 0.5);
	//~ une balle
	//~ 0.100530964914873 # masse
	//~ 0.2 # rayon 
	//~ 3 # masse volumique
	//~ 1.2 -0.4 0.3 # position
	//~ 0 0 0 # vitesse
	//~ 0 0 -0.591725259488945 # force
	Balle bal1(0.2, 3, {0, 0, 0}, {1.2, -0.4, 0.3});
	ChampForces c1({0.0,0.0,-9.81});
	cout<< "Nous avons :" << endl;
	cout<< "un champs de force :"<< endl;
	cout<<c1<<endl;
	cout<< "une balle :"<<endl;
	c1.agit_sur(bal1, true);
	cout<<bal1<<endl;
	
	cout << endl;
	cout << "TEST" << endl;
	cout << "# point plus proche plan" ;
	cout << p1.point_plus_proche(bal1) << endl;
	cout << "# distance plan " << p1.distance(bal1)<< endl;
	cout << "# point plus proche brique : " << br1.point_plus_proche(bal1) << endl;
	cout <<  " # distance brique : " << br1.distance(bal1) << endl;
	
	cout << endl;
	cout << "deplacement de la balle en 1.2 -0.4 1.3" << endl;
	bal1.set_position({ 1.2, -0.4, 1.3});
	cout << bal1 << endl;
	
	cout<< endl;
	cout << "tests" << endl;
	cout << "# point plus proche plan" << p1.point_plus_proche(bal1) << endl;
	cout << "# distance plan" << p1.distance(bal1) << endl;
	cout << "# point plus proche brique : " << br1.point_plus_proche(bal1) << endl;
	cout <<  " # distance brique : " << br1.distance(bal1) << endl;
	
	cout << endl;
	cout << "deplacement de la balle en 0.2 -0.4 1.3" << endl;
	bal1.set_position({0.2, -0.4, 1.3});
	cout << bal1 << endl;
	
	cout<< endl;
	cout << "tests" << endl;
	cout << "# point plus proche plan" << p1.point_plus_proche(bal1) << endl;
	cout << "# distance plan" << p1.distance(bal1) << endl;
	cout << "# point plus proche brique : " << br1.point_plus_proche(bal1) << endl;
	cout <<  " # distance brique : " << br1.distance(bal1) << endl;
	
	

//## ETC... TESTEZ AVEC TOUTES LES FACES
	
	
	
	
	
	
	return 0;
}*/
