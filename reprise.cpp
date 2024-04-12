///@file reprise.cpp
///@brief Fichier implémentant les méthodes de la classe Reprise

#include <iostream>

#include "voyant.h"
#include "reprise.h"

#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include <unistd.h>

/// @fn Reprise::Reprise()
/// @brief Constructeur de la classe Reprise
Reprise::Reprise()
{

}

/// @fn void Reprise::reprise_vehicule()
/// @brief Fonction permettant de gérer la borne lors de la reprise du véhicule
void Reprise::reprise_vehicule()
{
	entrees *io;
	int shmid;

	io=acces_memoire(&shmid);
	io->led_trappe=VERT;
	while(io->gene_u!=12){sleep(1);}
	io->led_prise=OFF;
	io->led_trappe=OFF;
	io->led_dispo=VERT;
}
