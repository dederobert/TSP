#pragma once
#include <fstream>
#include "Vector2D.h"
#include "Graphe.h"
#include "InfoAreteCarte.h"
#include "InfoSommetCarte.h"

using namespace std;

class DessinGraphe {
public:
	static void ecrireEntete(ofstream& of, const string& titre, const string& legende, const string& resume, const Vector2D& coinBG, const Vector2D& coinHD);
	static void ecritNombrePointsRemarquables(ofstream& of, int nombresPoints);
	static void ecritRepere(ofstream& of, const string& couleur);
	static void ecritNombreCourbes(ofstream& of, int nombreCourbes);
};