/*#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "objetmobile.h"
#include "balle.h"
#include "obstacle.h"
#include "constante.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//CLASSE OBJET GFENERAL//





//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//CLASSE DES OBSTACLES//





//DEFINITION DES METHODES DE OBSTACLE
void Obstacle::agit_sur(ObjetMobile& ob){// a redefinir prochainement 
	cout << "methode agit sur l objet : "<< ob << endl;
}
double Obstacle::distance(ObjetMobile& ob)const{
	// on soustrait le rayon de l'ObjetMobile à (la norme de) l'écart entre son centre et le point_plus_proche() de l'Obstacle
	// une distance peut etre negative->choc
	Vecteur i(0);
	i = get_pos() - point_plus_proche(ob);//ici on appelle une methode virtuelle pure, que l'on va definir plus loin 
	return (i.norme()-ob.get_rayon());
}



//DEFINITION DES METHODES DE PLAN
Vecteur Plan::point_plus_proche(ObjetMobile const& ob)const { // ici on redefinit la methode point_plus_proche pour la classe plan en particulier
	return (ob.get_Param() +(((get_pos() - ob.get_Param())*get_normal())*get_normal()));// ici position est privee 
}




//DEFINITION DES METHODES DE BRIQUE
Vecteur Brique::point_plus_proche(ObjetMobile const& ob)const {
	// l'idée est de faire une liste des distances avec chacun des 6 plans et de ensuie les comparer pour renvoyer la plus petite distance
								//		_
								//	   |_|       c'est la balle
								//      :
	Vecteur v1(0);				//	   _:_____
	Vecteur v2(0);				//	  / : 1  /|
	Vecteur v3(0);				//	 /______/ |
	Vecteur v4(0);				//  |		|6|
	Vecteur v5(0); 				//	|	2   | /
	Vecteur v6(0);				//	|_______|/      et v4 est en face de 1, v5 en face de 2, v8
	Plan p1(get_pos(), ((get_normal()).unitaire()));
	Plan p2(get_pos(), (largeur.unitaire()).oppose());
	Plan p3(get_pos(), (longueur.unitaire()).oppose());
	Plan p4((get_pos()+(longueur)*(longueur.unitaire())), longueur.unitaire());
	Plan p5((get_pos()+(largeur)*(largeur.unitaire())), largeur.unitaire());
	Plan p6((get_pos()-hauteur*(get_normal())),((get_normal()).unitaire()));         // D AILLEURS FAUT VERIFIER CE QU'ON A FAIT POUR LA SOUSTRACTION CAR C MIEUC DE FAIRE LADDITIOPN DE L'OPPOSE 
	// a partir de la on definit les vecteurs (point plus proche) entre chaques plans (1,2,...) et l'objet, a oter que c'est bien la position du point et non la distance entre le point et l'objet, distance que nous allons calculer 
	v1 = p1.point_plus_proche(ob);
	v2 = p2.point_plus_proche(ob);
	v3 = p3.point_plus_proche(ob);
	v4 = p4.point_plus_proche(ob);
	v5 = p5.point_plus_proche(ob);
	v6 = p6.point_plus_proche(ob);
	
	// pour savoir quel est le point le plus proche de l'objet on doit calculer les distances entres les points les plus proche de chaque plan avec l'objet, distances qui sont a chaque fois egale a la norme du vecteur  (positon de l'objet - les vecteurs v1,v2,...(point plus proche))
	double w1(0);	
	double w2(0);	
	double w3(0);	
	double w4(0);	
	double w5(0);	
	double w6(0);	
	w1 = (ob.get_Param()-v1).norme();
	w2 = (ob.get_Param()-v2).norme();
	w3 = (ob.get_Param()-v3).norme();
	w4 = (ob.get_Param()-v5).norme();
	w5 = (ob.get_Param()-v5).norme();
	w6 = (ob.get_Param()-v6).norme();
	
	// mtn on doit trouver quel est la distance la plus petite , la distance minimum
	Vecteur pointplusproche(0);
	double distance_min(w1);
	// voir s'il y a un moyen plus simple 
	pointplusproche = v1;
	if(w2<distance_min){
		pointplusproche = v2;
		distance_min = w2;
	}else if (w3<distance_min){
		pointplusproche = v3;
		distance_min = w3;
	}else if (w4<distance_min){
		pointplusproche = v4;
		distance_min = w4;
	}else if (w5<distance_min){
		pointplusproche = v5;
		distance_min = w5;
	}else if (w6<distance_min){
		pointplusproche = v6;
		distance_min = w6;
	}
	
	
	return pointplusproche;
}


*/

 
 
