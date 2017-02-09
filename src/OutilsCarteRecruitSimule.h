#pragma once
#include "Sommet.h"
#include "InfoSommetCarte.h"
#include "Arete.h"
#include "InfoAreteCarte.h"
#include "Graphe.h"

class OutilsCarteRecuitSimule {
public:
	static double distance(const Sommet<InfoSommetCarte>*  s1,
		const Sommet<InfoSommetCarte>* s2);
	static Arete<InfoAreteCarte, InfoSommetCarte>* creerArete(Sommet<InfoSommetCarte>* sA,
		Sommet<InfoSommetCarte>* sB,
		Graphe<InfoAreteCarte, InfoSommetCarte>& graphe);
};