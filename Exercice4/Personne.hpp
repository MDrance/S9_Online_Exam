#ifndef PERSONNE_H
#define PERSONNE_H
#include <iostream>
#include <string>
using namespace std;

class Personne{

    //Attributs protégés
    protected:
        string Nom;
        string Prenom;
        string Num_INSEE;
        string Date_Naissance;

    //Méthodes
    public:
        Personne(); //Constructeur par défaut
        Personne(string,string,string,string); //constructeur surchargé
        virtual ~Personne(); //Destructeur

        //Getters
        string getNom() const;
        string getPrenom() const;
        string getNum_INSEE() const;
        string getDate_Naissance() const;

        //Affichage des attributs sur la console
        virtual void affiche() const;
};
#endif