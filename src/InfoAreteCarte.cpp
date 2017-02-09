#pragma once
#include "InfoAreteCarte.h"
#include <sstream>

InfoAreteCarte::operator std::string() const {
	ostringstream oss;
	oss << "coût = " << _cout << endl;
	return oss.str();
}

ostream& operator<<(ostream& f, const InfoAreteCarte& infoAreteCarte) {
	return f << (string)infoAreteCarte;
}