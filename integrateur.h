#pragma once 
#include "objetmobile.h"

class integrateur{
	private:
	double pas_temps;
	public:
	integrateur(double pt)
	: pas_temps(pt){}
	double get_pt() const{
		return pas_temps;
	}
	virtual void integre(ObjetMobile& obj) =0;
	

};
