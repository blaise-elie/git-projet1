<<<<<<< HEAD
/*------------------------------------------------------------------------*/
/* FCHIER:                          vente.h                               */
/*AUTEUR:                           JEAN David Kehl                       */    
/*DATE DE CREATIION:                26/09/2025                            */  
/*DATE DE MODIFICATION:             02/10/2025                            */ 
/*DESCRIPTION:                      fichier contenant les nouveaux types de
                                    données, les prototypes, les structures 
                                    de données et les constantes          */    
/*------------------------------------------------------------------------*/ 
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "entrep.h"

// Insère une vente : lit les infos auprès de l'utilisateur, vérifie et met à jour le stock
int ins_vente() {
    Vente vente;
    Produit p;
    long record_pos = -1;
    int c;

    // Saisie des informations de vente
    
    vente.id_vente = obtenir_dernier_id_vente(HIST_VENTES_FILE) + 1;
    printf("Entrez l'ID du produit vendu : ");
    if (scanf("%d", &vente.id_prod) != 1) {
        printf("Entrée invalide pour l'ID du produit.\n");
        vider_buffer();
        return 0;
    }

    

    printf("Entrez la quantité vendue : ");
    if (scanf("%d", &vente.qte_vendue) != 1) {
        printf("Entrée invalide pour la quantité.\n");
       vider_buffer();
        return 0;   
    }
    // vider le buffer
     vider_buffer();

    // Ouvrir le fichier des produits (même fichier utilisé par prod.c)
    FILE *fp_prod = fopen(PRODUIT_FILE, "r+b");
    if (fp_prod == NULL) {
        perror("Erreur lors de l'ouverture du fichier des produits");
        return 0;
    }

    // Parcourir le fichier et garder la position du record trouvé
    while (1) {
        long pos = ftell(fp_prod);
        if (fread(&p, sizeof(Produit), 1, fp_prod) != 1) break;
        if (p.Id_prod == vente.id_prod) { record_pos = pos; break; }
    }

    

    // Vérifier la quantité disponible
    if (p.pro_qte < vente.qte_vendue) {
        printf("Erreur : Stock insuffisant pour le produit %d (Stock: %d, Demandé: %d).\n",
               p.Id_prod, p.pro_qte, vente.qte_vendue);
        fclose(fp_prod);
        return 0;
    }

    // Mettre à jour la quantité et réécrire le record
    p.pro_qte -= vente.qte_vendue;
    if (fseek(fp_prod, record_pos, SEEK_SET) != 0) {
        perror("Erreur lors du repositionnement dans le fichier produit");
        fclose(fp_prod);
        return 0;
    }
    if (fwrite(&p, sizeof(Produit), 1, fp_prod) != 1) {
        perror("Erreur lors de l'ecriture du produit");
        fclose(fp_prod);
        return 0;
    }
    fflush(fp_prod);
    fclose(fp_prod);

    // Calculer les montants de la vente
    vente.prix_unit = p.pro_prix;
    vente.prix_total = vente.prix_unit * vente.qte_vendue;
    generer_date_courante(vente.dat_vente);

    // Enregistrer la vente (historique)
    FILE *fp_hist = fopen(HIST_VENTES_FILE, "ab");
    if (fp_hist == NULL) {
        perror("Erreur d'ouverture du fichier d'historique des ventes");
        return 0;
    }
    if (fwrite(&vente, sizeof(Vente), 1, fp_hist) != 1) {
        perror("Erreur d'ecriture de la vente dans l'historique");
        fclose(fp_hist);
        return 0;
    }
    fclose(fp_hist);

    printf("Vente enregistrée avec succès (ID vente : %d).\n", vente.id_vente);
    return 1;

    
}



     



//     // 2. Parcourir le fichier pour trouver le produit (on sauvegarde la position AVANT la lecture)
//     while (1) 
//     {
//         long pos = ftell(fp_prod);
//         if (fread(&p, sizeof(Produit), 1, fp_prod) != 1) break;
//         if (p.Id_prod == v.id_prod) 
//         {
//             produit_trouve = 1;
//             record_pos = pos;
//             break; // Produit trouvé
//         }
//     }

//     if (!produit_trouve) 
//     {
//         printf("Erreur : Produit d'ID %d non trouvé dans le stock.\n", v.id_prod);
//         fclose(fp_prod);
//         return 0;
//     }

//     // 3. Vérifier la quantité disponible
//     if (p.pro_qte < v.qte_vendue) 
//     {
//         printf("Erreur : Stock insuffisant pour le produit %d (Stock: %d, Demandé: %d).\n", 
//                p.Id_prod, p.pro_qte, v.qte_vendue);
//         fclose(fp_prod);
//         return 0;
//     }

//     // 4. Mettre à jour la quantité et l'enregistrer dans le fichier produit.dat
//     p.pro_qte -= v.qte_vendue;

//     if (record_pos >= 0) 
//     {
//         if (fseek(fp_prod, record_pos, SEEK_SET) != 0) 
//         {
//             perror("Erreur lors du repositionnement dans produit.dat");
//             fclose(fp_prod);
//             return 0;
//         }
//         if (fwrite(&p, sizeof(Produit), 1, fp_prod) != 1) {
//             perror("Erreur lors de l'ecriture dans produit.dat");
//             fclose(fp_prod);
//             return 0;
//         }
//         fflush(fp_prod);
//         printf("Stock du produit %d mis à jour. Nouvelle quantité : %d.\n", p.Id_prod, p.pro_qte);
//     } else {
//         printf("Erreur interne: position d'enregistrement invalide.\n");
//         fclose(fp_prod);
//         return 0;
//     }
//     fclose(fp_prod);

//     //5. Effectuer la vente
//     v.prix_unit = p.pro_prix;
//     v.prix_total = v.prix_unit * v.qte_vendue;
//     generer_date_courante(v.dat_vente);

//     //6. Enregistrement de la vente dans Hist_vente.dat
//     FILE *fp_vente = fopen(HIST_VENTES_FILE, "ab");
//     if (fp_vente == NULL) {
//         perror("Erreur d'ouverture de Hist_Ventes.dat");
//         return 0;
//     }

//     if (fwrite(&v, sizeof(Vente), 1, fp_vente) != 1) {
//         perror("Erreur d'écriture de la vente");
//         fclose(fp_vente);
//         return 0;
//     }

//     fclose(fp_vente);
//     printf("Vente enregistrée avec succès (ID vente : %d).\n", v.id_vente);
//     return 1;

// }


/*-------------------------------------------------------------------------------*/
/*FOCNTION:    Obtenir le dernier ID de vente                                     */
/*Date de création:      18/10/2025                                                */
/*Date de modification: 18/10/2025                                                 */
/*DESCRIPTION:           Cette fonction permet d'obtenir le dernier ID de vente   */
/*VALEUR DE RETOUR:      Dernier ID de vente                                     */


int obtenir_dernier_id_vente(const char *nom_fichier) {
    FILE *fp = fopen(nom_fichier, "rb");
    if (fp == NULL) {
        // Si le fichier n'existe pas, on considère que c'est la première vente
        return 0;
    }

    Vente v;
    int max_id = 0;

    // Parcourir le fichier pour trouver le plus grand ID de vente
    while (fread(&v, sizeof(Vente), 1, fp) == 1) {
        if (v.id_vente > max_id) {
            max_id = v.id_vente;
        }
    }

    fclose(fp);
    return max_id;
}


=======
/*------------------------------------------------------------------------*/
/* FCHIER:                          vente.h                               */
/*AUTEUR:                           JEAN David Kehl                       */    
/*DATE DE CREATIION:                26/09/2025                            */  
/*DATE DE MODIFICATION:             02/10/2025                            */ 
/*DESCRIPTION:                      fichier contenant les nouveaux types de
                                    données, les prototypes, les structures 
                                    de données et les constantes          */    
/*------------------------------------------------------------------------*/ 
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "entrep.h"

// Insère une vente : lit les infos auprès de l'utilisateur, vérifie et met à jour le stock
int ins_vente() {
    Vente vente;
    Produit p;
    long record_pos = -1;
    int c;

    // Saisie des informations de vente
    
    vente.id_vente = obtenir_dernier_id_vente(HIST_VENTES_FILE) + 1;
    printf("Entrez l'ID du produit vendu : ");
    if (scanf("%d", &vente.id_prod) != 1) {
        printf("Entrée invalide pour l'ID du produit.\n");
        vider_buffer();
        return 0;
    }

    

    printf("Entrez la quantité vendue : ");
    if (scanf("%d", &vente.qte_vendue) != 1) {
        printf("Entrée invalide pour la quantité.\n");
       vider_buffer();
        return 0;   
    }
    // vider le buffer
     vider_buffer();

    // Ouvrir le fichier des produits (même fichier utilisé par prod.c)
    FILE *fp_prod = fopen(PRODUIT_FILE, "r+b");
    if (fp_prod == NULL) {
        perror("Erreur lors de l'ouverture du fichier des produits");
        return 0;
    }

    // Parcourir le fichier et garder la position du record trouvé
    while (1) {
        long pos = ftell(fp_prod);
        if (fread(&p, sizeof(Produit), 1, fp_prod) != 1) break;
        if (p.Id_prod == vente.id_prod) { record_pos = pos; break; }
    }

    

    // Vérifier la quantité disponible
    if (p.pro_qte < vente.qte_vendue) {
        printf("Erreur : Stock insuffisant pour le produit %d (Stock: %d, Demandé: %d).\n",
               p.Id_prod, p.pro_qte, vente.qte_vendue);
        fclose(fp_prod);
        return 0;
    }

    // Mettre à jour la quantité et réécrire le record
    p.pro_qte -= vente.qte_vendue;
    if (fseek(fp_prod, record_pos, SEEK_SET) != 0) {
        perror("Erreur lors du repositionnement dans le fichier produit");
        fclose(fp_prod);
        return 0;
    }
    if (fwrite(&p, sizeof(Produit), 1, fp_prod) != 1) {
        perror("Erreur lors de l'ecriture du produit");
        fclose(fp_prod);
        return 0;
    }
    fflush(fp_prod);
    fclose(fp_prod);

    // Calculer les montants de la vente
    vente.prix_unit = p.pro_prix;
    vente.prix_total = vente.prix_unit * vente.qte_vendue;
    generer_date_courante(vente.dat_vente);

    // Enregistrer la vente (historique)
    FILE *fp_hist = fopen(HIST_VENTES_FILE, "ab");
    if (fp_hist == NULL) {
        perror("Erreur d'ouverture du fichier d'historique des ventes");
        return 0;
    }
    if (fwrite(&vente, sizeof(Vente), 1, fp_hist) != 1) {
        perror("Erreur d'ecriture de la vente dans l'historique");
        fclose(fp_hist);
        return 0;
    }
    fclose(fp_hist);

    printf("Vente enregistrée avec succès (ID vente : %d).\n", vente.id_vente);
    return 1;

    
}



     



//     // 2. Parcourir le fichier pour trouver le produit (on sauvegarde la position AVANT la lecture)
//     while (1) 
//     {
//         long pos = ftell(fp_prod);
//         if (fread(&p, sizeof(Produit), 1, fp_prod) != 1) break;
//         if (p.Id_prod == v.id_prod) 
//         {
//             produit_trouve = 1;
//             record_pos = pos;
//             break; // Produit trouvé
//         }
//     }

//     if (!produit_trouve) 
//     {
//         printf("Erreur : Produit d'ID %d non trouvé dans le stock.\n", v.id_prod);
//         fclose(fp_prod);
//         return 0;
//     }

//     // 3. Vérifier la quantité disponible
//     if (p.pro_qte < v.qte_vendue) 
//     {
//         printf("Erreur : Stock insuffisant pour le produit %d (Stock: %d, Demandé: %d).\n", 
//                p.Id_prod, p.pro_qte, v.qte_vendue);
//         fclose(fp_prod);
//         return 0;
//     }

//     // 4. Mettre à jour la quantité et l'enregistrer dans le fichier produit.dat
//     p.pro_qte -= v.qte_vendue;

//     if (record_pos >= 0) 
//     {
//         if (fseek(fp_prod, record_pos, SEEK_SET) != 0) 
//         {
//             perror("Erreur lors du repositionnement dans produit.dat");
//             fclose(fp_prod);
//             return 0;
//         }
//         if (fwrite(&p, sizeof(Produit), 1, fp_prod) != 1) {
//             perror("Erreur lors de l'ecriture dans produit.dat");
//             fclose(fp_prod);
//             return 0;
//         }
//         fflush(fp_prod);
//         printf("Stock du produit %d mis à jour. Nouvelle quantité : %d.\n", p.Id_prod, p.pro_qte);
//     } else {
//         printf("Erreur interne: position d'enregistrement invalide.\n");
//         fclose(fp_prod);
//         return 0;
//     }
//     fclose(fp_prod);

//     //5. Effectuer la vente
//     v.prix_unit = p.pro_prix;
//     v.prix_total = v.prix_unit * v.qte_vendue;
//     generer_date_courante(v.dat_vente);

//     //6. Enregistrement de la vente dans Hist_vente.dat
//     FILE *fp_vente = fopen(HIST_VENTES_FILE, "ab");
//     if (fp_vente == NULL) {
//         perror("Erreur d'ouverture de Hist_Ventes.dat");
//         return 0;
//     }

//     if (fwrite(&v, sizeof(Vente), 1, fp_vente) != 1) {
//         perror("Erreur d'écriture de la vente");
//         fclose(fp_vente);
//         return 0;
//     }

//     fclose(fp_vente);
//     printf("Vente enregistrée avec succès (ID vente : %d).\n", v.id_vente);
//     return 1;

// }


/*-------------------------------------------------------------------------------*/
/*FOCNTION:    Obtenir le dernier ID de vente                                     */
/*Date de création:      18/10/2025                                                */
/*Date de modification: 18/10/2025                                                 */
/*DESCRIPTION:           Cette fonction permet d'obtenir le dernier ID de vente   */
/*VALEUR DE RETOUR:      Dernier ID de vente                                     */


int obtenir_dernier_id_vente(const char *nom_fichier) {
    FILE *fp = fopen(nom_fichier, "rb");
    if (fp == NULL) {
        // Si le fichier n'existe pas, on considère que c'est la première vente
        return 0;
    }

    Vente v;
    int max_id = 0;

    // Parcourir le fichier pour trouver le plus grand ID de vente
    while (fread(&v, sizeof(Vente), 1, fp) == 1) {
        if (v.id_vente > max_id) {
            max_id = v.id_vente;
        }
    }

    fclose(fp);
    return max_id;
}


>>>>>>> 16d998371f4d71ffd3ff471c01450329f54db791
