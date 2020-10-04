#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct cel
{
    int info ; //l'information
    struct cel * suiv ; // cellule suivante
}Cellule;



/* fonction : creer une cellule , et l'initialiser avec une valeur */
Cellule *creer_cellule(int info)
{
    Cellule *tmp = (Cellule*)malloc(sizeof(Cellule));
    if(!tmp)
    {
        printf("erreur");
        exit(0);
    }
    tmp->info=info;
    tmp->suiv=NULL;
    return((Cellule*)tmp);
}


/* fonction : calculer taille de liste */
int taille_liste(Cellule *Liste )
{
    int taille=0;
    Cellule * tmp;
    //pointer sur le premier élement de la liste
    tmp=Liste;

    while (tmp)
    {
        //incrementer la taille
        taille++;
        //pointer sur l'élement suivant
        tmp = tmp->suiv;
    }
    return ((int) taille);
}

/* fonction : ajouter une valeur a une position dans la liste */
Cellule *ajouter_valeur_pos(Cellule *Liste , int valeur , int position)
{
    Cellule *l , *cel;
    int compteur = 2;
    cel=creer_cellule(valeur);
    l=Liste;

    //position invalide
    if (  (position<1)  || (position>taille_liste(l)+1)  )
    {
        // affichage d'un message d'erreur
        printf("\n entrez une pos correcte !!!");
        return ((Cellule *) Liste);
    }
    else
    {
        // si l'inserttion se fait au debut de la liste
        if (position == 1)
        {
        cel->suiv = Liste;
        return ((Cellule *) cel);
        }

        while ((l) && (compteur < position))
        {
        compteur++;
        // se deplacer vers suivant
        l = l->suiv;
        }
        cel->suiv = l->suiv;
        l->suiv = cel;

    }
    return((Cellule*)l);
}

void afficher_liste(Cellule *Liste)
{
    Cellule * tmp;
    tmp=Liste;

    if (!Liste)
    {
        printf("\nliste vide!");
        return;
    }
    while (tmp->suiv)
    {
        printf("%d -> ",tmp->info);
        tmp = tmp->suiv;
    }
    printf("%d  ",tmp->info);
}

Cellule *supprimer_valeur_pos(Cellule *Liste ,int pos)
{
    int count = 2;
    Cellule * tmp,* lib;
    tmp=Liste;

    if (!Liste)
    {
        //afficher un message d'erreur
        printf(" la liste est vide !");
        return ((Cellule *) NULL);
    }

    // tester la validite de la pisition
    if( pos>=1 && pos<=taille_liste(Liste))
    {
        // position valide , debut traitement
    if (pos == 1)
    {
        lib = Liste;
        Liste = Liste->suiv;
        //libérer l'espace mémoire
        free(lib);
        return ((Cellule*) Liste);
    }

    while ((tmp->suiv) && (count<pos))
    {
        tmp = tmp->suiv;
        //incrémenter count
        count++;
    }
    lib = tmp->suiv;
    tmp->suiv = lib->suiv;
    free(lib);

    }
    else // position invalide
    {
        //affichage d'un message d'erreur
        printf("\n position invalide !");
        return ((Cellule *) Liste);
    }


    return ((Cellule *) Liste);
}
#endif // FUNCTIONS_H_INCLUDED
