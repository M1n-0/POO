#include <iostream>
#include <Pouvoir.hpp>


Pouvoir::Pouvoir(std::string transformer, std::string absorber, std::string lancer, std::string generer) : m_transformer(transformer), m_absorber(absorber), m_lancer(lancer), m_(generer)


void Pouvoir::feu()
{

}

void Pouvoir::eau()
{

}

void Pouvoir::electrique()
{

}

void Pouvoir::tenebre()
{

}

std::string Pouvoir::get_transformer()
{
	return std::string();
}

std::string Pouvoir::get_absorber()
{
	return std::string();
}

std::string Pouvoir::get_lancer()
{
	return std::string();
}

std::string Pouvoir::get_generer()
{
	return std::string();
}

Pouvoir::~Pouvoir()
{

}