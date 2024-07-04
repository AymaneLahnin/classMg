#ifndef FCTS1_H_INCLUDED
#define FCTS1_H_INCLUDED
typedef struct
{
    int j,m,a;
}Date;
typedef struct
{
    char NP[20];
    int mat;
    Date dn;
    float moy;
}Etudiant;
void menu(void)
{
    printf("\n\t\t\t\t********SYSTEME DE GESTION D`UNE CLASSE D`ETUDIANTS********\n");
    printf("\n\t\t\t\t\t\t\t****MENU****\n");
    printf("\n\n\t\t\t\t1.Pour lire et saisir les informations des etudiants en entree\n");
    printf("\t\t\t\t2.pour afficher la liste des etudiants\n");
    printf("\t\t\t\t3.pour afficher la liste des etudiants en ordre alphabetique\n");
    printf("\t\t\t\t4.pour afficher la liste des etudiants en ordre de merite\n");
    printf("\t\t\t\t5.pour ajouter un etudiant\n");
    printf("\t\t\t\t6.pour modifier la moyenne d`un etudiant\n");
    printf("\t\t\t\t7.pour supprimer\n");
    printf("\t\t\t\t8.pour rechercher un etudiant\n");
    printf("\t\t\t\t9.pour quitter\n");
    printf("\t\t\t\t--------------------------------------------------------------\n");
}
void remplir(void)
{
    int nbetd,i;
    FILE*f=fopen("listetd","w");
    Etudiant e;
    printf("\n\t\t\t********************** Saisir les informations d'etudiant **********************\n");
    printf("veuillez saisir lenombre des etudiants a inscrire: ");
    scanf("%d",&nbetd);
    for(i=0;i<nbetd;i++)
    {
    printf("\n\t\t\t********************** Saisir les informations d'etudiant %d **********************\n",i+1);
    printf("le matricule:");
    scanf("%d",&e.mat);
    printf("Saisir son nom et prenom:\n");
    fflush(stdin);
    gets(e.NP);
    printf("Saisir sa date de naissance:\n");
    printf("Entrez le jour:");
    scanf("%d",&e.dn.j);
    printf("Entrez le mois:");
    scanf("%d",&e.dn.m);
    printf("Entrez l'annee:");
    scanf("%d",&e.dn.a);
    printf("Saisir la moyenne: ");
    scanf("%f",&e.moy);
    fwrite(&e,sizeof(e),1,f);
    }
    printf("\n\t\t\t\t**********************inscription reussie**********************\n");
    fclose(f);
}
void afficher(void)
{
    FILE*f=fopen("listetd","r");
    Etudiant e;
    while(fread(&e,sizeof(e),1,f))
    {
         printf("Nom et prenom:%s, Matricule:%d, Date de naissance:%d/%d/%d, Moyenne:%f\n",e.NP,e.mat,e.dn.j,e.dn.m,e.dn.a,e.moy);
    }
}
int verifiermat(int nmat)
{
    int exist=0;
    FILE*f=fopen("listetd","r");
    Etudiant e;
    while(fread(&e,sizeof(e),1,f))
    {
        if(e.mat == nmat)
        {
            exist=1;
            break;
        }
    }
    if(exist == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void ajouteretd(void)
{
    int res,nmat;
    FILE*f=fopen("listetd","a");
    Etudiant e;
    printf("entrz le matricule: ");
    scanf("%d",&nmat);
    res=verifiermat(nmat);
    if(res == 0)
    {
        printf("le matricule %d correspond a un etudiant deja inscrit! Veuillez ressayer...\n",nmat);
    }
    else
    {
        e.mat=nmat;
        printf("Saisir son nom et prenom:\n");
        fflush(stdin);
        gets(e.NP);
        printf("Saisir sa date de naissance:\n");
        printf("Entrez le jour:");
        scanf("%d",&e.dn.j);
        printf("Entrez le mois:");
        scanf("%d",&e.dn.m);
        printf("Entrez l'annee:");
        scanf("%d",&e.dn.a);
        printf("Saisir la moyenne: ");
        scanf("%f",&e.moy);
        fwrite(&e,sizeof(e),1,f);
        printf("\n\t\t\t**********************inscription du nouveau etudiant reussie**********************\n");
    }
    fclose(f);
    return;
}
int nbinscri(void)
{
    int i=0;
    FILE*f=fopen("listetd","r");
    Etudiant e;
    while(fread(&e,sizeof(e),1,f))
    {
        i++;
    }
    fclose(f);
    return i;
}
void trimoy(void)
{
    int nbe,i,j,k=0;
    FILE *f;
    Etudiant e[100],c;
    nbe=nbinscri();
    f=fopen("listetd","r");
    while(fread(&c,sizeof(c),1,f))
    {
        e[k]=c;
        k++;
    }
    fclose(f);
    for(i=0;i<nbe;i++)
    {
        for(j=0;j<nbe-i-1;j++)
        {
            if(e[j+1].moy>e[j].moy)
            {
                c=e[j];
                e[j]=e[j+1];
                e[j+1]=c;
            }
        }
    }
    f=fopen("listetd","w");
    k=0;
    while(k<nbe)
    {
        fwrite(&e[k],sizeof(e[k]),1,f);
        k++;
    }
    fclose(f);
    f=fopen("listetd","r");
    for(k=0;k<nbe;k++)
    {
         printf("Nom et prenom:%s, Matricule:%d, Date de naissance:%d/%d/%d, Moyenne:%f\n",e[k].NP,e[k].mat,e[k].dn.j,e[k].dn.m,e[k].dn.a,e[k].moy);
    }
    return;
}
void trialp(void)
{
    int nbe,i,j,k=0,t=0;
    FILE *f;
    Etudiant e[100],c;
    nbe=nbinscri();
    f=fopen("listetd","r");
    while(fread(&c,sizeof(c),1,f))
    {
        e[k]=c;
        k++;
    }
    fclose(f);
    for(i=0;i<nbe;i++)
    {
        for(j=0;j<nbe-i-1;j++)
        {
            if(e[j+1].NP[t]<e[j].NP[t])
            {
                c=e[j];
                e[j]=e[j+1];
                e[j+1]=c;
            }
            if(e[j+1].NP[t] == e[j].NP[t] )
            {
                t++;
            }
        }
    }
    f=fopen("listetd","w");
    k=0;
    while(k<nbe)
    {
        fwrite(&e[k],sizeof(e[k]),1,f);
        k++;
    }
    fclose(f);
    f=fopen("listetd","r");
    for(k=0;k<nbe;k++)
    {
         printf("Nom et prenom:%s, Matricule:%d, Date de naissance:%d/%d/%d, Moyenne:%f\n",e[k].NP,e[k].mat,e[k].dn.j,e[k].dn.m,e[k].dn.a,e[k].moy);
    }
    return;
}
void deletd(int nmat,int a)
{
    Etudiant e[100],c;
    int i=0,j=0;
    FILE *f=fopen("listetd","r");
    while(fread(&c,sizeof(c),1,f))
    {
        if (c.mat == nmat)
        {
            continue;
        }
        e[i]=c;
        i++;
    }
    fclose(f);
    f=fopen("listetd","w");
    while(j<i)
    {
        fwrite(&e[j],sizeof(e[j]),1,f);
        j++;
    }
    fclose(f);
    if(a==1)
    {
      printf("etudiant qui correspond au matricule %d est supprime.",nmat);
    }
}
void rechercher_etd(int m)
{
    Etudiant e;
    FILE *f=fopen("listetd","r");
    while(fread(&e,sizeof(e),1,f))
    {
        if(e.mat == m)
        {
            printf("Nom et prenom:%s, Matricule:%d | Date de naissance:%d/%d/%d | Moyenne:%f\n",e.NP,e.mat,e.dn.j,e.dn.m,e.dn.a,e.moy);
        }
    }
}
Etudiant affecteretd(int m)
{
    Etudiant e;
    FILE *f=fopen("listetd","r");
    while(fread(&e,sizeof(e),1,f))
    {
        if(e.mat == m)
        {
            return e;
        }
    }
}
void modifier_moy(int m1,float m2)
{
    Etudiant e;
    int m=0;
    FILE *f;
    f=fopen("listetd","r");
    while(fread(&e,sizeof(e),1,f)){
    if(e.mat == m1)
    {
        m=1;
    }
    }
    fclose(f);
    if(m==0){printf("Aucun etudiant ne correspond a ce matricule");}
    if(m == 1)
    {
        e=affecteretd(m1);
        e.moy = m2;
    deletd(m1,0);
    f=fopen("listetd","a");
    fwrite(&e,sizeof(e),1,f);
    fclose(f);
    printf("la modification est effectuee.");
    }
    return;
}
#endif // FCTS1_H_INCLUDED
