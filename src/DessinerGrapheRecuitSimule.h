#pragma once
#include "Graphe.h"
#include "InfoAreteCarte.h"
#include "InfoSommetCarte.h"
#include "Vector2D.h"
#include <string>
using namespace std;

class DessinerGrapheRecuitSimule {
public:
	static void ecritSommet(ofstream& of, const Graphe<InfoAreteCarte, InfoSommetCarte>& graphe, const double & rayonSommet, const string& couleur);
	static void ecritAretes(ofstream& of, const Graphe<InfoAreteCarte, InfoSommetCarte>& graphe, const string& couleur);

	static void ecritGraphe(ofstream& of, 
		Graphe<InfoAreteCarte, InfoSommetCarte>& graphe, 
		const Vector2D& coinHD, const Vector2D& coinBG, 
		const string& couleurRepere, const double& rayonSommet, 
		const string& couleurSommets, const string& couleurAretes);
};