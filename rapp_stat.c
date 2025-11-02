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



//fonction pour les listes de produits disponibles par usine
void list_produits_dispo(ProduitEnStock produits[], int nb_produits, Periode *periode,const char* filename)
{  FILE *f=fopen(filename,"w");

    if (f == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }


    printf("Produits disponibles par usine :\n");
    fprintf(f, "Produits disponibles par usine :\n");
    for (int i = 0; i < nb_produits; i++) {
        printf("Usine: %s (%s) - Produit: %s (%s) - Quantité en stock: %d\n",
               produits[i].nom_usine, produits[i].id_usine,
               produits[i].nom_produit, produits[i].id_produit,
               produits[i].quantite_stock);
        fprintf(f, "Usine: %s (%s) - Produit: %s (%s) - Quantité en stock: %d\n",
               produits[i].nom_usine, produits[i].id_usine,
               produits[i].nom_produit, produits[i].id_produit,
               produits[i].quantite_stock);
    }
    fclose(f);
}
//fonction pour les produits fabriquers
void list_prod_fab(ProduitEnStock produits[], int nb_produits, Periode *periode,const char* filename) 
{  FILE *f=fopen(filename,"w");
    if (f == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }

    printf("Produits fabriqués dans la période donnée :\n");
    fprintf(f, "Produits fabriqués dans la période donnée :\n");
    for (int i = 0; i < nb_produits; i++) {
        printf("Usine: %s (%s) - Produit: %s (%s) - Quantité en stock: %d\n",
               produits[i].nom_usine, produits[i].id_usine,
               produits[i].nom_produit, produits[i].id_produit,
               produits[i].quantite_stock);
        fprintf(f, "Usine: %s (%s) - Produit: %s (%s) - Quantité en stock: %d\n",
               produits[i].nom_usine, produits[i].id_usine,
               produits[i].nom_produit, produits[i].id_produit,
               produits[i].quantite_stock);
    }
    fclose(f);
}
//focntions pour le chiffre d'affaire
float chiffre_affaire(VenteProduit ventes[], int nb_ventes, Periode *periode,const char* filename)
{ FILE *f=fopen(filename,"w");//ouverture du fichier en mode écriture
    if (f == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return -1.0; // Indiquer une erreur
    }


    float total = 0.0;
    
    printf("----------------------------------------\n");
    fprintf(f, "Rapport de chiffre d'affaires :\n");
    fprintf(f, "----------------------------------------\n");
    for (int i = 0; i < nb_ventes; i++) {
        float montant = ventes[i].quantite_vendue * ventes[i].prix_unitaire;
        total += montant;
        printf("Vente - Usine: %s\nProduit: %s\nQuantité: %d\nPrix unitaire: %.2f\nMontant: %.2f\n\n",
                ventes[i].nom_usine, ventes[i].nom_produit,
                ventes[i].quantite_vendue, ventes[i].prix_unitaire, montant);
        fprintf(f, "Vente - Usine: %s\nProduit: %s\nQuantité: %d\nPrix unitaire: %.2f\nMontant: %.2f\n\n",
                ventes[i].nom_usine, ventes[i].nom_produit,
                ventes[i].quantite_vendue, ventes[i].prix_unitaire, montant);
    }
    printf("----------------------------------------\n");
    printf("Chiffre d'affaires total: %.2f\n", total);
    fprintf(f, "----------------------------------------\n");
    fprintf(f, "Chiffre d'affaires total: %.2f\n", total);
    fclose(f);
    return total;
}

//fonction principale pour tester les fonctions
// int main() {    
//     list_produits_dispo(produits_test, sizeof(produits_test) / sizeof(produits_test[0]), NULL,"list_prod_dispo.txt");
//     list_prod_fab(produits_test, sizeof(produits_test) / sizeof(produits_test[0]), NULL,"list_prod_fab.txt");
//     chiffre_affaire(ventes_test, sizeof(ventes_test) / sizeof(ventes_test[0]), NULL,"chiffre_affaire.txt");
//     return 0;
// }