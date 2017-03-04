#include<math.h>
#include<cstdlib>
#include<ctime>

/**
* Donne un réel aléatoire dans [0,1]
* @return valeur aléatoir dans [0,1]
*/
double tirage01() {
	double t = rand();
	return t / RAND_MAX;
}

template<class S>
S recuitSimule(const double &tInitial, const double &tFinal, 
	const int &nombreTentativeMax, const int &nombreSuccesMax, 
	const S &s0, double (*cout1)(const S &s), S (*changementAlea)(const S &s), 
	double(*succ)(const double &d)) {
	
	double t = tInitial;
	S s = s0;
	S sBest = s0;
	int nombreTentatives;
	int nombreSucces;

	while (t > tFinal) {
		nombreTentatives = 0;
		nombreSucces = 0;
		while (nombreTentatives < nombreTentativeMax && nombreSucces < nombreSuccesMax) {
			nombreTentatives++;
			S sPrecedente = s;
			s = changementAlea(s);
			if (cout1(s) < cout1(sPrecedente)) {
				nombreSucces++;
				if (cout1(s) < cout1(sBest)) sBest = s;
			} else{
				double v = tirage01();
				double deltaCout = cout1(s) - cout1(sPrecedente);

				if (v < exp(-(deltaCout / t))) nombreSucces++;
				else s = sPrecedente;
			}
		}
		if (nombreSucces = 0) return sBest;
		t = succ(t);
	}
	return sBest;
}