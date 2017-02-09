#pragma once
#include "Vector2D.h"
#include "OutilsCarteRecruitSimule.h"
#include "AlgebreLineaire.h"

double OutilsCarteRecuitSimule::distance(const Sommet<InfoSommetCarte>* s1, const Sommet<InfoSommetCarte>* s2){
	return norme(s1->_v._position, s2->_v._position);
}

Arete<InfoAreteCarte, InfoSommetCarte>* OutilsCarteRecuitSimule::creerArete(Sommet<InfoSommetCarte>* sA, Sommet<InfoSommetCarte>* sB, Graphe<InfoAreteCarte, InfoSommetCarte>& graphe) {
	return graphe.creerArete(sA, sB, InfoAreteCarte(OutilsCarteRecuitSimule::distance(sA, sB)));
}