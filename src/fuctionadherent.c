#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "fuctionadherent.h"
#include "function_admin.h"
void agenda_adherent (rdv x)
{Date1 rdv;
char login[20];
FILE*f;
FILE*f1;
f=fopen("src/agenda.txt","a+");
f1=fopen("src/login.txt","r");
if (f1!=NULL)
{
while(fscanf(f1,"%s\n",login)!=EOF)
{
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %d %d %d %d %d\n",login,x.sujet,x.staff,x.prenom,x.rdv.jour,x.rdv.mois,x.rdv.annee,x.heure,x.min);
fclose(f);
}
}
}
}

int modifier_adherent(char nom[],char prenom[],char phone[])
{adherant a1;
char login[20];
int retour=-1;
a1.valid=2;
FILE*f;
FILE*f1;
FILE*f2;
f=fopen("src/adherant.txt","r");
f1=fopen("src/fichier.txt","a+");
f2=fopen("src/login.txt","r");
if (f2!=NULL)
{
while(fscanf(f2,"%s\n",login)!=EOF)
{
while(fscanf(f,"%s %s %s %s %d %d %d %s %s %s %s %s %d\n",a1.login,a1.password,a1.nom,a1.prenom,&a1.dt_nais.jour,&a1.dt_nais.mois,&a1.dt_nais.annee,a1.sexe,a1.adresse,a1.phone,a1.email,a1.choixactiv,&a1.valid)!=EOF)
{
if(strcmp(a1.login,login)==0)
{
fprintf(f1,"%s %s %s %s %d %d %d %s %s %s %s %s %d\n",a1.login,a1.password,nom,prenom,a1.dt_nais.jour,a1.dt_nais.mois,a1.dt_nais.annee,a1.sexe,a1.adresse,phone,a1.email,a1.choixactiv,a1.valid);
retour=1;
}
else
{
fprintf(f1,"%s %s %s %s %d %d %d %s %s %s %s %s %d\n",a1.login,a1.password,a1.nom,a1.prenom,a1.dt_nais.jour,a1.dt_nais.mois,a1.dt_nais.annee,a1.sexe,a1.adresse,a1.phone,a1.email,a1.choixactiv,a1.valid);
}
}
}
}
  fclose(f);
  fclose(f1);
  fclose(f2);
  remove("src/adherant.txt");
  rename("src/fichier.txt","src/adherant.txt");
return(retour);
}



