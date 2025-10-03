/*-----------------------------------------------------------------------*/
/* FICHIER:                          menu1.c                              */
/* AUTEUR:                           Blaise Elie                         */    
/* DATE DE CREATION:                25/09/2025                           */
/* DATE DE MODIFICATION:            03/10/2025                           */
/* DESCRIPTION:                     Menu principal du programme          */    
/*-----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
/* Definition de la fonction ajouter un departement*/
/*DESCRIPTION:            Cette fonction permet d'ajouter un departement*/
/*PARAMETRES :            Pas de parametre                              */
/*VALEUR DE RETOUR:       Pas de valeur de retour                      */
/*AUTEUR:                 Blaise Elie                                   */
/*DATE DE CREATION:       25/09/2025                                    */  
/*DATE DE MODIFICATION:   03/10/2025                                    */
/*----------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void ajouter_departement()
{
    printf("Fonction ajouter_departement appelée.\n");
    // Code pour ajouter un département
}

/*----------------------------------------------------------------------*/
/* Definition de la fonction pour modifier  un departement*/
/*DESCRIPTION:            Cette fonction permet de modifier un departement*/
/*PARAMETRES :            Pas de parametre                              */
/*VALEUR DE RETOUR:       Pas de valeur de retour                      */
/*AUTEUR:                 Blaise Elie                                   */
/*DATE DE CREATION:       25/09/2025                                    */  
/*DATE DE MODIFICATION:   03/10/2025                                    */
/*----------------------------------------------------------------------*/

void modifier_departement()
{
    printf("Vous avez choisi de modifier un Départements\n");
    //Logique pour ajouter un departement


}

/*----------------------------------------------------------------------- */
/* Definition de la fonction pour lister  les departements*/
/*DESCRIPTION:            Cette fonction permet de lister les departements*/
/*PARAMETRES :            Pas de parametre                                */
/*VALEUR DE RETOUR:       Pas de valeur de retour                         */
/*AUTEUR:                 Blaise Elie                                     */
/*DATE DE CREATION:       25/09/2025                                      */  
/*DATE DE MODIFICATION:   03/10/2025                                      */
/*------------------------------------------------------------------------ */

void lister_departements()
{
    printf("Vous avez choisi de lister les departement");
    //logique pour lister les departements
}

/*----------------------------------------------------------------------*/
/* Definition de la fonction ajouter une commune*/
/*DESCRIPTION:            Cette fonction permet d'ajouter une commune   */
/*PARAMETRES :            Pas de parametre                              */
/*VALEUR DE RETOUR:       Pas de valeur de retour                       */
/*AUTEUR:                 Blaise Elie                                   */
/*DATE DE CREATION:       25/09/2025                                    */  
/*DATE DE MODIFICATION:   03/10/2025                                    */
/*----------------------------------------------------------------------*/

void ajouter_commune()
{
    printf("Vous avez choisi d'ajouter une commune");
    //Logique pour ajouter une commune
}

/*----------------------------------------------------------------------*/
/* Definition de la fonction pour modifier une commune*/
/*DESCRIPTION:            Cette fonction permet de modifier une commune */
/*PARAMETRES :            Pas de parametre                              */
/*VALEUR DE RETOUR:       Pas de valeur de retour                       */
/*AUTEUR:                 Blaise Elie                                   */
/*DATE DE CREATION:       25/09/2025                                    */  
/*DATE DE MODIFICATION:   03/10/2025                                    */
/*----------------------------------------------------------------------*/
void modifier_commune()
{
  printf("Vous avez choisi de modifier une commune");
  //logique pour modifier une commune

}

/*----------------------------------------------------------------------*/
/* Definition de la fonction pour lister les commune*/
/*DESCRIPTION:            Cette fonction permet de lister les commune   */
/*PARAMETRES :            Pas de parametre                              */
/*VALEUR DE RETOUR:       Pas de valeur de retour                       */
/*AUTEUR:                 Blaise Elie                                   */
/*DATE DE CREATION:       25/09/2025                                    */  
/*DATE DE MODIFICATION:   03/10/2025                                    */
/*----------------------------------------------------------------------*/
void lister_commune()
{
    printf("Vous avez choisi de lister les communes");
    //Logique pour lister les communes
}

/*----------------------------------------------------------------------*/
/* Definition de la fonction pour afficher le menu des parametres       */
/*DESCRIPTION:            Cette fonction permet d'afficher le menu des 
                          parametres                                    */
/*PARAMETRES :            Pas de parametre                              */
/*VALEUR DE RETOUR:       Pas de valeur de retour                       */
/*AUTEUR:                 Blaise Elie                                   */
/*DATE DE CREATION:       25/09/2025                                    */  
/*DATE DE MODIFICATION:   03/10/2025                                    */
/*----------------------------------------------------------------------*/
void afficher_menu_parametres() {
    printf("\n---  MODULES PARAMETRES ---\n");
    printf("1. Ajouter un Département\n");
    printf("2. Modifier un Département\n");
    printf("3. Lister les Départements\n");
    printf("4. Ajouter une Commune\n");
    printf("5. Modifier une Commune\n");
    printf("6. Lister les Communes\n");
    printf("0. Retour au menu principal\n");
    printf("Votre choix : ");
}

/*----------------------------------------------------------------------*/
/*    Definition de la fonction pour gerer le menu des parametres        */
/*DESCRIPTION:            Cette fonction permet de gere le menu des 
                          parametres                                    */
/*PARAMETRES :            Pas de parametre                              */
/*VALEUR DE RETOUR:       Pas de valeur de retour                       */
/*AUTEUR:                 Blaise Elie                                   */
/*DATE DE CREATION:       25/09/2025                                    */  
/*DATE DE MODIFICATION:   03/10/2025                                    */
/*----------------------------------------------------------------------*/

void menu_parametres()
{
     int sous_choix = -1;
    while (sous_choix !=0)
    {
        afficher_menu_parametres();
        scanf("%d",&sous_choix);

        switch (sous_choix)
        {
            case 1:
                ajouter_departement();
            break;
            
            case 2:
                modifier_departement();
            break;

            case 3:
                lister_departements();
            break;

            case 4:
                ajouter_commune();
            break;

            case 5:
                modifier_commune();
            break;

            case 6:
                lister_commune();
            break;

            case 0:
                printf("Retour au menu principal.....");
            break;

            default:
                printf("Choix invalide veuillez reessayer");


        }


    }



}

/*----------------------------------------------------------------------*/
/* Definition de la fonction pour afficher le menu principale           */
/*DESCRIPTION:            Cette fonction permet d'afficher le menu princi 
                          pal                                    *      /
/*PARAMETRES :            Pas de parametre                              */
/*VALEUR DE RETOUR:       Pas de valeur de retour                       */
/*AUTEUR:                 Blaise Elie                                   */
/*DATE DE CREATION:       25/09/2025                                    */  
/*DATE DE MODIFICATION:   03/10/2025                                    */
/*----------------------------------------------------------------------*/

void afficher_menu_principale()
{

  printf("===============================================================================\n");
    printf("\n|               GESTION DES USINES AGRO-INDUSTRIELLES EN HAITI                |\n");
    printf("===============================================================================\n");
    printf("\n|                            MENU PRINCIPAL                                   |\n");
    printf("================================================================================\n");
    printf("\n1. Paramètres (Départements / Communes)\n");
    printf("2. Production (Usines/Produits/Lots)\n");
    printf("3. Ventes\n");
    printf("4. Rapports et Statistiques\n");
    printf("0. Quitter\n");
    printf("\nVeuillez entrer votre choix : ");
}

//fonction principale
int main(){
   
    bool running = true;
    int choix;

    while (running)
    {
        afficher_menu_principale();
        scanf("%d",&choix);

        switch(choix)
        {

         case 1:
            menu_parametres();
            break;

         case 2:
           // menu_production();
            break;

         case 3:
           // menu_ventes();
            break;

         case 4:
            //menu_rapports();
            break;

         case 0:
            printf("Merci d'avoir utiliser notre application");
            running = false;
            break;

         default:
            printf("Choix invalide veuillez reessayer");


        }


    }

   return 0;

 system("pause");

}