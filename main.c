#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// trouver un chemin dans le graphe
void trouver_chemin_graphe(int s  , int t , int matrice[5][5])
{
    Cellule *liste1=NULL , *liste2=NULL ;
    int array[5] , i=0 , j=0 , k=0 , val=0;


    //initialiser le tableau a -1
    for(i=0 ; i<5 ; array[i]=-1 , i++);
    //inilialiser la liste par la valeur de depart s a la position 1
    liste1=creer_cellule(s);

    // debut de traitement pour trouver le chemin si existe
    //tant que on est pas arrivé a la destination et la liste n'est pas vide
    while( (liste1) && (array[t]==-1) )
    {
        val=liste1->info; //on garde la valeur de depart
        liste1=supprimer_valeur_pos(liste1,1); // on supprime la valeur
        // on teste avec l'ensemble des sommets
        for(i=0 ; i<5 ; i++)
        {
            j=i;
            if(matrice[val][j]==1) // si existe un arc
            {
                if(array[j]==-1) // n'est pas marqué
                {
                    array[j]=val; // on rempli notre tableau par le chemin qu'on a trouvé
                    liste1=ajouter_valeur_pos(liste1,j,1);
                }
            }
        }

    }
    if(array[t]==-1) printf("y a pas de chemin entre %d et %d\n",s,t);
    else
    {
        printf("chemin de %d a %d :\n",s,t);
        k=t;
        while(k!=s)
        {
            liste2 = ajouter_valeur_pos(liste2,k,1);
            k=array[k];
        }
        liste2 = ajouter_valeur_pos(liste2,s,1);
        afficher_liste(liste2);
    }

}
void remplir_matrice(int matrice[5][5], char file[25])
{
    int i,j,ligne;
    FILE *f=fopen(file ,"r");
    fscanf(f,"%d",&ligne);

    if (!feof(f))
        for(i=0;i<ligne;i++)
            for(j=0;j<ligne;j++)
                fscanf(f, "%d", &matrice[i][j]);
        fclose(f);
}
int main()
{
    int matrice[5][5];
    remplir_matrice(matrice, "matrice.txt");
    trouver_chemin_graphe(0,3,matrice);


    return 0;
}
