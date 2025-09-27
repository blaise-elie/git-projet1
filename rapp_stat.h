/*----------------------------------------------------------------------------*/
/* FICHIER:                          rapp_stat.h                              */
/* AUTEUR:                           Blaise Elie                              */   
/* DATE DE CREATION:                 26/09/2025                               */
/* DATE DE MODIFICATION:             27/09/2025                               */
/* DESCRIPTION:     Fichier d'en-tête pour les rapports et statistiques      */    

/*-------------------------------- -------------------------------------------*/

#ifndef RAPP_STAT_H
#define RAPP_STAT_H
#include <stdio.h>
#include <time.h>

// Structure pour les ventes de produits
typedef struct {
    char id_usine[10];
    char nom_usine[50];
    char id_produit[10];
    char nom_produit[50];
    int quantite_vendue;
    float prix_unitaire;
    struct tm date_vente;
} VenteProduit;

// Structure pour les produits en stock par usine
typedef struct {
    char id_usine[10];
    char nom_usine[50];
    char id_produit[10];
    char nom_produit[50];
    int quantite_stock;
} ProduitEnStock;

//structure pour stocker une periode de date
typedef struct
  {
  struct tm date_debut;
  struct tm date_fin;
  }Periode;




// Fonction pour lister les produits disponibles par usine et période
void list_produits_dispo(ProduitEnStock produits[], int nb_produits, Periode *periode,const char* filename);

// Fonction pour lister les produits fabriqués dans une période donnée
void list_prod_fab(ProduitEnStock produits[], int nb_produits, Periode *periode,const char* filename);

// Fonction pour calculer et afficher le chiffre d'affaire par période
// Retourne le chiffre d'affaire total sur la période
float chiffre_affaire(VenteProduit ventes[], int nb_ventes, Periode *periode,const char* filename);


//commentaire impotantra  j'ai cree ces structures pour que je puisse voir si mes fonctions marchent bien
//je les ai mis dans le fichier d'en-tete pour qu'elles soient accessibles dans les deux fichiers .c mais pour le moment je ne les encore pas essayer



#endif