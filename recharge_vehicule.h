///@file recharge_vehicule.h
///@brief FIchier implémentant la classe de la recharge du véhicule

#ifndef RECHARGE_VEHICULE_H
#define RECHARGE_VEHICULE_H
#include <string>
#include <vector>
#include <iostream>
#include "timer.h"

using namespace std;

/// @class Recharge recharge_vehicule.h 
class Recharge
{
	Timer tim; //< Objet de la classe Timer

  public : 
	Recharge();
	void charge();
	void recharge_vehicule(Timer tim);

	

};
	
#endif // RECHARGE_VEHICULE_H
