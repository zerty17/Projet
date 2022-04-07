#pragma once 
#include "objetmobile.h"
#include "integrateur.h"

class integrateur_euler_ch : public integrateur{
	public:
	integrateur_euler_ch(double pt)
	: integrateur(pt){}
	virtual void integre(ObjetMobile& obj) override;
	
};
