/*#pragma once
#include <cmath>
#include "Vecteur.h"
#include "objetmobile.h"
#include "balle.h"
#include "constante.h"


class Obstacle {
	public:
	// constructeur
		Obstacle(Vecteur p, Vecteur n)
		:position(p), normal(n){}
	// methode 
		void agit_sur(ObjetMobile& ob);// modifie la vitesse de ob1, alors que la methode agit sur de la classe champForce ajoute une force 
		double distance(ObjetMobile& ob)const;// donne la distance de l'objet ob, le caclul est toujours le meme pour tous les objets
		virtual Vecteur point_plus_proche(ObjetMobile const& ob) const = 0;//retourne le point de l'obstacle le plus proche de ob1
	// getteur
	
		Vecteur get_pos()const{
			return position;
		}
		Vecteur get_normal()const{
			return normal;
		}
	private :
		Vecteur position;
		Vecteur normal;
};

class Plan : public Obstacle{
	public :
	//constructeur 
		Plan(Vecteur v1, Vecteur v2)
			:Obstacle(v1,v2){}
	//methodes
		Vecteur point_plus_proche(ObjetMobile const& ob)const override;


};

class Brique : public Obstacle{
	public:
	//constructeur 
		Brique(Vecteur o, Vecteur lon, Vecteur larg, double h)
			:Obstacle(o, (lon^larg)), longueur(lon), hauteur(h), largeur(larg){}
			
		Vecteur point_plus_proche(ObjetMobile const& ob)const override;
			
	private:
		Vecteur longueur;
		double hauteur;
		//Vecteur vech;// ici on definit un attribut pour la direction du vecteur hauteur *h
		Vecteur largeur;
};*/
