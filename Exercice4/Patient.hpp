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
        Patient(); //Constructeur
        Patient(string, string, string, string, int); //Constructeur surchargé
        virtual ~Patient(); //Destructeur

        //Getter
        int getEtat() const;

        //Affichage des attributs sur la console
        void affiche() const;

    //Surcharge de l'opérateur < 
    bool operator < (Patient const& patient)
    {
        return this->Etat < patient.Etat;
    }

    // //Surcharge de l'opérateur ==
    bool operator == (Patient& patient)
    {
        return this->Etat == patient.Etat;
    }

    //Surcharge de l'opérateur <<
    friend ostream& operator << (ostream& output, const Patient& patient)
    {
        output << "Patient : " << patient.getNom() << " / " << "Etat : " << patient.Etat;
        return output;
    }
};

#endif