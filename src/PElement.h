#pragma once
#include<iostream>
#include<sstream>
#include "Erreur.h"
using namespace std;

/**
* This class represent a list element
* An element is a pointer on the element's value and a pointer on the next element in list
* @version 1.0.0
*/
template<class V>
class PElement {
public:
	/**
	* The element's value
	* @var element value
	*/
	V* _v;

	/**
	* The next element in list
	* @var next list element
	*/
	PElement* _s;
	


	/**
	* Construct a list element with a pointer on value and a pointer on the next list element
	* If the pointer on next list element is NULL or not given, then is the end of the list
	* @param v Value of the list element
	* @parma s Next list element
	*/
	PElement(V* v, PElement* s = NULL) :_v(v), _s(s) {}

	/**
	* Give the length of a given list
	* @param l The pointer on list which need to be calculate the length
	* @throw when the given pointer on list is NULL
	* @return The length of given list
	*/
	static int taille(const PElement<V>* l) { 
		if (l == NULL) return 0;
		return 1 + taille(l->_s);
	}

	/**
	* Convert a list into a string using the given start, end and separator of element
	* @param p The pointer on list which need to be convert
	* @param debut The start of return string, default '('
	* @param separateur The separator put between each element of list, default ','
	* @param fin The end of the return string, default ')'
	* @return the convert string
	*/
	static const string toString(const PElement<V>* p, const char* debut = "( ", const char* separateur = ", ", const char* fin = ")") {
		ostringstream oss;
		oss << debut;
		if (p != NULL){
			for (; p->_s; p = p->_s) {
				oss << *(p->_v);
				oss << separateur;
			}
			oss << *(p->_v);
		}
		oss << fin;
		return oss.str();
	}

	/**
	* Insert the given value in the list, which is order. This function keep the list order
	* @param a The pointer on the value which'll be insert in the list
	* @param l The pointer on the list
	* @param estPlusPetitOuEgal Function which test if its first given element is lower or equals to the second
	*/
	static void insertionOrdonnee(V* a, PElement<V>* &l, bool(*estPlusPetitOuEgal)(const V* a1, const V* a2)) {
		if (l==NULL||estPlusPetitOuEgal(a, l->_v)) {
			// On insert
			l = new PElement<V>(a, l);
		} else{
			//On insertOrdonnee dans la suite
			insertionOrdonnee(a, l->_s, estPlusPetitOuEgal);
		}
	}

	/**
	* Remove the given list's head element
	* @param l The list which pop
	* @return The poped element
	* @throw when the given pointer list is NULL
	*/
	static V* depiler(PElement<V>*& l) {
		if (l != NULL) {
			V* tmp = l->_v;
			PElement<V>* t = l;
			l = l->_s;
			delete t;
			return tmp;
		}else
			throw Erreur("You cannot pop the head element of an NULL pointer list",2)
	}

	static bool retirer(const V* a, PElement<V>*& l) {
		if (l != NULL) {
			if (a == l->_v) {
				PElement<V>* t = l;
				l = l->_s;
				delete t;
				return true;
			}else
				return retirer(a, l->_s);
		}
		return false;
	}

	static void efface1(PElement<V>*& l) {
		if (l != NULL) {
			PElement<V>* t = l;
			l = l->_s;
			delete t;
			efface1(l);
		}
	}

	static void efface2(PElement<V>*& l) {
		if (l != NULL) {
			PElement<V>* t = l;
			delete l->_v;
			l = l->_s;
			delete t;
			efface2(l);
		}
	}

	/**
	* Test if the list has a successor
	* @return true if the list has successor
	*/
	bool hasSucc() const { return _s != NULL; }

	/**
	* It's the operator << use on ostream and list, it's use for printing
	* @param f The stream
	* @param l The pointer on list
	* @return The given stream with inputed the list
	*/
	friend ostream& operator <<(ostream &f, const PElement<V>* l) {
		return f << PElement<V>::toString(l);
	}
};
