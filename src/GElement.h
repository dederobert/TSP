#pragma once
#include <string>
#include <ostream>
#include <sstream>
using namespace std;

/**
* Class generique pour les elements d'un graphe
*/
class GElement{
public:
	int _clef;
	GElement(int clef):_clef(clef) {}
	operator string() const { ostringstream oss; oss << "clef " << _clef; return oss.str(); }
};

inline ostream& operator<<(ostream& f, const GElement& g) {
	return f << string(g);
}