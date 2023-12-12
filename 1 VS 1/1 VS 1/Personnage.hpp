#include <iostream>
#include <string>

class Personnage {
public:
    // Constructeur par défaut
    Personnage() : nom("Inconnu"), age(0) {}

    // Constructeur avec paramètres
    Personnage(const std::string& nom, int age) : nom(nom), age(age) {}

    // Méthode d'affichage des informations du personnage
    void afficher() const {
        std::cout << "Nom: " << nom << ", Age: " << age << " ans" << std::endl;
    }

    // Getter pour le nom
    std::string getNom() const {
        return nom;
    }

    // Getter pour l'âge
    int getAge() const {
        return age;
    }

    // Setter pour le nom
    void setNom(const std::string& nouveauNom) {
        nom = nouveauNom;
    }

    // Setter pour l'âge
    void setAge(int nouvelAge) {
        age = nouvelAge;
    }

private:
    std::string nom;
    int age;
};
