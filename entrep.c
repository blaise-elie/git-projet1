/*-----------------------------------------------------------------------*/
/* FICHIER:                          menu.c                              */
/* AUTEUR:                           Blaise Elie                         */    
/* DATE DE CREATION:                25/09/2025                           */
/* DATE DE MODIFICATION:            04/10/2025                           */
/* DESCRIPTION:                     Menu principal du programme          */    
/*-----------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>  
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include "entrep.h"



/*----------------------------------------------------------------------*/
/* FONCTION:              afficher_menu_principal                       */
/* DESCRIPTION:           Affiche le menu principal amélioré           */
/* PARAMETRES:            Aucun                                         */
/* VALEUR DE RETOUR:      Aucune                                       */
/* AUTEUR:                Blaise Elie                                  */
/* DATE DE CREATION:      25/09/2025                                   */
/* DATE DE MODIFICATION:  04/10/2025                                   */
/*----------------------------------------------------------------------*/

void afficher_menu_principal() {
     // Afficher la date et l'heure actuelles
     time_t t = time(NULL);
     struct tm *tm_info = localtime(&t);
     char date_str[100];
     strftime(date_str, sizeof(date_str), "%d/%m/%Y - %H:%M", tm_info);
    afficher_banniere();
    printf("\n");
    printf("  ┌───────────────────────────────────────────────────────────────────────┐\n");
    printf("  │                        ★ MENU PRINCIPAL ★                            │\n");
    printf("  ├───────────────────────────────────────────────────────────────────────┤\n");
    printf("  │              %s                                                       │\n", date_str);
    printf("  │      ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓    │\n");
    printf("  │      ┃  [1] ► Paramètres                                         ┃    │\n");
    printf("  │      ┃       └─ Gestion des Départements et Communes             ┃    │\n");
    printf("  │      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛    │\n");
    printf("  │                                                                       │\n");
    printf("  │      ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓    │\n");
    printf("  │      ┃  [2] ► Production                                         ┃    │\n");
    printf("  │      ┃       └─ Usines, Produits et Historiques                  ┃    │\n");
    printf("  │      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛    │\n");
    printf("  │                                                                       │\n");
    printf("  │      ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓    │\n");
    printf("  │      ┃  [3] ► Ventes                                             ┃    │\n");
    printf("  │      ┃       └─ Gestion des Ventes de Produits                   ┃    │\n");
    printf("  │      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛    │\n");
    printf("  │                                                                       │\n");
    printf("  │      ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓    │\n");
    printf("  │      ┃  [4] ► Rapports et Statistiques                           ┃    │\n");
    printf("  │      ┃       └─ Analyses et Tableaux de Bord                     ┃    │\n");
    printf("  │      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛    │\n");
    printf("  │                                                                       │\n");
    printf("  │      ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓    │\n");
    printf("  │      ┃  [0] ► Quitter                                            ┃    │\n");
    printf("  │      ┃       └─ Fermer le programme                              ┃    │\n");
    printf("  │      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛    │\n");
    printf("  │                                                                       │\n");
    printf("  └───────────────────────────────────────────────────────────────────────┘  \n");
    printf("\n  ╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("    ║  Votre choix ► ");
}



/*----------------------------------------------------------------------*/
/* FONCTION:              afficher_banniere                             */
/* DESCRIPTION:           Affiche la bannière du système                */
/* PARAMETRES:            Aucun                                         */
/* VALEUR DE RETOUR:      Aucune                                        */
/* AUTEUR:                Blaise Elie                                   */
/* DATE DE CREATION:      25/09/2025                                    */
/* DATE DE MODIFICATION:  04/10/2025                                    */
/*----------------------------------------------------------------------*/

void afficher_banniere() {
    system("cls"); // Ou system("cls"); pour Windows
    
    printf("\n");
    printf("  ╔═══════════════════════════════════════════════════════════════════════╗\n");
    printf("  ║                                                                       ║\n");
    printf("  ║     ██╗   ██╗███████╗██╗███╗   ██╗███████╗███████╗                    ║\n");
    printf("  ║     ██║   ██║██╔════╝██║████╗  ██║██╔════╝██╔════╝                    ║\n");
    printf("  ║     ██║   ██║███████╗██║██╔██╗ ██║█████╗  ███████╗                    ║\n");
    printf("  ║     ██║   ██║╚════██║██║██║╚██╗██║██╔══╝  ╚════██║                    ║\n");
    printf("  ║     ╚██████╔╝███████║██║██║ ╚████║███████╗███████║                    ║\n");
    printf("  ║      ╚═════╝ ╚══════╝╚═╝╚═╝  ╚═══╝╚══════╝╚══════╝                    ║\n");
    printf("  ║                                                                       ║\n");
    printf("  ║          ╔════════════════════════════════════════════╗               ║\n");
    printf("  ║          ║  SYSTÈME DE GESTION DE PRODUCTION          ║               ║\n");
    printf("  ║          ║  Transformation Agricole - Haïti           ║               ║\n");
    printf("  ║          ╚════════════════════════════════════════════╝               ║\n");
    printf("  ║                                                                       ║\n");
    printf("  ║              ⚙  Université d'État d'Haïti  ⚙                         ║\n");
    printf("  ║              ⚙  Faculté des Sciences       ⚙                         ║\n");
    printf("  ║                                                                       ║\n");
    printf("  ║      Bienvenue dans notre application de gestion des usines           ║\n");
     printf(" ║      agro-industrielles. Cette application vous permet de gérer       ║\n");
    printf("  ║      les productions des usines agro-industrielles en Haïti.          ║\n");                                                                               
    printf("  ╚═══════════════════════════════════════════════════════════════════════╝\n");
    printf("\n");
}


// void afficher_banniere() {
    
//     printf("********************************************************************************\n");
//     printf("*                                                                              *\n");
//     printf("*          SYSTÈME DE GESTION DES USINES AGRO-INDUSTRIELLES D'HAÏTI            *\n");
//     printf("*                                                                              *\n");
//     printf("*                   Transformation des Produits Agricoles                      *\n");
//     printf("*                                                                              *\n");
//     printf("********************************************************************************\n\n");
//     printf("* Bienvenue dans notre application de gestion des usines agro-industrielles    *!\n");
//     printf("* Cette application vous permet de gérer les départements, communes, usines,   *\n");
//     printf("*             produits, lots, ventes, rapports et statistiques.\n\n            0*");
//     printf("********************************************************************************\n");
// }


// void afficher_menu_principale()
// {
//       // Afficher la date et l'heure actuelles
//     time_t t = time(NULL);
//     struct tm *tm_info = localtime(&t);
//     char date_str[100];
//     strftime(date_str, sizeof(date_str), "%d/%m/%Y - %H:%M", tm_info);+


//   afficher_banniere();
    // printf("║║===============================================================================║║\n");
    // printf("║║                          MENU PRINCIPAL                                    \n");
    // printf("║║                          %s                                      ║║\n", date_str);
    // printf("║║===============================================================================║║\n");
    // printf("║║                                                                               ║║\n");
    // printf("║║  1.  Paramètres (Départements / Communes)                                     ║║\n");
    // printf("║║  2.  Production (Usines / Produits / Lots)                                    ║║\n");
    // printf("║║  3.  Ventes                                                                   ║║\n");
    // printf("║║  4.  Rapports et Statistiques                                                 ║║\n");
    // printf("║║                                                                               ║║\n");
    // printf("║║  0.  Quitter                                                                  ║║\n");
    // printf("║║                                                                               ║║\n");
    // printf("║║===============================================================================║║\n");
    // printf("\n Veuillez faire Votre choix : ");
//}


/*----------------------------------------------------------------------*/
/* FONCTION:              afficher menu parametres                      */
/* DESCRIPTION:           Affiche le menu paramètres du système         */
/* PARAMETRES:            Aucun                                         */
/* VALEUR DE RETOUR:      Aucune                                        */
/* AUTEUR:                Blaise Elie                                   */
/* DATE DE CREATION:      25/09/2025                                    */
/* DATE DE MODIFICATION:  04/10/2025                                    */  
/*----------------------------------------------------------------------*/
void menu_departements() {
    int sous_choix = -1;
    // char id_departement[10];
    
    while (sous_choix != 0) {
        printf("\n");
        printf("┌────────────────────────────────────────────────┐\n");
        printf("│          ★ GESTION DES DÉPARTEMENTS ★         │\n");
        printf("└────────────────────────────────────────────────┘\n");
        printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓   \n");
        printf("   ┃  [1] ► Ajouter un nouveau département    ┃   \n");
        printf("   ┃  [2] ► Modifier un département           ┃   \n");
        printf("   ┃  [3] ► Lister tous les départements      ┃   \n");
        printf("   ┃  [4] ► Gerer les communes                ┃   \n");
        printf("   ┃  [0] ► Retour au menu principal          ┃   \n");
        printf("   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛   \n");
        printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ \n");
        printf(" ┃  Veuillez faire Votre choix ►► ");

        
        scanf("%d", &sous_choix);
        switch (sous_choix) {
            case 1:
                 ins_dept();
                break;
            case 2:
                lister_departements();
                 mod_dept();
            
                break;
            case 3:
                lister_departements();
                break;
            case 4:
                menu_communes();
            case 0:
                printf("Retour au menu principal...\n");
                afficher_menu_principal();
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    }


}


//corps fonction menu communes
void menu_communes(void) {
    int sous_choix = -1;    
    while (sous_choix != 0) {
        printf("\n");
        printf("┌────────────────────────────────────────────────┐\n");
        printf("│          ★ GESTION DES COMMUNE ★              │\n");
        printf("└────────────────────────────────────────────────┘\n");
        printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓   \n");
        printf("   ┃  [1] ► Ajouter une nouvelle commune      ┃   \n");
        printf("   ┃  [2] ► Modifier une commune              ┃   \n");
        printf("   ┃  [3] ► Lister toutes les communes        ┃   \n");               
        printf("   ┃  [0] ► Retour au menu principal          ┃   \n");
        printf("   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛   \n");
        printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ \n");
        printf(" ┃  Veuillez faire Votre choix ►► ");
        
        scanf("%d", &sous_choix);
        
        switch (sous_choix) {
            case 1:
                printf("Voici la liste des départements existants:\n");
                    lister_departements();
                    ins_com();
                break;
            case 2:
                printf("Voici la liste des communes existantes:\n");
                lister_communes();
                    mod_com();
                break;
            case 3:
                lister_communes();
                break;
            case 4:
                menu_usines();
                break;
            case 0:
                printf("Retour au menu principal...\n");
                afficher_menu_principal();
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }   
    }
}

//corps de la fonction menu usines
void menu_usines(void) {

       int sous_choix = -1;    
    while (sous_choix != 0) {
             printf("┌────────────────────────────────────┐\n");
             printf("│        GESTION DES USINES          │ \n");
             printf("└────────────────────────────────────┘\n");
          printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓   \n");
        printf("   ┃  [1] ► Ajouter une nouvelle usine        ┃   \n");
        printf("   ┃  [2] ► Modifier une usine                ┃   \n");       
        printf("   ┃  [3] ► Lister toutes les usines          ┃   \n");
        printf("   ┃  [4] ► Gerer la production               ┃   \n");
        printf("   ┃  [0] ► Retour au menu principal          ┃   \n");
        printf("   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛   \n");
        printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ \n");
        printf(" ┃  Veuillez faire Votre choix ►► ");

        
        scanf("%d", &sous_choix);
         
        switch (sous_choix) {
            case 1:
                printf("Voici la liste des communes existantes:\n");
                lister_communes();
                ins_usine();
                break;
            case 2:
               lister_usines();
                mod_usine();
                break;
            case 3:
                lister_usines();
                break;
            case 4:
               menu_production();
            case 0:
                printf("Retour au menu principal...\n");
                afficher_menu_principal();
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    }



}

//corps de la fonction menu de production
void menu_production() {
    int sous_choix = -1;
    // char id_departement[10];
    
    while (sous_choix != 0) {
        printf("\n");
        printf("┌────────────────────────────────────────────────┐\n");
        printf("│             ★ GESTION DE PRODUITS ★           │\n");
        printf("└────────────────────────────────────────────────┘\n");
        printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓   \n");
        printf("   ┃  [1] ► Ajouter un nouveau produit        ┃   \n");
        printf("   ┃  [2] ► Modifier un produit               ┃   \n");
        printf("   ┃  [3] ► Lister tous les produits          ┃   \n");
        printf("   ┃  [4] ► Ajouter un lot de production      ┃   \n");      
        printf("   ┃  [0] ► Retour au menu principal          ┃   \n");
        printf("   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛   \n");
        printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ \n");
        printf(" ┃  Veuillez faire Votre choix ►► ");

        
        scanf("%d", &sous_choix);
        switch (sous_choix) {
            case 1:
                printf("Voici la liste des usines existantes:\n");
                lister_usines();
                ins_Prod();
                
                break;
            case 2:
                 mod_prod();
            
                break;
            case 3:
                lister_produits();
                break;
            case 4:
                enregistrer_production();
                break;
            case 0:
                printf("Retour au menu principal...\n");
                 afficher_menu_principal();
                 break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    }


}


/*-----------------------------------------------------------------*/   
/* FONCTION:              menu ventes                              */
/* DESCRIPTION:            Affiche le menu des ventes              */
/*VALEUR DE RETOUR:       Pas de valeur de retour                  */
/*AUTEUR:                David Kehl                                */
/*DATE DE CREATION:      22/10/2025                                */
/*DATE DE MODIFICATION:   30/10/2025                               */

void menu_ventes(void)
{ int sous_choix =-1;    
    while (sous_choix != 0) {
        printf("\n");
        printf("┌────────────────────────────────────────────────┐\n");
        printf("│             ★ GESTION DES VENTES ★            │\n");
        printf("└────────────────────────────────────────────────┘\n");
        printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓   \n");
        printf("   ┃  [1] ► Ajouter une nouvelle vente        ┃   \n");
        printf("   ┃  [2] ► Modifier une vente                ┃   \n");       
        printf("   ┃  [3] ► Lister toutes les ventes          ┃   \n");
        printf("   ┃  [0] ► Retour au menu principal          ┃   \n");
        printf("   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛   \n");
        printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ \n");
        printf(" ┃  Veuillez faire Votre choix ►► ");

        
        scanf("%d", &sous_choix);
  
        switch (sous_choix) {
            case 1:
                lister_produits();
                ins_vente();
                break;
            case 2:
               // mod_vente();
                break;
            case 3:
                //lister_ventes();
                break;
            case 0:
                printf("Retour au menu principal...\n");
                afficher_menu_principal();
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    }
}


//corps de la focntion vider buffer
/*------------------------------------------------------------------------*/
/* FONCTION:              vider_buffer                                    */
/*DESCRIPTION:           Cette fonction permet de vider le buffer stdin   */
/*VALEUR DE RETOUR:       Pas de valeur de retour                         */
/*AUTEUR:                David Kehl                                       */

void vider_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*-----------------------------------------------------------------*/   
/* FONCTION:              menu_rapports                             */  
/* DESCRIPTION:            Affiche le menu des rapports             */  
/*VALEUR DE RETOUR:       Pas de valeur de retour                  */   
/*AUTEUR:                David Kehl                                */
/*DATE DE CREATION:      22/10/2025                                */
/*DATE DE MODIFICATION:   30/10/2025                               */

void menu_rapports(void)
{ int sous_choix =-1;    
    while (sous_choix != 0) {
        printf("\n");
        printf("┌────────────────────────────────────────────────┐\n");
        printf("│             ★ GESTION DES RAPPORTS ★           │\n");
        printf("└────────────────────────────────────────────────┘\n");
        printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓   \n");
        printf("   ┃  [1] ►  Liste des produits fabriqués     ┃   \n");
        printf("   ┃  [2] ►  liste des produits disponible    ┃   \n");       
        printf("   ┃  [3] ► Chiffre d'affaire par periode     ┃   \n");
        printf("   ┃  [0] ► Retour au menu principal          ┃   \n");
        printf("   ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛   \n");
        printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ \n");
        printf(" ┃  Veuillez faire Votre choix ►► ");
        scanf("%d", &sous_choix);
        switch (sous_choix) {
            case 1:
                list_prod_fab();
                break;
            case 2:
                list_prod_dispo();
                break;
            case 3:
                chiffre_affaire();
                break;
            case 0:
                printf("Retour au menu principal...\n");
                afficher_menu_principal();
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    }
}

/* DESCRIPTION:           Fonction principale du programme              */
/* PARAMETRES:            Aucun                                         */
/* VALEUR DE RETOUR:      0 si succès                                  */
/* AUTEUR:                Blaise Elie                                  */
/* DATE DE CREATION:      25/09/2025                                   */
/* DATE DE MODIFICATION:  04/10/2025                                   */
/*----------------------------------------------------------------------*/
int main() {
    bool running = true;
    int choix;
    while (running) {
    afficher_menu_principal();
    scanf("%d", &choix);
        switch (choix) {
            case 1:
                menu_departements();
                break;
            case 2:
                menu_usines();
                break;
                
            case 3:
                lister_produits();
                menu_ventes();
                break;
            case 4:
                 menu_rapports();
                break;
            case 0:
                printf("\n");
                printf("  ╔═══════════════════════════════════════════════════════════════╗\n");
                printf("  ║                                                               ║\n");
                printf("  ║         ★ Merci d'avoir utilisé notre système ★              ║\n");
                printf("  ║                   Au revoir!                                  ║\n");
                printf("  ║                                                               ║\n");
                printf("  ╚═══════════════════════════════════════════════════════════════╝\n");
                printf("\n");
                running = false;
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
 
    }  
  return 0;
}
