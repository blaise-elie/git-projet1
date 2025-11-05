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
#include "entrep.h"

/*------------------------------------------------------------------------*/
/* FONCTION:              list_produits_dispo                            */
/* DESCRIPTION:           Affiche la liste des produits disponibles 
                          avec titre du rapport,date,nom de l'usine,nom 
                          du produit,la quantité disponible              */
/* PARAMETRES:            Aucun                                          */
/* VALEUR DE RETOUR:      Aucune                                         */
/* AUTEUR:                Blaise Elie                                    */
/* DATE DE CREATION:      25/10/2025                                    */
/* DATE DE MODIFICATION:  02/11/2025                                    */
/*----------------------------------------------------------------------*/

void list_prod_dispo() 
{  
 // Récupérer les données d'historique de production et pour chaque lot
 // afficher: date de production, nom de l'usine, nom du produit

}



/*------------------------------------------------------------------------*/
/* FONCTION:              list_prod_fab                                   */
/* DESCRIPTION:           Affiche la liste des produits fabriqués 
                          avec titre du rapport,date,nom de l'usine,nom 
                          du produit,la quantité disponible              */
/* PARAMETRES:            Aucun                                          */
/* VALEUR DE RETOUR:      Aucune                                         */
/* AUTEUR:                Blaise Elie                                    */
/* DATE DE CREATION:      25/10/2025                                    */
/* DATE DE MODIFICATION:  02/11/2025                                    */
/*----------------------------------------------------------------------*/

  // Dans rapp_sta.c

#include "entrep.h"

void List_Prod_Fab() {
    FILE *fHist, *fProd, *fUsine;
    char dat_debut[11], dat_fin[11];
    int found;
    
    // Structures pour stocker les données
    struct {
        char nom_usine[50];
        char nom_produit[50];
        int qte_totale;
    } resultats[100];
    int nb_resultats = 0;
    
    // 1. Demander la période à l'utilisateur
    printf("\n=== LISTE DES PRODUITS FABRIQUES ===\n");
    printf("Date de debut (JJ/MM/AAAA): ");
    scanf("%s", dat_debut);
    printf("Date de fin (JJ/MM/AAAA): ");
    scanf("%s", dat_fin);
    
    // 2. Ouvrir le fichier Hist_Prod.dat
    fHist = fopen("Hist_Prod.dat", "rb");
    if (fHist == NULL) {
        printf("Erreur: Impossible d'ouvrir Hist_Prod.dat\n");
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


//     float total = 0.0;
    
//     printf("----------------------------------------\n");
//     fprintf(f, "Rapport de chiffre d'affaires :\n");
//     fprintf(f, "----------------------------------------\n");
//     for (int i = 0; i < nb_ventes; i++) {
//         float montant = ventes[i].quantite_vendue * ventes[i].prix_unitaire;
//         total += montant;
//         printf("Vente - Usine: %s\nProduit: %s\nQuantité: %d\nPrix unitaire: %.2f\nMontant: %.2f\n\n",
//                 ventes[i].nom_usine, ventes[i].nom_produit,
//                 ventes[i].quantite_vendue, ventes[i].prix_unitaire, montant);
//         fprintf(f, "Vente - Usine: %s\nProduit: %s\nQuantité: %d\nPrix unitaire: %.2f\nMontant: %.2f\n\n",
//                 ventes[i].nom_usine, ventes[i].nom_produit,
//                 ventes[i].quantite_vendue, ventes[i].prix_unitaire, montant);
//     }
//     printf("----------------------------------------\n");
//     printf("Chiffre d'affaires total: %.2f\n", total);
//     fprintf(f, "----------------------------------------\n");
//     fprintf(f, "Chiffre d'affaires total: %.2f\n", total);
//     fclose(f);
//     return total;
// }

