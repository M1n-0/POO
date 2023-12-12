#pragma once
#include "Personnage.hpp"

class Joueur {
public:
	Joueur(std::string nom, Personnage personnage, bool gentil)
		: mNom(nom), personnage(personnage), mGentil(gentil) 
	{}

	bool isGenttil() {
		return mGentil;
	}
	std::string getNom() {
		return mNom;
	}
	void afficher() {
		std::cout << mNom << " (" << personnage.getNom() << ")" << std::endl;
		std::cout << "Vie: " << personnage.getVie() << " - Energie : " << personnage.getEnergie() << std::endl;
	}


	Personnage personnage;
private:
	std::string mNom;
	bool mGentil = true;
};


