#include "Jeu.hpp"



Jeu::Jeu() {
	CreerAttaques();
	CreerDefences();
	CreerGentils();
	CreerMechants();
}

void Jeu::CreerAttaques() {
	// ajouterAttaque prend en parametre le nom de l'attaque et les degats infliges
	ajouterAttaque("Tornarde", 69);
	ajouterAttaque("Meteore ", 88);
}
void Jeu::CreerDefences() {
	// ajouterDefence prend en parametre le nom de la defense et le nombre de degats bloques ainsi que le cout en energie
	ajouterDefence("Tourne sur soit meme", 69, 20);
	ajouterDefence("Permutation", 69, 20);
	
}
void Jeu::CreerMechants() {
	//creer un personnage avec le nom, la vie et l'energie
	//ensuite ajouter les defences et les attaques avec les fonctions getDefence et getAttaque
	//ajouter les ensuite au jeu avec ajouterMechant
	Personnage madara("Madara", 100, 200);
	madara.ajouterAttaque(getAttaque("Meteore"));
	madara.ajouterDefence(getDefence("Permutation"));
	ajouterMechant(madara);
}
void Jeu::CreerGentils() {
	//creer un personnage avec le nom, la vie et l'energie
	//ensuite ajouter les defences et les attaques avec les fonctions getDefence et getAttaque
	//ajouter les ensuite au jeu avec ajouterGentil
	Personnage maxwell("Maxwell ", 120, 160);
	maxwell.ajouterAttaque(getAttaque("Tornarde"));
	maxwell.ajouterDefence(getDefence("Tourne sur soit meme"));
	ajouterGentil(maxwell);
}
