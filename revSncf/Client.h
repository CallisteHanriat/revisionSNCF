/* 
 * File:   Client.h
 * Author: loft-2015-asus
 *
 * Created on 7 novembre 2015, 18:17
 */

#ifndef CLIENT_H
#define	CLIENT_H

#include <iostream>
using namespace std;
class  Client   { 
public : 

	Client(string &nom);
	string getNom() const;
	void setNom(string &nom);


	void saisir(istream &cin = cin);
	void afficher(ostream &cout = cout) const;
private :
	string nom;

};

std::ostream& operator<<(std::ostream& flux, const Client & c);
std::istream& operator>>(std::istream& flux, Client & c);

#endif	/* CLIENT_H */

