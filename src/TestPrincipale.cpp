#pragma once
#include <fstream>
#include <iostream>
#include <string>

#include "Graphe.h"
#include "DessinerGrapheRecuitSimule.h"
#include "OutilsCarteRecruitSimule.h"
#include "Vector2D.h"
#include "recuitSimule.h"

using namespace std;

double fCout(const Graphe<InfoAreteCarte, InfoSommetCarte> &g) {
	double coutTotal = 0;
	for (PElement<Arete<InfoAreteCarte,InfoSommetCarte>>* l = g._lArete; l=l->_s;)
		coutTotal += l->_v->_v._cout;
	return coutTotal;
}
Graphe<InfoAreteCarte, InfoSommetCarte> changement(const Graphe<InfoAreteCarte, InfoSommetCarte> &g) {
	return Graphe<InfoAreteCarte, InfoSommetCarte>();
}
double succ(const double &d) {
	return d -1;
}

const double tInitiale = 10;
const double tFinal = 100;
const int nbTentative = 100;
const int nbSucces = 50;

int main() {

	/*****************************************************\
	*			CONSTRUCTION DU GRAHE DE TEST			  *
	\*****************************************************/

	//Les sommets
	Sommet<InfoSommetCarte>* s0;
	Sommet<InfoSommetCarte>* s1;
	Sommet<InfoSommetCarte>* s2;
	Sommet<InfoSommetCarte>* s3;
	Sommet<InfoSommetCarte>* s4;
	Sommet<InfoSommetCarte>* s5;

	// Le graphe
	Graphe<InfoAreteCarte, InfoSommetCarte>* G = new Graphe<InfoAreteCarte, InfoSommetCarte>();
	s0 = G->creerSommet(InfoSommetCarte("s0", Vector2D(1,2)));
	s1 = G->creerSommet(InfoSommetCarte("s1", Vector2D(3,1)));
	s2 = G->creerSommet(InfoSommetCarte("S2", Vector2D(5,2)));
	s3 = G->creerSommet(InfoSommetCarte("s3", Vector2D(5,3)));
	s4 = G->creerSommet(InfoSommetCarte("s4", Vector2D(3,4)));
	s5 = G->creerSommet(InfoSommetCarte("s5", Vector2D(1,3)));
	
	//Les Aretes
	Arete<InfoAreteCarte,InfoSommetCarte>*** aretes = new Arete<InfoAreteCarte,InfoSommetCarte>**[6];
	for (int i =0; i < 6; i++) {
		aretes[i] = new Arete<InfoAreteCarte, InfoSommetCarte>*[6];
 	}
	aretes[0][1] = OutilsCarteRecuitSimule::creerArete(s0, s1, *G);
	aretes[0][2] = OutilsCarteRecuitSimule::creerArete(s0, s2, *G);
	aretes[0][3] = OutilsCarteRecuitSimule::creerArete(s0, s3, *G);
	aretes[0][4] = OutilsCarteRecuitSimule::creerArete(s0, s4, *G);
	aretes[0][5] = OutilsCarteRecuitSimule::creerArete(s0, s5, *G);

	aretes[1][2] = OutilsCarteRecuitSimule::creerArete(s1, s2, *G);
	aretes[1][3] = OutilsCarteRecuitSimule::creerArete(s1, s3, *G);
	aretes[1][4] = OutilsCarteRecuitSimule::creerArete(s1, s4, *G);
	aretes[1][5] = OutilsCarteRecuitSimule::creerArete(s1, s5, *G);

	aretes[2][3] = OutilsCarteRecuitSimule::creerArete(s2, s3, *G);
	aretes[2][4] = OutilsCarteRecuitSimule::creerArete(s2, s4, *G);
	aretes[2][5] = OutilsCarteRecuitSimule::creerArete(s2, s5, *G);

	aretes[3][4] = OutilsCarteRecuitSimule::creerArete(s3, s4, *G);
	aretes[3][5] = OutilsCarteRecuitSimule::creerArete(s3, s5, *G);

	aretes[4][5] = OutilsCarteRecuitSimule::creerArete(s4, s5, *G);

	/**************************************************\
	*			MISE EN PLACE RECUIT SIMULE			   *
	\**************************************************/

	
	/*Graphe<InfoAreteCarte, InfoSommetCarte> solutionInit;

	Graphe<InfoAreteCarte, InfoSommetCarte> solution = 
		recuitSimule<Graphe<InfoAreteCarte,InfoSommetCarte>>(tInitiale,
		 tFinal, nbTentative, nbSucces, solutionInit, fCout, changement, succ);
*/
	Graphe<InfoAreteCarte, InfoSommetCarte> GEuler = OutilsCarteRecuitSimule::circuitEulerAlea(*G);


	//Affichage du graphe
	cout << *G << endl;

	//Enregistrement dans un fichier
	ofstream fichier("test.txt", ios::out | ios::trunc);
	if (fichier){
	 	DessinerGrapheRecuitSimule::ecritGraphe(fichier,*G, Vector2D(0,5), Vector2D(5,0), "black", 10, "red", "black");
		fichier.close();
	}else
		cerr << "Impossible d'ouvrir le fichier " << endl;

	ofstream fichier2("Euler.txt", ios::out | ios::trunc);
	if (fichier2){
		DessinerGrapheRecuitSimule::ecritGraphe(fichier2,GEuler, Vector2D(0,5),Vector2D(5,0),"black",10,"red","black");
		fichier2.close();
	}
	system("PAUSE");
}