///@file lecteurcartes.cpp
///@brief Fichier implémentant les méthodes de la classe LecteurCarte

#include <iostream>
#include "lecteurcarte.h"
#include <lcarte.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

/// @fn LecteurCarte::LecteurCarte()
/// @brief Constructeur de la classe LecteurCarte pour initialiser les ports du lecteurs
LecteurCarte::LecteurCarte()
{
	initialisations_ports();
}

/// @fn void LecteurCarte::lire_carte()
/// @brief Fonction permettant de lire le numéro de la carte
void LecteurCarte::lire_carte()
{	
	cout<<"inserer carte"<<endl;
	attente_insertion_carte();
	_numero=lecture_numero_carte();
	cout<<_numero<<endl;
	cout<<"numero carte : "<<lecture_numero_carte()<<endl;
	cout<<"retirez carte "<<endl;
	attente_retrait_carte();
}

/// @fn void LecteurCarte::setCode(int code)
/// @param code numéro à stocker dans _code
/// @brief Fonction permettant de demander à l'utilisateur d'entrer son code
void LecteurCarte::setCode(int code)
{	cout<<"entrez le code pin :"<<endl;
	cin>>code;
	_code = code;

}

/// @fn int LecteurCarte::getCode()
/// @brief Fonction permettant de retourner _code
/// @return _code
int LecteurCarte::getCode()
{	
	return _code;
}

/// @fn int LecteurCarte::getNumero()
/// @brief Fonction permettant de retourner _numero
/// @return _numero
int LecteurCarte::getNumero()
{	
	return _numero;
}

/// @fn void LecteurCarte::LireFichierClient()
/// @brief Fonction permettant lire et sotcker les numéro de carte et code des clients dans des vecteurs
void LecteurCarte::LireFichierClient()
{
	string line;
	string line2;
	int l1, l2;
	ifstream fichierNum("numero.dat");
	ifstream fichierCode("code.dat");
	
	while(getline(fichierNum,line))
	{ 	istringstream(line)>>l1;
		num.push_back(l1);}
	while(getline(fichierCode,line2))
	{	istringstream(line2)>>l2;
		code.push_back(l2);}

	fichierNum.close();
	fichierCode.close();
	/*for(unsigned int i=0;i<num.size();i++){
		cout<<num[i]<<endl;
		cout<<code[i]<<endl;}*/
}

/// @fn unsigned int LecteurCarte::authentifier_carte()
/// @brief Fonction permettant d'identifier l'indice (ligne) du numéro de la carte s'il existe dans le vecteur num
/// @return L'indice ligne du numéro de la carte
unsigned int LecteurCarte::authentifier_carte()
{ 	
	unsigned int ligne=100;

	for(unsigned int i=0;i<num.size();i++){
		if (num[i]==_numero)
			ligne = i;
	}
	if(ligne==100)
		cout<<"numero carte inconnu"<<endl;
	return ligne;
}

/// @fn int LecteurCarte::authentifier_code(unsigned int ligne, Voyant V)
/// @brief Fonction permettant d'authentifier l'utilisateur
/// @note la led défaut clignote en Vert si l'authentification est réussi sinon elle clignote en rouge
/// @param ligne indice du code correspondant à celui du numero de la carte
/// @param V objet de la classe Voyant
/// @return etat=0 si code faux, etat=1 si code vrai
int LecteurCarte::authentifier_code(unsigned int ligne, Voyant V)
{	int etat=0;
	if (getCode()==code[ligne]){
		cout<<"code bon"<<endl;
		V.clignoteDefaut(VERT, t);
		etat=1;
		}
	else{
		cout<<"code faux"<<endl;
		V.clignoteDefaut(ROUGE, t);
		etat=0;}
	return etat;
}






