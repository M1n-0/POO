#pragma once
#include <vector>

#include "Attaque.hpp"
#include "Defence.hpp"
#include "Personnage.hpp"


class Jeu {
public:
	Jeu();

	void ajouterGentil(Personnage gentil) {
		mGentil.push_back(gentil); 
	}
	void ajouterMechant(Personnage mechant) {
		mMechant.push_back(mechant);
	}
	void ajouterAttaque(std::string nom, int degats) {
		mAttaques.push_back(Attaque(nom, degats));
	}
	void ajouterDefence(std::string nom, int defence, int energieRequis) {
		mDefences.push_back(Defence(nom, defence, energieRequis));
	}

	Attaque getAttaque(std::string nom) {
		for (int i = 0; i < mAttaques.size(); i++) {
			if (mAttaques[i].getNom() == nom) {
				return mAttaques[i];
			}
		}
	}
	Defence getDefence(std::string nom) {
		for (int i = 0; i < mDefences.size(); i++) {
			if (mDefences[i].getNom() == nom) {
				return mDefences[i];
			}
		}
	}

	void afficherGentils() {
		for (int i = 0; i < mGentil.size(); i++) {
			std::cout  << (i + 1) << ": " << mGentil[i].getNom() << "  Vie: " << mGentil[i].getVie() << " - Energie: " << mGentil[i].getEnergie() << std::endl;
		}
	}
	void afficherMechants() {
		for (int i = 0; i < mMechant.size(); i++) {
			std::cout << (i + 1) << ": " << mMechant[i].getNom() << "  Vie: " << mMechant[i].getVie() << " - Energie: " << mMechant[i].getEnergie() << std::endl;
		}
	}

	bool selectionPersonageValide(int choix, bool gentil) {
		if (gentil) {
			if (choix > 0 && choix <= mGentil.size()) {
				std::cout << "Vous avez choisi " << mGentil[choix - 1].getNom() << std::endl;
				return true;
			}
		}
		else {
			if (choix > 0 && choix <= mMechant.size()) {
				std::cout << "Vous avez choisi " << mMechant[choix - 1].getNom() << std::endl;
				return true;
			}
		}
		std::cout << "Choix invalide" << std::endl;
		return false;
	}
	Personnage getPersonnage(int choix, bool gentil) {
		if (gentil) {
			return mGentil[choix - 1];
		}
		else {
			return mMechant[choix - 1];
		}
	}
private:
	void CreerAttaques();
	void CreerDefences();
	void CreerMechants();
	void CreerGentils();

	std::vector<Attaque> mAttaques;
	std::vector<Defence> mDefences;
	std::vector<Personnage> mMechant;
	std::vector<Personnage> mGentil;
};
