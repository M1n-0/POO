#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "Attaque.hpp"
#include "Defence.hpp"

class Personnage {
public:
	Personnage(std::string nom, int vie, int energie) {
		mNom = nom;
		mVie = vie;
		mEnergie = energie;
	}
	std::string getNom() {
		return mNom;
	}
	int getVie() {
		return mVie;
	}
	int getEnergie() {
		return mEnergie;
	}
	void setNom(std::string nom) {
		mNom = nom;
	}
	void setVie(int vie) {
		mVie = vie;
	}
	void setEnergie(int energie) {
		mEnergie = energie;
	}
	//supprime de la vie et vous dit si le personnage est mort
	bool supprimerVie(int vie) {
		mVie = mVie - vie;
		return mVie <= 0;
	}
	//supprime de l'energie et vous dit si le personnage en a encore
	bool supprimerEnergie(int energie) {
		mEnergie = mEnergie - energie;
		return mEnergie <= 0;
	}
	bool possedeEnergie(int energie) {
		return mEnergie >= energie;
	}
	void ajouterAttaque(Attaque attaque) {
		mAttaques.push_back(attaque);
	}
	void ajouterDefence(Defence defence) {
		mDefence.push_back(defence);
	}

	std::vector<Attaque> getAttaques() {
		return mAttaques;
	}
	std::vector<Defence> getDefence() {
		return mDefence;
	}

	void afficher() {
		std::cout << "Nom : " << mNom << std::endl;
		std::cout << "Vie : " << mVie << " - Energie : " << mEnergie << std::endl;
	}

private:
	std::string mNom;
	int mVie = 0;
	int mEnergie;
	std::vector<Attaque> mAttaques;
	std::vector<Defence> mDefence;
};
