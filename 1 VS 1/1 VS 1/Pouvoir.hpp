#ifndef POUVOIR_HPP
#define POUVOIR_HPP

#include <cstring>

class Entite {
public:
    // Constructeur par défaut
    Entite() : nom("Entité"), pointsDeVie(100) {}

    // Constructeur avec paramètres
    Entite(const std::string& nom, int pointsDeVie) : nom(nom), pointsDeVie(pointsDeVie) {}

    // Méthode pour recevoir des dégâts
    virtual void recevoirDegats(int degats) {
        pointsDeVie -= degats;

        // Assurer que les points de vie ne deviennent pas négatifs
        if (pointsDeVie < 0) {
            pointsDeVie = 0;
        }

        std::cout << nom << " a subi " << degats << " points de dégâts. Points de vie restants : " << pointsDeVie << std::endl;

        // Vérifier si l'entité est encore en vie
        if (pointsDeVie == 0) {
            std::cout << nom << " est KO !" << std::endl;
        }
    }

    // Méthode pour afficher les informations de l'entité
    virtual void afficher() const {
        std::cout << "Nom: " << nom << ", Points de vie: " << pointsDeVie << std::endl;
    }

    // Getter pour le nom de l'entité
    std::string getNom() const {
        return nom;
    }

    // Getter pour les points de vie de l'entité
    int getPointsDeVie() const {
        return pointsDeVie;
    }

    // Setter pour le nom de l'entité
    void setNom(const std::string& nouveauNom) {
        nom = nouveauNom;
    }

    // Setter pour les points de vie de l'entité
    void setPointsDeVie(int nouveauxPointsDeVie) {
        pointsDeVie = nouveauxPointsDeVie;
    }

    // Destructeur virtuel pour permettre la polymorphie
    virtual ~Entite() {}

private:
    std::string nom;
    int pointsDeVie;
};

// Exemple de classe dérivée (Personnage) de la classe mère (Entite)
class Personnage : public Entite {
public:
    // Constructeur avec paramètres spécifique au personnage
    Personnage(const std::string& nom, int pointsDeVie, int niveau) : Entite(nom, pointsDeVie), niveau(niveau) {}

    // Redéfinition de la méthode pour afficher les informations du personnage
    void afficher() const override {
        std::cout << "Personnage - ";
        Entite::afficher();  // Appel de la méthode de la classe mère
        std::cout << "Niveau : " << niveau << std::endl;
    }

private:
    int niveau;
};


class CoupDePoings {
public:
    // Constructeur par défaut
    CoupDePoings() : nom("Coup de poings"), force(5) {}

    // Constructeur avec paramètres
    CoupDePoings(const std::string& nom, int force) : nom(nom), force(force) {}

    // Méthode virtuelle pure pour attaquer avec les poings
    virtual void attaquer() const = 0;

    // Méthode pour afficher les informations du coup de poings
    void afficher() const {
        std::cout << "Coup de poings : " << nom << ", Force : " << force << std::endl;
    }

    // Getter pour le nom du coup de poings
    std::string getNom() const {
        return nom;
    }

    // Getter pour la force du coup de poings
    int getForce() const {
        return force;
    }

    // Setter pour le nom du coup de poings
    void setNom(const std::string& nouveauNom) {
        nom = nouveauNom;
    }

    // Setter pour la force du coup de poings
    void setForce(int nouvelleForce) {
        force = nouvelleForce;
    }

    // Destructeur virtuel pour permettre la polymorphie
    virtual ~CoupDePoings() {}

private:
    std::string nom;
    int force;
};

// Exemple de classe dérivée (Coup de poings rapide) de la classe mère (CoupDePoings)
class CoupDePoingsRapide : public CoupDePoings {
public:
    // Constructeur avec paramètres spécifique au coup de poings rapide
    CoupDePoingsRapide(const std::string& nom, int force, int vitesse) : CoupDePoings(nom, force), vitesse(vitesse) {}

    // Implémentation de la méthode virtuelle pure pour attaquer avec les poings
    void attaquer() const override {
        std::cout << "Attaque rapide avec les poings !" << std::endl;
    }

    // Méthode spécifique au coup de poings rapide pour afficher des informations supplémentaires
    void afficherVitesse() const {
        std::cout << "Vitesse du coup de poings rapide : " << vitesse << " m/s" << std::endl;
    }

private:
    int vitesse;
};
#endif 