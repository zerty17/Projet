
#include <iostream>
#include <vector>
#include <cmath>
#include "Vecteur.h"
#include "ChampForces.h"
using namespace std;
void Vecteur::affiche() const{ // c'est la methode qui nous permet d'afficher le vecteur 
	for (auto composant : vect) {
			cout << composant << "  "<< endl;
	}
}

size_t taillemax(Vecteur v1, Vecteur v2){// nous avons défini cette methode pour qu'elle nous renvoies la taille du vecteur le plus grand entrre les deux rentrés en paramètres
	size_t taille_max;
	if (v1.get_taille() < v2.get_taille()){
		taille_max = v2.get_taille();
	}
	else{
		taille_max = v1.get_taille();
	}
	return taille_max;
}

bool Vecteur::compare(Vecteur vect2) const{ // cette methode nous permet de comparer 2 vecteur, avec une certaine precision
	if (get_taille() == vect2.get_taille()){ // compare les deux tailles des vecteurs
		size_t nb(0); // variable qui compte le nombre de fois ou des elements correspondants (un dans vect et l'autre dans vect2)
		// ont les memes valeurs 
		for (size_t i(0); i < get_taille(); ++i){	
			if (((vect[i]-vect2.get_valeur(i))<(1e-10)) and ((vect[i]-vect2.get_valeur(i))>-(1e-10))){// attention a la precision 
				nb +=1;
			}
		}
		if (nb == get_taille()){ // si tous les elements et leur correspondant ont les memes valeurs, on renvoie true 
			return true;
		}
	}
	return false ;
}

void Vecteur::augmente(double valeur){// une methode qui nous permet de rajouter une dimension a un vecteur,
	// qui prend comme parametre la valeur que l'on veut rajouter 
	vect.push_back(valeur);
}

void Vecteur::set_coord(size_t i, double valeur){ //methode qui change la valeur d'un composant du vecteur qui est a la place i, on commence a 0
	vect[i] = valeur ;
}

Vecteur Vecteur::addition(Vecteur vect_autre) const{
	Vecteur vecfinal(0);
	size_t taille_max;
	if(get_taille()>=vect_autre.get_taille()){
		taille_max = get_taille();
	}else {
		taille_max = vect_autre.get_taille();
	}
	for (size_t i(0); i < taille_max ; ++i){
		vecfinal.augmente(vect[i]+vect_autre.get_valeur(i));
	}
	return vecfinal;
}

Vecteur Vecteur::soustraction(Vecteur vect_autre) const{
	Vecteur vecfinal(0);
	size_t taille_max;
	if (get_taille() < vect_autre.get_taille()){
		taille_max = vect_autre.get_taille();
	}
	else{
		taille_max = get_taille();
	}
	for (size_t i(0); i < taille_max; ++i){// on peut aussi utiliser des for( auto element : .....)..... c'est meme bien plus pratique mais grosse flemme enfaite pas car on a besoin des i 
		vecfinal.augmente(vect[i]-vect_autre.get_valeur(i));
	}
	return vecfinal;
}


Vecteur Vecteur::oppose() const{
	Vecteur vectfinal(0);
	for(size_t i (0); i <= get_taille(); ++i){// on peut aussi utiliser des for( auto element: ....).....enfaite pas car on a besoin des i 
		vectfinal.augmente((-1)*vect[i]);
	}
	return vectfinal;
}



Vecteur Vecteur::mult(double x) const {
	Vecteur vectfinal(0);
	for(size_t i (0); i < get_taille(); ++i){// on peut aussi utiliser des for( auto element : ...).....enfaite pas car on a besoin des i 
		vectfinal.augmente(vect[i]*x);
	}
	return vectfinal;
}


double Vecteur::prod_scal(Vecteur autre) const {
	double s(0);
	constexpr int ERREUR(69);// mettre les constantes dans un fichier a pars 
	try {
		if(get_taille()==autre.get_taille()){
			for (size_t i  =0; i < get_taille(); ++i){
				s += (vect[i]*autre.get_valeur(i));
			}
		}
		else { 
			throw ERREUR;
			return 0;							// A REVOIR SI ON A BESOIN DE RETURN 0
		}
	}
	catch(int i) {// ATTNTION cela ne sert a rien de rattraper l'exception ici, il faut le faire atre part, voir question 67 sur piazza
		if (i == ERREUR){
		cerr << "Erreur, les deux vecteurs ne sont pas de la meme taille"<< endl;
	}
	}
	return s;// je pense que le return doit etre avant genre 5 lignes au dessus a voir 
}


Vecteur Vecteur::prod_vect(Vecteur autre) const{ // methode qui fait le produit scalaire de deux vecteurs rentrés en arguments 
	Vecteur vectfinal(0);
	constexpr int ERREUR(69);// ATTENTION il faudrait créer un fichier constante et mettre toute les constante dedans, dont celle ci
	try {
		if((get_taille()==autre.get_taille())and(get_taille()==3)){
			double x = (vect[1]*autre.get_valeur(2))-(vect[2]*autre.get_valeur(1));
			double y = (vect[2]*autre.get_valeur(0))-(vect[0]*autre.get_valeur(2));
			double z = (vect[0]*autre.get_valeur(1))-(vect[1]*autre.get_valeur(0));
			vectfinal.augmente(x);
			vectfinal.augmente(y);
			vectfinal.augmente(z);
		}
		else {
			throw ERREUR;// ici on lance une exception si les deux vecteurs ne sont pas de la meme taille 			
			/*return 0;*/				// A REVOIR SI ON A BESOIN DE RETURN 0
		} 
	}
		 catch(int i) {
			if (i == ERREUR){
			cerr << "Erreur, les deux vecteurs ne sont pas de la meme taille"<< endl;
		}
	}
	return vectfinal;
}

double Vecteur::norme()const { // methode qui permet de calculer la norme d'un vecteur 
	double s(0);
	for(auto el : vect){
		s+=el*el;
	}
	return (sqrt(s));
}

double Vecteur::norme2() const {// methode qui permet de calculer le carré de la norme d'un vecteur, nous n'avons pas utilisé la methode norme car elle necessite plus de calcul que juste refaire la somme s 
	double s(0);
	for(auto el : vect){
		s+=el*el;
	}
	return (s);
} 

Vecteur Vecteur::unitaire() const{ // methode qui nous permet de calculer le vecteur unitaire d'un vecteur. 
	Vecteur vectfinal(0);
	for(size_t i (0); i < get_taille(); ++i){
		vectfinal.augmente((vect[i]/norme())); //ET JSP SI CEST CETTE FORMULE QUI FAUT UTILISER
	}
	return vectfinal;
}


Vecteur::Vecteur(size_t n){// constructeur qui permet d'initialiser un vecteur de dimension(rentrée en argument) rempli de 0
	for(size_t i(0); i<n ; ++i){
		augmente(0);
	}
}

Vecteur::Vecteur(double a, double b, double c){// constructeur prenant 3 doubles en arguments et qui construit un vecteur 3d à partir de ces valeurs
	augmente(a);
	augmente(b);
	augmente(c);
}

Vecteur::Vecteur(initializer_list<double> const& initialiser){ // constructeur qui prend une liste d'initialisation, bcp plus pratique pour initialiser les vecteurs 
	for (auto el : initialiser){
		augmente(el);
	}
}

Vecteur& Vecteur::operator+=(Vecteur const& vect2){//en interne, on définit l'operateur += a l'aide du code que nous avions sous la methode addition. 
	size_t taille_max; 
	if(get_taille()>=vect2.get_taille()){
		taille_max = get_taille();
	}else {
		taille_max = vect2.get_taille();
	}
	for (size_t i(0); i < taille_max ; ++i){
		set_coord(i,get_valeur(i)+vect2.get_valeur(i));
	}
	return *this;
}

Vecteur operator+(Vecteur v1, Vecteur const& v2){ //en externe, on definit l'operateur + (interne) a l'aide de l'operateur +=, cela permet de faire moins de copie
	v1+=v2;
	return v1;
}

Vecteur& Vecteur::operator-=(Vecteur const& vect2){// en interne, on definit l'operteur -=  a l'aide du code que nous avions sous la methode soustratcion. 
	size_t taille_max;
	if (get_taille() < vect2.get_taille()){
		taille_max = vect2.get_taille();
	}
	else{
		taille_max = get_taille();
	}
	
	for (size_t i(0); i < taille_max; ++i){
		set_coord(i,get_valeur(i)-vect2.get_valeur(i));
	}
	return *this;
}

Vecteur operator-(Vecteur v1, Vecteur const& v2){// en externe, on definit l'operateur + (interne) a l'aide de l'operateur -=, cela permet de faire moins de copie
	v1-=v2;
	return v1;
}

ostream& operator<<(ostream& out, Vecteur const& v1){// en externe, on definit l'operateur d'affichage
	for (size_t i(0); i< v1.get_taille(); ++i){
			out << v1.get_valeur(i) <<"  ";
	}
	out << endl;
	return out;
}

/*ostream& operator<<(ostream& out, ChampForces const& champ){// en externe, on definit l'operateur d'affichage
	out << champ.get_intensite() <<"  ";
	/*out << endl;
	return out;
}*/
Vecteur ChampForces::get_intensite()const{
		return intensite;
}


Vecteur& Vecteur::operator*=(double n){//entre un vecteur et un entier ex 3*v1 
	for(size_t i (0); i < get_taille(); ++i){// on peut aussi utiliser des for( auto element : ...).....enfaite pas car on a besoin des i 
		set_coord(i, get_valeur(i)*n);
	}	
	return *this;
}


Vecteur operator*(Vecteur v1, double n){// en externe, on definit l'operateur + (interne) a l'aide de l'operateur -=, cela permet de faire moins de copie
	v1*=n;
	return v1;
}

Vecteur operator*(double n, Vecteur v1){// en externe, on definit l'operateur + (interne) a l'aide de l'operateur -=, cela permet de faire moins de copie
	v1*=n;
	return v1;
}// on a defini dans les deux sens pour que cela soit plus pratique et qu'iol n'y ait pas d'erreur par la suite 



double operator*(Vecteur v1, Vecteur const& v2){
	double s(0);
	constexpr int ERREUR(69);// mettre les constantes dans un fichier a pars 
	if(v1.get_taille()==v2.get_taille()){
		for (size_t i  =0; i < v1.get_taille(); ++i){
			s += (v1.get_valeur(i)*v2.get_valeur(i));
					}
	}
	else { 
		throw ERREUR;
		return 0;							// A REVOIR SI ON A BESOIN DE RETURN 0
	}
	
	/*
	catch(int i) {// ATTNTION cela ne sert a rien de rattraper l'exception ici, il faut le faire atre part, voir question 67 sur piazza
		if (i == ERREUR){
		cerr << "Erreur, les deux vecteurs ne sont pas de la meme taille"<< endl;
	}
	
	}*/
	return s;// je pense que le return doit etre avant genre 5 lignes au dessus a voir 
} 




Vecteur operator~(Vecteur v1){// operateur de la methode unitaire
	// ATTENTION JE NE SAIS PAS SI ON PEUT MODIFIER V1 ICI OU ALORS REFAIRE UN VECFINAL
	for(size_t i (0); i < v1.get_taille(); ++i){
		v1.augmente((v1.get_valeur(i)/v1.norme())); //ET JSP SI CEST CETTE FORMULE QUI FAUT UTILISER
	} 
	return v1;
}


Vecteur operator^(Vecteur v1, Vecteur const& v2){
	Vecteur v3(0);
	constexpr int ERREUR(69);
	if((v1.get_taille()==v2.get_taille())and(v1.get_taille()==3)){
			double x = (v1.get_valeur(1)*v2.get_valeur(2))-(v1.get_valeur(2)*v2.get_valeur(1));
			double y = (v1.get_valeur(2)*v2.get_valeur(0))-(v1.get_valeur(0)*v2.get_valeur(2));
			double z = (v1.get_valeur(0)*v2.get_valeur(1))-(v1.get_valeur(1)*v2.get_valeur(0));
			v3.augmente(x);
			v3.augmente(y);
			v3.augmente(z);
		}
		else {
			throw ERREUR;// ici on lance une exception si les deux vecteurs ne sont pas de la meme taille 			
			/*return 0;*/				// A REVOIR SI ON A BESOIN DE RETURN 0
		} 
	
	return v3;
}

bool operator==(Vecteur const& v1, Vecteur const& v2){
	if (v1.get_taille() == v2.get_taille()){ // compare les deux tailles des vecteurs
		size_t nb(0); // variable qui compte le nombre de fois ou des elements correspondants (un dans vect et l'autre dans vect2)
		// ont les memes valeurs 
		for (size_t i(0); i < v1.get_taille(); ++i){	
			if (((v1.get_valeur(i)-v2.get_valeur(i))<(1e-10)) and ((v1.get_valeur(i)-v2.get_valeur(i))>-(1e-10))){// attention a la precision 
				nb +=1;
			}
		}
		if (nb == v1.get_taille()){ // si tous les elements et leur correspondant ont les memes valeurs, on renvoie true 
			return true;
		}
	}
	return false ;
}


bool operator!=(Vecteur const& v1, Vecteur const& v2){
	if(v1==v2){
		return false;
	} else {
		return true;
	}
}
// definir un operateur de copie ex : vect3(vect1); copie de v1 dans v3







