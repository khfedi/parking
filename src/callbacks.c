#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"rec.h"

char ch[5000]="";
int choix[4]={0,0,0,0};
void
on_button_GR_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *EspaceReclamation,*GestionR ;


	EspaceReclamation=lookup_widget(button,"EspaceReclamation");
	gtk_widget_destroy(EspaceReclamation);
	GestionR=create_GestionR();
	gtk_widget_show(GestionR); 

}


void
on_APT_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Affichagelisteparking,*EspaceReclamation ;


	EspaceReclamation=lookup_widget(button,"EspaceReclamation");
	gtk_widget_destroy(EspaceReclamation);
	Affichagelisteparking=create_Affichagelisteparking();
	gtk_widget_show(Affichagelisteparking);
}


void
on_historique_R_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_M_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *ModificationR,*GestionR;


	GestionR=lookup_widget(button,"GestionR");
	gtk_widget_destroy(GestionR);
	ModificationR=create_ModificationR();
	gtk_widget_show(ModificationR); 
}


void
on_button_Supp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *SuppRec,*GestionR;


	GestionR=lookup_widget(button,"GestionR");
	gtk_widget_destroy(GestionR);
	SuppRec=create_SuppRec();
	gtk_widget_show(SuppRec); 
}


void
on_button1_hist_r_gest_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_Ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *AjouterRec,*GestionR ;


	GestionR=lookup_widget(button,"GestionR");
	gtk_widget_destroy(GestionR);
	AjouterRec=create_AjouterRec();
	gtk_widget_show(AjouterRec); 

}


void
on_home1_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *EspaceReclamation,*GestionR ;
	GestionR=lookup_widget(button,"GestionR");
	gtk_widget_destroy(GestionR);
	EspaceReclamation=create_EspaceReclamation();
	gtk_widget_show(EspaceReclamation);
}


void
on_return1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *EspaceReclamation,*GestionR ;
	GestionR=lookup_widget(button,"GestionR");
	gtk_widget_destroy(GestionR);
	EspaceReclamation=create_EspaceReclamation();
	gtk_widget_show(EspaceReclamation); 
}


void
on_return2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GestionR,*ModificationR;
	ModificationR=lookup_widget(button,"ModificationR");
	gtk_widget_destroy(ModificationR);
	GestionR=create_GestionR();
	gtk_widget_show(GestionR);
}


void
on_home2_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *EspaceReclamation,*ModificationR;
	ModificationR=lookup_widget(button,"ModificationR");
	gtk_widget_destroy(ModificationR);
	EspaceReclamation=create_EspaceReclamation();
	gtk_widget_show(EspaceReclamation); 
}


void
on_button_rmod_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_return3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *ModificationR,*Modificationunrec;
	Modificationunrec=lookup_widget(button,"Modificationunrec");
	gtk_widget_destroy(Modificationunrec);
	ModificationR=create_ModificationR();
	gtk_widget_show(ModificationR);
}


void
on_home3_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *EspaceReclamation,*Modificationunrec;
	Modificationunrec=lookup_widget(button,"Modificationunrec");
	gtk_widget_destroy(Modificationunrec);
	EspaceReclamation=create_EspaceReclamation();
	gtk_widget_show(EspaceReclamation); 
}



void
on_button_Cmod_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_checkbutton2_rdv_mod_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton1_rdv_mod_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_home4_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *EspaceReclamation,*AjouterRec;
	AjouterRec=lookup_widget(button,"AjouterRec");
	gtk_widget_destroy(AjouterRec);
	EspaceReclamation=create_EspaceReclamation();
	gtk_widget_show(EspaceReclamation);
}


void
on_return4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GestionR,*AjouterRec;
	AjouterRec=lookup_widget(button,"AjouterRec");
	gtk_widget_destroy(AjouterRec);
	GestionR=create_GestionR();
	gtk_widget_show(GestionR); 
}


void
on_button_A_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
 char vide[2] = "";

	GtkWidget *ch1,*ch2,*ch3,*ch4;


	ch1=lookup_widget(button,"checkbutton5_rec_A");
	ch2=lookup_widget(button,"checkbutton6_rec_A");
	ch3=lookup_widget(button,"checkbutton7_rec_A");
	ch4=lookup_widget(button,"checkbutton8_rec_A");


    int a;
    rec v;
    GtkWidget *input1, *input2, *input3, *input4, *input5, *input6 ,*input7 ;
    GtkWidget *AjouterRec;

    AjouterRec = lookup_widget(button, "AjouterRec");
    input1 = lookup_widget(button, "combobox1_Areclamation");
    input2 = lookup_widget(button, "entry2");
    input3 = lookup_widget(button, "spinbutton3");
    input4 = lookup_widget(button, "spinbutton4");
    input5 = lookup_widget(button, "spinbutton_Areclamation");
    input6 = lookup_widget(button, "combobox2_reclamationA");
    input7 = lookup_widget(button, "entry_descA");


	strcpy(v.desc,gtk_entry_get_text(GTK_ENTRY(input7)));
	v.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input3));
	v.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input4));
	v.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input5));
	strcpy(v.avis,gtk_combo_box_get_active_text(GTK_COMBO_BOX (input1)));
	strcpy(v.idpark,gtk_combo_box_get_active_text(GTK_COMBO_BOX (input6)));
	strcpy(v.tel,gtk_entry_get_text(GTK_ENTRY(input2)));


     		a=ajouter("reclamations.txt", v,choix,ch);
		   if(a==1){
		choix[0]=0;
		choix[1]=0;
		choix[2]=0;
		choix[3]=0;
		    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4), 1);
		    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5), 1);
		    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input3), 1);
                    gtk_entry_set_text(GTK_ENTRY(input7), vide);
                    gtk_combo_box_set_active(GTK_COMBO_BOX (input1),0);
                    gtk_combo_box_set_active(GTK_COMBO_BOX (input6),0);
                    gtk_entry_set_text(GTK_ENTRY(input2), vide);
		    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ch1),FALSE);
		    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ch2),FALSE);
		    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ch3),FALSE);
		    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ch4),FALSE);
   

		      }
}


void
on_home5_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *EspaceReclamation,*SuppRec;
	SuppRec=lookup_widget(button,"SuppRec");
	gtk_widget_destroy(SuppRec);
	EspaceReclamation=create_EspaceReclamation();
	gtk_widget_show(EspaceReclamation); 
}


void
on_return5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *GestionR,*SuppRec;
	SuppRec=lookup_widget(button,"SuppRec");
	gtk_widget_destroy(SuppRec);
	GestionR=create_GestionR();
	gtk_widget_show(GestionR);
}


void
on_button_supp1_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_return6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *AssurerSuppRec,*SuppRec;
	AssurerSuppRec=lookup_widget(button,"AssurerSuppRec");
	gtk_widget_destroy(AssurerSuppRec);
	SuppRec=create_SuppRec();
	gtk_widget_show(SuppRec); 
}


void
on_radiobutton_A_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton_supp_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_home6_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *AssurerSuppRec,*EspaceReclamation;
	AssurerSuppRec=lookup_widget(button,"AssurerSuppRec");
	gtk_widget_destroy(AssurerSuppRec);
	EspaceReclamation=create_EspaceReclamation();
	gtk_widget_show(EspaceReclamation);
}


void
on_treeview1_tree_don_cin_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_return7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  	GtkWidget *Affichagelisteparking,*EspaceReclamation ;
	Affichagelisteparking=lookup_widget(button,"Affichagelisteparking");
	gtk_widget_destroy(Affichagelisteparking);
	EspaceReclamation=create_EspaceReclamation();
	gtk_widget_show(EspaceReclamation);
}


void
on_home7_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Affichagelisteparking,*EspaceReclamation ;
	Affichagelisteparking=lookup_widget(button,"Affichagelisteparking");
	gtk_widget_destroy(Affichagelisteparking);
	EspaceReclamation=create_EspaceReclamation();
	gtk_widget_show(EspaceReclamation);
}


void
on_checkbutton5_rec_A_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix[0]=1;
}
}


void
on_checkbutton7_rec_A_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix[1]=1;
}
}


void
on_checkbutton6_rec_A_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix[2]=1;
}
}


void
on_checkbutton8_rec_A_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix[3]=1;
}
}

