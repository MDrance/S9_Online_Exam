#ifndef LISTEORD_H
#define LISTEORD_H
#include<iostream>
using namespace std;

//On créé une classe template des objets qui seront contenus dans la liste
template<class E>
class CElement{
    public:
        E m_value; //La valeur de l'objet
        CElement *m_next; //Un pointeur vers l'objet qui suivra dans la liste
        virtual ~CElement() {delete m_next;} //A l'appel du destructeur, on veut detruire le pointeur vers le prochain élément
        CElement(E &value) //A la création de l'objet, on assigne la valeur et on initialise le pointeur à null
        {
            m_value = value;
            m_next = NULL;
        };
};

//On créé une classe template de la liste simplement chainée
template<class T>
class ListeOrd{
    protected:
        CElement<T> *m_first; //Pointeur vers le premier élément de la liste
        int m_size; //Taille de la liste
    public:
        ListeOrd();
        virtual ~ListeOrd();
        void insertInPlace(T data); //insère l'objet data à la bonne place
        void popFirst(); //retire le premier élément de la liste
        bool is_empty() const; //vérifie si la liste est vide
        void display () const; //affiche le contenu de la liste
};

//A la création de l'objet, on initialise les pointeurs à null et la taille à 0
template<class T> ListeOrd<T>::ListeOrd()
{
    m_first = NULL;
    m_size = 0;
}

//A l'appel du destructeur, on veut detruire les pointeurs
template<class T> ListeOrd<T>::~ListeOrd(){delete m_first;}

//Le premier élément devient celui le précédent, la taille de la liste diminue de 1
template<class T> void ListeOrd<T>::popFirst()
{
    m_first = m_first->m_next;
    m_size--;
}


//Si la taille de la liste est nulle, renvoi true, sinon false
template<class T> bool ListeOrd<T>::is_empty() const
{
   if (m_size == 0)
   {
       return true;
   } 
    return false;
}

//Si la taille de la liste est nulle, indique que la liste est vide
//Sinon parcourt un à un les éléments et les affiche
template<class T> void ListeOrd<T>::display() const
{
    cout << "Taille de la liste = " << m_size << endl;
    if (m_first == NULL){cout << "La liste est vide" << endl;}
    else
    {
        CElement <T> *node = m_first;
        cout << "[0] : " << node->m_value << endl;
        for (int i = 1; i < m_size; i++)
        {
            node = node->m_next;
            cout << "[" << i << "] : " << node->m_value<< endl;
        }
    }
}

template<class T> void ListeOrd<T>::insertInPlace(T data)
{
    CElement<T> *m_new;
    m_new = new CElement<T>(data); //Créé un pointeur vers notre nouvel objet à ajouter
    // On place notre nouvel élément au début de la liste
    m_new->m_next = m_first;
    m_first = m_new;
    m_size++;
    CElement<T> *swap_node = m_first; //On créer un pointeur vers un CElement qui se déplacera dans la liste
    for (int i = 0; i < m_size-1; i++)
    {
        CElement<T> *next_node = swap_node->m_next; //On créer un pointeur vers un CElement qui sera systématiquement l'élement après swap_node
        if (swap_node->m_value < next_node->m_value) //Si notre valeur n'est pas à sa place
        {
            T temp = swap_node->m_value; //On conserve la valeur de l'élément à déplacer
            swap_node->m_value = next_node->m_value; //L'élément actuel prend la valeur du prochain élément
            next_node->m_value = temp; // Le prochain prend comme valeur celle de l'élément qu'il faut placer
        }
        swap_node = next_node; //On se déplace d'une 'case' et on recommence
    }
}

#endif