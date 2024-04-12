///
///@file borne.cpp
///@brief FIchier implémentant les étapes de la recharge de la borne
///


#include <iostream>
#include "memoire_borne.h"
#include "donnees_borne.h"
#include <string>
#include "lecteurcarte.h"
#include "recharge_vehicule.h"
#include "voyant.h"
#include "timer.h"
#include "reprise.h"
int main()
{

	LecteurCarte lecteurcarte;
	Voyant voyant;
	Recharge recharge;
	Reprise reprise;
	Timer time;
	unsigned int numClient=100;
	unsigned int numActuel=100;
	int code=0;
	int code_correct=0;
	int i=0;

	lecteurcarte.LireFichierClient();
    while (1)
    {	while(code_correct==0){
        lecteurcarte.lire_carte();
	numClient= lecteurcarte.authentifier_carte();

	numActuel=numClient;

	if (numClient != 100)
	{
		
		lecteurcarte.setCode(code);
		code_correct=lecteurcarte.authentifier_code(numClient, voyant);}
		recharge.recharge_vehicule(time);	
		

	}
numClient=100;
		code_correct=0;

while(code_correct==0){
	if(numClient != numActuel){
		if(i>0)
			cout<<"La carte ne correspond pas au véhicule "<<endl;
		lecteurcarte.lire_carte();
		numClient= lecteurcarte.authentifier_carte();
		i++;}

	else{
	lecteurcarte.setCode(code);
	code_correct=lecteurcarte.authentifier_code(numClient, voyant);}
}
	reprise.reprise_vehicule();
	
	
    }

}
