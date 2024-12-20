#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
#include <ctype.h>
#include <gtk/gtk.h>


typedef struct
{
    int jour;
    int mois;
    int annee;

}dates;
typedef struct
{
    int recid;
    dates date; 
    char tel[9] ;
    char idpark[5];
    char avis [2];
    char desc[300];
}rec;
typedef struct {
    char idpark[20];
    int totalAvis;
    int countAvis;
    float moyenneAvis;
} ParkingInfo;


int ajouter(char *,rec ,int choix[],char ch[]);
int modifier( char *, char*,int, rec,char cha[] ,char ch[],int choix2[]);
int supprimer(char *, char* ,int,char ch[]);
rec chercher(char *, char*,int,char ch[]);
void afficherListeTrieeParAvis( char *filename);
void add( int ,char tel[]);
int pull( int ,char tel[]);
void supprimer_tre(rec,char ch[]);
void afficher_rec (GtkWidget *liste,char ch[]);
void supprimer_tretree(rec);
void afficher_rectree (GtkWidget *liste);
#endif // POINT_H_INCLUDED
