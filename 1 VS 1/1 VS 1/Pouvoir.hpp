#ifndef POUVOIR_HPP
#define POUVOIR_HPP

#include <cstring>

class Entite {
public:
    // Constructeur par d�faut
    Entite() : nom("Entite"), pointsDeVie(100) {}

    // Constructeur avec param�tres
    Entite(const std::string& nom, int pointsDeVie) : nom(nom), pointsDeVie(pointsDeVie) {}

    // M�thode pour recevoir des d�g�ts
    virtual void recevoirDegats(int degats) {
        pointsDeVie -= degats;

        // Assurer que les points de vie ne deviennent pas n�gatifs
        if (pointsDeVie < 0) {
            pointsDeVie = 0;
        }

        std::cout << nom << " a subi " << degats << " points de degats. Points de vie restants : " << pointsDeVie << std::endl;

        // V�rifier si l'entit� est encore en vie
        if (pointsDeVie == 0) {
            std::cout << nom << " est KO !" << std::endl;
        }
    }

    // Méthode pour afficher les informations de l'entit�
    virtual void afficher() const {
        std::cout << "Nom: " << nom << ", Points de vie: " << pointsDeVie << std::endl;
    }

    // Getter pour le nom de l'entit�
    std::string getNom() const {
        return nom;
    }

    // Getter pour les points de vie de l'entit�
    int getPointsDeVie() const {
        return pointsDeVie;
    }

    // Setter pour le nom de l'entit�
    void setNom(const std::string& nouveauNom) {
        nom = nouveauNom;
    }

    // Setter pour les points de vie de l'entit�
    void setPointsDeVie(int nouveauxPointsDeVie) {
        pointsDeVie = nouveauxPointsDeVie;
    }

    // Destructeur virtuel pour permettre la polymorphie
    virtual ~Entite() {}

private:
    std::string nom;
    int pointsDeVie;
};

// Exemple de classe dérivée (Personnage) de la classe mére (Entite)
class Personnage : public Entite {
public:
    // Constructeur avec paramètres sp�cifique au personnage
    Personnage(const std::string& nom, int pointsDeVie, int niveau) : Entite(nom, pointsDeVie), niveau(niveau) {}

    // Red�finition de la m�thode pour afficher les informations du personnage
    void afficher() const override {
        std::cout << "Personnage - ";
        Entite::afficher();  // Appel de la m�thode de la classe m�re
        std::cout << "Niveau : " << niveau << std::endl;
    }

private:
    int niveau;
};


class CoupDePoings {
public:
    // Constructeur par d�faut
    CoupDePoings() : nom("Coup de poings"), force(5) {}

    // Constructeur avec param�tres
    CoupDePoings(const std::string& nom, int force) : nom(nom), force(force) {}

    // M�thode virtuelle pure pour attaquer avec les poings
    virtual void attaquer() const = 0;

    // M�thode pour afficher les informations du coup de poings
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

// Exemple de classe d�riv�e (Coup de poings rapide) de la classe m�re (CoupDePoings)
class CoupDePoingsRapide : public CoupDePoings {
public:
    // Constructeur avec param�tres sp�cifique au coup de poings rapide
    CoupDePoingsRapide(const std::string& nom, int force, int vitesse) : CoupDePoings(nom, force), vitesse(vitesse) {}

    // Impl�mentation de la m�thode virtuelle pure pour attaquer avec les poings
    void attaquer() const override {
        std::cout << "Attaque rapide avec les poings !" << std::endl;
    }

    // M�thode sp�cifique au coup de poings rapide pour afficher des informations suppl�mentaires
    void afficherVitesse() const {
        std::cout << "Vitesse du coup de poings rapide : " << vitesse << " m/s" << std::endl;
    }

private:
    int vitesse;
};
#endif 