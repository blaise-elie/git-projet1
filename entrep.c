/*-----------------------------------------------------------------------*/
/* FICHIER:                          menu.c                              */
/* AUTEUR:                           Blaise Elie                         */    
/* DATE DE CREATION:                25/09/2025                           */
/* DATE DE MODIFICATION:            04/10/2025                           */
/* DESCRIPTION:                     Menu principal du programme          */    
/*-----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/* FONCTION:              afficher_banniere                             */
/* DESCRIPTION:           Affiche la bannière du système                */
/* PARAMETRES:            Aucun                                         */
/* VALEUR DE RETOUR:      Aucune                                        */
/* AUTEUR:                Blaise Elie                                   */
/* DATE DE CREATION:      25/09/2025                                    */
/* DATE DE MODIFICATION:  04/10/2025                                    */
/*----------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>  
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include "entrep.h"

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;
void afficher_banniere() {
    
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*          SYSTÈME DE GESTION DES USINES AGRO-INDUSTRIELLES D'HAÏTI            *\n");
    printf("*                                                                              *\n");
    printf("*                   Transformation des Produits Agricoles                      *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n\n");
    printf(" Bienvenue dans notre application de gestion des usines agro-industrielles !\n");
    printf(" Cette application vous permet de gérer les départements, communes, usines, \n");
    printf("              produits, lots, ventes, rapports et statistiques.\n\n           ");
}

/*----------------------------------------------------------------------*/
/* FONCTION:              afficher_menu_principal                       */
/* DESCRIPTION:           Affiche le menu principal amélioré           */
/* PARAMETRES:            Aucun                                         */
/* VALEUR DE RETOUR:      Aucune                                       */
/* AUTEUR:                Blaise Elie                                  */
/* DATE DE CREATION:      25/09/2025                                   */
/* DATE DE MODIFICATION:  04/10/2025                                   */
/*----------------------------------------------------------------------*/
void afficher_menu_principale()
{
      // Afficher la date et l'heure actuelles
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char date_str[100];
    strftime(date_str, sizeof(date_str), "%d/%m/%Y - %H:%M", tm_info);

  afficher_banniere();
    printf("********************************************************************************\n");
    printf("*                            MENU PRINCIPAL                                    *\n");
    printf("*                          %s                                      ║\n", date_str);
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*  1.  Paramètres (Départements / Communes)                                    *\n");
    printf("*  2.  Production (Usines / Produits / Lots)                                   *\n");
    printf("*  3.  Ventes                                                                  *\n");
    printf("*  4.  Rapports et Statistiques                                                *\n");
    printf("*                                                                              *\n");
    printf("*  0.  Quitter                                                                 *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    printf("\n Veuillez faire Votre choix : ");
}

/*----------------------------------------------------------------------*/
/* FONCTION:              ajout departement                            */
/* DESCRIPTION:           Ajoute un nouveau département                  */
/* PARAMETRES:            Aucun                                         */
/* VALEUR DE RETOUR:      Aucune                                        */
/* AUTEUR:                Blaise Elie                                   */
/* DATE DE CREATION:      25/09/2025                                    */
/* DATE DE MODIFICATION:  04/10/2025                                    */
/*----------------------------------------------------------------------*/
void ajouter_departement()
{
    printf("Fonction ajouter_departement appelée.\n");
    // Code pour ajouter un département ici code de Derival

}


/*----------------------------------------------------------------------*/
/* FONCTION:              afficher menu parametres                      */
/* DESCRIPTION:           Affiche le menu paramètres du système         */
/* PARAMETRES:            Aucun                                         */
/* VALEUR DE RETOUR:      Aucune                                        */
/* AUTEUR:                Blaise Elie                                   */
/* DATE DE CREATION:      25/09/2025                                    */
/* DATE DE MODIFICATION:  04/10/2025                                    */
/*----------------------------------------------------------------------*/
void menu_parametres() {
    int sous_choix = -1;
    char id_departement[10];
    
    while (sous_choix != 0) {
        printf("\n=== GESTION DES DÉPARTEMENTS ===\n");
        printf("1. Ajouter un nouveau département\n");
        printf("2. Sélectionner un département à gérer\n");
        printf("3. Lister tous les départements\n");
        printf("0. Retour au menu principal\n");
        printf(" Veuillez faire Votre choix : ");

        
        scanf("%d", &sous_choix);

        switch (sous_choix) {
            case 1:
                ajouter_departement();
                break;
            case 2:
                printf("Entrez l'ID du département à gérer : ");
                scanf("%s", id_departement);
                //gerer_departement(id_departement);
                break;
            case 3:
               // lister_departements();
                break;
            case 0:
                printf("Retour au menu principal...\n");
                afficher_menu_principale();
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

    afficher_menu_principale();
    scanf("%d", &choix);
    switch (choix) {
        case 1:
             menu_parametres();
            break;
        case 2:
            insererUsine(1);
            mod_usine(1);//menu_production();
            break;
        case 3:
            // menu_ventes();
            break;
        case 4:
            // menu_rapports();
            break;
        case 0:
            printf("Merci d'avoir utilisé notre application. Au revoir !\n");
            running = false;
            break;
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
            break;
    }
    











    return 0;
}
