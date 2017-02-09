#pragma once
#include <string>
#include "Vector2D.h"
using namespace std;
class InfoSommetCarte {
public:
	string _nom;
	Vector2D _position;

	InfoSommetCarte(const string& nom, const Vector2D& position) :_nom(nom), _position(position) {}
	operator string() const;
};

ostream& operator<< (ostream& os, const InfoSommetCarte& infoSommetCarte);