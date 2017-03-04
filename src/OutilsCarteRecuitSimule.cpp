#pragma once
#include <time.h>
#include <cstdlib>
#include <iostream>
#include "Vector2D.h"
#include "OutilsCarteRecruitSimule.h"
#include "AlgebreLineaire.h"

double OutilsCarteRecuitSimule::distance(const Sommet<InfoSommetCarte>* s1, const Sommet<InfoSommetCarte>* s2){
	return norme(s1->_v._position, s2->_v._position);
}

Arete<InfoAreteCarte, InfoSommetCarte>* OutilsCarteRecuitSimule::creerArete(Sommet<InfoSommetCarte>* sA, Sommet<InfoSommetCarte>* sB, Graphe<InfoAreteCarte, InfoSommetCarte>& graphe) {
	return graphe.creerArete(sA, sB, InfoAreteCarte(OutilsCarteRecuitSimule::distance(sA, sB)));
}

int alea(int bs) {
	return (rand() % bs);
}

Graphe<InfoAreteCarte,InfoSommetCarte>* OutilsCarteRecuitSimule::circuitEulerAlea(const Graphe<InfoAreteCarte, InfoSommetCarte> &g) {
	srand(time(NULL));
	Graphe<InfoAreteCarte, InfoSommetCarte>* ret = new Graphe<InfoAreteCarte,InfoSommetCarte>();
	Sommet<InfoSommetCarte>** sommets = new Sommet<InfoSommetCarte>*[g.nombreSommets()];
	int* entiers = new int[g.nombreSommets()+1];
	
	PElement<Sommet<InfoSommetCarte>>* l = g._lSommets;

	for (int i = 0; i < g.nombreSommets(); i++){
		ret->_lSommets = new PElement<Sommet<InfoSommetCarte>>(l->_v, ret->_lSommets);
		sommets[i] = l->_v;
		entiers[i] = i;
		l = l->_s;
	}
	
	for (int k = 0; k < g.nombreSommets(); k++) {
		int alea1 = alea(g.nombreSommets());
		int alea2 = alea(g.nombreSommets());
		int tmp = entiers[alea1];
		entiers[alea1] = entiers[alea2];
		entiers[alea2] = tmp;
	}
	
	entiers[g.nombreSommets()] = entiers[0];
	

	for (int j = 0; j < g.nombreSommets(); j++) {
		OutilsCarteRecuitSimule::creerArete(sommets[entiers[j]], sommets[entiers[j+1]], *ret);
	}
	delete[] entiers;
	delete[] sommets;
	return ret;
}

