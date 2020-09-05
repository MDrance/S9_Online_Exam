#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
#include "Personne.hpp"
using namespace std;

class Patient : public Personne{

    //Attributs privés
    private:
        int Etat;

    //Méthodes
    public:
        Patient(); //Constructeur par défaut
        Patient(string, string, string, string, int); ///Constructeur surchargé
        virtual ~Patient(); //Destructeur

        //Getter
        int getEtat();

        //Affichage des attributs sur le terminal
        void affiche() const;
};

#endif