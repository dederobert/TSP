#pragma once
#include "Graphe.h"
#include "InfoAreteCarte.h"
#include "InfoSommetCarte.h"
#include "Vector2D.h"
#include <string>
using namespace std;

/**
* Permet de dessiner un graphe en utilisant le programme BSpline
*/
class DessinerGrapheRecuitSimule {
public:
	/**
	* Ecrit tout les sommets du graphe dans le fichier de sortie
	* @param of Fichier de sortie
	* @param graphe Graphe dont les sommets sont à dessiner
	* @param rayonSommet Taille des sommets sur le resultat
	* @param couleur Couleur du sommet sur le resultat
	*/
	static void ecritSommet(ofstream& of, const Graphe<InfoAreteCarte, InfoSommetCarte>& graphe, const double & rayonSommet, const string& couleur);
	/**
	* Ecrit toute les aretes du graphe dans le fichier de sortie
	* @param of Fichier de sortie
	* @param graphe Graphe dont les aretes sont à ecrire
	* @param couleur Couleur des aretes
	*/
	static void ecritAretes(ofstream& of, const Graphe<InfoAreteCarte, InfoSommetCarte>& graphe, const string& couleur);

	/**
	* Ecrit un graphe dans le fichier de sortie
	* @param of Fichier de sortie
	* @param graphe Graphe à ecrire
	* @param coinHD Coin en haut à droite du repère
	* @param coinBG Coin en bas à gauche du repère
	* @param couleurRepere Couleur du repère
	* @param rayonSommet Rayon des sommets sur le resultat
	* @param couleurSommets Couleur des sommets dans le résultat
	* @param couleurAretes Couleur des aretes dans le resultat
	*/
	static void ecritGraphe(ofstream& of, 
		Graphe<InfoAreteCarte, InfoSommetCarte>& graphe, 
		const Vector2D& coinHD, const Vector2D& coinBG, 
		const string& couleurRepere, const double& rayonSommet, 
		const string& couleurSommets, const string& couleurAretes);
};