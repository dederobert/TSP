#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include "GElement.h"
#include "Sommet.h"
#include "Erreur.h"
using namespace std;

/**
* Represent a edge in graphe <br />
* A edge is two vertices pointer and a value
*/
template <typename S, typename T>
class Arete :
	public GElement{
public:
	Sommet<T>* _debut; /**< The start-vertex's edge */
	Sommet<T>* _fin; /**< The end-vertex's edge  */
	S _v; /**< Generique class S instance*/
	string _color;

	/**
	* Constructor <br />
	* @param clef The edge key
	* @param debut The start-vertex's edge
	* @param fin The end-vertex's edge
	* @param v The edge value
	*/
	Arete(int clef, Sommet<T>* debut, Sommet<T>* fin,const S& v, const string &color = "black") : GElement(clef), _debut(debut), _fin(fin), _v(v),_color(color){
		// Augmenter les degre des sommet
		_debut->_degre++;
		_fin->_degre++;
	}
	/**
	* Destructor<br />
	*/
	~Arete(){
		_debut->_degre--;
		_fin->_degre--;
	}
	/**
	* Converte edge to string
	* @return A string represent string
	*/
	operator string() const { 
		ostringstream oss; 
		oss << "{" << _debut->_v << "," << _fin->_v << "}{" << _debut << "," << _fin << "}";
		return oss.str(); }
	
	/**
	* Check if two edges are equals
	* @param s1 The edge-to-compare vertex
	* @param s2 The edge-to-compare vertex
	*/
	bool estEgal(const Sommet<T> *s1, const Sommet<T> * s2) const { return ((_debut == s1 && _fin == s2) || (_debut == s2 && _fin == s1)); }
};
/**
* Use to print a edge
* @param f The used flux
*/
template<class S, class T>
ostream& operator<<(ostream& f, const Arete<S,T> a){ return f << string(a); }

