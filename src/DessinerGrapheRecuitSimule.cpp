#pragma once
#include "DessinGraphe.h"
#include "DessinerGrapheRecuitSimule.h"

void DessinerGrapheRecuitSimule::ecritSommet(ofstream& of, const Graphe<InfoAreteCarte, InfoSommetCarte>& graphe, const double & rayonSommet, const string& couleur) {
	PElement<Sommet<InfoSommetCarte>>* l;
	for (l = graphe.)
}

void DessinerGrapheRecuitSimule::ecritAretes(ofstream& of, const Graphe<InfoAreteCarte, InfoSommetCarte>& graphe, const string& couleur) {

}

void DessinerGrapheRecuitSimule::ecritGraphe(ofstream& of,
	Graphe<InfoAreteCarte, InfoSommetCarte>& graphe,
	const Vector2D& coinHD, const Vector2D& coinBG,
	const string& couleurRepere, const double& rayonSommet,
	const string& couleurSommets, const string& couleurAretes) {

}