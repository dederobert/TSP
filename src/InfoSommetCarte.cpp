#pragma once
#include "InfoSommetCarte.h"
#include <sstream>
/**
	* iformation : name and position of the vertex <br />
	*/
InfoSommetCarte::operator std::string() const {
	ostringstream oss;
	oss << "nom = " << _nom << ", position = " << _position << endl;
	return oss.str();
}

/**
	* display with ostream operator <br />
	*/
ostream& operator<< (ostream& os, const InfoSommetCarte& infoSommetCarte) {
	return os << (string)infoSommetCarte;
}
