/* 
 * File:   Trajet.cpp
 * Author: loft-2015-asus
 * 
 * Created on 5 novembre 2015, 21:10
 */

#include "Trajet.h"
#include "NombreContraint.h"



//constructor

Trajet::Trajet(string &villeDep, string &villeAr, int dist) 
    : villeDepart(villeDep), villeArrivee(villeAr), distance(dist, 1, DISTANCEMAX)
{}

string Trajet::getVilleDepart() const {

	return this->villeDepart;

}

void Trajet::setVilleDepart(string &villeDepart) {

	this->villeDepart=villeDepart;

}

string Trajet::getVilleArrivee() const {

	return this->villeArrivee;

}

void Trajet::setVilleArrivee(string &villeArrivee) {

	this->villeArrivee=villeArrivee;

}

NombreContraint<int> Trajet::getDistance() const {

	return this->distance;

}

void Trajet::setDistance(int distance) {
    try {
	this->distance.setVal(distance); 
    } catch (exception &e) {
        cout << e.what() << endl;
    }
}

void Trajet::saisir(istream &cin) 
{
    string villeDep;
    string villeArr;
    int distance;
    cout << "Ville depart : ";
    cin >> villeDep;
    setVilleDepart(villeDep);
    cout <<"ville arrivee : ";
    cin >> villeArr;
    setVilleArrivee(villeArr);
    cout << "distance : ";
    cin >> distance;
    try {
        setDistance(distance);
    } catch (exception &e) {
        cout << e.what() << endl;
    }
}

void Trajet::afficher(ostream &cout) const
{
    cout << "VilleDep : " << getVilleDepart() << endl;
    cout << "VilleArr : " << getVilleArrivee() << endl;
    cout << "distance : " << getDistance() << endl;
}


std::ostream& operator<<(std::ostream& flux, Trajet & t) {
	t.afficher(flux);
	return flux;
}

std::istream& operator>>(std::istream& flux, Trajet & t) {
	t.saisir(flux);
	return flux;
}
