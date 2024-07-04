#include <stdio.h>
#include <stdlib.h>
#include "Fcts1.h"
int main()
{
    int choix,nmat,nmat1,m1;
    float m3;
    do
    {
        menu();
        printf("\t\t\t\tVeuillez saisir votre choix: ");
        scanf("%d",&choix);
        switch(choix)
        {
            case 1: remplir();
            break;
            case 2: afficher();
            break;
            case 3: trialp();
            break;
            case 4: trimoy();
            break;
            case 5: ajouteretd();
            break;
            case 6: printf("entrez le matricule de l`etudiant: ");
            scanf("%d",&m1);
            printf("Entrez la nouvelle moyenne: ");
            scanf("%f",&m3);
            modifier_moy(m1,m3);
            break;
            case 7: printf("entrez le matricule de l`etudiant a supprimer: ");
            scanf("%d",&nmat);
            deletd(nmat,1);
            break;
            case 8: printf("entrez le matricule de l`etudiant: ");
            scanf("%d",&nmat1);
            rechercher_etd(nmat1);
            break;
            case 9: printf("Merci pour utiliser notre application.\n");
            break;
            default: printf("les choix possibiles sont entre 1 et 9.\n");
        }

    }while(choix!= 9);
    return 0;
}
