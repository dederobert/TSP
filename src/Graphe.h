#pragma once
#include "PElement.h"
#include "Arete.h"
#include "Sommet.h"
#include <sstream>

template<class S, class T>
class Graphe{
	PElement<Sommet<T>>* _lSommets;
	PElement<Arete<S, T>>* _lArete;
	int _prochaineClef;
public:
	Graphe() :_prochaineClef(0), _lSommets(NULL), _lArete(NULL) {}
	virtual ~Graphe(){ PElement<Arete<S, T>>::efface2(_lArete); PElement<Sommet<T>>::efface2(_lSommets); } 
	
//	Graphe(const Graphe<S, T> g) :_prochaineClef(g._prochaineClef), _lSommets(g._lSommets), _lArete(g._lArete){}
//	Graphe& operator=(const Graphe<S, T>& g) { return *this; }

	Sommet<T>* creerSommet(const T& info) {
		Sommet<T>* tmp = new Sommet<T>(_prochaineClef++, info);
		_lSommets = new PElement<Sommet<T>>(tmp, _lSommets);
		return tmp;
	}
	Arete < S, T>* creerArete(Sommet<T>* debut, Sommet<T>* fin, const S& info) {
		Arete<S, T>* tmp = new Arete<S, T>(_prochaineClef++, debut, fin, info);
		_lArete = new PElement<Arete<S, T>>(tmp, _lArete);
		return tmp;
	}
	
	int nombreSommets() const {
		return _lSommets->taille();
	}

	int nombreAretes() const {
		return _Arete->taille();
	}

	Arete<S, T>* getAreteParSommets(const Sommet<T>* s1, const Sommet<T>* s2) const {
		for (PElement<Arete<S, T>>* tmp = _lArete; tmp; tmp = tmp->_s){
			if (tmp->_v->estEgal(s1, s2))
				return tmp->_v;
		}
		return NULL;
	}


	PElement<pair<Sommet<T>*, Arete<S, T>*>>* adjacences(const Sommet<T>* sommet) const {
		PElement<pair<Sommet<T>*, Arete<S, T>*>>* xd = NULL;
		for (PElement<Sommet<T>>* tmp = _lSommets; tmp; tmp = tmp->_s) {
			if (tmp->_v != sommet){
				Arete<S,T>* a = getAreteParSommets(tmp->_v, sommet);
				if (a != NULL)
					xd = new PElement<pair<Sommet<T>*, Arete<S, T>*>>(new pair<Sommet<T>*, Arete<S, T>*>(tmp->_v, a), xd);
			}
		}
		return xd;
	}

	operator string() const { ostringstream oss; oss << "Graphe sommets " << _lSommets << ", aretes " << _lArete; return oss.str(); }
};

template<class S, class T>
ostream& operator<<(ostream& f, const Graphe<S, T>& g) {
	return f << string(g);
}