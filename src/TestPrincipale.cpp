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
Graphe<InfoAreteCarte, InfoSommetCarte>* changement(Graphe<InfoAreteCarte, InfoSommetCarte>* g) {

	Sommet<InfoSommetCarte> *A, *B, *C = NULL, *D = NULL;
	int i = 0;
	do{
		PElement<Sommet<InfoSommetCarte>>* l = g->_lSommets;
		for (int iA = rand() % g->nombreSommets(); iA >= 0; iA--) {
			A = l->_v;
			l = l->_s;
		}
		l = g->_lSommets;
		for (int iB = rand() % g->nombreSommets(); iB >= 0; iB--) {
			B = l->_v;
			l = l->_s;
		}
		if (++i > (2 * g->nombreAretes())) throw Erreur("Failed to get A and B vertex");
	} while (g->getAreteParSommets(A, B) || A == B);
	
	i = 0;
	do {
		if ((rand() % 2)) {
			C = g->adjacences(A)->_v->first;
			D = g->adjacences(B)->_v->first;
		}else{
			if (g->adjacences(A)->_s) C = g->adjacences(A)->_s->_v->first; else C = g->adjacences(A)->_v->first;
			if (g->adjacences(B)->_s) D = g->adjacences(B)->_s->_v->first; else D = g->adjacences(B)->_v->first;
		}
		
		if (++i > (2 * g->nombreAretes())) throw Erreur("Failed to change the circuit");
	} while (C==D);

	// Permuttation
	Arete<InfoAreteCarte, InfoSommetCarte> *AR1, *AR2;
	AR1 = g->getAreteParSommets(A, C);
	AR2 = g->getAreteParSommets(B, D);
	
	//g->check();
	
	if (AR1->_debut == A && AR2->_debut == B) {
		AR1->_fin = B;
		AR2->_debut = C;
	}else if (AR1->_debut == C && AR2->_debut == B) {
		AR1->_debut = D;
		AR2->_fin = C;
	}else if (AR1->_debut == C && AR2->_debut == D) {
		AR1->_debut = B;
		AR2->_fin = C;
	}else {
		AR1->_fin = D;
		AR2->_debut = C;
	}
	/*
	if (AR1->_fin == C) AR1->_fin = B; else AR1->_debut = B;
	g->check();
	if (AR2->_debut == B) AR2->_debut = C; else AR2->_fin = C;
	g->check();*/

	

	cout << "A " << *A << " B " << *B << " C " << *C << " D " << *D << endl;
	return g;
}
double succ(const double &d) {
	return d -1;
}

const double tInitiale = 100;
const double tFinal = 10;
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
	
	OutilsCarteRecuitSimule::creerArete(s0, s1, *G);
	OutilsCarteRecuitSimule::creerArete(s0, s2, *G);
	OutilsCarteRecuitSimule::creerArete(s0, s3, *G);
	OutilsCarteRecuitSimule::creerArete(s0, s4, *G);
	OutilsCarteRecuitSimule::creerArete(s0, s5, *G);

	OutilsCarteRecuitSimule::creerArete(s1, s2, *G);
	OutilsCarteRecuitSimule::creerArete(s1, s3, *G);
	OutilsCarteRecuitSimule::creerArete(s1, s4, *G);
	OutilsCarteRecuitSimule::creerArete(s1, s5, *G);

	OutilsCarteRecuitSimule::creerArete(s2, s3, *G);
	OutilsCarteRecuitSimule::creerArete(s2, s4, *G);
	OutilsCarteRecuitSimule::creerArete(s2, s5, *G);

	OutilsCarteRecuitSimule::creerArete(s3, s4, *G);
	OutilsCarteRecuitSimule::creerArete(s3, s5, *G);

	OutilsCarteRecuitSimule::creerArete(s4, s5, *G);

	/**************************************************\
	*			MISE EN PLACE RECUIT SIMULE			   *
	\**************************************************/

	
	
	Graphe<InfoAreteCarte, InfoSommetCarte>* solutionInit = OutilsCarteRecuitSimule::circuitEulerAlea(*G);
	ofstream fichier2("../../bsplines/Euler.txt", ios::out | ios::trunc);
	if (fichier2){
		DessinerGrapheRecuitSimule::ecritGraphe(fichier2, *solutionInit, Vector2D(0, 5),
			Vector2D(5, 0), "black", 5, "black", "black");
		fichier2.close();
	}
	Graphe<InfoAreteCarte, InfoSommetCarte>* solution;
	try {
		solution =
			recuitSimule<Graphe<InfoAreteCarte, InfoSommetCarte>>(tInitiale,
			tFinal, nbTentative, nbSucces, solutionInit, fCout, changement, succ);
	}catch(Erreur e) {
		cerr << e.trace();
		system("PAUSE");
		return e.getCode();
	}
	
	/*
	try {
		for (int i = 0; i < 10; i++)
			solution = changement(solutionInit);
	}
	catch (Erreur e) {
		cerr << e.trace();
		system("PAUSE");
		return e.getCode();
	}*/
	G->colorierChemin(*solution);

	
	//Enregistrement dans un fichier

	

	ofstream fichier3("../../bsplines/Solution.txt", ios::out | ios::trunc);
	if (fichier3){
		DessinerGrapheRecuitSimule::ecritGraphe(fichier3, *G, Vector2D(0, 5),
			Vector2D(5, 0), "black", 5, "black", "black");
		fichier3.close();
	}
	
	system("PAUSE");
}