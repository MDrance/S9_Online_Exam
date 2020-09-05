#include "Patient.hpp"
#include "ListeOrd.hpp"
#include <iostream>
#include <string>
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

string Personne::getNom() const {return Nom;}

string Personne::getPrenom() const {return Prenom;}

string Personne::getNum_INSEE() const {return Num_INSEE;}

string Personne::getDate_Naissance() const {return Date_Naissance;}

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

int Patient::getEtat() const {return Etat;}

void Patient::affiche() const{
    cout << "Nom : " << Nom << endl;
    cout << "Prénom : " << Prenom << endl;
    cout << "Numéro INSEE : " << Num_INSEE << endl;
    cout << "Date de naissance : " << Date_Naissance << endl;
    cout << "Etat du patient : " << Etat << endl;
}


// MAIN
int main(){
    //On créé 5 patients
    Patient patient1("Drancé", "Martin", "123", "24/04/1994", 1);
    Patient patient2("Amirault", "Ophélie", "456", "08/05/1995", 3);
    Patient patient3("Neuhaus", "Abdel", "789", "12/03/1997", 2);
    Patient patient4("Cornier", "Alex", "147", "29/02/1997", 2);
    Patient patient5("Alves", "Marine", "258", "24/12/1996", 1);

    //On créé une liste qui contiendra des Patient
    ListeOrd<Patient> liste;

    //On ajoute les 5 Patient
    liste.insertInPlace(patient1);
    liste.insertInPlace(patient2);
    liste.insertInPlace(patient3);
    liste.insertInPlace(patient4);
    liste.insertInPlace(patient5);
    liste.display();
    cout << endl;

    //On retire le premier
    liste.popFirst();
    liste.display();

    return 0;
}
