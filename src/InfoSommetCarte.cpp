#pragma once
#include "InfoSommetCarte.h"
#include <sstream>

InfoSommetCarte::operator std::string() const {
	ostringstream oss;
	oss << "nom = " << _nom << ", position = " << _position << endl;
	return oss.str();
}

ostream& operator<< (ostream& os, const InfoSommetCarte& infoSommetCarte) {
	return os << (string)infoSommetCarte;
}