#pragma once
#include "Graphe.h"
#include "InfoAreteCarte.h"
#include "InfoSommetCarte.h"

Graphe<InfoAreteCarte, InfoSommetCarte>* changement(Graphe<InfoAreteCarte, InfoSommetCarte>* g) {	
	Sommet<InfoSommetCarte> *A, *B, *C = NULL, *D = NULL;
	int i = 0;	
	do{		
		// Choix aléatoire de A et B		
		int j = 0;		
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
			if (++j > (10 * g->nombreAretes())) throw Erreur("Failed to get A and B vertex");		
		} while (g->getAreteParSommets(A, B) || g->getAreteParSommets(B, A) || A == B);				
		C = g->successeur(A)->_v;		
		D = g->successeur(B)->_v;		
		if (++i > (10 * g->nombreAretes())) throw Erreur("Failed to get C and D vertex");	
	} while (C == D);	
	cout << "A " << *A << " B " << *B << " C " << *C << " D " << *D;	
	// Permuttation	
	Arete<InfoAreteCarte, InfoSommetCarte> *AR1, *AR2;
	AR1 = g->getAreteParSommets(A, C);	
	AR2 = g->getAreteParSommets(B, D);	
	//cout << "AC " << *AR1 << endl;	
	//cout << "BD " << *AR2 << endl;	
	AR1->_fin = B;	
	Sommet<InfoSommetCarte>* s0;	
	PElement<Arete<InfoAreteCarte, InfoSommetCarte>>* l, *ls; 	
	l = ls = g->cheminFromTo(C, B);	
	//cout << "chemin avant " << PElement<Arete<InfoAreteCarte,InfoSommetCarte>>::toString(ls) << endl;	
	for (; l; l = l->_s) {		
		//cout << "arete " << *l->_v << endl;		
		s0 = l->_v->_debut;		
		l->_v->_debut = l->_v->_fin;		
		l->_v->_fin = s0;	
	}	
	/*cout << "chemin apres " << PElement<Arete<InfoAreteCarte, InfoSommetCarte>>::toString(ls) << endl;	
	ofstream fichier3("../../bsplines/tmp.txt", ios::out | ios::trunc);	
	if (fichier3){		
		DessinerGrapheRecuitSimule::ecritGraphe(fichier3, *g, Vector2D(0, 5),			
			Vector2D(5, 0), "black", 5, "black", "black");		
		fichier3.close();	
	}	
	system("PAUSE");*/	
	AR2->_debut = C;	
	return g;
}
