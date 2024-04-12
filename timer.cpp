///@file timer.cpp
///@brief Fichier implémentant les méthodes de la classe Timer

#include <iostream>
#include <memoire_borne.h>
#include "timer.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int depart_timer; ///< Stocke la valeur de départ du timer

/// @fn Timer::Timer()
/// @brief Constructeur de la classe Timer
Timer::Timer()
{
	depart_timer=0;
}

/// @fn void Timer::timer_initialiser()
/// @brief Fonction permettant d'intialiser la valeur de départ du timer
void Timer::timer_initialiser()
{
	entrees *io;
	int shmid;
	
	io=acces_memoire(&shmid);
	depart_timer=io->timer_sec;
}

/// @fn int Timer::timer_valeur()
/// @brief Fonction permettant de calculer le temps écouler depuis le temps depart_timer
/// @return temps : temps écoulé
int Timer::timer_valeur()
{
	entrees *io;
	int shmid;
	
	io=acces_memoire(&shmid);
	int temps = 0;
	temps=io->timer_sec-depart_timer;
	return temps;
}


