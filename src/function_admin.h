#include <gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}Date;
typedef struct
{
char login[20];
char password[20];
char nom[20];
char prenom[20];
Date dt_nais;
char sexe[20];
char adresse[20];
char phone[20];
char email[50];
int role;
}admin;

typedef struct
{
char login[30];
char password[20];
char nom[20];
char prenom[20];
Date dt_nais;
char sexe[20];
char adresse[20];
char phone[20];
char email[50];
char choixactiv[20];
int valid;
}adherant;
 
int verifier (char login[], char password[]);
void ajouter (admin s);
void ajouter_adherant (adherant s);
int supprimer(char loginadmin[]);
int modifier(admin s);
void afficher_admin(GtkWidget *liste);
void afficher_demandes(GtkWidget *liste);
int accepter(char login[]);
void memoriser(char login[]);
