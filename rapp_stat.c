/*------------------------------------------------------------------------*/
/* FICHIER:                          rapp_stat.c                           */
/* AUTEUR:                           Blaise Elie                           */    
/* DATE DE CREATION:                 25/09/2025                            */  
/* DATE DE MODIFICATION:             27/09/2025                            */ 
/* DESCRIPTION:                      Rapport et statistiques des entreprises*/    
/*------------------------------------------------------------------------*/  

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "rapp_stat.h"

// Données de test (à remplacer par les vraies données)
static ProduitEnStock produits_test[] = {
    {"U001", "Usine Port-au-Prince", "P001", "Sucre", 500},
    {"U001", "Usine Port-au-Prince", "P002", "Riz", 300},
    {"U002", "Usine Cap-Haïtien", "P001", "Sucre", 250},
    {"U002", "Usine Cap-Haïtien", "P003", "Sel", 400}
};

static VenteProduit ventes_test[] = {
    {"U001", "Usine Port-au-Prince", "P001", "Sucre", 100, 50.0, {.tm_mday=15, .tm_mon=8, .tm_year=125}},
    {"U001", "Usine Port-au-Prince", "P002", "Riz", 50, 45.0, {.tm_mday=16, .tm_mon=8, .tm_year=125}},
    {"U002", "Usine Cap-Haïtien", "P003", "Sel", 75, 30.0, {.tm_mday=17, .tm_mon=8, .tm_year=125}}
};

// Données de test en attendant les vraies données
static ProduitEnStock produits_test[] = {
    {"U---", "En attente...", "P---", "En attente...", 0},
    {"U---", "En attente...", "P---", "En attente...", 0}
};

//fonction pour les listes de produits disponibles par usine
void list_produits_dispo(ProduitEnStock produits[], int nb_produits, Periode *periode,const char* filename)
{  FILE *f=fopen(filename,"w");

    if (f == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }


    printf("Produits disponibles par usine :\n");
    for (int i = 0; i < nb_produits; i++) {
        printf("Usine: %s (%s) - Produit: %s (%s) - Quantité en stock: %d\n",
               produits[i].nom_usine, produits[i].id_usine,
               produits[i].nom_produit, produits[i].id_produit,
               produits[i].quantite_stock);
    }
}
//fonction pour les produits fabriquers
void list_prod_fab(ProduitEnStock produits[], int nb_produits, Periode *periode,const char* filename) 
{  FILE *f=fopen(filename,"w");
    if (f == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }

    printf("Produits fabriqués dans la période donnée :\n");
    for (int i = 0; i < nb_produits; i++) {
        printf("Usine: %s (%s) - Produit: %s (%s) - Quantité en stock: %d\n",
               produits[i].nom_usine, produits[i].id_usine,
               produits[i].nom_produit, produits[i].id_produit,
               produits[i].quantite_stock);
    }
}
//focntions pour le chiffre d'affaire
float chiffre_affaire(VenteProduit ventes[], int nb_ventes, Periode *periode,const char* filename)
{ FILE *f=fopen(filename,"w");//ouverture du fichier en mode écriture
    if (f == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return -1.0; // Indiquer une erreur
    }


    float total = 0.0;
    for (int i = 0; i < nb_ventes; i++) {
        total += ventes[i].quantite_vendue * ventes[i].prix_unitaire;
    }
    return total;
}