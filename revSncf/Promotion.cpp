/* 
 * File:   Promotion.cpp
 * Author: loft-2015-asus
 * 
 * Created on 7 novembre 2015, 17:31
 */

#include "Promotion.h"

//constructor
const float Promotion::TAUXMIN = 0.01;
const float Promotion::TAUXMAX = 0.99;
Promotion::Promotion(string &lib, float tauxReduc)
    :libelle(lib), tauxReduction(tauxReduc, TAUXMIN, TAUXMAX)
{}

string Promotion::getLibelle() const {
	return this->libelle;
}

void Promotion::setLibelle(string &libelle) {
	this->libelle=libelle;
}

NombreContraint<float> Promotion::getTauxReduction() const {
	return this->tauxReduction;
}

void Promotion::setTauxReduction(float tauxReduction) {
	this->tauxReduction.setVal(tauxReduction);
}

float Promotion::calculerPrixReduit(float prix) const {
    return prix*(1-getTauxReduction());
}

void Promotion::saisir(istream &cin) {
    float taux;
    string lib;
    cout << "Entrez un libellé : ";
    cin >> lib;
    cout << "Entrez la réduction : ";
    cin >> taux;
    
    setLibelle(lib);
    setTauxReduction(taux);
}

void Promotion::afficher(ostream &cout) const {
    cout << "Type de réduction : " << getLibelle() << endl;
    cout << "Promotion : " << getTauxReduction() << " %";
}

std::ostream& operator<<(std::ostream& flux, const Promotion & p) {
	p.afficher(flux);
	return flux;
}

std::istream& operator>>(std::istream& flux, Promotion & p) {
	p.saisir(flux);
	return flux;
}


