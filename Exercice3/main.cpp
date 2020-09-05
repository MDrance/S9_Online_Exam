#include "ListeOrd.hpp"

int main()
{
    //On instancie un objet de la classe ListeOrd qui contiendra des int
    ListeOrd<int> liste;

    //On remplie la liste et on affiche son contenu
    liste.insertInPlace(8);
    liste.insertInPlace(2);
    liste.insertInPlace(5);
    liste.display();
    cout << endl;

    //On retire les deux premières valeurs de la liste et on affiche
    liste.popFirst();
    liste.popFirst();
    liste.display();

    return 0;
}