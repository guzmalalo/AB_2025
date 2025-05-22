#include <stdio.h>
#include <stdlib.h>

typedef struct  n{
    // clé
    int val;

    // enfant à gauche
    struct n* gauche;
    struct n* droite;
} Noeud;

void ajouterNoued(Noeud ** pArbre, int val)
{
    if (*pArbre == NULL)
    {
        *pArbre = malloc(sizeof(Noeud));
        (*pArbre)->val = val;
        (*pArbre)->gauche = NULL;
        (*pArbre)->droite = NULL;
    }
    else if ( val < (*pArbre)->val )
    {
      ajouterNoued(&((*pArbre)->gauche), val);
    }
    else if (val > (*pArbre)->val)
    {
        ajouterNoued(&((*pArbre)->droite), val);
    }else
    {
        printf("La valeur est déja dans l'arbre");
    }
}

void libererArbre(Noeud ** pArbre)
{
    // on vérifie que l'arbre n'est pas vide
    if (*pArbre == NULL)
    {
        return;
    }
    // on efface l'arbre à gauche
    libererArbre(&((*pArbre)->gauche));
    // on efface l'arbre à droite
    libererArbre(&((*pArbre)->droite));
    // on efface la racine
    free(*pArbre);
}

int main(void)
{
    Noeud* racine = NULL;
    ajouterNoued(&racine, 10);
    ajouterNoued(&racine, 8);
    ajouterNoued(&racine, 5);
    ajouterNoued(&racine, 3);
    ajouterNoued(&racine, 15);

    libererArbre(&racine);
    return 0;
}