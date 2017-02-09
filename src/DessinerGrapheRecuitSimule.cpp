#pragma once
#include "DessinGraphe.h"
#include "DessinerGrapheRecuitSimule.h"

void DessinerGrapheRecuitSimule::ecritSommet(ofstream& of, const Graphe<InfoAreteCarte, InfoSommetCarte>& graphe, const double & rayonSommet, const string& couleur) {
	PElement<Sommet<InfoSommetCarte>>* l;
	for (l = graphe._lSommets; l; l = l->_s){
		InfoSommetCarte* info = &(l->_v->_v);
		of << "point remarquable = " << rayonSommet <<
			" " << couleur << " " << info->_position <<
			" " << info->_nom << info->_position << endl;
	}
}

void DessinerGrapheRecuitSimule::ecritAretes(ofstream& of, const Graphe<InfoAreteCarte, InfoSommetCarte>& graphe, const string& couleur) {
	PElement<Arete<InfoAreteCarte, InfoSommetCarte>> * l;

	for (l = graphe._lArete; l; l = l->_s)
	{
		of << "couleur =  " << couleur << endl;
		of << "nombre de points = 2" << endl;
		of << l->_v->_debut->_v._position << endl;
		of << l->_v->_fin->_v._position << endl;
	}
}

void DessinerGrapheRecuitSimule::ecritGraphe(ofstream& of,
	Graphe<InfoAreteCarte, InfoSommetCarte>& graphe,
	const Vector2D& coinHD, const Vector2D& coinBG,
	const string& couleurRepere, const double& rayonSommet,
	const string& couleurSommets, const string& couleurAretes) {
	
	string resume;

	resume = "carte routi�re";

	DessinGraphe::ecrireEntete(of, "carte routi�re", "carte routi�re simplifi�e repr�sent�e par un graphe", resume, coinBG, coinHD);

	DessinGraphe::ecritNombrePointsRemarquables(of, 3 + graphe.nombreSommets());
	DessinGraphe::ecritRepere(of, couleurRepere);
	ecritSommet(of, graphe, rayonSommet, couleurSommets);

	DessinGraphe::ecritNombreCourbes(of, graphe.nombreAretes());
	ecritAretes(of, graphe, couleurAretes);
}