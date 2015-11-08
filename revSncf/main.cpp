/* 
 * File:   main.cpp
 * Author: loft-2015-asus
 *
 * Created on 4 novembre 2015, 20:27
 */

#include <cstdlib>
#include "NombreContraint.h"
#include "Trajet.h"
#include "Tarif.h"
#include "Client.h"
#include "Billet.h"
#include "Promotion.h"
#include "Produit.h"
#include "Conteneur.h"
#include "Reservation.h"
#include "BilletReduit.h"
using namespace std;

void testNombreContraint() {
    cout << "Constructeur : \n";
    NombreContraint<int> n1(20);
    cout << "\nok.\n";
    cout << "Test d'affichage du nombre contraint : \n";
    cout << n1 << endl;
    n1.afficher(cout);
    cout << "\nok.\n";
    cout << "Test de creation d'un nombre contraint trop grand : \n";
    try {
        NombreContraint<int> n2(1001);
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    cout << "\nok.\n";
}

void testTrajet() {
    string va = "Paris";
    string vd = "Marseille";
    cout << "Constructeur : " << endl;
    Trajet t(vd, va, 650);
    cout << "ok.\n";
    cout << "Affichage : \n";
    cout << t;
    cout << "ok.\n";
    cout << "saisie : \n";
    cin >> t;
    cout << "ok.\n";
}

void testTarif() {
    string lib = "illico";
    float price = 0.2;
    cout << "Constructeur : " << endl;
    Tarif t(lib, price);
    cout << "ok.\n";
    cout << "Affichage : \n";
    cout << t << endl;
    cout << "Saisie :\n";
    cin >> t;
    cout << endl << t;
}

void testBillet() {
    string villeDep = "Paris";
    string nomClient = "Bruno";
    string villeAr = "Marseille";
    int distance = 550;
    string lib = "illico";
    float price = 0.2;
    Client cl(nomClient);

    cout << "Constructeurs : " << endl;
    Tarif tarif(lib, price);
    Trajet trajet(villeDep, villeAr, distance);
    cout << "ok.\n";
    cout << "Affichage du tarif: \n";
    cout << tarif << endl;
    cout << "Affichage du trajet : \n";
    cout << trajet << endl;

    cout << "Constructeur du billet : \n";
    Billet billet(trajet, tarif, cl);
    cout << "ok.\n";
    cout << "Affichage du billet : " << endl;
    cout << billet << endl;
}

void testPromotion() {
    string lib = "illico_jeunes_mensuel";
    float tauxReduc = 0.75;
    cout << "Constructeur : \n";
    Promotion p(lib, tauxReduc);
    cout << "ok.\n";
    cout << "affichage de p : \n";
    cout << p;
    cout << "ok.\n";
    cout << "saisie de p : ";
    cin >> p;
    cout << "nouvel affichage de p : \n";
    cout << p;
}

void testBilletReduit() {
    string villeDep = "Paris";
    string villeAr = "Marseille";
    int distance = 550;
    string nomClient = "Maxime";
    string promoLib = "illico_jeunes_mensuel";
    float promo = 0.75;
    string lib = "illico";
    float price = 0.2;

    Client cl(nomClient);
    Promotion promotion(promoLib, promo);
    cout << "Constructeurs : " << endl;
    Tarif tarif(lib, price);
    Trajet trajet(villeDep, villeAr, distance);
    cout << "ok.\n";
    cout << "Affichage du tarif: \n";
    cout << tarif << endl;
    cout << "Affichage du trajet : \n";
    cout << trajet << endl;

    cout << "Constructeur du billet : \n";
    Billet billet(trajet, tarif, cl);
    cout << "ok.\n";
    cout << "Affichage du billet Reduit : " << endl;
    cout << billet << endl;

    cout << "AFFICHAGE DU BILLET REDUIT : " << endl;
    BilletReduit billetReduit(trajet, tarif, cl, promotion);
    cout << billetReduit;
}

void testClient() {
    string nm = "maxime";
    cout << "Constructeur : \n";
    Client c(nm);
    cout << "Affichage : \n";
    cout << c;
    cout << "\nsaisie : \n";
    cin >> c;
    cout << "Affichage : \n";
    cout << c;
}

void testConteneur() {
    //pattern singleton : le getInstance nous assure qu'il y a une seule instance de chaque conteneur.
    Conteneur<Promotion>* contPromo = Conteneur<Promotion>::getInstance();
    Conteneur<Trajet>* contTraj = Conteneur<Trajet>::getInstance();
    Conteneur<Tarif>* contTari = Conteneur<Tarif>::getInstance();
    Conteneur<Client>* contClient = Conteneur<Client>::getInstance();
    Conteneur<Billet>* contBillet = Conteneur<Billet>::getInstance();
    string nom = "romain";
    string illico = "jeunes";
    Tarif t(illico, 0.2);
    contTari->ajouter(t);
    string villeDep = "Paris";
    string villeAr = "Marseille";
    int distance = 550;
    Trajet tra(villeDep, villeAr, distance);
    Client cli(nom);

    int choix;
    do {
        cout << "\t1 - creer des tarifs\n\t2- - creer des trajets\n\t3 - creer des promotions\n\t4 - creer des Clients\n\t5 - creer des billets reduits ou billets en choissisant ses composants\n\t0 - quitter\n";
        cin >> choix;
        switch (choix) {
            case 1:
            {
                Tarif* t = new Tarif(illico, 0.2);
                cin>>*t;
                contTari->ajouter(*t);
                break;
            }
            case 2:
            {
                Trajet* tr = new Trajet(villeDep, villeAr, 100);
                cin>>*tr;
                contTraj->ajouter(*tr);
                break;
            }
            case 3:
            {
                string promo = "promo";
                Promotion* p = new Promotion(promo, 10.0);
                cin>>*p;
                contPromo->ajouter(*p);
            }
            case 4:
            {
                Client* cli = new Client(nom);
                cin>>*cli;
                contClient->ajouter(*cli);
                break;
            }
            case 5:
            {
                Trajet* tr = new Trajet(villeDep, villeAr, 100);
                cin>>*tr;
                Tarif* t = new Tarif(illico, 0.2);
                cin>>*t;
                Client* cli = new Client(nom);
                Billet bill(*tr, *t, *cli);
                contBillet->ajouter(bill);
                break;
            }
        }
    } while (choix != 0 && choix < 5);

    cout << *contTraj;

    delete contBillet;
    delete contClient;
    delete contPromo;
    delete contTari;
    delete contTraj;
}

void testComposite() {
    //pattern singleton : le getInstance nous assure qu'il y a une seule instance de chaque conteneur.
    Conteneur<Produit>* contProduit = Conteneur<Produit>::getInstance();

    string nom = "romain";
    string illico = "jeunes";
    string lib = "illico";
    Tarif t(illico, 0.2);
    string villeDep = "Paris";
    string villeAr = "Marseille";
    int distance = 550;
    Trajet tra(villeDep, villeAr, distance);
    Client cli(nom);
    Promotion p(lib, 0.50);
    Billet b(tra, t, cli);
    BilletReduit br(tra, t, cli, p);
    Reservation r(cli, 150.0);
    
    contProduit->ajouter(b);
    contProduit->ajouter(br);
    contProduit->ajouter(r);
    cout << *contProduit;

    delete contProduit;

}

/*
 * 
 */
int main(int argc, char** argv) {
    testComposite();
    return EXIT_SUCCESS;
}

