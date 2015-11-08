/* 
 * File:   Produit.h
 * Author: loft-2015-asus
 *
 * Created on 8 novembre 2015, 10:01
 */

#ifndef PRODUIT_H
#define	PRODUIT_H
#include <vector>
#include "Tarif.h"
#include "Trajet.h"
#include "Client.h"
using namespace std;
class Produit {
public:
    Produit(Client &cl);
    virtual Client &getClient() const;
    virtual float getPrix() const = 0;
    virtual void afficher(ostream &cout = cout) const;
    virtual void ajouter(Produit *p);
    
private:
    Client &client;
    vector<const Produit*> produits;
    float prix;
};

std::ostream& operator<<(std::ostream& flux, const Produit & p);


#endif	/* PRODUIT_H */

