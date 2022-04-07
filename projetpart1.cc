#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void Vecteur::affiche() const{ // c'est la methode qui nous permet d'afficher le vecteur 
	for (auto composant : vect) {
			cout << composant << "  "<< endl;
	}
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
	Vecteur vecfinal;
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
	Vecteur vecfinal;
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
	Vecteur vectfinal;
	for(size_t i (0); i <= get_taille(); ++i){// on peut aussi utiliser des for( auto element: ....).....enfaite pas car on a besoin des i 
		vectfinal.augmente((-1)*vect[i]);
	}
	return vectfinal;
}



Vecteur Vecteur::mult(double x) const {
	Vecteur vectfinal;
	for(size_t i (0); i < get_taille(); ++i){// on peut aussi utiliser des for( auto element : ...).....enfaite pas car on a besoin des i 
		vectfinal.augmente(vect[i]*x);
	}
	return vectfinal;
}


double Vecteur::prod_scal(Vecteur autre) const {
	double s(0);
	constexpr int ERREUR(69);
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
	catch(int i) {
		if (i == ERREUR){
		cerr << "Erreur, les deux vecteurs ne sont pas de la meme taille"<< endl;
	}
	}
	return s;// je pense que le return doit etre avant genre 5 lignes au dessus a voir 
}


Vecteur Vecteur::prod_vect(Vecteur autre) const{
	Vecteur vectfinal;
	constexpr int ERREUR(69);
	try {
		if((get_taille()==autre.get_taille())and(get_taille()==3)){
			// je n'arrive pas a obtenir un code avec une boucle for ici. je crois qu'on est oblige de le faire ligne par ligne 
			double x = (vect[1]*autre.get_valeur(2))-(vect[2]*autre.get_valeur(1));
			double y = (vect[2]*autre.get_valeur(0))-(vect[0]*autre.get_valeur(2));
			double z = (vect[0]*autre.get_valeur(1))-(vect[1]*autre.get_valeur(0));
			vectfinal.augmente(x);
			vectfinal.augmente(y);
			vectfinal.augmente(z);
		}
		else {
			throw ERREUR;			
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

double Vecteur::norme()const {
	double s(0);
	for(auto el : vect){
		s+=el*el;
	}
	return (sqrt(s));
}

double Vecteur::norme2() const {
	double s(0);
	for(auto el : vect){
		s+=el*el;
	}
	return (s);// ATTENTION VOIR NOTE DANS LE PDF DU PROF J'AI PAS CAPTE
} 

Vecteur Vecteur::unitaire() const{
	Vecteur vectfinal;
	for(size_t i (0); i < get_taille(); ++i){
		vectfinal.augmente((vect[i]/norme())); //ET JSP SI CEST CETTE FORMULE QUI FAUT UTILISER
	}
	return vectfinal;
}




// TEST
int main(){
	/*
Vecteur vect1;
Vecteur vect2;
Vecteur vect3;
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
return 0; 
}


