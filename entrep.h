/*------------------------------------------------------------------------*/
/* FCHIER:                          entrep.h                              */
/*AUTEUR:                           PIERRE-LOUIS Alven Bernadin           */    
/*DATE DE CREATIION:                26/09/2025                            */  
/*DATE DE MODIFICATION:             26/09/2025                            */ 
/*DESCRIPTION:                      fichier contenant les nouveaux types de
                                    données, les prototypes, les structures 
                                    de données et les constantes          */    
/*------------------------------------------------------------------------*/ 

#ifndef ENTREP_H
#define ENTREP_H

//structure pour la date
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

//structure usine
typedef struct{
    int Id_usine;
    int Id_com;
    char Usi_nom[50];
    char Usin_desc[200];
}Usine;

//structure produit
typedef struct{
    int Id_prod;
    int Id_usine;
    char Pro_nom[50];
    char pro_desc[200];
    float pro_prix;
    int pro_qte;
}Produit;

//structure Historique production
typedef struct{
    int Id_lot;
    int id_prod;
    char Dat_prod[11];
    char Dat_exp[11];
    int Lot_qte;
}Hist_production;

//structure commune
typedef struct 
{
    int id_commune;
    int id_departement;
    char nom_com[50];
    char desc_com[200];
}Commune;



//Prototypes des fonctions
void ins_usine(int ID_commune);
int ecrire_usine(const char *nom_fichier, Usine *u);
int lire_usine(const char *nom_fichier, int id_recherche, Usine *resultat);
void mod_usine(int ID);


// structure vente
typedef struct {
    int id_vente;
    int id_prod;
    char dat_vente[11]; // format "JJ/MM/AAAA"
    int qte_vendue;
    float prix_unit;
    float prix_total;
} Vente;

// --- Prototypes des fonctions ---
int mettre_a_jour_stock(int id_prod, int qte_vendue);
int ajouter_vente(int id_prod, int qte_vendue, float prix_unit);
void generer_date_courante(char* date_str);

/*===========
=============================================================*/
/*                    PROTOTYPES - MENUS                                  */
/*========================================================================*/

void afficher_banniere(void);
void afficher_menu_principal(void);
void menu_parametres(void);
void menu_production(void);
void menu_ventes(void);
void menu_rapports(void);
void menu_communes(void);

//Structures pour les départements et communes
typedef struct
{
    int id_departement;
    char nom_departement[50];
    char desc_departement[200];
} Departement;

// Prototype des fonctions pour les départements
void ins_dept();
int ecrire_departement(const char *nom_fichier, Departement *d);
int lire_departement(const char *nom_fichier, int id_recherche, Departement *resultat);
void mod_dept();

//prototype des fonctions pour gerer les ID
                                                   

int obtenir_dernier_id_dept(const char *nom_fichier);

//prototype des fonctions pour gerer les ID
                                                 

int obtenir_dernier_id_usine(const char *nom_fichier);

//prototype du fonction pour lister les departements
void lister_departements();
//prototype focntion pour  obtenir le dernier ID de commune
int obtenir_dernier_id_commune(const char *nom_fichier);
//prototype des fonctions pour ecrire une commune(mode ajout)
int ecrire_commune(const char *nom_fichier, Commune *c);
//prototype des fonctions pour lire une commune
int lire_commune(const char *nom_fichier, int id_recherche, Commune *resultat);
//prototype des fonctions pour modifier une commune
void mod_com(int ID);
//prototype des fonctions pour insérer une commune
void ins_com();


















#endif // ENTREP_H
