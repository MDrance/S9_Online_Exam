#include <iostream>
#include <string>
#include "Personne.hpp"
#include "Patient.hpp"
using namespace std;


//Définition des méthodes de Personne
Personne::Personne() {};

Personne::Personne(string nom, string prenom, string num_insee, string date_naissance){
    Nom = nom;
    Prenom = prenom;
    Num_INSEE = num_insee;
    Date_Naissance = date_naissance;
}

Personne::~Personne(){}

string Personne::getNom() {return Nom;}

string Personne::getPrenom() {return Prenom;}

string Personne::getNum_INSEE() {return Num_INSEE;}

string Personne::getDate_Naissance() {return Date_Naissance;}

void Personne::affiche() const{
    cout << "Nom : " << Nom << endl;
    cout << "Prénom : " << Prenom << endl;
    cout << "Numéro INSEE : " << Num_INSEE << endl;
    cout << "Date de naissance : " << Date_Naissance << endl;
}


//Définition des méthodes de Patient
Patient::Patient() {}

Patient::Patient(string nom, string prenom, string num_insee, string date_naissance, int etat) :
Personne(nom, prenom, num_insee, date_naissance){
    Etat = etat;
} 

Patient::~Patient(){};

int Patient::getEtat() {return Etat;}

void Patient::affiche() const{
    cout << "Nom : " << Nom << endl;
    cout << "Prénom : " << Prenom << endl;
    cout << "Numéro INSEE : " << Num_INSEE << endl;
    cout << "Date de naissance : " << Date_Naissance << endl;
    cout << "Etat du patient : " << Etat << endl;
}


// MAIN
int main(){

    //Création des instances des objets
    Personne personne("Drancé", "Martin", "0123456789", "24/04/1994");
    Patient patient ("Amirault", "Ophélie", "9876543210", "08/05/1995", 2);

    //Affichage des informations pour chaque instance
    personne.affiche();
    patient.affiche();

    return 0;
}
