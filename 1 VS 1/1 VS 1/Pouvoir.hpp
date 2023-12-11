#ifndef BATTLE_HPP
#define POUVOIR_HPP

#include <string>

class Pouvoir{

public :

	Pouvoir(std::string transformer, std::string absorber, std::string lancer, std::string generer);
	~Pouvoir();

	void feu();
	void eau();
	void electrique();
	void tenebre();

	std::string get_transformer;
	std::string get_absorber;
	std::string get_lancer;
	std::string get_generer;

private :
	std::string m_transformer;
	std::string m_absorber;
	std::string m_lancer;
	std::string m_generer;

};

#endif 