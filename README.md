# TSP
## LE PROJET
Le probl�me du voyageur de commerce (*Travelling Salesman Problem*) 
est un c�l�bre probl�me d'algorithmique. Un voyageur de commerce r�sidant
dans une ville _V0_ part faire la tourn� de ses clients. Supposons qu'il 
doive rencontrer _n_ clients _c1_,...,_cn_ r�sidant dans _n_ villes 
_v1_,....,_vn_ telles que _ci_ habite � _vi_ pour _i = 1...n_. On suppose
que quels qe soient _i_ et _j_ tels que _0 <= i < j <= n_, _vi_ et _vj_ sont 
distinctes et il existe une route reliant _vi_ et _vj_ (Le graphe _v0,...,vn_
est complet). Le voyageur part de sa ville de r�sidence _v0_, r�alise la tourn�e
de ses clients puis reviens � _v0_. Pour optimiser le trajet total parcouru, le
voyageur ne parcourt jamais deux fois la m�me route.

Quel itin�raire doit-il emprunter pour minimiser la distance totale parcourue ?

Ce probl�me n'a, dans le cas g�n�ral, pas de solution de complexit� polynomiale
connue. En effet, le seul algorithme exact connu consiste � �valuer les _n!/2_
itin�raires possibles. Cette solution n'est pas r�aliste pour _n_ grand (10!/2 > 10^6)

__Remarque__: Tout chemin ferm� passant exactement une seul fois par chaque sommet
_v0,...,vn_ est dit circuit hamiltonien du graphe complet(_v0,...,vn_)