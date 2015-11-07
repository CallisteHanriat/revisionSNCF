/* 
 * File:   Tarif.h
 * Author: loft-2015-asus
 *
 * Created on 5 novembre 2015, 22:14
 */

#ifndef TARIF_H
#define	TARIF_H

#include "NombreContraint.h"
using namespace std;
class  Tarif   { 

public : 

	Tarif(string & unLibelle, float prixAuKg);

	string getLibelle() const;

	void setLibelle(string &libelle);

	NombreContraint<float> getPrixAuKm() const;

	void setPrixAuKm(float prixAuKm);



	void saisir(istream &cin = cin);

	void afficher(ostream &cout = cout) const;

private :
        const static float PRIXMIN;
        const static float PRIXMAX;
	string libelle;

	NombreContraint<float> prixAuKm;


};

std::ostream& operator<<(std::ostream& flux, const Tarif & t);
std::istream& operator>>(std::istream& flux, Tarif & t);


#endif	/* TARIF_H */

