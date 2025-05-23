#include <stdio.h>
#include <stdlib.h>

typedef struct  n{
    // clé
    int val;

    // enfant à gauche
    struct n* gauche;
    struct n* droite;
} Noeud;

void ajouterNoeud(Noeud ** pArbre, int val)
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
      ajouterNoeud(&((*pArbre)->gauche), val);
    }
    else if (val > (*pArbre)->val)
    {
        ajouterNoeud(&((*pArbre)->droite), val);
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

void affichageInfixe(Noeud * arbre )
{
    // on vérifie que l'arbre n'est pas nul
    if (arbre == NULL) return;

    affichageInfixe(arbre->gauche);
    printf("%d ", arbre->val);
    affichageInfixe(arbre->droite);
}

void affichagePrefixe(Noeud * arbre )
{
    // on vérifie que l'arbre n'est pas nul
    if (arbre == NULL) return;

    printf("%d ", arbre->val);
    affichagePrefixe(arbre->gauche);
    affichagePrefixe(arbre->droite);
}

void affichagePostfixe(Noeud * arbre )
{
    // on vérifie que l'arbre n'est pas nul
    if (arbre == NULL) return;

    affichagePostfixe(arbre->gauche);
    affichagePostfixe(arbre->droite);
    printf("%d ", arbre->val);
}

int main(void)
{
    Noeud* racine = NULL;
    ajouterNoeud(&racine, 10);
    ajouterNoeud(&racine, 8);
    ajouterNoeud(&racine, 5);
    ajouterNoeud(&racine, 3);
    ajouterNoeud(&racine, 15);

    printf("\nAffichage infixe\n");
    affichageInfixe(racine);

    printf("\nAffichage prefixe\n");
    affichagePrefixe(racine);

    printf("\nAffichage postfixe\n");
    affichagePostfixe(racine);

    libererArbre(&racine);
    return 0;
}