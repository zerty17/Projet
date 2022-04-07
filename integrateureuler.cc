#include <iostream>
#include "integrateureuler.h"
using namespace std;


	 void integrateur_euler_ch::integre(ObjetMobile& obj) {
		 obj.set_vitesse(obj.get_Vitesse()+ get_pt()*obj.evolution());
		 obj.set_position(obj.get_position() + get_pt()*obj.get_Vitesse());
	 }
		

