#pragma once
#include <string>

class Defence {
public:
	Defence(std::string nom, int defence, int energie)
		: mNom(nom), mDefence(defence), mEnergie(energie) 
	{}

	std::string getNom() const { return mNom; }
	int getDefence() const { return mDefence; }
	int getEnergie() const { return mEnergie; }
	void setEnergie(int energie) { mEnergie = energie; }
	void setDefence(int defence) { mDefence = defence; }
	void setNom(std::string nom) { mNom = nom; }
private:
	std::string mNom;
	int mDefence = 0;
	int mEnergie = 0;
};
