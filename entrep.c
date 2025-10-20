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
                menu_parametres();
                break;
            case 2:
                ins_usine(0); // appeler la fonction d'insertion d'usine (commune par défaut 0)
                mod_usine(1);//menu_production();
                break;
                break;
            case 3:
                // menu_ventes();
                break;
            case 4:
                // menu_rapports();
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
