#pragma once
#include <fstream>
#include <iostream>
#include <string>

#include "Graphe.h"
#include "DessinerGrapheRecuitSimule.h"
#include "OutilsCarteRecruitSimule.h"
#include "Vector2D.h"

using namespace std;
int main_test() {
	Sommet<InfoSommetCarte>* s0;
	Sommet<InfoSommetCarte>* s1;
	Sommet<InfoSommetCarte>* s2;
	Sommet<InfoSommetCarte>* s3;
	Sommet<InfoSommetCarte>* s4;
	Sommet<InfoSommetCarte>* s5;

	Graphe<InfoAreteCarte, InfoSommetCarte>* G = new Graphe<InfoAreteCarte, InfoSommetCarte>();
	s0 = G->creerSommet(InfoSommetCarte("s0", Vector2D(1,2)));
	s1 = G->creerSommet(InfoSommetCarte("s1", Vector2D(3,1)));
	s2 = G->creerSommet(InfoSommetCarte("S2", Vector2D(5,2)));
	s3 = G->creerSommet(InfoSommetCarte("s3", Vector2D(5,3)));
	s4 = G->creerSommet(InfoSommetCarte("s4", Vector2D(3,4)));
	s5 = G->creerSommet(InfoSommetCarte("s5", Vector2D(1,3)));

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

	cout << *s0 << endl << endl;

	cout << *G << endl;

	ofstream fichier("test.txt", ios::out | ios::trunc);
	if (fichier){
	 	DessinerGrapheRecuitSimule::ecritGraphe(fichier,*G, Vector2D(0,5), Vector2D(5,0), "black", 10, "red", "black");
		fichier.close();
	}else
		cerr << "Impossible d'ouvrir le fichier " << endl;
	system("PAUSE");
	return 0;
}