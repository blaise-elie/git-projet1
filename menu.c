/*-----------------------------------------------------------------------*/
/* FICHIER:                          menu.c                              */
/* AUTEUR:                           Blaise Elie                         */    
/* DATE DE CREATION:                25/09/2025                           */
/* DATE DE MODIFICATION:            25/09/2025                           */
/* DESCRIPTION:                     Menu principal du programme          */    
/*-----------------------------------------------------------------------*/

/*Menu principale du programme*/
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{
    bool running = true;
    int choix;

    while (running)
    {
        printf("===============================================================================\n");
        printf("\n|               GESTION DES USINES AGRO-INDUSTRIELLES EN HAITI                |\n");
        printf("===============================================================================\n");
        printf("\n|                            MENU PRINCIPAL                                   |\n");
        printf("================================================================================\n");
        printf("\n1. Paramètres (Départements / Communes)\n");
        printf("2. Production (Usines/Produits/Lots)\n");
        printf("3. Ventes\n");
        printf("4.Raports et Statistiques\n");
        printf("0. Quitter\n");
        printf("\nVeuillez entrer votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {    // Menu Paramètres (Départements / Communes)
            case 1: {
                int sous_choix = -1;
                while (sous_choix != 0) {
                    printf("\n---  MODULES PARAMETRES ---\n");
                    printf("1. Ajouter un Départements\n");
                    printf("2. Modifier un Départements\n");
                    printf("3.Lister les Départements\n");
                    printf("4. Ajouter une Commune\n");
                    printf("5. Modifier une Commune\n");
                    printf("6. Lister les Communes\n");
                    printf("0. Retour au menu principal\n");
                    printf("Votre choix : ");
                    scanf("%d", &sous_choix);
                    switch (sous_choix) {
                        case 1:
                            printf("Vous avez choisi d'ajouter un Départements.\n");
                            break;
                        case 2:
                            printf("Vous avez choisi de modifier un Départements\n");
                        case 3:
                            printf("Vous avez choisi de lister les Départements\n");
                            break;
                        case 4:
                            printf("Vous avez choisi d'ajouter une Commune\n");
                            break;
                        case 5:
                            printf("Vous avez choisi de modifier une Commune\n");
                            break;
                        case 6:
                            printf("Vous avez choisi de lister les Communes\n");
                            break;
                        case 0:
                            printf("Retour au menu principal...\n");
                            break;
                        default:
                            printf("Choix invalide, veuillez réessayer.\n");
                            break;
                    }
                }
                break;
            }
             // Fin du menu Paramètres
            // Menu Production
            case 2:
                    printf("Vous avez choisi Production.\n");
                int sous_choix_prod = -1;
                while (sous_choix_prod != 0) {
                    printf("\n---  MODULES PRODUCTION ---\n");
                    printf("1. Ajouter une Usine\n");
                    printf("2. Modifier une Usine\n");
                    printf("3. Lister les Usines\n");
                    printf("4. Ajouter un Produit\n");
                    printf("5. Modifier un Produit\n");
                    printf("6. Lister les Produits\n");
                    printf("7. Ajouter un Lot\n");
                    printf("8. Modifier un Lot\n");
                    printf("9. Lister les Lots\n");
                    printf("0. Retour au menu principal\n");
                    printf("Votre choix : ");
                    scanf("%d", &sous_choix_prod);
                    switch (sous_choix_prod) {
                        case 1:
                            printf("Vous avez choisi d'ajouter une Usine.\n");
                            break;
                        case 2:
                            printf("Vous avez choisi de modifier une Usine.\n");
                            break;
                        case 3:
                            printf("Vous avez choisi de lister les Usines.\n");
                            break;
                        case 4:
                            printf("Vous avez choisi d'ajouter un Produit.\n");
                            break;
                        case 5:
                            printf("Vous avez choisi de modifier un Produit.\n");
                            break;
                        case 6:
                            printf("Vous avez choisi de lister les Produits.\n");
                            break;
                        case 7:
                            printf("Vous avez choisi d'ajouter un Lot.\n");
                            break;
                        case 8:
                            printf("Vous avez choisi de modifier un Lot.\n");
                            break;
                        case 9:
                            printf("Vous avez choisi de lister les Lots.\n");
                            break;
                        case 0:
                            printf("Retour au menu principal...\n");
                            break;
                        default:
                            printf("Choix invalide, veuillez réessayer.\n");
                            break;
                    }


                

                }
                 //fin menu production
                ;
                break;
            case 3:
                printf("Vous avez choisi Ventes.\n");
                int sous_choix_ventes = -1;
                while (sous_choix_ventes != 0) 
                {
                    printf("\n---  MODULES VENTES ---\n");
                    printf("1. Ajouter une Vente\n");
                    printf("2. Modifier une Vente\n");
                    printf("3. Lister les Ventes\n");
                    printf("0. Retour au menu principal\n");
                    printf("Votre choix : ");
                    scanf("%d", &sous_choix_ventes);
                    switch (sous_choix_ventes) {
                        case 1:
                            printf("Vous avez choisi d'ajouter une Vente.\n");
                            break;
                        case 2:
                            printf("Vous avez choisi de modifier une Vente.\n");
                            break;
                        case 3:
                            printf("Vous avez choisi de lister les Ventes.\n");
                            break;
                        case 0:
                            printf("Retour au menu principal...\n");
                            break;
                        default:
                            printf("Choix invalide, veuillez réessayer.\n");
                            break;
                    }


                }
                break;
            case 4:
                printf("Vous avez choisi Rapports et Statistiques.\n");
                // Appel de la fonction du module rapp_stat.c
                // rapp_stat();
                break;
            case 0:
                printf("Au revoir !\n");
                running = false;
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }
        printf("\n");
    }
}