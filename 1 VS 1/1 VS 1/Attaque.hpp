#pragma once
#include <string>

class Attaque {
public:
	Attaque(std::string nom, int degats)
		: mNom(nom), mDegats(degats)
	{}

	std::string getNom() const { return mNom; }
	int getDegats() const { return mDegats; }

	void setNom(std::string nom) { mNom = nom; }
	void setDegats(int degats) { mDegats = degats; }
private:
	std::string mNom;
	int mDegats = 0;
};
