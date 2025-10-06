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

//Prototypes des fonctions
void insererUsine(int ID_commune);
int ecrire_usine(const char *nom_fichier, Usine *u);
int lire_usine(const char *nom_fichier, int id_recherche, Usine *resultat);
void mod_usine(int ID);


/*------------------------------------------------------------------------*/
/* FCHIER:                          vente.h                               */
/*AUTEUR:                           JEAN David Kehl                       */    
/*DATE DE CREATIION:                26/09/2025                            */  
/*DATE DE MODIFICATION:             02/10/2025                            */ 
/*DESCRIPTION:                      fichier contenant les nouveaux types de
                                    données, les prototypes, les structures 
                                    de données et les constantes          */    
/*------------------------------------------------------------------------*/ 

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

/*========================================================================*/
/*                    PROTOTYPES - MENUS                                  */
/*========================================================================*/

void afficher_banniere(void);
void afficher_menu_principale(void);
void menu_parametres(void);
void menu_production(void);
void menu_ventes(void);
void menu_rapports(void);



#endif // ENTREP_H
