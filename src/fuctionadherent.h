#include <gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}Date1;
typedef struct
{
char cin[20];
char sujet[20];
char staff[30];
char prenom[20];
Date1 rdv;
int heure;
int min;
}rdv;
void agenda_adherent (rdv x);
int modifier_adherent(char nom[],char prenom[],char phone[]);
