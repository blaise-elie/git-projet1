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

// Helper: convert date string "DD/MM/YYYY" into integer YYYYMMDD for comparisons
static int date_to_yyyymmdd(const char *d) {
    if (d == NULL) return -1;
    int dd, mm, yyyy;
    if (sscanf(d, "%d/%d/%d", &dd, &mm, &yyyy) != 3) return -1;
    if (dd < 1 || dd > 31 || mm < 1 || mm > 12 || yyyy < 0) return -1;
    return yyyy*10000 + mm*100 + dd;
}

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

// Dans rapp_sta.c


void list_prod_dispo() {
    FILE *fProd, *fUsine;
    Produit prod;
    Usine usine;
    int total_general = 0;
    char date_actuelle[20];
    
    // 1. Obtenir la date actuelle
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(date_actuelle, 20, "%d/%m/%Y", tm_info);
    
    // 2. Afficher l'en-tête du rapport
    printf("\n");
    printf("=================================================================\n");
    printf("           LISTE DES PRODUITS DISPONIBLES EN STOCK\n");
    printf("                    Date: %s\n", date_actuelle);
    printf("=================================================================\n");
    printf("%-30s %-25s %s\n", "USINE", "PRODUIT", "QUANTITE");
    printf("-----------------------------------------------------------------\n");
    
    // 3. Ouvrir le fichier des usines (nom utilisé ailleurs: "usine.dat")
    fUsine = fopen("usine.dat", "rb");
    if (fUsine == NULL) {
        printf("Erreur: Impossible d'ouvrir usine.dat (fichier des usines introuvable)\n");
        return;
    }
    
    // 4. Parcourir toutes les usines
    while (fread(&usine, sizeof(Usine), 1, fUsine) == 1) {
        int total_usine = 0;
        int a_des_produits = 0;
        
        // 5. Ouvrir le fichier des produits pour cette usine
        fProd = fopen(PRODUIT_FILE, "rb");
        if (fProd == NULL) {
            printf("Erreur: Impossible d'ouvrir %s (fichier des produits introuvable)\n", PRODUIT_FILE);
            fclose(fUsine);
            return;
        }
        
        // 6. Parcourir tous les produits de cette usine
        while (fread(&prod, sizeof(Produit), 1, fProd) == 1) {
            // Vérifier si le produit appartient à cette usine
            if (prod.Id_usine == usine.id_usine)  {
                // Afficher le produit avec sa quantité
                printf("%-30s %-25s %d\n", 
                       usine.Usi_nom,
                       prod.Pro_nom,
                       prod.pro_qte);
                
                total_usine += prod.pro_qte;
                a_des_produits = 1;
            }
        }
        
        fclose(fProd);
        
        // 7. Afficher le sous-total par usine si elle a des produits
        if (a_des_produits) {
            printf("                                                  -----------\n");
            printf("%-30s %-25s %d\n", "", "Sous-total:", total_usine);
            printf("\n");
            total_general += total_usine;
        }
    }
    
    fclose(fUsine);
    
    // 8. Afficher le total général
    printf("=================================================================\n");
    printf("%-55s %d\n", "TOTAL GENERAL:", total_general);
    printf("=================================================================\n");
    
    printf("\nAppuyez sur Entree pour continuer...");
    getchar();
    getchar();
}

// Dans rapp_sta.c

#include "entrep.h"

void list_prod_fab() {
    FILE *fHist;
    int found;
    char dat_debut[11], dat_fin[11];

    // Structures pour stocker les données
    struct {
        char nom_usine[50];
        char nom_produit[50];
        int qte_totale;
    } resultats[200];
    int nb_resultats = 0;

    // Demander la période
    printf("Entrez la date de début (JJ/MM/AAAA) : ");
    if (fgets(dat_debut, sizeof(dat_debut), stdin) == NULL) return;
    dat_debut[strcspn(dat_debut, "\n")] = '\0';
    printf("Entrez la date de fin (JJ/MM/AAAA) : ");
    if (fgets(dat_fin, sizeof(dat_fin), stdin) == NULL) return;
    dat_fin[strcspn(dat_fin, "\n")] = '\0';

    int d_deb = date_to_yyyymmdd(dat_debut);
    int d_fin = date_to_yyyymmdd(dat_fin);
    if (d_deb < 0 || d_fin < 0) {
        printf("Dates invalides. Utilisez le format JJ/MM/AAAA.\n");
        return;
    }

    // 2. Ouvrir le fichier Hist_Prod.dat
    fHist = fopen(HIST_PROD_FILE, "rb");
    if (fHist == NULL) {
        printf("Erreur: Impossible d'ouvrir %s\n", HIST_PROD_FILE);
        return;
    }

    // 3. Parcourir tous les lots de production
    Hist_production lot;
    while (fread(&lot, sizeof(Hist_production), 1, fHist) == 1) {
        int lot_date = date_to_yyyymmdd(lot.Dat_prod);
        if (lot_date < 0) continue;
        if (lot_date < d_deb || lot_date > d_fin) continue;

        // Récupérer le produit correspondant
        FILE *fProd = fopen(PRODUIT_FILE, "rb");
        if (fProd == NULL) continue;
        Produit prod;
        int prod_found = 0;
        while (fread(&prod, sizeof(Produit), 1, fProd) == 1) {
            if (prod.Id_prod == lot.id_prod) { prod_found = 1; break; }
        }
        fclose(fProd);
        if (!prod_found) continue;

        // Récupérer l'usine correspondante
        FILE *fUsine = fopen("usine.dat", "rb");
        if (fUsine == NULL) continue;
        Usine usine;
        int usine_found = 0;
        while (fread(&usine, sizeof(Usine), 1, fUsine) == 1) {
            if (usine.id_usine == prod.Id_usine) { usine_found = 1; break; }
        }
        fclose(fUsine);
        if (!usine_found) continue;

        // Chercher si cette combinaison usine/produit existe déjà
        int idx = -1;
        for (int i = 0; i < nb_resultats; i++) {
            if (strcmp(resultats[i].nom_usine, usine.Usi_nom) == 0 &&
                strcmp(resultats[i].nom_produit, prod.Pro_nom) == 0) {
                idx = i; break;
            }
        }
        if (idx == -1) {
            strncpy(resultats[nb_resultats].nom_usine, usine.Usi_nom, sizeof(resultats[nb_resultats].nom_usine)-1);
            resultats[nb_resultats].nom_usine[sizeof(resultats[nb_resultats].nom_usine)-1] = '\0';
            strncpy(resultats[nb_resultats].nom_produit, prod.Pro_nom, sizeof(resultats[nb_resultats].nom_produit)-1);
            resultats[nb_resultats].nom_produit[sizeof(resultats[nb_resultats].nom_produit)-1] = '\0';
            resultats[nb_resultats].qte_totale = lot.Lot_qte;
            nb_resultats++;
        } else {
            resultats[idx].qte_totale += lot.Lot_qte;
        }
    }
    fclose(fHist);

    // Afficher les résultats
    printf("\n");
    printf("=================================================================\n");
    printf("  PRODUITS FABRIQUES du %s au %s\n", dat_debut, dat_fin);
    printf("=================================================================\n");
    printf("%-30s %-25s %s\n", "USINE", "PRODUIT", "QUANTITE");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < nb_resultats; i++) {
        printf("%-30s %-25s %d\n", resultats[i].nom_usine, resultats[i].nom_produit, resultats[i].qte_totale);
    }
    printf("=================================================================\n");
    printf("\nAppuyez sur Entree pour continuer...");
    getchar();
}
