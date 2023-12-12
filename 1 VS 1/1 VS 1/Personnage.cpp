#include <iostream>
#include <Personnage.hpp>



int main() {
    // Exemple d'utilisation de la classe Personnage
    Personnage personnage1;  // Utilisation du constructeur par défaut
    personnage1.afficher();

    Personnage personnage2("Alice", 25);  // Utilisation du constructeur avec paramètres
    personnage2.afficher();

    personnage2.setNom("Bob");  // Utilisation du setter pour le nom
    personnage2.setAge(30);     // Utilisation du setter pour l'âge
    personnage2.afficher();

    return 0;
}
