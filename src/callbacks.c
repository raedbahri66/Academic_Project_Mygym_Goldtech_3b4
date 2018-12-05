#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "callbacks.h"
#include <string.h>
#include "function_admin.h"
#include"fuctionadherent.h"

void
on_button25_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox6; 
GtkWidget *jour; 
GtkWidget *mois; 
GtkWidget *annees; 
GtkWidget *cin; 
GtkWidget *password;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *tel;
GtkWidget *adresse;
GtkWidget *mail,*output;
int a=0; 
Date dt_nais;
admin s;
s.role=1;
combobox6=lookup_widget(objet_graphique, "combobox6");

cin=lookup_widget(objet_graphique, "entry23");
jour=lookup_widget(objet_graphique, "spinbutton4");
mois=lookup_widget(objet_graphique, "spinbutton5");
annees=lookup_widget(objet_graphique, "spinbutton6");
password=lookup_widget(objet_graphique, "entry24");
nom=lookup_widget(objet_graphique, "entry19");
prenom=lookup_widget(objet_graphique, "entry20");
tel=lookup_widget(objet_graphique, "entry22");
adresse=lookup_widget(objet_graphique, "entry21");
mail=lookup_widget(objet_graphique, "entry25");

output=lookup_widget(objet_graphique, "label613");

s.dt_nais.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
s.dt_nais.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
s.dt_nais.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annees));
strcpy(s.login,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(s.password,gtk_entry_get_text(GTK_ENTRY(password)));
strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(s.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(s.phone,gtk_entry_get_text(GTK_ENTRY(tel)));
strcpy(s.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
strcpy(s.email,gtk_entry_get_text(GTK_ENTRY(mail)));
strcpy(s.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox6)));
a=raedcin(s.login);

if(a==0)
{
gtk_label_set_text(GTK_LABEL(output),"Correct");
ajouter(s);
}
if(a==1)
gtk_label_set_text(GTK_LABEL(output),"Données inv-alide");

}


void
on_afficherr_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *listview;
listview=lookup_widget(objet_graphique,"treeview1");
afficher_admin(listview);
}


void
on_button33_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *xx; 
int acc;
char xxx[20];
xx=lookup_widget(objet_graphique, "entry43");
strcpy(xxx,gtk_entry_get_text(GTK_ENTRY(xx)));
acc=supprimer(xxx);

}

void
on_modifier1_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox12; 
GtkWidget *jour; 
GtkWidget *mois; 
GtkWidget *annees; 
GtkWidget *cin; 
GtkWidget *password;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *tel;
GtkWidget *adresse;
GtkWidget *mail;
 
Date dt_nais;
admin s;
GtkWidget *mm; 
int acc1;


cin=lookup_widget(objet_graphique, "entry40");
jour=lookup_widget(objet_graphique, "spinbutton17");
mois=lookup_widget(objet_graphique, "spinbutton16");
annees=lookup_widget(objet_graphique, "spinbutton18");
password=lookup_widget(objet_graphique, "entry59");
nom=lookup_widget(objet_graphique, "entry49");
prenom=lookup_widget(objet_graphique, "entry50");
tel=lookup_widget(objet_graphique, "entry52");
adresse=lookup_widget(objet_graphique, "entry51");
mail=lookup_widget(objet_graphique, "entry53");
combobox12=lookup_widget(objet_graphique, "combobox12");


s.dt_nais.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
s.dt_nais.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
s.dt_nais.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annees));
strcpy(s.login,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(s.password,gtk_entry_get_text(GTK_ENTRY(password)));
strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(s.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(s.phone,gtk_entry_get_text(GTK_ENTRY(tel)));
strcpy(s.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
strcpy(s.email,gtk_entry_get_text(GTK_ENTRY(mail)));
strcpy(s.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox12)));
acc1=modifier(s);
}


void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
}








void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button41_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button43_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox; 
GtkWidget *jour; 
GtkWidget *mois; 
GtkWidget *annees;  
GtkWidget *heure;
GtkWidget *min;
GtkWidget *sujet;
GtkWidget *staff;
rdv x;
Date1 rdv;
combobox=lookup_widget(objet_graphique, "comboboxentry1");

jour=lookup_widget(objet_graphique, "spinbutton19");
mois=lookup_widget(objet_graphique, "spinbutton20");
annees=lookup_widget(objet_graphique, "spinbutton21");
heure=lookup_widget(objet_graphique, "spinbutton22");
min=lookup_widget(objet_graphique, "spinbutton23");
sujet=lookup_widget(objet_graphique, "entry54");

x.rdv.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
x.rdv.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
x.rdv.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annees));
x.heure=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (heure));
x.min=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (min));
strcpy(x.sujet,gtk_entry_get_text(GTK_ENTRY(sujet)));
strcpy(x.staff,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
agenda_adherent(x);

}


void
on_button45_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *input1,*input2,*adherent11,*admin,*medcin,*error,*adherantnotvalid;
char loginad[20];char password[30];
int z=9;int aa=0;
input1=lookup_widget(objet_graphique,"entry56");
input2=lookup_widget(objet_graphique,"entry55");
//adherent1=lookup_widget(objet_graphique,"adherent1");
strcpy(loginad,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
z=verifier(loginad,password);
if(z==1)
{
admin= create_admin ();
gtk_widget_show(admin);
}
else if(z==2)
{

adherent11 = create_adherent1 ();
gtk_widget_show (adherent11);
memoriser(loginad);

}

else if(z==0)
{
adherantnotvalid= create_adherantnotvalid ();
gtk_widget_show(adherantnotvalid);
}
else if(z==-1)
{
error= create_error ();
gtk_widget_show(error);
}

}


void
on_button44_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button46_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button50_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button47_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button51_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button52_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}





void
on_button28_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char login[30];
GtkWidget *verif,*output,*output1,*output2,*output3,*output4,*output5,*output6;
output=lookup_widget(objet_graphique,"label491");
output1=lookup_widget(objet_graphique,"label130");
output2=lookup_widget(objet_graphique,"label129");
output3=lookup_widget(objet_graphique,"label128");
output4=lookup_widget(objet_graphique,"label127");
output5=lookup_widget(objet_graphique,"label126");
output6=lookup_widget(objet_graphique,"label125");
verif=lookup_widget(objet_graphique, "entry40");
strcpy(login,gtk_entry_get_text(GTK_ENTRY(verif)));

admin s;
FILE*f;
f=fopen("admin.txt","a+");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s \n",s.login,s.password,s.nom,s.prenom,&s.dt_nais.jour,&s.dt_nais.mois,&s.dt_nais.annee,s.sexe,s.adresse,s.phone,s.email)!=EOF)
{
if(strcmp(login,s.login)==0)
{
gtk_label_set_text(GTK_LABEL(output),s.password);
gtk_label_set_text(GTK_LABEL(output1),s.prenom);
gtk_label_set_text(GTK_LABEL(output2),s.nom);
gtk_label_set_text(GTK_LABEL(output3),s.sexe);
gtk_label_set_text(GTK_LABEL(output4),s.adresse);
gtk_label_set_text(GTK_LABEL(output5),s.phone);
gtk_label_set_text(GTK_LABEL(output6),s.email);
}
}
}
}


void
on_button53_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *sexe; 
GtkWidget *jour; 
GtkWidget *mois; 
GtkWidget *annees; 
GtkWidget *cin; 
GtkWidget *password;
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *tel;
GtkWidget *adresse;
GtkWidget *mail;
GtkWidget *choixactiv;
 
Date dt_nais;
adherant s;
sexe=lookup_widget(objet_graphique, "combobox20");

cin=lookup_widget(objet_graphique, "entry64");
jour=lookup_widget(objet_graphique, "spinbutton36");
mois=lookup_widget(objet_graphique, "spinbutton37");
annees=lookup_widget(objet_graphique, "spinbutton38");
password=lookup_widget(objet_graphique, "entry65");
nom=lookup_widget(objet_graphique, "entry60");
prenom=lookup_widget(objet_graphique, "entry61");
tel=lookup_widget(objet_graphique, "entry63");
adresse=lookup_widget(objet_graphique, "entry62");
mail=lookup_widget(objet_graphique, "entry67");
choixactiv=lookup_widget(objet_graphique, "combobox21");
s.dt_nais.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
s.dt_nais.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
s.dt_nais.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annees));
s.valid=0;
strcpy(s.login,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(s.password,gtk_entry_get_text(GTK_ENTRY(password)));
strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(s.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(s.phone,gtk_entry_get_text(GTK_ENTRY(tel)));
strcpy(s.adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
strcpy(s.email,gtk_entry_get_text(GTK_ENTRY(mail)));
strcpy(s.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe)));
strcpy(s.choixactiv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(choixactiv)));
ajouter_adherant(s);
}


void
on_button59_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *listview1;
listview1=lookup_widget(objet_graphique,"treeview2");
afficher_demandes(listview1);
}


void
on_button60_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *accept; 
int done;
char accepter1[20];
accept=lookup_widget(objet_graphique, "entry69");
strcpy(accepter1,gtk_entry_get_text(GTK_ENTRY(accept)));
done=accepter(accepter1);
}




void
on_adherent1_activate_default          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char login[30];
GtkWidget *output,*output1,*output2,*output3;
output=lookup_widget(objet_graphique,"label539");
output1=lookup_widget(objet_graphique,"label540");
output2=lookup_widget(objet_graphique,"label612");
output3=lookup_widget(objet_graphique,"label608");
adherant a;
FILE*f1;
FILE*f2;
f1=fopen("src/adherant.txt","r");
f2=fopen("src/login.txt","r");
if (f2!=NULL)
{
 while(fscanf(f2,"%s\n",login)!=EOF)
{
 if (f1!=NULL)
 {
 while(fscanf(f1,"%s %s %s %s %d %d %d %s %s %s %s %s      %d\n",a.login,a.password,a.nom,a.prenom,&a.dt_nais.jour,&a.dt_nais.mois,&a.dt_nais.annee,a.sexe,a.adresse,a.phone,a.email,a.choixactiv,&a.valid)!=EOF)
 {
 if(strcmp(login,a.login)==0)
 {

 gtk_label_set_text(GTK_LABEL(output),a.prenom);
 gtk_label_set_text(GTK_LABEL(output1),a.nom);
 gtk_label_set_text(GTK_LABEL(output2),a.phone);
 gtk_label_set_text(GTK_LABEL(output3),a.login);

}
}
}
}
}
}


void
on_button62_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button63_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button64_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button65_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button66_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button67_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button70_clicked                      (GtkWidget       *objet_graphique,
                                          gpointer         user_data)
{
GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *tel;

GtkWidget *output,*output1,*output2,*output3;
int mod_adher;
adherant a;
char login[20];

output=lookup_widget(objet_graphique,"label539");
output1=lookup_widget(objet_graphique,"label540");
output2=lookup_widget(objet_graphique,"label612");
output3=lookup_widget(objet_graphique,"label608");

nom=lookup_widget(objet_graphique,"entry71");
prenom=lookup_widget(objet_graphique,"entry72");
tel=lookup_widget(objet_graphique,"entry73");

strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(a.phone,gtk_entry_get_text(GTK_ENTRY(tel)));
mod_adher=modifier_adherent(a.nom,a.prenom,a.phone);

output=lookup_widget(objet_graphique,"label539");
output1=lookup_widget(objet_graphique,"label540");
output2=lookup_widget(objet_graphique,"label612");
output3=lookup_widget(objet_graphique,"label608");
gtk_label_set_text(GTK_LABEL(output),a.nom);
gtk_label_set_text(GTK_LABEL(output1),a.prenom);
gtk_label_set_text(GTK_LABEL(output2),a.phone);

}












