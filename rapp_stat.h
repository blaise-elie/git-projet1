/*----------------------------------------------------------------------------*/

/*FICHIER:                          rapp_stat.h                               */
/*AUTEUR:                           Blaise Elie                               */   
/*DATE DE CREATIION:                26/09/2025                               `*/
/*DATE DE MODIFICATION:             26/09/2025                                */
/*DESCRIPTION:                      Fichier en tete que contient les prototypes
                                    des fonctions  rapports et statistiques   */   

/*-------------------------------- -------------------------------------------*/

#ifndef RAPP_STAT_H
#define RAPP_STAT_H
#include <stdio.h>
#include <time.h>

//structure pour stocker une periode de date
typedef struct
  {
  struct tm date_debut;
  struct tm date_fin;
  }Periode;




//fonction pour les listes des produits disponibles

void list_produits_dispo(void);

//fonction pour les listes de produits fabriquers

void list_prod_fab(Periode periode);

//fonction pour les chiffre d'affaire

void chiffre_affaire(Periode periode);






#endif