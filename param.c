<<<<<<< HEAD

//corps fonction pour les departements et communes
#include <stdio.h>
#include <stdlib.h>
#include "entrep.h"
#include <string.h>
#include <time.h>
#include <ctype.h>
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
        printf("\n");
        printf("┌────────────────────────────────────────────────┐\n");
        printf("│          ★ GESTION DES COMMUNE ★              │\n");
        printf("└────────────────────────────────────────────────┘\n");
        printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓   \n");
        printf("   ┃  [1] ► Ajouter une nouvelle commune      ┃   \n");
        printf("   ┃  [2] ► Modifier une commune              ┃   \n");
        printf("   ┃  [3] ► Lister toutes les communes        ┃   \n");               
        printf("   ┃  [0] ► Retour au menu des departements   ┃   \n");
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
                    mod_com();
                break;
            case 3:
                lister_communes();
                break;
            case 4:
                menu_usines();
                break;
            case 0:
                printf("Retour au menu departement...\n");
                menu_departements();
            default:
                printf("Choix invalide, veuillez réessayer.\n");
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
        printf("   ┃  [0] ► Retour au menu des communes       ┃   \n");
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
                mod_usine();
                break;
            case 3:
                lister_usines();
                break;
            case 4:
               menu_production();
            case 0:
                printf("Retour au menu communes...\n");
                menu_communes();
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
        printf("   ┃  [0] ► Retour au menu de usines          ┃   \n");
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
            case 0:
                printf("Retour au menu des usines...\n");
                 menu_usines();
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
{   lister_departements();
    Departement nouveauDepartement;
    
    char texte[50]; // pour recevoir le texte à saisir
    nouveauDepartement.id_departement= obtenir_dernier_id_dept("departement.dat") + 1;//l'ID de departement sera incrémenté automatiquement

    //Vider le buffer avant de lire une chaîne de caractères
    vider_buffer();

    printf("  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("  ┃  Entrez le nom du département   ┃\n"); 
    printf("         ►   "); 
    fgets(texte, sizeof(texte), stdin);
    //Supprime le retour à la ligne (\n) si présent
    texte[strcspn(texte, "\n")] = '\0';
    strcpy(nouveauDepartement.nom_departement, texte); // pour copier le nom dans le champ nom de departement
     //verifier si le nom du département existe déjà
    if (verifier_nom_departement_existe("departement.dat", nouveauDepartement.nom_departement)) {
        printf("Erreur: Le nom du département '%s' existe déjà. Veuillez choisir un autre nom.\n", nouveauDepartement.nom_departement);
        return; // sortir de la fonction sans ajouter le département
    }
    printf("\n");   
    printf("  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("  ┃  Entrez la description du département   ┃\n");
    printf("         ►   ");  
    
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
       
        //afficher sur forme de tableau (lignes et colonnes) les infos de la commune ajoutée son id et id du département parent et le nom de la commune et sa description
        printf("--------------------------------------------------\n");
        printf("| ID Departement| Nom Departement | Description Departement  |\n");
        printf("--------------------------------------------------\n");
        printf("| %d             | %s                   | %s                   |\n", nouveauDepartement.id_departement,nouveauDepartement.nom_departement, nouveauDepartement.desc_departement);
        printf("--------------------------------------------------\n");
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
       //afficher sur forme de tableau (lignes et colonnes) les infos du département avec son id , le nom et la description
        printf("| ID Departement| Nom Departement | Description Departement  |\n");
        printf("--------------------------------------------------\n");
        printf("| %d             | %s                   | %s                   |\n", dept.id_departement,dept.nom_departement, dept.desc_departement);
        printf("--------------------------------------------------\n");
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
    if (fc == NULL) {
        printf("Erreur lors de l'ouverture du fichier des communes.\n");
        return 0;
    }
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
    
    vider_buffer();

    //Saisir l'id du département auquel la commune appartient
    printf("Entrez l'ID du département auquel la commune appartient: ");
    if (scanf("%d", &nouvelleCommune.id_departement) != 1) {
        printf("Entrée invalide pour l'ID du département.\n");
        return;
    }
     vider_buffer();
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
   //verifier si le nom de la commune existe déjà dans le même département
    Commune com_test;
    if ( verifier_nom_commune_existe(FICHIER_COMMUNE, texte)) {
        printf("Erreur: Le nom de la commune '%s' existe déjà dans le département avec l'ID %d. Veuillez choisir un autre nom.\n", texte, nouvelleCommune.id_departement);
        return; // sortir de la fonction sans ajouter la commune
    }


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
//Corps fonction pour modifier une commune
/*-------------------------------------------------------------------------------------*/
/* FONCTION:              mod_com                                                      */
/*AUTEUR:                JEAN David Kehl                                               */
/*Date de création:      18/10/2025                                                    */
/*Date de modification:  22/10/2025                                                    */
/*DESCRIPTION:           Cette fonction permet de modifier une commune                 */
/*VALEUR DE RETOUR:      Pas de valeur de retour                                       */

void mod_com()
    {
        int ID;
    Commune nouvellecommune;
    char texte [200]; // pour recevoir le texte à saisir
    int choix;
       
    printf("Entrer l'Id de la commune à modifier-> ");
    scanf("%d",&ID);
     
      if (lire_commune(FICHIER_COMMUNE, ID, &nouvellecommune)) {
          
          printf("Commune trouvée !\n");
          printf("Nom actuel: %s\n", nouvellecommune.nom_com);
          printf("Description actuelle: %s\n", nouvellecommune.desc_com);
          do {
              printf("Que voulez-vous modifier ?\n");
              printf("1. Nom\n");
              printf("2. Description\n");
              printf("3. Quitter\n");
              scanf("%d", &choix);
              getchar(); // absorber le \n restant
            

                switch(choix) {
                    case 1:
                        printf("Entrer le nouveau nom: ");
                        fgets(texte, sizeof(texte), stdin);
                        texte[strcspn(texte, "\n")] = '\0'; // Supprime le retour à la ligne (\n) si présent
                        strcpy(nouvellecommune.nom_com, texte);
                        break;
                    case 2:
                        printf("Entrer la nouvelle description: ");
                        fgets(texte, sizeof(texte), stdin);
                        texte[strcspn(texte, "\n")] = '\0'; // Supprime le retour à la ligne (\n) si présent
                        strcpy(nouvellecommune.desc_com, texte);
                        break;
                    case 3:
                        printf("Modification terminée.\n");
                        break;
                    default:
                        printf("Choix invalide. Veuillez réessayer.\n");
                        break;
                }
            } while (choix != 3);
            if (ecrire_commune(FICHIER_COMMUNE, &nouvellecommune)) {
                printf("Modifications enregistrées avec succès.\n");
            } else {
                printf("Erreur lors de l'enregistrement des modifications.\n");
            }
        } else {
            printf("Commune non trouvée.\n");
        }
}

//Corps de la fonction pour verifier si le nom d'un departement existe deja dans le fichier departement.dat
//faire seulement la recherche dans le fichier sans demander de l'entrer


// fonction pour trim les espaces en début et fin de chaîne
static void str_trim(char *s) {
    char *p = s;
    // trim leading
    while (isspace((unsigned char)*p)) p++;
    if (p != s) memmove(s, p, strlen(p) + 1);
    // cette partie permet de faire le trim trailing
    size_t len = strlen(s);
    while (len > 0 && isspace((unsigned char)s[len-1])) s[--len] = '\0';
}

//cette fonction convertit une chaîne en minuscules (in place)
static void str_tolower_inplace(char *s) {
    for (; *s; ++s) *s = (char)tolower((unsigned char)*s);
}

/*
 * verifier_nom_departement_existe
 * Retourne 1 si un département avec le même nom (insensible à la casse, espaces ignorés en début/fin)
 * existe dans le fichier binaire `nom_fichier`. Sinon 0.
 */
int verifier_nom_departement_existe(const char *nom_fichier, const char *nom_dept)
{
    if (nom_fichier == NULL || nom_dept == NULL) return 0;

    char cible[64];
    strncpy(cible, nom_dept, sizeof(cible)-1);
    cible[sizeof(cible)-1] = '\0';
    str_trim(cible);
    str_tolower_inplace(cible);

    Departement d;
    FILE *f = fopen(nom_fichier, "rb");
    if (f == NULL) {
        return 0; // fichier inexistant -> pas d'enregistrements
    }

    int found = 0;
    while (fread(&d, sizeof(Departement), 1, f) == 1) {
        char nom_actuel[64];
        strncpy(nom_actuel, d.nom_departement, sizeof(nom_actuel)-1);
        nom_actuel[sizeof(nom_actuel)-1] = '\0';
        str_trim(nom_actuel);
        str_tolower_inplace(nom_actuel);
        if (strcmp(nom_actuel, cible) == 0) { found = 1; break; }
    }
    fclose(f);
    return found;
}
//corps fonction pour lister les communes
/*-------------------------------------------------------------------------------------*/    
/* FONCTION:              lister_communes                                              */    
/*DESCRIPTION:            Cette fonction permet de lister  les communes                */    
/*VALEUR DE RETOUR:       Pas de valeur de retour                                       */
/*Auteur:                 Blaise Elie                                                  */
/*DATE DE CREATION:      22/10/2025                                                   */    
/*DATE DE MODIFICATION:  22/10/2025                                                   */    
void lister_communes() {
    Commune com;
    FILE *fc = fopen(FICHIER_COMMUNE, "rb");
    if (fc == NULL) {
        printf("Erreur lors de l'ouverture du fichier des communes.\n");
        return;
    }

    printf("\nListe des communes:\n");
    printf("-----------------------\n");
    while (fread(&com, sizeof(Commune), 1, fc) == 1)
    {
        printf("ID Commune: %d\n", com.id_commune);
        printf("ID Département: %d\n", com.id_departement);
        printf("Nom: %s\n", com.nom_com);
        printf("Description: %s\n", com.desc_com);
        printf("-----------------------\n");
    }

    fclose(fc);
}
//corps de la fonction pour verifier si le nom d'une commune existe deja dans le fichier commune.dat
//faire seulement la recherche dans le fichier sans demander de l'entrer
/*
 * verifier_nom_commune_existe
 * Retourne 1 si une commune avec le même nom (insensible à la casse, espaces ignorés en début/fin)
 * existe dans le fichier binaire `nom_fichier`. Sinon 0.
    */
int verifier_nom_commune_existe(const char *nom_fichier, const char *nom_com)
{
    if (nom_fichier == NULL || nom_com == NULL) return 0;

    char cible[64];
    strncpy(cible, nom_com, sizeof(cible)-1);
    cible[sizeof(cible)-1] = '\0';
    str_trim(cible);
    str_tolower_inplace(cible);

    Commune c;
    FILE *f = fopen(nom_fichier, "rb");
    if (f == NULL) {
        return 0; // fichier inexistant -> pas d'enregistrements
    }

    int found = 0;
    while (fread(&c, sizeof(Commune), 1, f) == 1) {
        char nom_actuel[64];
        strncpy(nom_actuel, c.nom_com, sizeof(nom_actuel)-1);
        nom_actuel[sizeof(nom_actuel)-1] = '\0';
        str_trim(nom_actuel);
        str_tolower_inplace(nom_actuel);
        if (strcmp(nom_actuel, cible) == 0) { found = 1; break; }
    }
    fclose(f);
    return found;
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
        printf("   ┃  [1] ► Liste des produits disponibles    ┃   \n");
        printf("   ┃  [2] ► Liste des produits fabriqués      ┃   \n");       
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
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    }
=======

//corps fonction pour les departements et communes
#include <stdio.h>
#include <stdlib.h>
#include "entrep.h"
#include <string.h>
#include <time.h>
#include <ctype.h>
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
        printf("\n");
        printf("┌────────────────────────────────────────────────┐\n");
        printf("│          ★ GESTION DES COMMUNE ★              │\n");
        printf("└────────────────────────────────────────────────┘\n");
        printf("   ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓   \n");
        printf("   ┃  [1] ► Ajouter une nouvelle commune      ┃   \n");
        printf("   ┃  [2] ► Modifier une commune              ┃   \n");
        printf("   ┃  [3] ► Lister toutes les communes        ┃   \n");               
        printf("   ┃  [0] ► Retour au menu des departements   ┃   \n");
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
                    mod_com();
                break;
            case 3:
                lister_communes();
                break;
            case 4:
                menu_usines();
                break;
            case 0:
                printf("Retour au menu departement...\n");
                menu_departements();
            default:
                printf("Choix invalide, veuillez réessayer.\n");
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
        printf("   ┃  [0] ► Retour au menu des communes       ┃   \n");
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
                mod_usine();
                break;
            case 3:
                lister_usines();
                break;
            case 4:
               menu_production();
            case 0:
                printf("Retour au menu communes...\n");
                menu_communes();
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
        printf("   ┃  [0] ► Retour au menu de usines          ┃   \n");
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
            case 0:
                printf("Retour au menu des usines...\n");
                 menu_usines();
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
{   lister_departements();
    Departement nouveauDepartement;
    
    char texte[50]; // pour recevoir le texte à saisir
    nouveauDepartement.id_departement= obtenir_dernier_id_dept("departement.dat") + 1;//l'ID de departement sera incrémenté automatiquement

    //Vider le buffer avant de lire une chaîne de caractères
    vider_buffer();

    printf("  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("  ┃  Entrez le nom du département   ┃\n"); 
    printf("         ►   "); 
    fgets(texte, sizeof(texte), stdin);
    //Supprime le retour à la ligne (\n) si présent
    texte[strcspn(texte, "\n")] = '\0';
    strcpy(nouveauDepartement.nom_departement, texte); // pour copier le nom dans le champ nom de departement
     //verifier si le nom du département existe déjà
    if (verifier_nom_departement_existe("departement.dat", nouveauDepartement.nom_departement)) {
        printf("Erreur: Le nom du département '%s' existe déjà. Veuillez choisir un autre nom.\n", nouveauDepartement.nom_departement);
        return; // sortir de la fonction sans ajouter le département
    }
    printf("\n");   
    printf("  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("  ┃  Entrez la description du département   ┃\n");
    printf("         ►   ");  
    
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
       
        //afficher sur forme de tableau (lignes et colonnes) les infos de la commune ajoutée son id et id du département parent et le nom de la commune et sa description
        printf("--------------------------------------------------\n");
        printf("| ID Departement| Nom Departement | Description Departement  |\n");
        printf("--------------------------------------------------\n");
        printf("| %d             | %s                   | %s                   |\n", nouveauDepartement.id_departement,nouveauDepartement.nom_departement, nouveauDepartement.desc_departement);
        printf("--------------------------------------------------\n");
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
       //afficher sur forme de tableau (lignes et colonnes) les infos du département avec son id , le nom et la description
        printf("| ID Departement| Nom Departement | Description Departement  |\n");
        printf("--------------------------------------------------\n");
        printf("| %d             | %s                   | %s                   |\n", dept.id_departement,dept.nom_departement, dept.desc_departement);
        printf("--------------------------------------------------\n");
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
    if (fc == NULL) {
        printf("Erreur lors de l'ouverture du fichier des communes.\n");
        return 0;
    }
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
    
    vider_buffer();

    //Saisir l'id du département auquel la commune appartient
    printf("Entrez l'ID du département auquel la commune appartient: ");
    if (scanf("%d", &nouvelleCommune.id_departement) != 1) {
        printf("Entrée invalide pour l'ID du département.\n");
        return;
    }
     vider_buffer();
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
   //verifier si le nom de la commune existe déjà dans le même département
    Commune com_test;
    if ( verifier_nom_commune_existe(FICHIER_COMMUNE, texte)) {
        printf("Erreur: Le nom de la commune '%s' existe déjà dans le département avec l'ID %d. Veuillez choisir un autre nom.\n", texte, nouvelleCommune.id_departement);
        return; // sortir de la fonction sans ajouter la commune
    }


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
//Corps fonction pour modifier une commune
/*-------------------------------------------------------------------------------------*/
/* FONCTION:              mod_com                                                      */
/*AUTEUR:                JEAN David Kehl                                               */
/*Date de création:      18/10/2025                                                    */
/*Date de modification:  22/10/2025                                                    */
/*DESCRIPTION:           Cette fonction permet de modifier une commune                 */
/*VALEUR DE RETOUR:      Pas de valeur de retour                                       */

void mod_com()
    {
        int ID;
    Commune nouvellecommune;
    char texte [200]; // pour recevoir le texte à saisir
    int choix;
       
    printf("Entrer l'Id de la commune à modifier-> ");
    scanf("%d",&ID);
     
      if (lire_commune(FICHIER_COMMUNE, ID, &nouvellecommune)) {
          
          printf("Commune trouvée !\n");
          printf("Nom actuel: %s\n", nouvellecommune.nom_com);
          printf("Description actuelle: %s\n", nouvellecommune.desc_com);
          do {
              printf("Que voulez-vous modifier ?\n");
              printf("1. Nom\n");
              printf("2. Description\n");
              printf("3. Quitter\n");
              scanf("%d", &choix);
              getchar(); // absorber le \n restant
            

                switch(choix) {
                    case 1:
                        printf("Entrer le nouveau nom: ");
                        fgets(texte, sizeof(texte), stdin);
                        texte[strcspn(texte, "\n")] = '\0'; // Supprime le retour à la ligne (\n) si présent
                        strcpy(nouvellecommune.nom_com, texte);
                        break;
                    case 2:
                        printf("Entrer la nouvelle description: ");
                        fgets(texte, sizeof(texte), stdin);
                        texte[strcspn(texte, "\n")] = '\0'; // Supprime le retour à la ligne (\n) si présent
                        strcpy(nouvellecommune.desc_com, texte);
                        break;
                    case 3:
                        printf("Modification terminée.\n");
                        break;
                    default:
                        printf("Choix invalide. Veuillez réessayer.\n");
                        break;
                }
            } while (choix != 3);
            if (ecrire_commune(FICHIER_COMMUNE, &nouvellecommune)) {
                printf("Modifications enregistrées avec succès.\n");
            } else {
                printf("Erreur lors de l'enregistrement des modifications.\n");
            }
        } else {
            printf("Commune non trouvée.\n");
        }
}

//Corps de la fonction pour verifier si le nom d'un departement existe deja dans le fichier departement.dat
//faire seulement la recherche dans le fichier sans demander de l'entrer


// fonction pour trim les espaces en début et fin de chaîne
static void str_trim(char *s) {
    char *p = s;
    // trim leading
    while (isspace((unsigned char)*p)) p++;
    if (p != s) memmove(s, p, strlen(p) + 1);
    // cette partie permet de faire le trim trailing
    size_t len = strlen(s);
    while (len > 0 && isspace((unsigned char)s[len-1])) s[--len] = '\0';
}

//cette fonction convertit une chaîne en minuscules (in place)
static void str_tolower_inplace(char *s) {
    for (; *s; ++s) *s = (char)tolower((unsigned char)*s);
}

/*
 * verifier_nom_departement_existe
 * Retourne 1 si un département avec le même nom (insensible à la casse, espaces ignorés en début/fin)
 * existe dans le fichier binaire `nom_fichier`. Sinon 0.
 */
int verifier_nom_departement_existe(const char *nom_fichier, const char *nom_dept)
{
    if (nom_fichier == NULL || nom_dept == NULL) return 0;

    char cible[64];
    strncpy(cible, nom_dept, sizeof(cible)-1);
    cible[sizeof(cible)-1] = '\0';
    str_trim(cible);
    str_tolower_inplace(cible);

    Departement d;
    FILE *f = fopen(nom_fichier, "rb");
    if (f == NULL) {
        return 0; // fichier inexistant -> pas d'enregistrements
    }

    int found = 0;
    while (fread(&d, sizeof(Departement), 1, f) == 1) {
        char nom_actuel[64];
        strncpy(nom_actuel, d.nom_departement, sizeof(nom_actuel)-1);
        nom_actuel[sizeof(nom_actuel)-1] = '\0';
        str_trim(nom_actuel);
        str_tolower_inplace(nom_actuel);
        if (strcmp(nom_actuel, cible) == 0) { found = 1; break; }
    }
    fclose(f);
    return found;
}
//corps fonction pour lister les communes
/*-------------------------------------------------------------------------------------*/    
/* FONCTION:              lister_communes                                              */    
/*DESCRIPTION:            Cette fonction permet de lister  les communes                */    
/*VALEUR DE RETOUR:       Pas de valeur de retour                                       */
/*Auteur:                 Blaise Elie                                                  */
/*DATE DE CREATION:      22/10/2025                                                   */    
/*DATE DE MODIFICATION:  22/10/2025                                                   */    
void lister_communes() {
    Commune com;
    FILE *fc = fopen(FICHIER_COMMUNE, "rb");
    if (fc == NULL) {
        printf("Erreur lors de l'ouverture du fichier des communes.\n");
        return;
    }

    printf("\nListe des communes:\n");
    printf("-----------------------\n");
    while (fread(&com, sizeof(Commune), 1, fc) == 1)
    {
        printf("ID Commune: %d\n", com.id_commune);
        printf("ID Département: %d\n", com.id_departement);
        printf("Nom: %s\n", com.nom_com);
        printf("Description: %s\n", com.desc_com);
        printf("-----------------------\n");
    }

    fclose(fc);
}
//corps de la fonction pour verifier si le nom d'une commune existe deja dans le fichier commune.dat
//faire seulement la recherche dans le fichier sans demander de l'entrer
/*
 * verifier_nom_commune_existe
 * Retourne 1 si une commune avec le même nom (insensible à la casse, espaces ignorés en début/fin)
 * existe dans le fichier binaire `nom_fichier`. Sinon 0.
    */
int verifier_nom_commune_existe(const char *nom_fichier, const char *nom_com)
{
    if (nom_fichier == NULL || nom_com == NULL) return 0;

    char cible[64];
    strncpy(cible, nom_com, sizeof(cible)-1);
    cible[sizeof(cible)-1] = '\0';
    str_trim(cible);
    str_tolower_inplace(cible);

    Commune c;
    FILE *f = fopen(nom_fichier, "rb");
    if (f == NULL) {
        return 0; // fichier inexistant -> pas d'enregistrements
    }

    int found = 0;
    while (fread(&c, sizeof(Commune), 1, f) == 1) {
        char nom_actuel[64];
        strncpy(nom_actuel, c.nom_com, sizeof(nom_actuel)-1);
        nom_actuel[sizeof(nom_actuel)-1] = '\0';
        str_trim(nom_actuel);
        str_tolower_inplace(nom_actuel);
        if (strcmp(nom_actuel, cible) == 0) { found = 1; break; }
    }
    fclose(f);
    return found;
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
        printf("   ┃  [1] ► Liste des produits disponibles    ┃   \n");
        printf("   ┃  [2] ► Liste des produits fabriqués      ┃   \n");       
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
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    }
>>>>>>> 16d998371f4d71ffd3ff471c01450329f54db791
}