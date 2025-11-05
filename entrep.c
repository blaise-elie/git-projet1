<<<<<<< HEAD
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
    system("clear"); // Ou system("cls"); pour Windows
    
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
=======
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
    system("clear"); // Ou system("cls"); pour Windows
    
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
>>>>>>> 16d998371f4d71ffd3ff471c01450329f54db791
