/* 
 * File:   Trajet.h
 * Author: loft-2015-asus
 *
 * Created on 5 novembre 2015, 21:10
 */

#ifndef TRAJET_H
#define	TRAJET_H
#include "NombreContraint.h"
#include <iostream>
using namespace std;
class  Trajet   { 

public : 

	Trajet(string &villeDep, string &villeAr, int dist);

	string getVilleDepart() const;

	void setVilleDepart(string &villeDepart);

	string getVilleArrivee() const;

	void setVilleArrivee(string &villeArrivee);

	NombreContraint<int> getDistance() const;

	void setDistance(int distance);



	void saisir(istream &cin = cin);

	void afficher(ostream &cout = cout) const;

private :

	string villeDepart;

        const static int DISTANCEMAX = 1000;
        
	string villeArrivee;

	NombreContraint<int> distance;


};


std::ostream& operator<<(std::ostream& flux, const Trajet & t);
std::istream& operator>>(std::istream& flux, Trajet & t);


#endif	/* TRAJET_H */

