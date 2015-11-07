/* 
 * File:   Billet.h
 * Author: loft-2015-asus
 *
 * Created on 7 novembre 2015, 15:11
 */

#ifndef BILLET_H
#define	BILLET_H
#include "Tarif.h"
#include "Client.h"
#include "Trajet.h"
#include <iostream>

using namespace std;
class  Billet   { 

public : 

	Billet(Trajet &unTrajet, Tarif &unTarif);

	virtual const Tarif &getTarif() const;

	virtual const Trajet &getTrajet() const;

	virtual void afficher(ostream &cout = cout) const ;
        
        virtual float getPrix() const;
        

private :

	const Tarif& tarif;

	const Trajet& trajet;


};

std::ostream& operator<<(std::ostream& flux, const Billet & b);

#endif	/* BILLET_H */

