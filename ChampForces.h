#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Balle.h"
#include "Vecteur.h"

class ChampForces{
	public:
	ChampForces(Vecteur i)
	: intensite(i) {}
	Vecteur get_intensite()const;
	void agit_sur(ObjetMobile& balle,bool test)const;
		
	private:
	Vecteur intensite;
	
};
std::ostream& operator<<(std::ostream& out, ChampForces const& champ);
