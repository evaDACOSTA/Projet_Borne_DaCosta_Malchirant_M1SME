///@file voyant.h
///@brief FIchier implémentant la classe de voyants

#ifndef VOYANT_H
#define VOYANT_H
#include <iostream>
#include <string>
#include <vector>
#include <memoire_borne.h>
#include "timer.h"


using namespace std;

/// @class Voyant voyant.h 
class Voyant
{
	Timer T; //< Objet de la classe Timer

  public : 
	Voyant();
	void clignoteDefaut(led couleur, Timer T);

	

};

#endif // VOYANT_H
