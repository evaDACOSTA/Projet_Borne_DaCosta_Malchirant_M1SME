///@file lecteurcarte.h
///@brief FIchier implémentant la classe du lecteur de carte

#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H
#include <lcarte.h>
#include <string>
#include <vector>
#include <memoire_borne.h>
#include "timer.h"
#include "voyant.h"

using namespace std;


/// @class LecteurCarte lecteurcarte.h 
class LecteurCarte
{
	
	int _numero, _code; //< Numéro de carte et code de l'utilisateur
	vector<int> num; //< Vecteur de numéro de carte de la base de donnée
	vector<int> code; //< Vecteur de code de la base de donnée
	Timer t; //< Objet de la classe Timer
	Voyant V; //< Objet de la classe Voyant

  public : 
	LecteurCarte();
	void LireFichierClient();
	void initialiser();
	void lire_carte();
	unsigned int authentifier_carte();
	int authentifier_code(unsigned int ligne, Voyant V);
	int getNumero();
	int getCode();
	void setCode(int code);

};

#endif // LECTEURCARTE_H
