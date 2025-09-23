#include <iostream>
using namespace std;


//1. Arbre binaire
struct noeud {
    int donnee;
    noeud* gauche;
    noeud* droite;
};
//prefixe : on visite le noeud avnt ces enfants = racine->gauche->droite
void createArbrePrefix(noeud** racine, int prof)
{
    noeud* newNoeud = new noeud;
   // newNoeud->gauche = NULL;
   // newNoeud->droite = NULL;
    cout << "Saisie la valeur de la racine : ";
    cin >> newNoeud->donnee;
    *racine = newNoeud;
    if (prof == 0) return;
    else
    {
        createArbrePrefix(&(*racine)->gauche, prof - 1);
        createArbrePrefix(&(*racine)->droite, prof -1);
    }
    
}
void affichePrefix(noeud* racine)
{
    if (racine == NULL)return;
    else
    {
        cout << racine->donnee << " -> ";
        affichePrefix(racine->gauche);
        affichePrefix(racine->droite);
    }
}

//Infixe : on visite le noeud avant ces enfants = gauche->racine->droite
void createArbreInfix(noeud** racine, int prof)
{
    if (prof >= 0)
    {
        //noeud* newNoeud = new noeud;
        *racine = new noeud;
        createArbreInfix(&(*racine)->gauche, prof - 1);
        cout << "Saisie la valeur de la racine : ";
        cin >> (*racine)->donnee;
        createArbreInfix(&(*racine)->droite, prof -1);
    }
    
}
void afficheInfix(noeud* racine)
{
    if (racine == NULL) return;
    else
    {
        afficheInfix(racine->gauche);
        cout << racine->donnee << "->";
        afficheInfix(racine->droite);
    }
}

//postfixe : On visite la racine apres ces enfants : gauhe->droite->racine
void createArbrePostfix(noeud** racine, int prof)
{
    if (prof >= 0)
    {
        //noeud* newNoeud = new noeud;
        *racine = new noeud;
        createArbrePostfix(&(*racine)->gauche, prof - 1);
        createArbrePostfix(&(*racine)->droite, prof -1);
        cout << "Saisie la valeur de la racine : ";
        cin >> (*racine)->donnee;
    }
    
}

//AFFICHAGE DES ARBRES

void affichePostFix(noeud* racine)
{
    if (racine == NULL) return;
    else
    {
        affichePostFix(racine->gauche);
        affichePostFix(racine->droite);
        cout << racine->donnee;
        
    }
}

// Recherche dans un arbre
//Recherche d'une valeur
//On affiche une valeur passer en parametre
void afficheValeurPrefix(noeud* racine, int X)
{
    if (racine != NULL)
    {
        
        if (racine->donnee < X) {
            cout << racine->donnee;
            afficheValeurPrefix(racine->gauche, X);
                afficheValeurPrefix(racine->droite, X);
        }
        else
        {
            cout << " Valeur superieur a " << X << " arbre non affiche " << endl;
        }
    }
    
}

//Infixe : on visite le noeud avant ces enfants = gauche->racine->droite
void afficheValeurInfix(noeud* racine, int X)
{
    if (racine != NULL)
    {
        
        if (racine->donnee < X) {
            afficheValeurInfix(racine->gauche, X);
            cout << racine->donnee;
            afficheValeurInfix(racine->droite, X);
        }
        else
        {
            cout << " Valeur superieur a " << X << " arbre non affiche " << endl;
        }
        
    }
}
//postfixe : On visite la racine apres ces enfants : gauhe->droite->racine
void afficheValeurPostfix(noeud* racine, int X)
{
    if (racine != NULL)
    {
        
        if (racine->donnee < X)
        {
            afficheValeurInfix(racine->gauche, X);
            afficheValeurInfix(racine->droite, X);
            cout << racine->donnee;
        }
        else
        {
            cout << " Valeur superieur a " << X << " arbre non affiche " << endl;
        }
        
    }
}

bool rechercheValeurPrefix(noeud* racine, int X)
{
    if (racine == NULL) return false;
    else
    {
        if (racine->donnee == X)
        {
            cout <<" le nombre est bel et bien dans l'arbre " << endl;
            return true;}
        
        if(rechercheValeurPrefix(racine->gauche, X))
        {
            cout <<" le nombre est bel et bien dans l'arbre " << endl;
            return true;
        }
        if(rechercheValeurPrefix(racine->droite, X))
        {cout <<" le nombre est bel et bien dans l'arbre " << endl;
            return true;}
    }
    
    return false;
}

int compterFeuille(noeud* racine)
{
    if (racine == NULL) return 0;
    if (racine->gauche == NULL && racine->droite == NULL) return 1;
    return compterFeuille(racine->gauche) + compterFeuille(racine->droite);
                
}


//RECHERCHES DES CARACTERISTIQUES

int compterNoeuds(noeud* racine)
{
    if (racine != NULL)
    {
                return 1 + compterNoeuds(racine->gauche) + compterNoeuds(racine->droite);
    }
    return 0;
}

int compterNoeudsInterne(noeud* racine)
{
    if (racine == NULL) return 0;
    if (racine->gauche == NULL && racine->droite == NULL) return 0;
    return 1 + compterNoeudsInterne(racine->gauche) + compterNoeudsInterne(racine->droite);
}

int profondeur(noeud* racine)
{
    if (racine == NULL) return 0;
    if (racine->gauche == NULL && racine->droite == NULL) return 1;
    int courant = profondeur(racine->gauche);
    int courant1 = profondeur(racine->droite);
    if (courant > courant1)
    {
        return 1 + courant;
    }
    return 1 + courant1;
}

int combienProf(noeud* racine, int P)
{
    if (racine != NULL & P == 0) return 1;
    return combienProf(racine->gauche, P - 1) + combienProf(racine->droite, P - 1);
}










int main(int argc, const char * argv[]) {
    int hauteur;
    
    cout << "saisissez la hauteur : ";
    cin >> hauteur;
    noeud* newNoeud = NULL;
createArbrePrefix(&newNoeud, hauteur);
    cout << endl;
    cout << " Arbre : " << endl;
    affichePrefix(newNoeud);
    cout << endl;
    bool result = rechercheValeurPrefix(newNoeud, 5);
    cout << " le nombre est il dans l'arbre ? " << result << endl;
    cout << endl;
    afficheValeurPrefix(newNoeud, 1);
    int result4 = profondeur(newNoeud);
    int result3 = compterNoeudsInterne(newNoeud);
    int result2 = compterFeuille(newNoeud);
    int result1 = combienProf(newNoeud, 1);
    
    cout << " nombre de noeuds dans l'arbre : " << result1 << endl;
    //afficheValeurPrefix(newNoeud, 5);
    
    
    
    
    
    
    
    //createArbreInfix(&newNoeud, hauteur);
    //cout << endl;
   // cout << " Arbre : ";
    //afficheInfix(newNoeud);
    
    return 0;
}
