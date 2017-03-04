#pragma once
#include "Sommet.h"
#include "InfoSommetCarte.h"
#include "Arete.h"
#include "InfoAreteCarte.h"
#include "Graphe.h"

class OutilsCarteRecuitSimule {
public:
	
	/**
	* distance between two vertex <br />
	*/
	static double distance(const Sommet<InfoSommetCarte>*  s1,
		const Sommet<InfoSommetCarte>* s2);
	
	/**
	* creation of a graph
	* @param sA information of the 1st vertex
	* @param sB information of the 2nd vertex
	* creation of the edge between the 2 vertex
	*/
	static Arete<InfoAreteCarte, InfoSommetCarte>* creerArete(Sommet<InfoSommetCarte>* sA,
		Sommet<InfoSommetCarte>* sB,
		Graphe<InfoAreteCarte, InfoSommetCarte>& graphe);

	static Graphe<InfoAreteCarte,InfoSommetCarte> circuitEulerAlea(const Graphe<InfoAreteCarte, InfoSommetCarte> &g); 
};
