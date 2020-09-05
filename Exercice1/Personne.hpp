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
        string getNom();
        string getPrenom();
        string getNum_INSEE();
        string getDate_Naissance();

        //Affichage des attributs sur le terminal
        virtual void affiche() const;
};
#endif