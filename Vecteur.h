#pragma once
#include <iostream>
#include <vector>
#include <cmath>

class Vecteur {// AATENTION il ne faut pas oublier de supprimer toutes les methodes qui ne servent a rien  car on a des operateurs mtn
	public :
		// constructeur 
		Vecteur(size_t n);
		Vecteur(double a,double b, double c);
		Vecteur(std::initializer_list<double> const& initialiser);
		
		
		// operateurs
		Vecteur& operator+=(Vecteur const& vect2);
		Vecteur& operator-=(Vecteur const& vect2);
		Vecteur& operator*=(double n);
		// definir un operateur de copie ex : vect3(vect1); copie de v1 dans v3


		
		//accesseur
		void affiche() const; // permet d'afficher avec un cout un objet vecteur
		bool compare (Vecteur vect2) const; // pemret de tester l'egalite d'un vecteur avec un autre 
		std::vector<double> get_vecteur()const{ // on a besoin d'une methode qui nous retourne le vecteur
		return vect;
		}
		double get_valeur(size_t i)const{// cette méthode nous retourne la valeur a l'indice i, on commence a numeroter a partir de 0
		return vect[i];
		}
		size_t get_taille()const{// cette méthode nous retourne la taille des objets vecteur
			return vect.size();
		}
			
		// prototype des methodes
		Vecteur addition(Vecteur autre) const;
		Vecteur soustraction(Vecteur autre) const;
		Vecteur oppose() const;
		Vecteur mult(double x) const;
		double prod_scal(Vecteur autre) const;
		Vecteur prod_vect(Vecteur autre) const;
		double norme() const;
		double norme2() const;
		Vecteur unitaire() const; // ATTENTION JSP SI CA DOIT ETRE UN VECTEUR OU DOUBLE OU AUTRE 
		size_t taillemax(Vecteur v1, Vecteur v2);// nous renvoies la taille du vecteur le plus grand entre les deux
		
		//manipulateur
		void augmente(double valeur) ; // permet d'ajouter une dimension au vecteur et une valeur de cette dimension 
		void set_coord(size_t i, double valeur); //permettant de modifier la valeur d'une coordonnée du vecteur, on commence a partir de 0.
	

	
	private :
		std::vector <double > vect;
};

Vecteur operator+(Vecteur v1, Vecteur const& v2);
Vecteur operator-(Vecteur v1, Vecteur const& v2);
std::ostream& operator<<(std::ostream& out, Vecteur const& v1);
Vecteur operator*(double n, Vecteur v1);
Vecteur operator*(Vecteur v1, double n);
double operator*(Vecteur v1, Vecteur const& v2);
Vecteur operator^(Vecteur v1, Vecteur const& v2);
Vecteur operator~(Vecteur v1);

bool operator==(Vecteur const& v1, Vecteur const& v2);
bool operator!=(Vecteur const& v1, Vecteur const& v2);

// definir l operateur de copie 


