/* 
 * File:   Client.cpp
 * Author: loft-2015-asus
 * 
 * Created on 7 novembre 2015, 18:17
 */

#include "Client.h"

Client::Client(string &nom)
: nom(nom) {
}

string Client::getNom() const {
    return this->nom;
}

void Client::setNom(string &nom) {
    this->nom = nom;
}

void Client::saisir(istream &cin) {
    string nm;
    cout << "Nom du client : "; 
    cin >> nm;
    setNom(nm);
}

void Client::afficher(ostream &cout) const {
    cout << "nom du client : " << getNom();
}

std::ostream& operator<<(std::ostream& flux, const Client & c) {
    c.afficher(flux);
    return flux;
}

std::istream& operator>>(std::istream& flux, Client & c) {
    c.saisir(flux);
    return flux;
}



