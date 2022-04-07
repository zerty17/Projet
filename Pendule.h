#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Vecteur.h"
#include "Balle.h"
#include "objetmobile.h"
#include "constante.h"


class Pendule : public ObjetMobile{
	public:
	Pendule(double r, double mv, Vecteur v, Vecteur p, double l, double fr, Vecteur o/*=(3)*/, Vecteur direction)
		: ObjetMobile(r, mv,v, p), Longueur(l), frottement(fr), origine(o), d(direction){}
	
	Vecteur evolution() override;
	double get_longueur() const{
		return Longueur;
	}
	Vecteur get_origine() const{
		return origine;
	}
	double get_frottement() const{
		return frottement;
	}
	Vecteur get_d() const{
		return d;
	}
	Vecteur bout_pendule();
	private:
	double Longueur;
	double frottement;
	Vecteur origine;
	Vecteur d;
	
	
};

std::ostream& operator <<(std::ostream& sortie, Pendule& p1);
