#include <iostream>
#include <Pouvoir.hpp>


Pouvoir::Entite(std::string transformer, std::string absorber, std::string lancer, std::string generer) : m_transformer(transformer), m_absorber(absorber), m_lancer(lancer), m_(generer)


void Pouvoir::feu()
{
	std::cout << "Utilisation du pouvoir de feu" << std::endl;
}

void Pouvoir::eau()
{
	std::cout << "Utilisation du pouvoir d'eau" << std::endl;
}

void Pouvoir::electrique()
{
	std::cout << "Utilisation du pouvoir électrique" << std::endl;
}

void Pouvoir::tenebre()
{
	std::cout << "Utilisation du pouvoir des ténèbres" << std::endl;
}

std::string Entite::get_transformer()
{
	return std::string();
}

std::string Entite::get_absorber()
{
	return std::string();
}

std::string Entite::get_lancer()
{
	return std::string();
}

std::string Entite::get_generer()
{
	return std::string();
}

Entite::~Entite()
{

}