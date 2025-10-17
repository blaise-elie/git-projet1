/*------------------------------------------------------------------------*/
/* FICHIER:                          usine.c                               */ 
/*AUTEUR:                           PIERRE-LOUIS Alven Bernadin           */    
/*DATE DE CREATIION:                27/09/2025                            */
/*DATE DE MODIFICATION:             03/10/2025                            */
/*DESCRIPTION:                      fichier contenant les fonctions de 
                                    gestion des usines.                   */
/*------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrep.h"

/*------------------------------------------------------------------------*/
/*FONCTION:                         ins_usine                             */ 
/*AUTEUR:                           PIERRE-LOUIS Alven Bernadin           */ 
/*PARAMETRE:                        ID de la commune où se trouve l'usine */
/*VALEUR DE RETOUR:                 Aucune                                */
/*DATE DE CREATIION:                27/09/2025                            */
/*DATE DE MODIFICATION:             03/10/2025                            */
/*DESCRIPTION:                      Fonction qui permet d'inserer une 
                                    usine                                 */
/*------------------------------------------------------------------------*/

//fonction pour inserer une usine
void ins_usine(int ID_commune) 
{
    Usine nouvelleUsine;
    char texte[50]; // pour recevoir le texte à saisir

    nouvelleUsine.Id_usine= obtenir_dernier_id_usine("usine.dat") + 1;
    //nouvelleUsine.Id_com= ID_commune;

    // Vider le buffer avant de lire une chaîne de caractères
    int c;
    while ((c = getchar()) != '\n' && c != EOF);


    printf("Entrez le nom de l'usine: ");
    fgets(texte, sizeof(texte), stdin);
    // Supprime le retour à la ligne (\n) si présent
    texte[strcspn(texte, "\n")] = '\0';
    strcpy(nouvelleUsine.Usi_nom, texte); //Pour copier le nom dans le champ nom de l'usine

    printf("Entrez la description de l'usine: ");
    fgets(texte, sizeof(texte), stdin);
    texte[strcspn(texte, "\n")] = '\0';
    strcpy(nouvelleUsine.Usin_desc, texte); //Pour copier le nom dans le champ nom de l'usine

    int retour= ecrire_usine("usine.dat", &nouvelleUsine);
    if(retour== 1)
    {
        printf("usine ajoutée avec succes\n");
    }

    if (lire_usine("usine.dat",nouvelleUsine.Id_usine, &nouvelleUsine)) 
    {
        printf("Nom de l'usine : %s\n", nouvelleUsine.Usi_nom);
        printf("Description de l'usine : %s\n", nouvelleUsine.Usin_desc);
        printf("ID de l'usine : %d\n", nouvelleUsine.Id_usine);//afficher l'ID de l'usine
    } 
    else 
    {
        printf("Usine non trouvée.\n");
    }
   
}

/*------------------------------------------------------------------------*/
/*FONCTION:                         ecrire_usine                          */ 
/*AUTEUR:                           PIERRE-LOUIS Alven Bernadin           */ 
/*PARAMETRE:                        Nom du fichier/un pointeur vers une 
                                    usine                                 */
/*VALEUR DE RETOUR:                 Un entier                             */
/*DATE DE CREATIION:                27/09/2025                            */
/*DATE DE MODIFICATION:             03/10/2025                            */
/*DESCRIPTION:                      Fonction qui permet d'écrire les infos 
                                    de l'usine à inserer dans le fichier 
                                    usine.dat                             */
/*------------------------------------------------------------------------*/

int ecrire_usine(const char *nom_fichier, Usine *u) 
{
    FILE *f = fopen(nom_fichier, "wb");//ouvrir le fichier
    if (f == NULL) 
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }
    fwrite(u, sizeof(Usine), 1, f); //ecrire dans le fichier
    fclose(f);
    return 1;
}

/*------------------------------------------------------------------------*/
/*FONCTION:                         lire_usine                            */ 
/*AUTEUR:                           PIERRE-LOUIS Alven Bernadin           */ 
/*PARAMETRE:                        Nom du fichier/ l'ID de l'usine qu'on 
                                    cherche/ un pointeur vers une usine   */
/*VALEUR DE RETOUR:                 Un entier                             */
/*DATE DE CREATIION:                27/09/2025                            */
/*DATE DE MODIFICATION:             03/10/2025                            */
/*DESCRIPTION:                      Fonction qui permet de lire les données
                                    stockés dans le fichier usine.dat     */
/*------------------------------------------------------------------------*/

int lire_usine(const char *nom_fichier, int id_recherche, Usine *resultat) 
{
    FILE *f = fopen(nom_fichier, "rb");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }
    
    while (fread(resultat, sizeof(Usine), 1, f) == 1)
    {
        if (resultat->Id_usine == id_recherche) {
            fclose(f);
            return 1; // Usine trouvée
        }
    }
    
    fclose(f);
    return 0; // Usine non trouvée
}
/*------------------------------------------------------------------------*/
/*FONCTION:                         mod_usine                             */ 
/*AUTEUR:                           PIERRE-LOUIS Alven Bernadin           */ 
/*PARAMETRE:                        ID de l'usine à modifier              */
/*VALEUR DE RETOUR:                 Aucune                                */
/*DATE DE CREATIION:                27/09/2025                            */
/*DATE DE MODIFICATION:             03/10/2025                            */
/*DESCRIPTION:                      Fonction pour modifier les informations
                                    d'une usine                           */
/*------------------------------------------------------------------------*/

void mod_usine(int ID)
{
    Usine usine_a_modifier;
    int choix;
    char texte[200]; // pour stocker le texte saisi
    
    printf("Entrer l'Id de l'usine à modifier-> ");
    scanf("%d", &ID);
    getchar(); // absorber le \n restant
    
    if (lire_usine("usine.dat", ID, &usine_a_modifier)) 
    {
        printf("Usine trouvée !\n");
        printf("Nom actuel: %s\n", usine_a_modifier.Usi_nom);
        printf("Description actuelle: %s\n", usine_a_modifier.Usin_desc);
        
        do {
            printf("Que voulez-vous modifier ?\n");
            printf("1. Nom\n");
            printf("2. Description\n");
            printf("3. Quitter\n");
            scanf("%d", &choix);
            getchar(); // absorber le \n

            switch(choix)
            {
                case 1: 
                    printf("Entrer le nouveau nom: ");
                    fgets(texte, sizeof(texte), stdin);
                    texte[strcspn(texte, "\n")] = '\0';
                    strcpy(usine_a_modifier.Usi_nom, texte);
                    printf("Nom modifié avec succès!\n");
                    return;
                    
                case 2:
                    printf("Entrer la nouvelle description: ");
                    fgets(texte, sizeof(texte), stdin);
                    texte[strcspn(texte, "\n")] = '\0';
                    strcpy(usine_a_modifier.Usin_desc, texte);
                    printf("Description modifiée avec succès!\n");
                    return;
                    
                case 3:
                    printf("Modification annulée\n");
                    return;
                    
                default: 
                    printf("Choix invalide. Veuillez réessayer.\n");
                    break;
            }
        } while (choix != 3);
    } else {
        printf("Aucune usine trouvée avec l'ID %d\n", ID);
    }
}

/*-------------------------------------------------------------------------------------*/
/* FONCTION:             Obtenir_dernier_id_usine                                      */
/*DESCRIPTION:           Cette fonction permet d'obtenir le dernier ID de departement  */
/*PARAMETRE:             Nom du fichier                                                */
/*VALEUR DE RETOUR:      Dernier ID de departement                                     */
/*AUTEUR:                Blaise Elie                                                   */
/*DATE DE CREATION:      10/10/2025                                                    */
/*DATE DE MODIFICATION:  10/10/2025                                                    */
int obtenir_dernier_id_usine(const char *nom_fichier)
{    
    int max_id = 0;
    Usine usine;
    FILE *f = fopen(nom_fichier, "rb");
    while (fread(&usine, sizeof(Usine), 1, f) == 1)
    {
        if (usine.Id_usine > max_id)
        {
            max_id = usine.Id_usine;
        }
    }
    fclose(f);
    return max_id;


}
