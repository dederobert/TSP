#pragma once
#include "GElement.h"
#include <ostream>
#include <string>
#include <sstream>
using namespace std;

template<class T>
class Sommet :
	public GElement{
public:
	int _degre;
	T _v;

	Sommet(int clef, const T& v, int degre = 0) :GElement(clef),_degre(degre), _v(v){}
	operator string() const{ ostringstream oss; oss << "Sommet Istance(v) :" << _v << " Degre : " << _degre << " " << GElement::operator string(); return oss.str(); }
};
template<class T>
ostream& operator<<(ostream& f, const Sommet<T> s){ return f << string(s); }