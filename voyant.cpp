///@file voyant.cpp
///@brief Fichier implémentant les méthodes de la classe Voyant

#include <iostream>

#include "voyant.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include <unistd.h>

using namespace std;

/// @fn Voyant::Voyant()
/// @brief Constructeur de la classe Voyant
Voyant::Voyant()
{

	entrees *io;
	int shmid;

	io=acces_memoire(&shmid);
	if(io==NULL)
		cout<<"erreur "<<endl;
	io->led_dispo=VERT;
	io->led_charge=OFF;
	io->led_defaut=OFF;
	io->led_prise=OFF;
	io->led_trappe=OFF;
}

/// @fn void Voyant::clignoteDefaut(led couleur, Timer T)
/// @brief Fonction permettant de calculer le temps écouler depuis le temps depart_timer
/// @param couleur variable permettant de définir la couleur de la led
/// @param T Objet de la classe Timer
void Voyant::clignoteDefaut(led couleur, Timer T)
{
	entrees *io;
	int shmid;
	
	io=acces_memoire(&shmid);
	int temps=0;

	T.timer_initialiser();
	while (temps<8) {
		io->led_defaut = couleur;
		sleep(1);	
		io->led_defaut = OFF;
		sleep(1);
		temps=T.timer_valeur();
	}	
}
