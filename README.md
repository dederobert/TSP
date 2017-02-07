# TSP
## LE PROJET
Le problème du voyageur de commerce (*Travelling Salesman Problem*) 
est un célèbre problème d'algorithmique. Un voyageur de commerce résidant
dans une ville _V0_ part faire la tourné de ses clients. Supposons qu'il 
doive rencontrer _n_ clients _c1_,...,_cn_ résidant dans _n_ villes 
_v1_,....,_vn_ telles que _ci_ habite à _vi_ pour _i = 1...n_. On suppose
que quels qe soient _i_ et _j_ tels que _0 <= i < j <= n_, _vi_ et _vj_ sont 
distinctes et il existe une route reliant _vi_ et _vj_ (Le graphe _v0,...,vn_
est complet). Le voyageur part de sa ville de résidence _v0_, réalise la tournée
de ses clients puis reviens à _v0_. Pour optimiser le trajet total parcouru, le
voyageur ne parcourt jamais deux fois la même route.

Quel itinéraire doit-il emprunter pour minimiser la distance totale parcourue ?

Ce problème n'a, dans le cas général, pas de solution de complexité polynomiale
connue. En effet, le seul algorithme exact connu consiste à évaluer les _n!/2_
itinéraires possibles. Cette solution n'est pas réaliste pour _n_ grand (10!/2 > 10^6)

__Remarque__: Tout chemin fermé passant exactement une seul fois par chaque sommet
_v0,...,vn_ est dit circuit hamiltonien du graphe complet(_v0,...,vn_)