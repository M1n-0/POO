#include <iostream>
#include <string>

#include "Personage.hpp"


template <typename T>
void print(T valeur) {
	std::cout << valeur << std::endl;
}



int main() {
	print("choisissez votre personnage : ");

	return 0;
}