#pragma once
#include <string>
#include <iostream>
using namespace std;

/**
* Edge's informations bind 2 cities on a road map <br />
* Only edge's cost is stored
*/
class InfoAreteCarte {
public:
	double _cout; /**< The edge's cost*/
	/**
	* Constructor
	* @param cout The edge's cost
	*/
	InfoAreteCarte(const double& cout) :_cout(cout){}

	/**
	* Convert edge's information object into string
	*/
	operator string() const;
};
/**
* Use to print edge's information object
* @param f The output used flux
* @param infoAreteCarte The printed object
*/
ostream& operator<<(ostream& f, const InfoAreteCarte& infoAreteCarte);