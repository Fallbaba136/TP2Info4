#include <iostream>
using namespace std;

//2-Nombres n-Aires
struct noeudMult
{
    int donnee;
    int fils_noeud;
    noeudMult* tab[100];
};
struct file
{
    noeudMult* element[100];
    int debut;
    int fin;
};
void intiFile(file* f)
{
    f->debut = 0;
    f->fin = 0;
}

bool estVide(file* f)
{
    return f->debut = f->fin;
}

void enfiler(file* f, noeudMult* n)
{
    f->element[f->debut] = n;
    f->fin++;
}
noeudMult* defiler(file* f)
{
    noeudMult* n = f->element[f->debut];
    f->debut++;
    return n;
}

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

void afficheProfondeur(noeudMult* arbre, int prof)
{
    if (arbre == NULL) return;
    else
    {
        cout << arbre->donnee;
        for (int i = 0; i < arbre->fils_noeud; i++)
        {
            afficheProfondeur(arbre->tab[i], prof - 1);
        }
    }
}
void afficheLargeurRec(file* f)
{
    if (estVide(f)) return;
    noeudMult* n = defiler(f);
    cout << n->donnee << " -> ";
    for (int i = 0; n->fils_noeud; i++)
    {
        enfiler(f, n->tab[i]);
    }
    afficheLargeurRec(f);
}
int rechercheHauteur(noeudMult* racine)
{
    if (racine == NULL) return 0;
    int maxH = 0;
    for (int i = 0; i < racine->fils_noeud; i++)
    {
        int h = rechercheHauteur(racine->tab[i]);
        if (h > maxH) maxH = h;
    }
    return maxH + 1;
}
void afficheEnLargeur(noeudMult* racine)
{
    if (racine == NULL) return;
    int h = rechercheHauteur(racine);
    for (int niveau = 0; niveau < h; niveau++)
    {
        afficheProfondeur(racine, niveau);
    }
}
int main()
{
    int prof;
    cout << "Saisissez le profondeur : ";
    cin >> prof;
    noeudMult* newNoeud = NULL;
    createArbreNAire(&newNoeud);
    afficheProfondeur(newNoeud, prof);
    
    
    return 0;
    
}
