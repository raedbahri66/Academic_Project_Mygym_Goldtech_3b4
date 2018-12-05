#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "function_admin.h"

int verifier (char login[], char password[])
{
FILE*f;//admin
FILE*f1;//coach
FILE*f2;//adherant
FILE*f3;//staffs medicaux

int d=1,b=1,c=-1;

f=fopen("src/admin.txt","r");
f1=fopen("src/adherant.txt","r");
f2=fopen("src/coach.txt","r");
f3=fopen("src/staffs.txt","r");
admin s;
adherant a;
if(f !=NULL) {
while(fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s %d\n",s.login,s.password,s.nom,s.prenom,&s.dt_nais.jour,&s.dt_nais.mois,&s.dt_nais.annee,s.sexe,s.adresse,s.phone,s.email,&s.role)!=EOF)
{ //parcours du fichier admin

d=strcmp(login,s.login);
b=strcmp(password,s.password);
if( d==0 && b==0)
{
c=s.role;
}
}
}
if(f1 !=NULL) {
while(fscanf(f1,"%s %s %s %s %d %d %d %s %s %s %s %s %d\n",a.login,a.password,a.nom,a.prenom,&a.dt_nais.jour,&a.dt_nais.mois,&a.dt_nais.annee,a.sexe,a.adresse,a.phone,a.email,a.choixactiv,&a.valid)!=EOF)
{ //parcours du fichier adherant

d=strcmp(login,a.login);
b=strcmp(password,a.password);
if( d==0 && b==0)
{
c=a.valid;
}
}
}
return c;
}

void ajouter (admin s)
{
s.role=1;
FILE*f;
f=fopen("src/admin.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %d %d %d %s %s %s %s %d\n",s.login,s.password,s.nom,s.prenom,s.dt_nais.jour,s.dt_nais.mois,s.dt_nais.annee,s.sexe,s.adresse,s.phone,s.email,s.role);
fclose(f);
}
}

void ajouter_adherant (adherant s)
{

FILE*f;
f=fopen("src/adherant.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %d %d %d %s %s %s %s %s %d \n",s.login,s.password,s.nom,s.prenom,s.dt_nais.jour,s.dt_nais.mois,s.dt_nais.annee,s.sexe,s.adresse,s.phone,s.email,s.choixactiv,s.valid);
fclose(f);
}
}


int supprimer(char loginadmin[])
{
admin s;
FILE*f;
FILE*f1;
int test=-1;
f=fopen("src/admin.txt","r");
f1=fopen("src/fichier.txt","a+");
while(fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s %d\n",s.login,s.password,s.nom,s.prenom,&s.dt_nais.jour,&s.dt_nais.mois,&s.dt_nais.annee,s.sexe,s.adresse,s.phone,s.email,&s.role)!=EOF)
{
if(strcmp(loginadmin,s.login)!=0)
{
fprintf(f1,"%s %s %s %s %d %d %d %s %s %s %s %d\n",s.login,s.password,s.nom,s.prenom,s.dt_nais.jour,s.dt_nais.mois,s.dt_nais.annee,s.sexe,s.adresse,s.phone,s.email,s.role);
}
else
{
test=1;
}
}
fclose(f);
fclose(f1);
remove("src/admin.txt");
rename("src/fichier.txt","src/admin.txt");
return(test);
}
////////////////////////////////////////////////
void memoriser(char login[])
{
int retour=-1;
FILE*f;
FILE*f1;
f=fopen("src/login.txt","a+");
f1=fopen("src/fichier.txt","a+");
if (f1!=NULL)
{
fprintf(f1,"%s \n",login);
fclose(f1);
}
  fclose(f);

  remove("src/login.txt");
  rename("src/fichier.txt","src/login.txt");
return(retour);
}

////////////////////////////////////////
int modifier(admin s)
{
admin s1;
int retour=-1;
FILE*f;
FILE*f1;
f=fopen("src/admin.txt","r");
f1=fopen("src/fichier.txt","a+");
while(fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s %d \n",s1.login,s1.password,s1.nom,s1.prenom,&s1.dt_nais.jour,&s1.dt_nais.mois,&s1.dt_nais.annee,s1.sexe,s1.adresse,s1.phone,s1.email,&s1.role)!=EOF)
{
if(strcmp(s1.login,s.login)==0)
{
fprintf(f1,"%s %s %s %s %d %d %d %s %s %s %s %d \n",s.login,s.password,s.nom,s.prenom,s.dt_nais.jour,s.dt_nais.mois,s.dt_nais.annee,s.sexe,s.adresse,s.phone,s.email,s1.role);
retour=1;
}
else
{
fprintf(f1,"%s %s %s %s %d %d %d %s %s %s %s %d \n",s1.login,s1.password,s1.nom,s1.prenom,s1.dt_nais.jour,s1.dt_nais.mois,s1.dt_nais.annee,s1.sexe,s1.adresse,s1.phone,s1.email,s1.role);
}
}
  fclose(f);
  fclose(f1);
  remove("src/admin.txt");
  rename("src/fichier.txt","src/admin.txt");
return(retour);
}


/////////////////////////////////////////////////////////////////////

void afficher_admin(GtkWidget *liste)
{
enum   
{       
        login,
        password,
	email,
        COLUMNS
};

        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	admin s;
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Login", renderer, "text",login, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Password", renderer, "text",password, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Email", renderer, "text",email, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("src/admin.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("src/admin.txt", "a+");
              while(fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s %d \n",s.login,s.password,s.nom,s.prenom,&s.dt_nais.jour,&s.dt_nais.mois,&s.dt_nais.annee,s.sexe,s.adresse,s.phone,s.email,&s.role)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, login, s.login, password, s.password, email, s.email, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

void afficher_demandes(GtkWidget *liste)
{
enum   
{       nom,
	prenom,
        login,
        password,
	email,
	choix,
        COLUMNS
};

        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	adherant a;
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Nom", renderer, "text",nom, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Prenom", renderer, "text",prenom, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Login", renderer, "text",login, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Password", renderer, "text",password, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Email", renderer, "text",email, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Choix d'activités", renderer, "text",choix, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("src/adherant.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("src/adherant.txt", "a+");
              while(fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s %s %d\n",a.login,a.password,a.nom,a.prenom,&a.dt_nais.jour,&a.dt_nais.mois,&a.dt_nais.annee,a.sexe,a.adresse,a.phone,a.email,a.choixactiv,&a.valid)!=EOF)
		{
if(a.valid==0)
{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, nom, a.nom, prenom, a.prenom, login, a.login, password, a.password, email, a.email, choix, a.choixactiv, -1); 
}
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

////////////

int accepter(char login[])
{
adherant a1;
int valider=2;
int retour=-1;
FILE*f;
FILE*f1;
f=fopen("src/adherant.txt","r");
f1=fopen("src/fichier.txt","a+");
while(fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s %s %d\n",a1.login,a1.password,a1.nom,a1.prenom,&a1.dt_nais.jour,&a1.dt_nais.mois,&a1.dt_nais.annee,a1.sexe,a1.adresse,a1.phone,a1.email,a1.choixactiv,&a1.valid)!=EOF)
{
if(strcmp(login,a1.login)==0)
{

fprintf(f1,"%s %s %s %s %d %d %d %s %s %s %s %s %d \n",a1.login,a1.password,a1.nom,a1.prenom,a1.dt_nais.jour,a1.dt_nais.mois,a1.dt_nais.annee,a1.sexe,a1.adresse,a1.phone,a1.email,a1.choixactiv,valider);
retour=1;
}
else
{
fprintf(f1,"%s %s %s %s %d %d %d %s %s %s %s %s %d \n",a1.login,a1.password,a1.nom,a1.prenom,a1.dt_nais.jour,a1.dt_nais.mois,a1.dt_nais.annee,a1.sexe,a1.adresse,a1.phone,a1.email,a1.choixactiv,a1.valid);
}
}
  fclose(f);
  fclose(f1);
  remove("src/adherant.txt");
  rename("src/fichier.txt","src/adherant.txt");
return(retour);
}
////
int verifier_number(char tmp[])
{
int isDigit1;
int j;
while(j<strlen(tmp)){
  isDigit1 = isdigit(tmp[j]);
  if (isDigit1 == 0) break;
  j++;
}
return j;
}
///
int validercin(char cin[])
{

if(validerchaine(cin)==1 && verifier_number(cin)==8)
return 1;
else 
return 0;
}
///
int validerchaine(char vchaine[])
{
int a=0;
if((vchaine[0] != '\0'))
a=1;
else 
a=0;
return a;
}

///
int verifier_email(char email[])
{
int a=0;
int j;
for(j=0;j<strlen(email);j++)
{
if((email[j] == '@'))
  a=1;
else
  a=0;
}
return a;
}
///

///////
int raedcin(char loginadmin1[])
{
admin s;
FILE*f;

int test=-1;
f=fopen("src/admin.txt","r");

while(fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s %d \n",s.login,s.password,s.nom,s.prenom,&s.dt_nais.jour,&s.dt_nais.mois,&s.dt_nais.annee,s.sexe,s.adresse,s.phone,s.email,&s.role)!=EOF)
{
if(strcmp(loginadmin1,s.login)==0)
{
test=1;
}
else
{
test=0;
}
fclose(f);
}
return(test);
}

