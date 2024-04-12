///@file reacharge_vehicule.cpp
///@brief Fichier implémentant les méthodes de la classe Recharge

#include <iostream>

#include "voyant.h"
#include "recharge_vehicule.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include <unistd.h>

/// @fn Recharge::Recharge()
/// @brief Constructeur de la classe Recharge
Recharge::Recharge()
{
	entrees *io;
	int shmid;

	io=acces_memoire(&shmid);

	io->gene_pwm=STOP;
}

/// @fn void Recharge::charge()
/// @brief Fonction permettant de gérer les étapes avant la charge du véhicule
void Recharge::charge(){
	entrees *io;
	int shmid;

	io=acces_memoire(&shmid);
	int stop =0;
	while(io->gene_u!=9){sleep(1);}
	io->led_prise=VERT;
	sleep(1);
	io->led_trappe=OFF;
	sleep(1);
	io->gene_pwm=AC_1K;
	sleep(1);
	while(io->gene_u!=6) {sleep(1);}
	io->contacteur_AC=1;
	sleep(1);
	io->gene_pwm=AC_CL;
	sleep(1);
	while(stop==0){
		if(io->bouton_stop==1)
			stop=1;
		sleep(1);}
	io->gene_pwm=DC;
	while(io->gene_u!=9){sleep(1);}
	io->contacteur_AC=0;
	io->gene_pwm=DC;
	io->led_charge=OFF;

}

/// @fn void Recharge::recharge_vehicule(Timer tim)
/// @brief Fonction permettant de gérer la charge du véhicule
/// @param tim Objet de la classe Timer
void Recharge::recharge_vehicule(Timer tim)
{
	entrees *io;
	int shmid;

	io=acces_memoire(&shmid);
	int temps=0;
	int commencer_charge=0;
	tim.timer_initialiser();
	io->bouton_charge=0;
	while(commencer_charge==0){
		if(io->bouton_charge==1){
			commencer_charge=1;
			io->led_dispo=OFF; 
			io->led_charge=ROUGE;
			io->led_trappe=VERT;  
			io->gene_pwm=DC;
			charge();}
		if(temps>6)
			commencer_charge=1;
		sleep(1);
		temps=tim.timer_valeur();
	}
}








