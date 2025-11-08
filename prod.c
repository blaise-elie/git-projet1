/*------------------------------------------------------------------------*/
/* FICHIER:                          usine.c                               */ 
/*AUTEUR:                           PIERRE-LOUIS Alven Bernadin           */    
/*DATE DE CREATIION:                27/09/2025                            */
/*DATE DE MODIFICATION:             22/10/2025                            */
/*DESCRIPTION:                      fichier contenant les fonctions de 
                                    gestion des usines.                   */
/*------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrep.h"
#include "time.h"

// prototype du helper local
static void enregistrer_production_after_insert(Produit *produit);

/*------------------------------------------------------------------------*/
//fonction pour inserer une usine
void ins_usine() 
{
    Usine nouvelleUsine;
    char texte[50];

    // Définir l'ID avant l'écriture
    nouvelleUsine.id_usine = obtenir_dernier_id_usine("usine.dat") + 1;\
    
    // Vider le buffer avant de lire une chaîne de caractères
    vider_buffer();  

    // Demander l'ID de la commune parente et vérifier son existence dans le fichier commune.dat
    int id_com_input;
    printf("Entrez l'ID de la commune parente de l'usine: ");
    if (scanf("%d", &id_com_input) != 1) {
        printf("Entrée invalide pour l'ID de la commune.\n");
        // vider le buffer
        vider_buffer();
        return;
    }
    // vider le reste du buffer
       vider_buffer();

    // Vérifier que le fichier existe et que l'ID correspond à une commune
    Commune com_tmp;
    if (!lire_commune("commune.dat", id_com_input, &com_tmp)) {
        printf("ERREUR: La commune avec l'ID %d n'existe pas. Veuillez créer la commune avant d'ajouter une usine.\n", id_com_input);
        return;
    }
    // Rattacher l'usine à l'ID de commune validé
    nouvelleUsine.id_com = com_tmp.id_commune;
  

    printf("Entrez le nom de l'usine: ");
    fgets(texte, sizeof(texte), stdin);
    texte[strcspn(texte, "\n")] = '\0';
    strcpy(nouvelleUsine.Usi_nom, texte);

    printf("Entrez la description de l'usine: ");
    fgets(texte, sizeof(texte), stdin);
    texte[strcspn(texte, "\n")] = '\0';
    strcpy(nouvelleUsine.Usin_desc, texte);

    // Écrire l'usine après avoir défini toutes ses propriétés
    int retour = ecrire_usine("usine.dat", &nouvelleUsine);
    if(retour == 1)
    {
        printf("Usine ajoutée avec succès\n");
        //affichage sur forme de tableau des infos de l'usine ajoutée
        printf("--------------------------------------------------\n");
        printf("| ID Commune | ID Usine | Nom Usine        | Description Usine    |\n");
        printf("--------------------------------------------------\n");
        printf("| %d         | %d        | %s           | %s                 |\n", nouvelleUsine.id_com, nouvelleUsine.id_usine, nouvelleUsine.Usi_nom, nouvelleUsine.Usin_desc);
        printf("--------------------------------------------------\n");
    }
    else 
    {
        printf("Erreur lors de l'ajout de l'usine.\n");
    }
}

/*------------------------------------------------------------------------*/
int ecrire_usine(const char *nom_fichier, Usine *u) 
{
    FILE *f = fopen(nom_fichier, "ab"); // Ouvre le fichier en mode ajout binaire
    if (f == NULL) 
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }
    fwrite(u, sizeof(Usine), 1, f);
    fclose(f);
    return 1;
}

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
        if (resultat->id_usine == id_recherche) {
            fclose(f);
            return 1; // Usine trouvée
        }
    }
    
    fclose(f);
    return 0; // Usine non trouvée
}

/*------------------------------------------------------------------------*/
void mod_usine()
{   int ID;
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
                    break;
                    
                case 2:
                    printf("Entrer la nouvelle description: ");
                    fgets(texte, sizeof(texte), stdin);
                    texte[strcspn(texte, "\n")] = '\0';
                    strcpy(usine_a_modifier.Usin_desc, texte);
                    printf("Description modifiée avec succès!\n");
                    break;
                    
                case 3:
                    printf("Modification terminée.\n");
                    break;
                    
                default: 
                    printf("Choix invalide. Veuillez réessayer.\n");
                    break;
            }
        } while (choix != 3);
        /* Après modifications en mémoire, sauvegarder dans le fichier en place */
        FILE *f = fopen("usine.dat", "r+b");
        if (f == NULL) {
            printf("Impossible d'ouvrir le fichier usine.dat pour mise à jour.\n");
            return;
        }
        Usine tmp;
        int updated = 0;
        while (fread(&tmp, sizeof(Usine), 1, f) == 1) {
            if (tmp.id_usine == usine_a_modifier.id_usine) {
                /* Reculer d'un enregistrement et écraser */
                fseek(f, -((long)sizeof(Usine)), SEEK_CUR);
                if (fwrite(&usine_a_modifier, sizeof(Usine), 1, f) == 1) {
                    fflush(f);
                    updated = 1;
                }
                break;
            }
        }
        fclose(f);
        if (updated) {
            printf("Usine mise à jour avec succès.\n");
        } else {
            printf("Aucune usine modifiée (ID introuvable).\n");
        }
    } else {
        printf("Aucune usine trouvée avec l'ID %d\n", ID);
    }
}

/*-----------------------------------------------------------------------------------*/
void lister_usines()
{
    Usine usine;
    FILE *f = fopen("usine.dat", "rb");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    printf("\nListe des usines:\n");
    printf("--------------------------------------------------\n");
    printf("| ID Usine | ID Commune | Nom Usine        | Description Usine    |\n");
    printf("--------------------------------------------------\n");
    while (fread(&usine, sizeof(Usine), 1, f) == 1)
    {
        printf("| %d       | %d         | %s           | %s                 |\n", usine.id_usine, usine.id_com, usine.Usi_nom, usine.Usin_desc);
        printf("--------------------------------------------------\n");
    }

    fclose(f);
}

int obtenir_dernier_id_usine(const char *nom_fichier)
{    
    int max_id = 0;
    Usine usine;
    FILE *f = fopen(nom_fichier, "rb");
    while (fread(&usine, sizeof(Usine), 1, f) == 1)
    {
        if (usine.id_usine > max_id)
        {
            max_id = usine.id_usine;
        }
    }
    fclose(f);
    return max_id;


}

/*------------------------------------------------------------------------*/
void ins_Prod()
{   
    Produit nouveauProduit;
    char texte[50]; // pour recevoir le texte à saisir

    nouveauProduit.Id_prod = obtenir_dernier_id_produit("produit.dat") + 1;
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    // Demander et valider l'ID de l'usine parente
    int id_usine_input;
    printf("Entrez l'ID de l'usine parente du produit: ");
    if (scanf("%d", &id_usine_input) != 1) {
        printf("Entrée invalide pour l'ID de l'usine.\n");
        // vider le buffer
        while ((c = getchar()) != '\n' && c != EOF) {}
        return;
    }
    // vider le reste du buffer
    vider_buffer();

    Usine usine_tmp;
    if (!lire_usine("usine.dat", id_usine_input, &usine_tmp)) {
        printf("ERREUR: L'usine avec l'ID %d n'existe pas. Veuillez créer l'usine avant d'ajouter un produit.\n", id_usine_input);
        return;
    }
    nouveauProduit.Id_usine = usine_tmp.id_usine;

    printf("Entrez le nom du produit: ");
    fgets(texte, sizeof(texte), stdin);

    // Supprime le retour à la ligne (\n) si présent
    texte[strcspn(texte, "\n")] = '\0';
    strcpy(nouveauProduit.Pro_nom, texte); //Pour copier le nom dans le champ nom de l'usine
    //description du produit
    printf("Entrez la description du produit: ");
    fgets(texte, sizeof(texte), stdin);
    texte[strcspn(texte, "\n")] = '\0';
    strcpy(nouveauProduit.pro_desc, texte); //Pour copier le nom dans le champ nom de l'usine

    //prix du produit
    printf("Entrez le prix du produit en Gourdes  ► ");
    scanf("%f", &nouveauProduit.pro_prix);
    getchar(); // absorber le \n restant

    // Quantité du produit
    printf("Entrez la quantité du produit fabrique ► ");
    scanf("%d", &nouveauProduit.pro_qte);
    getchar(); // absorber le \n restant


    int retour = ecrire_produit("produit.dat", &nouveauProduit);
    if(retour == 1)
    {
        printf("Produit ajouté avec succes\n");
    }

    if (lire_produit("produit.dat", nouveauProduit.Id_prod, &nouveauProduit)) 

    {  //affichage sous forme de tableau des infos du produit ajouté
        printf("--------------------------------------------------\n");
        printf("| ID Produit | ID Usine | Nom Produit      | Description Produit  | Prix | Quantité |\n");
        printf("--------------------------------------------------\n");
        printf("| %d         | %d        | %s           | %s                 | %.2f | %d       |\n", nouveauProduit.Id_prod, nouveauProduit.Id_usine, nouveauProduit.Pro_nom, nouveauProduit.pro_desc, nouveauProduit.pro_prix, nouveauProduit.pro_qte);
        printf("--------------------------------------------------\n");
    
    } 
    else 
    {
        printf("Produit non trouvé.\n");
    }

    /* Après l'insertion du produit, enregistrer automatiquement
       une entrée de production (lot) liée à ce produit.
       On demande uniquement les dates (production et expiration).
       La quantité du lot sera la quantité initiale saisie pour le produit.
    */
     if (retour == 1) {
         enregistrer_production_after_insert(&nouveauProduit);
     }

    
}

/*------------------------------------------------------------------------*/
int ecrire_produit(const char *nom_fichier, Produit *p) 
{
    FILE *f = fopen(nom_fichier, "ab"); // Ouvre le fichier en mode ajout binaire
    if (f == NULL) 
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }
    fwrite(p, sizeof(Produit), 1, f);
    fclose(f);
    return 1;
}

/*------------------------------------------------------------------------*/
int lire_produit(const char *nom_fichier, int id_recherche, Produit *resultat) 
{
    FILE *f = fopen(nom_fichier, "rb");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }
    
    while (fread(resultat, sizeof(Produit), 1, f) == 1)
    {
        if (resultat->Id_prod == id_recherche) {
            fclose(f);
            return 1; // Produit trouvé
        }
    }
    
    fclose(f);
    return 0; // Produit non trouvé
}


int obtenir_dernier_id_produit(const char *nom_fichier) 
{
    FILE *f = fopen(nom_fichier, "rb");
    if (f == NULL) return 0;

    Produit temp;
    int dernier_id = 0;

    while (fread(&temp, sizeof(Produit), 1, f) == 1) {
        if (temp.Id_prod > dernier_id) {
            dernier_id = temp.Id_prod;
        }
    }

    fclose(f);
    return dernier_id;
}

/*------------------------------------------------------------------------*/
void mod_prod()
{
    Produit produit_a_modifier;
    int choix, ID;
    char texte[200]; // pour stocker le texte saisi
    
    printf("Entrer l'Id du produit à modifier-> ");
    scanf("%d", &ID);
    getchar(); // absorber le \n restant
    
    if (lire_produit("produit.dat", ID, &produit_a_modifier)) 
    {
        printf("produit trouvée !\n");
        printf("Nom actuel: %s\n", produit_a_modifier.Pro_nom);
        printf("Description actuelle: %s\n", produit_a_modifier.pro_desc);
        printf("Prix actuel: %.2f\n", produit_a_modifier.pro_prix);
        printf("Quantité actuelle: %d\n", produit_a_modifier.pro_qte);
        
        do {
            printf("Que voulez-vous modifier ?\n");
            printf("1. Nom\n");
            printf("2. Description\n");
            printf("3. Prix\n");
            printf("4. Quantité\n");
            printf("5. Quitter\n");
            scanf("%d", &choix);
            getchar(); // absorber le \n

            switch(choix)
            {
                case 1: 
                    printf("Entrer le nouveau nom: ");
                    fgets(texte, sizeof(texte), stdin);
                    texte[strcspn(texte, "\n")] = '\0';
                    strcpy(produit_a_modifier.Pro_nom, texte);
                    printf("Nom modifié avec succès!\n");
                    printf("Nouveau nom: %s\n", produit_a_modifier.Pro_nom);
                    break;
                    
                case 2:
                    printf("Entrer la nouvelle description: ");
                    fgets(texte, sizeof(texte), stdin);
                    texte[strcspn(texte, "\n")] = '\0';
                    strcpy(produit_a_modifier.pro_desc, texte);
                    printf("Description modifiée avec succès!\n");
                    printf("Nouvelle description: %s\n", produit_a_modifier.pro_desc);
                    break;

                case 3:
                    printf("Entrer le nouveau prix: ");
                    float new_prix;
                    scanf("%f", &new_prix);
                    produit_a_modifier.pro_prix = new_prix;
                    printf("Prix modifié avec succès!\n");
                    printf("Nouveau prix: %.2f\n", produit_a_modifier.pro_prix);
                    break;
                 
                case 4: 
                    printf("Entrer la nouvelle quantité: ");
                    int new_qte;
                    scanf("%d", &new_qte);
                    produit_a_modifier.pro_qte = new_qte;
                    printf("Quantité modifiée avec succès!\n");
                    printf("Nouvelle quantité: %d\n", produit_a_modifier.pro_qte);
                    break;

                case 5:
                    printf("Modification annulée\n");
                    break;
                    
                default: 
                    printf("Choix invalide. Veuillez réessayer.\n");
                    break;
            }
        } while (choix != 5);
    } else {
        printf("Aucune usine trouvée avec l'ID %d\n", ID);
    }
}

/*------------------------------------------------------------------------*/
void lister_produits() {
    Produit produit;
    FILE *f = fopen("produit.dat", "rb");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier des produits.\n");
        return;
    }

    //afficher les produits avec leurr id et l'ID de l'usine ou ils sont
   printf("\nListe des produits:\n");
   while(fread(&produit, sizeof(Produit), 1, f) == 1) {

     //affichage sous forme de tableau des infos du produit ajouté
        printf("--------------------------------------------------\n");
        printf("| ID Produit | ID Usine | Nom Produit      | Description Produit  | Prix | Quantité |\n");
        printf("--------------------------------------------------\n");
        printf("| %d         | %d        | %s           | %s                 | %.2f | %d       |\n", produit.Id_prod, produit.Id_usine, produit.Pro_nom, produit.pro_desc, produit.pro_prix, produit.pro_qte);
        printf("--------------------------------------------------\n");
        
    }

    fclose(f);
}

/*------------------------------------------------------------------------*/
void generer_date_courante(char* date_str) {
    if (date_str == NULL) return;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t == NULL) {
        date_str[0] = '\0';
        return;
    }
    strftime(date_str, 11, "%d/%m/%Y", t);
}

/*------------------------------------------------------------------------*/
  static void enregistrer_production_after_insert(Produit *produit) {
      if (produit == NULL) return;
     Hist_production nouveau_lot;
     char buffer[32];

      nouveau_lot.Id_lot = obtenir_dernier_id_lot(HIST_PROD_FILE) + 1;
      nouveau_lot.id_prod = produit->Id_prod;

//     // Demander la date de production
     printf("Entrez la date de production pour '%s' (JJ/MM/AAAA) : ", produit->Pro_nom);
      // vider le buffer éventuel puis lire
     if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
//         // si EOF ou erreur, on génère la date courante
          generer_date_courante(nouveau_lot.Dat_prod);
      } else {
         buffer[strcspn(buffer, "\n")] = '\0';
         if (strlen(buffer) == 0) {
              generer_date_courante(nouveau_lot.Dat_prod);
          } else {
             strncpy(nouveau_lot.Dat_prod, buffer, sizeof(nouveau_lot.Dat_prod)-1);
             nouveau_lot.Dat_prod[sizeof(nouveau_lot.Dat_prod)-1] = '\0';
          }
     }

//     // Demander la date d'expiration
      printf("Entrez la date d'expiration pour '%s' (JJ/MM/AAAA) : ", produit->Pro_nom);
      if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
         nouveau_lot.Dat_exp[0] = '\0';
       } else {
           buffer[strcspn(buffer, "\n")] = '\0';
          strncpy(nouveau_lot.Dat_exp, buffer, sizeof(nouveau_lot.Dat_exp)-1);
         nouveau_lot.Dat_exp[sizeof(nouveau_lot.Dat_exp)-1] = '\0';
       }

      //Quantité = quantité initiale saisie pour le produit
      nouveau_lot.Lot_qte = produit->pro_qte;

     FILE *f = fopen(HIST_PROD_FILE, "ab");
       if (f == NULL) {
           printf("Erreur: impossible d'ouvrir %s pour écrire l'historique de production.\n", HIST_PROD_FILE);
          return;
       }
       fwrite(&nouveau_lot, sizeof(Hist_production), 1, f);
     fclose(f);

      printf("Production initiale enregistrée (lot ID %d) : %d unités pour '%s'.\n", nouveau_lot.Id_lot, nouveau_lot.Lot_qte, produit->Pro_nom);
  }


void enregistrer_production() {
    Hist_production nouveau_lot;
    Produit produit;
    char date_exp[11];
    
    // Générer ID lot unique
    nouveau_lot.Id_lot = obtenir_dernier_id_lot(HIST_PROD_FILE) + 1;
    
    // Saisir ID produit et vérifier existence
    printf("Entrez l'ID du produit: ");
    scanf("%d", &nouveau_lot.id_prod);
    getchar();
    
    if (!lire_produit(PRODUIT_FILE, nouveau_lot.id_prod, &produit)) {
        printf("Erreur: Produit non trouvé!\n");
        return;
    }
    
    // Date de production (aujourd'hui)
    generer_date_courante(nouveau_lot.Dat_prod);
    
    // Date d'expiration
    printf("Entrez la date d'expiration (DD/MM/YYYY): ");
    fgets(date_exp, sizeof(date_exp), stdin);
    date_exp[strcspn(date_exp, "\n")] = '\0';
    strcpy(nouveau_lot.Dat_exp, date_exp);
    
    // Quantité du lot
    printf("Entrez la quantité produite: ");
    scanf("%d", &nouveau_lot.Lot_qte);
    getchar();
    
    // Enregistrer dans l'historique
    FILE *f = fopen(HIST_PROD_FILE, "ab");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier historique.\n");
        return;
    }
    fwrite(&nouveau_lot, sizeof(Hist_production), 1, f);
    fclose(f);
    
    // Mettre à jour la quantité du produit
    produit.pro_qte += nouveau_lot.Lot_qte;
    
    // Réécrire le fichier produit avec la nouvelle quantité
    FILE *temp = fopen("temp.dat", "wb");
    FILE *orig = fopen(PRODUIT_FILE, "rb");
    Produit p;
    
    while(fread(&p, sizeof(Produit), 1, orig) == 1) {
        if(p.Id_prod == produit.Id_prod) {
            fwrite(&produit, sizeof(Produit), 1, temp);
        } else {
            fwrite(&p, sizeof(Produit), 1, temp);
        }
    }
    
    fclose(orig);
    fclose(temp);
    remove(PRODUIT_FILE);
    rename("temp.dat", PRODUIT_FILE);
    
    printf("Production enregistrée avec succès!\n");
    printf("Nouveau stock pour %s: %d unités\n", produit.Pro_nom, produit.pro_qte);
}

/*-------------------------------------------------------------------------------*/
/*FOCNTION:    obtenir denier id lot                                             */
int obtenir_dernier_id_lot(const char *nom_fichier) 
{
    FILE *f = fopen(nom_fichier, "rb");
    if (f == NULL) return 0;

    Hist_production temp;
    int dernier_id = 0;

    while (fread(&temp, sizeof(Hist_production), 1, f) == 1) {
        if (temp.Id_lot > dernier_id) {
            dernier_id = temp.Id_lot;
        }
    }

    fclose(f);
    return dernier_id;
}






/* FONCTION:              mise_a_jour_produit                             */
/* DESCRIPTION:           Met à jour un enregistrement Produit dans le    */
/* fichier produit.dat                             */
/* VALEUR DE RETOUR:      Un entier (1 succès, 0 erreur)                  */

int mise_a_jour_produit(const char *nom_fichier, Produit produit_maj) 
{
    FILE *orig = fopen(nom_fichier, "rb");
    if (orig == NULL) return 0; // Fichier original non trouvé

    FILE *temp = fopen("temp_prod.dat", "wb");
    if (temp == NULL) {
        fclose(orig);
        return 0; // Erreur création fichier temporaire
    }
    
    Produit p;
    int trouve = 0;
    
    // Parcourir le fichier original
    while (fread(&p, sizeof(Produit), 1, orig) == 1) {
        if (p.Id_prod == produit_maj.Id_prod) {
            // Écrire le produit MODIFIÉ dans le fichier temporaire
            fwrite(&produit_maj, sizeof(Produit), 1, temp);
            trouve = 1;
        } else {
            // Écrire les autres produits inchangés
            fwrite(&p, sizeof(Produit), 1, temp);
        }
    }
    
    fclose(orig);
    fclose(temp);

    if (trouve) {
        // Remplacer l'original par le temporaire
        remove(nom_fichier);
        rename("temp_prod.dat", nom_fichier);
        return 1;
    } else {
        // Nettoyer si le produit n'a pas été trouvé (ne devrait pas arriver ici)
        remove("temp_prod.dat");
        return 0;
    }
}



/* FONCTION:                     ins_hist_prod                            */ 
/* DESCRIPTION:          Ajoute un lot de production et met à jour le stock*/
/* PARAMETRE:            Structure Hist_production (le lot à insérer)     */
/* VALEUR DE RETOUR:     Un entier (1 si succès, 0 si échec)              */
/* AUTEUR:               Adapté de PIERRE-LOUIS Alven Bernadin            */
/* DATE DE MODIFICATION: 05/11/2025                                       */


int ins_hist_prod() {
    Produit produit_associe;
    Hist_production h;
    
    // --- ÉTAPE 1 : Vérifier l'existence du produit ---
    if (!lire_produit(PRODUIT_FILE, h.id_prod, &produit_associe)) {
        printf("ECHEC : Produit avec ID %d non trouve. Insertion du lot annulee.\n", h.id_prod);
        return 0;
    }
    
    // --- ÉTAPE 2 : Écrire le nouveau lot dans l'historique ---
    FILE *f = fopen(HIST_PROD_FILE, "ab"); // J'utilise HIST_PRODUCTION_FILE
    if (f == NULL) {
        printf("ECHEC : Erreur d'ouverture du fichier historique (%s).\n", HIST_PROD_FILE);
        return 0;
    }
    size_t written = fwrite(&h, sizeof(Hist_production), 1, f);
    fclose(f);

    if (written != 1) {
        printf("ECHEC : Erreur lors de l'ecriture du lot dans l'historique.\n");
        return 0;
    }
    
    // --- ÉTAPE 3 : Mettre à jour la quantité du produit ---
    
    // Ajouter la quantité du lot au stock existant
    produit_associe.pro_qte += h.Lot_qte;
    
    // Réécrire le produit dans le fichier produit.dat
    if (mise_a_jour_produit(PRODUIT_FILE, produit_associe) == 0) {
        printf("ATTENTION : Lot insere, mais ECHEC de la mise a jour du stock du produit.\n");
        return 0;
    }
    
    printf("SUCCES : Lot %d pour produit %d enregistre. Nouveau stock: %d.\n", h.Id_lot, h.id_prod, produit_associe.pro_qte);
    return 1;
}