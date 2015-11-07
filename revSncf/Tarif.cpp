/* 
 * File:   Tarif.cpp
 * Author: loft-2015-asus
 * 
 * Created on 5 novembre 2015, 22:14
 */

#include "Tarif.h"
const float Tarif::PRIXMIN=0.01;
const float Tarif::PRIXMAX=10.0;

//constructor
Tarif::Tarif(string & unLibelle, float prixAuK) 
    :libelle(unLibelle), prixAuKm(prixAuK, PRIXMIN, PRIXMAX)
{}

string Tarif::getLibelle() const {

	return this->libelle;

}

void Tarif::setLibelle(string &libelle) {

	this->libelle=libelle;

}

NombreContraint<float> Tarif::getPrixAuKm() const {

	return this->prixAuKm;

}

void Tarif::setPrixAuKm(float prixAuKm) {
    try{
	this->prixAuKm.setVal(prixAuKm);
    } catch (exception &e) {
        cout << e.what() << endl;
    }

}

void Tarif::saisir(istream &cin) {
    string lib;
    float prix = 0.2;
    cout << "Saisir le libellé du tarif : ";
    cin >> lib;
    setLibelle(lib);
    cout << "Le prix au KiloMetre : ";
    cin >> prix;
    setPrixAuKm(prix);
    
}

void Tarif::afficher(ostream &cout) const {
    cout << "libelle : " << this->getLibelle() << endl;
    cout << "prix au kilometre :  " << this->getPrixAuKm();
}

std::ostream& operator<<(std::ostream& flux, const Tarif & t) {
	t.afficher(flux);
	return flux;
}

std::istream& operator>>(std::istream& flux, Tarif & t) {
	t.saisir(flux);
	return flux;
}
