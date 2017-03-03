#pragma once
#include "DessinGraphe.h"

/**
	* Function ecrireEntete <br />
	* @param of ofstream text output
	* @param titre title of the graph
	* @param legende information of the graph
	* @param resume summary
	* @param coinBG
	* @param coinHD
	*/
void DessinGraphe::ecrireEntete(ofstream& of, const string& titre, const string& legende, const string& resume, const Vector2D& coinBG, const Vector2D& coinHD){
	of << "titre = " << titre << endl;
	of << "legende = " << legende << endl;
	of << "resume = " << resume << endl;
	of << "type de scene = courbes" << endl;
	of << "coin bas gauche de la figure sur l'écran en coordonnées monde = " << coinBG << endl;
	of << "coin haut droit de la figure sur l'écran en coordonnées monde = " << coinHD << endl;
}

/**
	* Function ecritNombrePointsRemarquables <br />
	* @param of ofstream text output
	* @param nombrePoints number of points
	*/

void DessinGraphe::ecritNombrePointsRemarquables(ofstream& of, int nombrePoints){
	of << "nombre de points remarquables = " << nombrePoints << endl;
}

/**
	* Function ecritRepere <br />
	* @param of ofstream text output
	* @param couleur color of the graph
	*/
void DessinGraphe::ecritRepere(ofstream& of, const string& couleur) {
	of << "point remarquable = 2 black (0,0) O" << endl;
	of << "point remarquable = 2 black (1,0) 1" << endl;
	of << "point remarquable = 2 black (0,1) 1" << endl;
}

/**
	* Function ecritNombreCourbes <br />
	* @param of ofstream text output
	* @param nombreCourbes
	*/
void DessinGraphe::ecritNombreCourbes(ofstream& of, int nombreCourbes) {
	of << "nombre de courbes = " << nombreCourbes << endl;
}
