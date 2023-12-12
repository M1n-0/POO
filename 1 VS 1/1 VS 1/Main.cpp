#include <iostream>
#include <string>

#include "Jeu.hpp"
#include "Joueur.hpp"


template <typename T>
void print(T valeur) {
	std::cout << valeur << std::endl;
}

int demanderChoix(std::string message, std::vector<std::string> choix) {
	while (true) {
		std::cout << message << std::endl;
		for (int i = 0; i < choix.size(); i++) {
			std::cout << (i + 1) << ": " << choix[i] << std::endl;
		}
		int choixUtilisateur = 0;
		std::cin >> choixUtilisateur;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Vous devez entrer un nombre valide!" << std::endl;
		}
		if (choixUtilisateur > 0 && choixUtilisateur <= choix.size()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			return choixUtilisateur-1;
		}
		else {
			std::cout << "Vous devez entrer un nombre entre 1 et " << choix.size() << std::endl;
		}
	}
}


int main() {
	Jeu jeu;

	int perso1Gentil = demanderChoix("Etes vous gentil ou mechant?", {"Gentil", "Mechant"});
	bool perso2Gentil = perso1Gentil == 1;
	std::string perso1Name;

	Personnage perso1Personnage = jeu.getPersonnage(demanderChoix("Choisissez votre personnage", jeu.getNomPersonnages(!perso2Gentil)), !perso2Gentil);
	print("Nom du joueur 1");
	std::getline(std::cin, perso1Name);
	Joueur joueur1(perso1Name, perso1Personnage, !perso2Gentil);

	std::string perso2Name;
	Personnage perso2Personnage = jeu.getPersonnage(demanderChoix("Choisissez votre personnage", jeu.getNomPersonnages(perso2Gentil)), perso2Gentil);
	print("Nom du joueur 2: ");
	std::getline(std::cin, perso2Name);
	Joueur joueur2(perso2Name, perso2Personnage, perso2Gentil);
	
	bool tourJoueur1 = true;
	Joueur* attaqueur = &joueur1;	
	Joueur* defenceur = &joueur2;

	
	print("\n");
	while (joueur1.personnage.getVie() > 0 && joueur2.personnage.getVie() > 0) {
		joueur1.afficher();
		print("\n");
		joueur2.afficher();
		print("\n");

		

		
		 std::vector<Attaque> attaquesPossibles = attaqueur->personnage.getAttaques();
		 std::vector<std::string> attaques;
		 for (int i = 0; i < attaquesPossibles.size(); i++) {
			 attaques.push_back(attaquesPossibles[i].getNom() + "  Degats: " + std::to_string(attaquesPossibles[i].getDegats()));
		 }
		 int choixAttaque = demanderChoix(attaqueur->getNom() + " Choisis une attaque", attaques);
		 Attaque attaque = attaquesPossibles[choixAttaque];
			
		 Defence defence("Rien", 0, 0);
		 bool pasDefence = true;
		 while (true) {
			 std::vector<std::string> defences;
			 defences.push_back("Ne pas defendre");
			 std::vector<Defence> defencesPossibles = defenceur->personnage.getDefence();
			 for (int i = 0; i < defencesPossibles.size(); i++) {
				 defences.push_back(defencesPossibles[i].getNom() + "  Defence: " + std::to_string(defencesPossibles[i].getDefence()) + "  Energie: " + std::to_string(defencesPossibles[i].getEnergie()));
			 }
			 int choixDefence = demanderChoix(defenceur->getNom() + " Choisis une defense", defences);
			 defence = defencesPossibles[choixDefence - 1 + (int)(choixDefence == 0)];
			 pasDefence = choixDefence == 0;
			 if (pasDefence) {
				 break;
			 }
			 if (defence.getEnergie() > defenceur->personnage.getEnergie()) {
				 print("Vous n'avez pas assez d'energie pour cette defense");
			 }
			 else {
				 defenceur->personnage.supprimerEnergie(defence.getEnergie());
				 break;
			 }
		 }
		
		 if (pasDefence) {
			 print(defenceur->getNom() + " n'a pas defendu");
			 if (defenceur->personnage.supprimerVie(attaque.getDegats())) {
				 break;
			 }
		 }
		 else {
			 print(defenceur->getNom() + " a defendu " + defence.getNom());
			 if (defenceur->personnage.supprimerVie(attaque.getDegats() - defence.getDefence())) {
				 break;
			 }
		 }
		 tourJoueur1 = !tourJoueur1;
		 if (tourJoueur1) {
			 attaqueur = &joueur1;
			 defenceur = &joueur2;
		 }
		 else {
			 attaqueur = &joueur2;
			 defenceur = &joueur1;
		 }
	}
	print("\n");
	if (joueur1.personnage.getVie() > 0) {
		print(joueur1.getNom() + " a gagne!");
	}
	else {
		print(joueur2.getNom() + " a gagne!");
	}
	std::cin.get();
	return 0;
}