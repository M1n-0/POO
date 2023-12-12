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
		return Attaque("Mince Alors!", -50000);
	}
	Defence getDefence(std::string nom) {
		for (int i = 0; i < mDefences.size(); i++) {
			if (mDefences[i].getNom() == nom) {
				return mDefences[i];
			}
		}
		return Defence("Mince Alors!", -50000, 50000);
	}

	void afficherGentils() {
		for (int i = 0; i < mGentil.size(); i++) {
			std::cout  << (i + 1) << ": " << mGentil[i].getNom() << "  Vie: " << mGentil[i].getVie() << " - Energie: " << mGentil[i].getEnergie() << std::endl;
		}
	}
	std::vector<std::string> getNomGentils() {
		std::vector<std::string> gentils;
		for (int i = 0; i < mGentil.size(); i++) {
			gentils.push_back(mGentil[i].getNom() + " Vie: " + std::to_string(mGentil[i].getVie()) + " - Energie: " + std::to_string(mGentil[i].getEnergie()));
		}
		return gentils;
	}
	std::vector<std::string> getNomMechants() {
		std::vector<std::string> mechants;
		for (int i = 0; i < mMechant.size(); i++) {
			mechants.push_back(mMechant[i].getNom() + " Vie: " + std::to_string(mMechant[i].getVie()) + " - Energie: " + std::to_string(mMechant[i].getEnergie()));
		}
		return mechants;
	}
	std::vector<std::string> getNomPersonnages(bool gentil) {
		if (gentil) {
			return getNomGentils();
		}
		else {
			return getNomMechants();
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
			return mGentil[choix];
		}
		else {
			return mMechant[choix];
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
