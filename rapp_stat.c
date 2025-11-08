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

// helper: strip trailing CR/LF produced on Windows or Unix
static void trim_newline(char *s) {
    if (s == NULL) return;
    size_t n = strcspn(s, "\r\n");
    s[n] = '\0';
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
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("           LISTE DES PRODUITS DISPONIBLES EN STOCK\n");
    printf("                    Date: %s\n", date_actuelle);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
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
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("%-55s %d\n", "TOTAL GENERAL:", total_general);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    
    printf("\nAppuyez sur Entree pour continuer...");
    getchar();
    getchar();
}

// Dans rapp_sta.c

// #include "entrep.h"

// void list_prod_fab() {
//     FILE *fHist;
//     int found;
//     char dat_debut[11], dat_fin[11];

//     // Structures pour stocker les données
//     struct {
//         char nom_usine[50];
//         char nom_produit[50];
//         int qte_totale;
//     } resultats[200];
//     int nb_resultats = 0;

//     // Demander la période
//     printf("Entrez la date de début (JJ/MM/AAAA) : ");
//     if (fgets(dat_debut, sizeof(dat_debut), stdin) == NULL) return;
//     dat_debut[strcspn(dat_debut, "\n")] = '\0';
//     printf("Entrez la date de fin (JJ/MM/AAAA) : ");
//     if (fgets(dat_fin, sizeof(dat_fin), stdin) == NULL) return;
//     dat_fin[strcspn(dat_fin, "\n")] = '\0';

//     int d_deb = date_to_yyyymmdd(dat_debut);
//     int d_fin = date_to_yyyymmdd(dat_fin);
//     if (d_deb < 0 || d_fin < 0) {
//         printf("Dates invalides. Utilisez le format JJ/MM/AAAA.\n");
//         return;
//     }

//     // 2. Ouvrir le fichier Hist_Prod.dat
//     fHist = fopen(HIST_PROD_FILE, "rb");
//     if (fHist == NULL) {
//         printf("Erreur: Impossible d'ouvrir %s\n", HIST_PROD_FILE);
//         return;
//     }

//     // 3. Parcourir tous les lots de production
//     Hist_production lot;
//     while (fread(&lot, sizeof(Hist_production), 1, fHist) == 1) {
//         int lot_date = date_to_yyyymmdd(lot.Dat_prod);
//         if (lot_date < 0) continue;
//         if (lot_date < d_deb || lot_date > d_fin) continue;

//         // Récupérer le produit correspondant
//         FILE *fProd = fopen(PRODUIT_FILE, "rb");
//         if (fProd == NULL) continue;
//         Produit prod;
//         int prod_found = 0;
//         while (fread(&prod, sizeof(Produit), 1, fProd) == 1) {
//             if (prod.Id_prod == lot.id_prod) { prod_found = 1; break; }
//         }
//         fclose(fProd);
//         if (!prod_found) continue;

//         // Récupérer l'usine correspondante
//         FILE *fUsine = fopen("usine.dat", "rb");
//         if (fUsine == NULL) continue;
//         Usine usine;
//         int usine_found = 0;
//         while (fread(&usine, sizeof(Usine), 1, fUsine) == 1) {
//             if (usine.id_usine == prod.Id_usine) { usine_found = 1; break; }
//         }
//         fclose(fUsine);
//         if (!usine_found) continue;

//         // Chercher si cette combinaison usine/produit existe déjà
//         int idx = -1;
//         for (int i = 0; i < nb_resultats; i++) {
//             if (strcmp(resultats[i].nom_usine, usine.Usi_nom) == 0 &&
//                 strcmp(resultats[i].nom_produit, prod.Pro_nom) == 0) {
//                 idx = i; break;
//             }
//         }
//         if (idx == -1) {
//             strncpy(resultats[nb_resultats].nom_usine, usine.Usi_nom, sizeof(resultats[nb_resultats].nom_usine)-1);
//             resultats[nb_resultats].nom_usine[sizeof(resultats[nb_resultats].nom_usine)-1] = '\0';
//             strncpy(resultats[nb_resultats].nom_produit, prod.Pro_nom, sizeof(resultats[nb_resultats].nom_produit)-1);
//             resultats[nb_resultats].nom_produit[sizeof(resultats[nb_resultats].nom_produit)-1] = '\0';
//             resultats[nb_resultats].qte_totale = lot.Lot_qte;
//             nb_resultats++;
//         } else {
//             resultats[idx].qte_totale += lot.Lot_qte;
//         }
//     }
//     fclose(fHist);

//     // Afficher les résultats
//     printf("\n");
//     printf("=================================================================\n");
//     printf("  PRODUITS FABRIQUES du %s au %s\n", dat_debut, dat_fin);
//     printf("=================================================================\n");
//     printf("%-30s %-25s %s\n", "USINE", "PRODUIT", "QUANTITE");
//     printf("-----------------------------------------------------------------\n");
//     for (int i = 0; i < nb_resultats; i++) {
//         printf("%-30s %-25s %d\n", resultats[i].nom_usine, resultats[i].nom_produit, resultats[i].qte_totale);
//     }
//     printf("=================================================================\n");
//     printf("\nAppuyez sur Entree pour continuer...");
//     getchar();
// }


/* FONCTION:              lister_quantite_fabriquee                       */ 
/* AUTEUR:                (Votre Nom)                                     */ 
/* PARAMETRE:             Aucun                                           */
/* VALEUR DE RETOUR:      Aucune                                          */
/* DESCRIPTION:           Calcule et affiche la quantite totale de chaque */
/* produit jamais fabriquee, agregee par usine.    */

void list_prod_fab() {
    FILE *fHist;
    Hist_production lot;
    Produit prod;
    Usine usine_tmp;

    // Définir la structure pour stocker les quantités fabriquées par ID
    // Réutilise CaisseAggregat pour la simplicité, mais change la sémantique
    typedef struct {
        int id;
        int qte_fabriquee;
        char nom[50];
        int id_usine; // Ajout de l'ID usine pour l'agrégation
    } FabricationAggregat;

    // Utilisation d'un tableau pour agréger les totaux (simplification)
    FabricationAggregat fab_par_produit[MAX_AGGREGATES] = {0};
    int prod_count = 0;
    int total_general_fab = 0;

    printf("\n");
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃            RAPPORT DES QUANTITÉS TOTALES FABRIQUÉES                ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

    // --- 1. PARCOURS DE L'HISTORIQUE DE PRODUCTION ---
    fHist = fopen(HIST_PROD_FILE, "rb");
    if (fHist == NULL) {
        printf("Erreur: Impossible d'ouvrir %s (fichier d'historique introuvable).\n", HIST_PROD_FILE);
        return;
    }

    while (fread(&lot, sizeof(Hist_production), 1, fHist) == 1) {
      
        // --- 2. AGRÉGATION PAR PRODUIT ---
        int i;
        int found_prod = 0;
        
        // Chercher si le produit est déjà dans notre tableau d'agrégation
        for (i = 0; i < prod_count; i++) {
            if (fab_par_produit[i].id == lot.id_prod) {
                fab_par_produit[i].qte_fabriquee += lot.Lot_qte;
                found_prod = 1;
                break;
            }
        }
        
        // Si nouveau produit, l'ajouter et récupérer son nom/usine
        if (!found_prod && prod_count < MAX_AGGREGATES) {
             if (lire_produit(PRODUIT_FILE, lot.id_prod, &prod)) {
                fab_par_produit[prod_count].id = lot.id_prod;
                fab_par_produit[prod_count].qte_fabriquee = lot.Lot_qte;
                strcpy(fab_par_produit[prod_count].nom, prod.Pro_nom);
                fab_par_produit[prod_count].id_usine = prod.Id_usine;
                prod_count++;
            } else {
                 printf("ATTENTION: Produit ID %d associe au lot %d non trouve.\n", lot.id_prod, lot.Id_lot);
            }
        }
        total_general_fab += lot.Lot_qte;
    }

    fclose(fHist);

    // --- 3. AFFICHAGE DES RÉSULTATS AGRÉGÉS PAR USINE ---
    
    // Ouvrir le fichier des usines pour l'affichage structuré
    FILE *fUsine = fopen("usine.dat", "rb");
    if (fUsine == NULL) {
        printf("Erreur: Impossible d'ouvrir usine.dat.\n");
        return;
    }

    printf("%-30s %-25s %s\n", "USINE", "PRODUIT", "QTE FABRIQUÉE");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    // Parcourir toutes les usines pour structurer l'affichage
    while (fread(&usine_tmp, sizeof(Usine), 1, fUsine) == 1) {
        int total_usine_fab = 0;
        int usine_a_produit = 0;
        
        // Parcourir les résultats agrégés pour trouver les produits de cette usine
        for (int i = 0; i < prod_count; i++) {
            if (fab_par_produit[i].id_usine == usine_tmp.id_usine) {
                
                // Afficher l'usine (une seule fois pour les produits de cette usine)
                if (!usine_a_produit) {
                    printf("\n%-30s\n", usine_tmp.Usi_nom);
                    usine_a_produit = 1;
                }
                
                // Afficher le produit et sa quantité totale fabriquée
                printf("%-30s %-25s %d\n", 
                       "", // Laisser vide car le nom de l'usine est affiché au-dessus
                       fab_par_produit[i].nom,
                       fab_par_produit[i].qte_fabriquee);
                
                total_usine_fab += fab_par_produit[i].qte_fabriquee;
            }
        }
        
        // Afficher le sous-total par usine si elle a des produits
        if (usine_a_produit) {
            printf("                                                 ━━━━━━━━━━━━━━\n");
            printf("%-30s %-25s %d\n", "", "Sous-total Fabriqué:", total_usine_fab);
        }
    }
    
    fclose(fUsine);
    
    // --- 4. AFFICHAGE DU TOTAL GÉNÉRAL ---
    printf("\n\n");
    printf("%-55s %d\n", "TOTAL GENERAL FABRIQUE:", total_general_fab);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    
    printf("\nAppuyez sur Entree pour continuer...");
    // Nécessaire pour attendre la saisie de l'utilisateur
    getchar(); 
}



// Fonction utilitaire pour convertir "JJ/MM/AAAA" en entier pour comparaison (AAAAMMJJ)
// Fonction de conversion de date (hypothèse d'implémentation)
int date_to_int(const char *date_str) {
    int day, month, year;
    if (sscanf(date_str, "%d/%d/%d", &day, &month, &year) == 3) {
        return year * 10000 + month * 100 + day; // Format AAAAMMJJ pour comparaison
    }
    return 0; 
}
/*--------------------------------------------------------------------------------*/
/* FONCTION:              chiffre d'affaire                                      */
/* DESCRIPTION:           Calcule et affiche le chiffre d'affaire total
                          pour une periode donnee                             */
/* PARAMETRES:            Aucun                                               */
/* VALEUR DE RETOUR:      Aucune                                              */
/* AUTEUR:                Blaise Elie                                         */
/* DATE DE CREATION:      25/10/2025                                          */
/* DATE DE MODIFICATION:  02/11/2025                                          */
/*------------------------------------------------------------------------------*/

void chiffre_affaire(void)
{
    char date_debut[11];
    char date_fin[11];

    // Demander la période à l'utilisateur
    printf("Entrez la date de debut (JJ/MM/AAAA): ");
    if (fgets(date_debut, sizeof(date_debut), stdin) == NULL) return;
    vider_buffer();
    trim_newline(date_debut);
    printf("Entrez la date de fin (JJ/MM/AAAA): ");
    if (fgets(date_fin, sizeof(date_fin), stdin) == NULL) return;
    trim_newline(date_fin);

    FILE *f_hist = fopen(HIST_VENTES_FILE, "rb");
    if (f_hist == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier d'historique des ventes.\n");
        return;
    }

    Vente vente_courante;
    Produit produit_tmp;
    Usine usine_tmp;

    // Convertir les dates de début et fin pour la comparaison
    int start_date_int = date_to_int(date_debut);
    int end_date_int = date_to_int(date_fin);
    if (start_date_int < 0 || end_date_int < 0) {
        printf("Dates invalides. Utilisez le format JJ/MM/AAAA.\n");
        fclose(f_hist);
        return;
    }
    
    // Total général pour vérification
    double total_ca_global = 0.0;
    int ventes_comptees = 0;

    // Utilisation de tableaux pour agréger les totaux (simplification)
    CaisseAggregat ca_par_produit[MAX_AGGREGATES] = {0};
    CaisseAggregat ca_par_usine[MAX_AGGREGATES] = {0};
    int prod_count = 0;
    int usine_count = 0;

    printf("\n━━━━Analyse du Chiffre d'Affaires du %s au %s━━━━\n", date_debut, date_fin);

    // --- 1. PARCOURS DE L'HISTORIQUE DES VENTES ---
    while (fread(&vente_courante, sizeof(Vente), 1, f_hist) == 1)
    {
        int vente_date_int = date_to_int(vente_courante.dat_vente);
        
        // Vérifier si la vente est dans la plage de dates
        if (vente_date_int >= start_date_int && vente_date_int <= end_date_int)
        {
            double montant_ca = vente_courante.prix_total;
            total_ca_global += montant_ca;
            ventes_comptees++;

            // Récupérer le produit (nécessaire pour l'ID Usine)
            if (!lire_produit(PRODUIT_FILE, vente_courante.id_prod, &produit_tmp)) {
                 printf("ATTENTION: Produit ID %d de la vente %d non trouve.\n", vente_courante.id_prod, vente_courante.id_vente);
                 continue; // Passer à la vente suivante
            }
            
            // --- 2. AGRÉGATION PAR PRODUIT ---
            int i;
            int found_prod = 0;
            for (i = 0; i < prod_count; i++) {
                if (ca_par_produit[i].id == vente_courante.id_prod) {
                    ca_par_produit[i].total_ca += montant_ca;
                    found_prod = 1;
                    break;
                }
            }
            // Si nouveau produit, l'ajouter
            if (!found_prod && prod_count < MAX_AGGREGATES) {
                ca_par_produit[prod_count].id = vente_courante.id_prod;
                ca_par_produit[prod_count].total_ca = montant_ca;
                strcpy(ca_par_produit[prod_count].nom, produit_tmp.Pro_nom);
                prod_count++;
            }

            // --- 3. AGRÉGATION PAR USINE ---
            int id_usine = produit_tmp.Id_usine;
            int found_usine = 0;
            for (i = 0; i < usine_count; i++) {
                if (ca_par_usine[i].id == id_usine) {
                    ca_par_usine[i].total_ca += montant_ca;
                    found_usine = 1;
                    break;
                }
            }
            // Si nouvelle usine, l'ajouter
            if (!found_usine && usine_count < MAX_AGGREGATES) {
                if (lire_usine("usine.dat", id_usine, &usine_tmp)) {
                    ca_par_usine[usine_count].id = id_usine;
                    ca_par_usine[usine_count].total_ca = montant_ca;
                    strcpy(ca_par_usine[usine_count].nom, usine_tmp.Usi_nom);
                    usine_count++;
                } else {
                     printf("ATTENTION: Usine ID %d pour produit %d non trouvee.\n", id_usine, produit_tmp.Id_prod);
                }
            }
        }
    }

    fclose(f_hist);

    // --- 4. AFFICHAGE DES RÉSULTATS ---
    printf("\nTotal des ventes comptees: %d\n", ventes_comptees);
    printf("Chiffre d'Affaires GLOBAL total: %.2f\n", total_ca_global);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    // Affichage par Produit
    printf("\n--- Chiffre d'Affaires par Produit ---\n");
    printf("| ID Produit | Nom Produit       | C.A. Total (Gourdes) |\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    for (int i = 0; i < prod_count; i++) {
        printf("| %-10d | %-17s | %-20.2f |\n", 
               ca_par_produit[i].id, 
               ca_par_produit[i].nom, 
               ca_par_produit[i].total_ca);
    }
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    // Affichage par Usine
             printf("\n━━━━ Chiffre d'Affaires par Usine ━━━━\n");
    printf("| ID Usine   | Nom Usine         | C.A. Total (Gourdes) |\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    for (int i = 0; i < usine_count; i++) {
        printf("| %-10d | %-17s | %-20.2f |\n", 
               ca_par_usine[i].id, 
               ca_par_usine[i].nom, 
               ca_par_usine[i].total_ca);
    }
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}