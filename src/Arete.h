#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include "GElement.h"
#include "Sommet.h"
#include "Erreur.h"
using namespace std;

template <class S, class T>
class Arete :
	public GElement{
public:
	Sommet<T>* _debut;
	Sommet<T>*_fin;
	S _v; //instance de la classe générique T

	Arete(int clef, Sommet<T>* debut, Sommet<T>* fin,const S& v) : GElement(clef), _debut(debut), _fin(fin), _v(v){
		// Augmenter les degre des sommet
		_debut->_degre++;
		_fin->_degre++;
	}
	~Arete(){
		_debut->_degre--;
		_fin->_degre--;
	}
	operator string() const { ostringstream oss; oss << "{" << _debut->_clef << "," << _fin->_clef << "}"; return oss.str(); }
	bool estEgal(const Sommet<T> *s1, const Sommet<T> * s2) const {	return ((_debut == s1 && _fin == s2) || (_debut == s2 && _fin == s1)); }
};
template<class S, class T>
ostream& operator<<(ostream& f, const Arete<S,T> a){ return f << string(a); }

