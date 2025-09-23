#include <iostream>
using namespace std;

//2-Nombres n-Aires
struct noeudMult
{
    int donnee;
    int fils_noeud;
    noeudMult* tab[100];
};

void createArbreNAire(noeudMult** racine)
{
    noeudMult* newNode = new noeudMult;
    for (int i = 0; i < 100; i++)
    {
        newNode->tab[i] = NULL;
    }
    cout << "Entrez la valeur du noeud :";
    cin >> newNode->donnee;
    *racine = newNode;
    cout << "Entrez le nombre de fils du noeud :";
    cin >> newNode->fils_noeud;
    if (newNode->fils_noeud == 0) return;
    else
    {
        for (int i = 0; i < newNode->fils_noeud; i++)
        {
            createArbreNAire(&(*racine)->tab[i]);
        }
    }
}

void afficheProfondeur(noeudMult* arbre)
{
    if (arbre == NULL) return;
    else
    {
        cout << arbre->donnee;
        for (int i = 0; i < arbre->fils_noeud; i++)
        {
            afficheProfondeur(arbre->tab[i]);
        }
    }
}


int main()
{
    noeudMult* newNoeud = NULL;
    createArbreNAire(&newNoeud);
    afficheProfondeur(newNoeud);
    
    
    return 0;
    
}
