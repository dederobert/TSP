#pragma once
#include "InfoAreteCarte.h"
#include <sstream>
/**
	* Cost of the edge <br />
	* @return oss.str() string with the cost
	*/
InfoAreteCarte::operator std::string() const {
	ostringstream oss;
	oss << "cout = " << _cout << endl;
	return oss.str();
}

	/**
	* display with ostream operator <br />
	*/
ostream& operator<<(ostream& f, const InfoAreteCarte& infoAreteCarte) {
	return f << (string)infoAreteCarte;
}
