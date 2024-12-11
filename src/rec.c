#include "rec.h"
#include<string.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <config.h>
#define MAX_PARKINGS 1000
enum{
	ERECID ,
	EJOUR ,
	EMOIS ,
	EANNEE, 
	ETEL,
	EIDPARK,
	EAVIS,
	EDESC,
	COLUMNS,
};

////////////////////////////////////////////////////////////////////////////////////////////////////////

int ajouter(char *filename, rec d, int choix[], char ch[])
{

    for (int i = 0; d.tel[i] != '\0'; i++) {
    if (d.tel[i] < '0' || d.tel[i] > '9') { 
        return 0;
    }
}
        if (strlen(d.tel) != 8) {
	return 0;
    }

    FILE *f = fopen(filename, "a+");  
    if (f != NULL)
    {
        strcpy(ch, "");  
        if (choix[0] == 1)
            strcat(ch, "/Problème_de_paiement/");
        if (choix[1] == 1)
            strcat(ch, "/Problème_avec_le_service_client/");
        if (choix[2] == 1)
            strcat(ch, "/Dommages_au_véhicule/");
        if (choix[3] == 1)
            strcat(ch, "/Autre/");

        for (int i = 0; d.desc[i] != '\0'; i++) {
            if (d.desc[i] == ' ') {
                d.desc[i] = '_';
            }
        }

        int lastRecid = 0;
        rec temp;

        while (fscanf(f, "%d %d %d %d %s %s %s %s %s\n", &temp.recid, &temp.date.jour, &temp.date.mois, &temp.date.annee, temp.tel, temp.idpark, temp.avis, temp.desc, ch) != EOF)
        {
            if (temp.recid > lastRecid)
                lastRecid = temp.recid;
        }

        d.recid = lastRecid + 1; 
      
        fprintf(f, "%d %d %d %d %s %s %s %s %s\n", d.recid, d.date.jour, d.date.mois, d.date.annee, d.tel, d.idpark, d.avis, d.desc, ch);
        fclose(f);
        return 1;
    }
    else
        return 0;
}




////////////////////////////////////////////////////////////////////////////////////////////////////////

int pull( int recid,char tel[9]){
   FILE *f = fopen("add.txt", "r");
    if (f != NULL)
    {
        fscanf(f, "%d",&recid);
        fclose(f);
    }
	remove("add.txt");
	return recid;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

void add( int recid,char tel[9]){
   FILE *f = fopen("add.txt", "w");
    if (f != NULL)
    {
        fprintf(f, "%d",recid);
        fclose(f); 
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////

int modifier(char *filename, char tel[], int recid, rec nouv, char cha[], char ch[], int choix2[])
{
    

    rec t;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    
    if (f != NULL && f2 != NULL)
    {
    strcpy(cha, "");
    if (choix2[0] == 1)
        strcat(cha, "/Problème_de_paiement/");
    if (choix2[1] == 1)
        strcat(cha, "/Problème_avec_le_service_client/");
    if (choix2[2] == 1)
        strcat(cha, "/Dommages_au_véhicule/");
    if (choix2[3] == 1)
        strcat(cha, "/Autre/");

    for (int i = 0; nouv.desc[i] != '\0'; i++) {
        if (nouv.desc[i] == ' ') {
            nouv.desc[i] = '_';
        }
    }
        while (fscanf(f, "%d %d %d %d %s %s %s %s %s\n",
                      &t.recid, &t.date.jour, &t.date.mois, &t.date.annee, 
                      t.tel, t.idpark, t.avis, t.desc, ch) != EOF)
        {
            if (recid == t.recid)
            {
                fprintf(f2, "%d %d %d %d %s %s %s %s %s\n", 
                        t.recid, nouv.date.jour, nouv.date.mois, 
                        nouv.date.annee, nouv.tel, nouv.idpark, 
                        nouv.avis, nouv.desc, cha);
                tr = 1; 
            }
            else
            {
                fprintf(f2, "%d %d %d %d %s %s %s %s %s\n", 
                        t.recid, t.date.jour, t.date.mois, 
                        t.date.annee, t.tel, t.idpark, 
                        t.avis, t.desc, ch);
            }
        }

        fclose(f);
        fclose(f2);
        remove(filename);
        rename("nouv.txt", filename);
        return tr;
    }
    else
    {
        
        if (f != NULL) fclose(f);
        if (f2 != NULL) fclose(f2);
        return -1; 
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

 int supprimer(char * filename, char tel[], int recid,char ch[])
{
    int tr=0;
    rec d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %s %s %s %s %s\n",&d.recid, &d.date.jour, &d.date.mois, &d.date.annee, d.tel, d.idpark, d.avis , d.desc,ch)!=EOF)
        {
            if( recid==d.recid)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %s %s %s %s %s\n",d.recid,d.date.jour,d.date.mois,d.date.annee,d.tel ,d.idpark, d.avis , d.desc,ch);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////

rec chercher(char * filename, char tel[],int recid,char ch[])
{
    rec d;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {    
        while(tr==0&& fscanf(f,"%d %d %d %d %s %s %s %s %s\n",&d.recid, &d.date.jour, &d.date.mois, &d.date.annee, d.tel,d.idpark, d.avis , d.desc ,ch)!=EOF)
        {
            if(strcmp(d.tel,tel)==0 && recid == d.recid)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(d.tel,"-1");
    return d;

}
///////////////////////////////////////////////////////////////////////////////////////////////////

void afficherListeTrieeParAvis(char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("\nErreur.\n");
        return;
    }

    ParkingInfo parkingList[MAX_PARKINGS];
    int count = 0;
    rec claim;
    char ch[100];

    while (fscanf(f, "%d %d %d %d %s %s %s %s %s\n",
                  &claim.recid, &claim.date.jour, &claim.date.mois, &claim.date.annee,
                  claim.tel, claim.idpark, claim.avis, claim.desc, ch) != EOF) {
        int avis = atoi(claim.avis);
        int found = 0;

        for (int i = 0; i < count; i++) {
            if (strcmp(parkingList[i].idpark, claim.idpark) == 0) {
                parkingList[i].totalAvis += avis;
                parkingList[i].countAvis++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(parkingList[count].idpark, claim.idpark);
            parkingList[count].totalAvis = avis;
            parkingList[count].countAvis = 1;
            count++;
        }
    }

    fclose(f);

    for (int i = 0; i < count; i++) {
        parkingList[i].moyenneAvis = (float)parkingList[i].totalAvis / parkingList[i].countAvis;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (parkingList[i].moyenneAvis < parkingList[j].moyenneAvis) {
                ParkingInfo temp = parkingList[i];
                parkingList[i] = parkingList[j];
                parkingList[j] = temp;
            }
        }
    }

    FILE *liste = fopen("parking_trie.txt", "w");
    if (liste == NULL) {
        printf("\nErreur.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(liste, "%s : %.1f\n", parkingList[i].idpark, parkingList[i].moyenneAvis);
    }

    fclose(liste);
  

}




void afficher_rec (GtkWidget *liste,char ch[]){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter ;
	GtkListStore *store;
    	

	int recid; 
    	int jour;  
   	int mois;  
    	int annee; 
    	char tel[9] , idpark[5];
    	char avis[2];
    	char desc[300];
	store =NULL;


	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("ID ",renderer,"text",ERECID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("tel",renderer,"text",ETEL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("id park",renderer,"text",EIDPARK,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("avis",renderer,"text",EAVIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("description",renderer,"text",EDESC,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

	
	}
	store=gtk_list_store_new (COLUMNS ,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING);
	f=fopen("reclamations.txt", "r");
	if (f==NULL){
		return;
	}
	else {
		f=fopen("reclamations.txt", "a+");
		while (fscanf(f,"%d %d %d %d %s %s %s %s %s\n",&recid, &jour, &mois, &annee,tel,idpark,avis,desc,ch)!=EOF){

			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store ,&iter ,ERECID ,recid ,EJOUR, jour ,EMOIS,mois,EANNEE ,annee ,ETEL, tel ,EIDPARK,idpark,EAVIS,avis,EDESC,desc,-1);
	}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);


}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////



void supprimer_tre(rec r,char ch[])
{

	int recid;
    	int jour;
   	int mois;
    	int annee;
    	char tel[9] , avis[2];
    	char desc[300];
    	char idpark[5];


	rec r2;
	FILE *f,*g;
	f=fopen("reclamations.txt","r");
	g=fopen("dumb.txt","w");
	if (f==NULL || g==NULL){
		return;
	}
	else {
		while(fscanf(f,"%d %d %d %d %s %s %s %s %s\n",&r2.recid,&r2.date.jour,&r2.date.mois,&r2.date.annee,r2.tel,r2.idpark,r2.avis,r2.desc,ch)!=EOF){
			if (r.recid != r2.recid ||r.date.jour != r2.date.jour ||r.date.mois != r2.date.mois ||r.date.annee != r2.date.annee || strcmp(r.tel,r2.tel)!=0|| strcmp(r.idpark,r2.idpark)!=0 || strcmp(r.avis,r2.avis)!=0 || strcmp(r.desc,r2.desc)!=0)
				fprintf(g,"%d %d %d %d %s %s %s %s %s\n",r2.recid,r2.date.jour,r2.date.mois,r2.date.annee,r2.tel,r2.idpark,r2.avis,r2.desc,ch);
		}

	} 
	fclose(f);
	fclose(g);
	remove("reclamations.txt");
	rename("dumb.txt","reclamations.txt");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

