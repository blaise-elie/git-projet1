
//corps fonction pour les departements et communes
#include <stdio.h>
#include <stdlib.h>
#include "entrep.h"
#include <string.h>

void inserer_departement(id_departement)
{
    Departement nouveauDepartement;
    char texte[50]; // pour recevoir le texte à saisir
    //le champ nouvelleUsine.Id_usine n'est pas definitif. l'iD de l'usine sera incrémenté(via un pointeur) automatiquement dans cette fonction ou dans la fonction appelante(on verra ca plus tard)
    nouveauDepartement.id_departement= 1;
    nouveauDepartement.id_departement= id_departement;

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
    }
    else
    {
        printf("Département non trouvé.\n");
    }

}


//fonction pour ecrire les infos du departement à inserer dans le fichier departement.dat
int ecrire_departement(const char *nom_fichier, Departement *d)
{
    FILE *f = fopen(nom_fichier, "wb");//ouvrir le fichier
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
void_modifier_departement(int ID)
{
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
            scanf("%d", &choix);
            getchar(); // absorber le \n

            switch(choix) {
                case 1:
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
    } else {
        printf("Département non trouvé.\n");
        return;
    }
}
