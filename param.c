
//corps fonction pour les departements et communes
#include <stdio.h>
#include <stdlib.h>
#include "entrep.h"
#include <string.h>
#include <time.h>
#define  FICHIER_COMMUNE   "commune.dat"
//#define  FICHIER_DEPARTEMENT   "departement.dat"


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

/*----------------------------------------------------------------------*/
/* FONCTION:              afficher_menu_principal                       */
/* DESCRIPTION:           Affiche le menu principal amélioré           */
/* PARAMETRES:            Aucun                                         */
/* VALEUR DE RETOUR:      Aucune                                       */
/* AUTEUR:                Blaise Elie                                  */
/* DATE DE CREATION:      25/09/2025                                   */
/* DATE DE MODIFICATION:  04/10/2025                                   */
/*----------------------------------------------------------------------*/
// void afficher_menu_principale()
// {
//       // Afficher la date et l'heure actuelles
//     time_t t = time(NULL);
//     struct tm *tm_info = localtime(&t);
//     char date_str[100];
//     strftime(date_str, sizeof(date_str), "%d/%m/%Y - %H:%M", tm_info);

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
    // char id_departement[10];
    
    while (sous_choix != 0) {
        printf("\n=== GESTION DES DÉPARTEMENTS ===\n");
        printf("1. Ajouter un nouveau département\n");
        printf("2. Modifier un département\n");
        printf("3.Lister tous les départements\n");
        printf("4.Gerer les communes \n");
        printf("0. Retour au menu principal\n");
        printf(" Veuillez faire Votre choix : ");

        
        scanf("%d", &sous_choix);
  
        switch (sous_choix) {
            case 1:
                 ins_dept();
                break;
            case 2:
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
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    }


}


//corps fonction menu communes
void menu_communes(void) {
    int sous_choix = -1;    
    while (sous_choix != 0) {
        printf("\n=== GESTION DES COMMUNES ===\n");
        printf("1. Ajouter une nouvelle commune\n");
        printf("2. Modifier une commune\n");
        printf("3.Lister toutes les communes\n");
        printf("4. Gerer les Usines\n");
        printf("0. Retour au menu paramètres\n");
        printf(" Veuillez faire Votre choix : ");

        
        scanf("%d", &sous_choix);
  
        switch (sous_choix) {
            case 1:
                printf("Voici la liste des départements existants:\n");
                 lister_departements();
                 ins_com();
                break;
            case 2:
                 //mod_com(0);
                break;
            case 3:
                //lister_communes();
                break;
            case 0:
                printf("Retour au menu paramètres...\n");
                menu_parametres();
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    }
}





//corps fonction pour obtenir le dernier ID de departement
/*-------------------------------------------------------------------------------------*/
/* FONCTION:              obtenir_dernier_id_dept                                      */
/*DESCRIPTION:           Cette fonction permet d'obtenir le dernier ID de departement  */
/*VALEUR DE RETOUR:      Dernier ID de departement                                     */
/*AUTEUR:                Blaise Elie                                                   */
/*DATE DE CREATION:      10/10/2025                                                    */
/*DATE DE MODIFICATION:  10/10/2025                                                    */
int obtenir_dernier_id_dept(const char *nom_fichier)
{    
    int max_id = 0;
    Departement dept;
    FILE *f = fopen(nom_fichier, "rb");
    if (f == NULL) {
        // fichier inexistant -> pas d'enregistrements
        return 0;
    }
    while (fread(&dept, sizeof(Departement), 1, f) == 1)
    {
        if (dept.id_departement > max_id)
        {
            max_id = dept.id_departement;
        }
    }
    fclose(f);
    return max_id;


}


void ins_dept()
{
    Departement nouveauDepartement;

    char texte[50]; // pour recevoir le texte à saisir
    nouveauDepartement.id_departement= obtenir_dernier_id_dept("departement.dat") + 1;//l'ID de departement sera incrémenté automatiquement

    //Vider le buffer avant de lire une chaîne de caractères
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Entrez le nom du département: ");
    fgets(texte, sizeof(texte), stdin);
    //Supprime le retour à la ligne (\n) si présent
    texte[strcspn(texte, "\n")] = '\0';
    strcpy(nouveauDepartement.nom_departement, texte); // pour copier le nom dans le champ nom de departement

    printf("Entrez la description du département: ");
    fgets(texte, sizeof(texte), stdin);
    texte[strcspn(texte, "\n")] = '\0';
    strcpy(nouveauDepartement.desc_departement, texte); // pour copier le nom dans le champ nom de departement

    int retour= ecrire_departement("departement.dat", &nouveauDepartement);
    if(retour== 1)
    {
        printf("Département ajouté avec succès\n");
    }
    if (lire_departement("departement.dat",nouveauDepartement.id_departement, &nouveauDepartement))
    {
        printf("Nom du département : %s\n", nouveauDepartement.nom_departement);
        printf("Description du département : %s\n", nouveauDepartement.desc_departement);
        printf("ID du département : %d\n", nouveauDepartement.id_departement);
    }
    else
    {
        printf("Département non trouvé.\n");
    }

}


//fonction pour ecrire les infos du departement à inserer dans le fichier departement.dat
int ecrire_departement(const char *nom_fichier, Departement *d)
{
    FILE *f = fopen(nom_fichier, "ab"); // ouvrir en mode ajout pour ne pas écraser
    if (f == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }
    fwrite(d, sizeof(Departement), 1, f);
    fclose(f);
    return 1;
}
//fonction pour lire les données stockés dans le fichier departement.dat
int lire_departement(const char *nom_fichier, int id_recherche, Departement *resultat)
{
    FILE *f = fopen(nom_fichier, "rb");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }

    while (fread(resultat, sizeof(Departement), 1, f) == 1)
    {
        if (resultat->id_departement == id_recherche) {
            fclose(f);
            return 1; // departement trouvée
        }
    }

    fclose(f);
    return 0; // departement non trouvée
}
//fonction pour modifier les infos d'un departement
//on a pas besoin d'ajouter un parametre iD car l'ID incrémente automatiquement
void mod_dept()
{
    int ID;
   Departement modDepartement;
    char texte[200]; // pour recevoir le texte à saisir
    int choix;

    printf("Entrer l'Id du département à modifier-> ");
    scanf("%d",&ID);
    getchar(); // absorber le \n restant

    if (lire_departement("departement.dat", ID, &modDepartement))
    {
        printf("Departement trouvée !\n");
        printf("Nom actuel: %s\n", modDepartement.nom_departement);
        printf("Description actuelle: %s\n", modDepartement.desc_departement);

        do {
            printf("Que voulez-vous modifier ?\n");
            printf("1. Nom\n");
            printf("2. Description\n");
            printf("3. Quitter\n");
            printf(" Veuillez faire Votre choix : ");
            scanf("%d", &choix);
            getchar(); // absorber le \n

            switch(choix) {
                case 1:
                    printf("Vous allez modifier le nom du département (ID: %d)\n", modDepartement.id_departement);
                    printf("Entrez le nouveau nom: ");
                    fgets(texte, sizeof(texte), stdin);
                    texte[strcspn(texte, "\n")] = '\0'; // Supprime le retour à la ligne (\n) si présent
                    strcpy(modDepartement.nom_departement, texte);
                    break;
                case 2:
                    printf("Entrez la nouvelle description: ");
                    fgets(texte, sizeof(texte), stdin);
                    texte[strcspn(texte, "\n")] = '\0'; // Supprime le retour à la ligne (\n) si présent
                    strcpy(modDepartement.desc_departement, texte);
                    break;
                case 3:
                    printf("Modification terminée.\n");
                    break;
                default:
                    printf("Choix invalide. Veuillez réessayer.\n");
                    break;
            }

        }while(choix !=3);
        // Après modifications en mémoire, il faut sauvegarder dans le fichier
        FILE *f = fopen("departement.dat", "r+b");
        if (f == NULL) {
            printf("Impossible d'ouvrir le fichier pour mise à jour.\n");
            return;
        }
        Departement temp;
        while (fread(&temp, sizeof(Departement), 1, f) == 1) {
            if (temp.id_departement == modDepartement.id_departement) {
                // Reculer d'un enregistrement pour écraser
                fseek(f, -((long)sizeof(Departement)), SEEK_CUR);
                fwrite(&modDepartement, sizeof(Departement), 1, f);
                fflush(f);
                break;
            }
        }
        fclose(f);
    } else {
        printf("Département non trouvé.\n");
        return;
    }
}
// corps de la fonction pour lister les departements 
/*-------------------------------------------------------------------------------------*/
/* FONCTION:              lister_departements                                           */
/*DESCRIPTION:            Cette fonction permet de lister  les departements */
/*VALEUR DE RETOUR:       Pas de valeur de retour                        t                                     */
/*AUTEUR:                 Blaise Elie                                                   */
/*DATE DE CREATION:      10/10/2025                                                    */
/*DATE DE MODIFICATION:  18/10/2025                                                    */
void lister_departements()
{
    Departement dept;
    FILE *f = fopen("departement.dat", "rb");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    printf("\nListe des départements:\n");
    printf("-----------------------\n");
    while (fread(&dept, sizeof(Departement), 1, f) == 1)
    {
        printf("ID: %d\n", dept.id_departement);
        printf("Nom: %s\n", dept.nom_departement);
        printf("Description: %s\n", dept.desc_departement);
        printf("-----------------------\n");
    }

    fclose(f);
}

//corps fonction pour obtenir le dernier ID de commune
/*-------------------------------------------------------------------------------------*/
/* FONCTION:              obtenir_dernier_id_commune                                   */
/*Date de création:      18/10/2025                                                    */
/*Date de modification: 18/10/2025                                                     */
/*DESCRIPTION:           Cette fonction permet d'obtenir le dernier ID de commune      */
/*VALEUR DE RETOUR:      Dernier ID de commune                                         */
/*AUTEUR:                JEAN David Kehl                                                */

int obtenir_dernier_id_commune(const char *nom_fichier)
{

    int max_id = 0;
    Commune com;
    FILE *fc =fopen(nom_fichier, "rb");
    if (fc == NULL) {
        // fichier inexistant -> pas d'enregistrements
        return 0;
    }
    while (fread(&com, sizeof(Commune), 1, fc) == 1)
    {
        if (com.id_commune > max_id)
        {
            max_id = com.id_commune;
        }
    }
    fclose(fc);
    return max_id;


}

//corps fonction pour ecrire une commune(mode ajout)
/*-------------------------------------------------------------------------------------*/
/* FONCTION:              ecrire_commune                                               */
/*Date de création:      18/10/2025                                                    */
/*Date de modification: 18/10/2025                                                     */
/*DESCRIPTION:           Cette fonction permet d'obtenir le dernier ID de commune      */
/*VALEUR DE RETOUR:      1 si ajout effectué, 0 sinon                                  */
/*AUTEUR:                JEAN David Kehl                                                */

int ecrire_commune(const char *nom_fichier, Commune *c)
{
    FILE *fc = fopen(nom_fichier, "ab"); // ouvrir en mode ajout pour ne pas écraser
    if (fc == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier %s.\n", nom_fichier);
        return 0;
    }
    fseek(fc, 0, SEEK_END);
    fwrite(c, sizeof(Commune), 1, fc);
    fclose(fc);
    return 1;
}


//corps fonction pour lire une commune
/*-------------------------------------------------------------------------------------*/
/* FONCTION:              lire commune                                                 */
/*Date de création:      18/10/2025                                                    */
/*Date de modification:  18/10/2025                                                    */
/*DESCRIPTION:           Cette fonction permet de lire une commune par son ID          */
/*VALEUR DE RETOUR:      Dernier ID de commune                                         */
/*AUTEUR:                JEAN David Kehl                                                */

int lire_commune(const char *nom_fichier, int id_recherche, Commune *resultat)
{
    FILE *fc = fopen(nom_fichier, "rb");
    if (fc == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", nom_fichier);
        return 0;
    }

    while (fread(resultat, sizeof(Commune), 1, fc) == 1)
    {
        if (resultat->id_commune == id_recherche) {
            fclose(fc);
            return 1; // commune trouvée
        }
    }

    fclose(fc);
    return 0; // commune non trouvée
}
//corps fonction pour inserer une commune
/*-------------------------------------------------------------------------------------*/
/* FONCTION:              ins_com                                                      */
/*AUTEUR:                JEAN David Kehl                                               */
/*Date de création:      18/10/2025                                                    */
/*Date de modification:  18/10/2025                                                    */
/*DESCRIPTION:           Cette fonction permet d'inserer une commune                    */
/*VALEUR DE RETOUR:      Pas de valeur de retour                                        */

void ins_com()
{

  Commune nouvelleCommune;
  char texte[50]; // pour recevoir le texte à saisir
  nouvelleCommune.id_commune= obtenir_dernier_id_commune(FICHIER_COMMUNE) + 1;//l'ID de commune sera incrémenté automatiquement
    //Vider le buffer avant de lire une chaîne de caractères
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    //Saisir l'id du département auquel la commune appartient
    printf("Entrez l'ID du département auquel la commune appartient: ");
    if (scanf("%d", &nouvelleCommune.id_departement) != 1) {
        printf("Entrée invalide pour l'ID du département.\n");
        return;
    }
    while ((c = getchar()) != '\n' && c != EOF);
    //verirfier si le département parent existe
    Departement dept_test;
    if (!lire_departement("departement.dat", nouvelleCommune.id_departement, &dept_test)) {
        printf("ERREUR: Le département avec l'ID %d n'existe pas. Veuillez créer le département avant d'ajouter une commune.\n", nouvelleCommune.id_departement);
        return;
    }
    nouvelleCommune.id_departement = dept_test.id_departement;
    //Saisir le nom de la commune
    printf("Entrez le nom de la commune: ");
    fgets(texte, sizeof(texte), stdin);
    //Supprime le retour à la ligne (\n) si présent
    texte[strcspn(texte, "\n")] = '\0';
    strcpy(nouvelleCommune.nom_com, texte); // pour copier le nom dans le champ nom de commune

    //Saisir la description de la commune
    printf("Entrez la description de la commune: ");
    fgets(texte, sizeof(texte), stdin);
    texte[strcspn(texte, "\n")] = '\0';
    strcpy(nouvelleCommune.desc_com, texte); // pour copier le nom dans le champ nom de commune
    if(ecrire_commune(FICHIER_COMMUNE, &nouvelleCommune)== 1)
    {
        printf("Commune ajoutée avec succès  \n");
        //afficher sur forme de tableau (lignes et colonnes) les infos de la commune ajoutée son id et id du département parent et le nom de la commune et sa description
        printf("--------------------------------------------------\n");
        printf("| ID Departement | ID Commune | Nom Commune       | Description Commune  |\n");
        printf("--------------------------------------------------\n");
        printf("| %d         | %d             | %s                | %s                   |\n", nouvelleCommune.id_departement, nouvelleCommune.id_commune, nouvelleCommune.nom_com,nouvelleCommune.desc_com);
        printf("--------------------------------------------------\n");
    }



}



