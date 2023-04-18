#include <stdio.h>

int bin_packing_FirstFit(int *valeur, int size, int capacite_bac, int matrice_0, int matrice_etat)
{
    //int matrice_etat[size][2]; 1 ere colonne = premier indice dispo dans la matrice et 2 eme colonnne = la somme 
    
    int zero = 0;
    int un = 1;

    for (int j=0; j<size; j++) // balayage du tableau de valeur 
    {
        for (int w=0; w<size; w++) // balayage de la matrice_etat pour savoir ou il reste de la place 
        {
            int indice_colonne = matrice_etat[&w][&zero];

            if (valeur[j] > capacite_bac)
            {
                break;
            }

            if (valeur[j] + matrice_etat[&w][&un] <= capacite_bac && indice_colonne < size) // verification de la place 
            {
                // il reste de la place 
                matrice_0[&w][&indice_colonne] = valeur[j];
                matrice_etat[&w][&zero]++;
                matrice_etat[&w][&un] += valeur[j];
            }
        }
    }
}

int matrice_de_zero(int size)
{
    int matrice_0;

	for (int x=0; x<size; x++)
    {
		for (int y=0; y<size; y++)
		{
            matrice_0[&x][&y] = 0; 
		}
    }
    return matrice_0;
}

int matrice_de_etat(int size)
{
    // 1 ere colonne = premier indice dispo dans la matrice et 2 eme colonnne = la somme 
    int matrice_etat;

	for (int x=0; x<size; x++)
    {
		for (int y=0; y<2; y++)
		{
            matrice_etat[&x][&y] = 0; 
		}
    }
    return matrice_etat;
}

int affichage(int size, int matrice_0, int matrice_etat)
{
    for(int x=0; x<size; x++)
    {
        for(int w=0; w<size; w++)
        {
            printf("%d   ", matrice_0[&x][&w]);
        }
        printf("\n");
    }
    /*
    for(int z=0; z<size; z++)
    {
        for(int y=0; y<2; y++)
        {
            printf("%d   ", matrice_etat[&z][&y]);
        }
        printf("\n");
    }
    */
    return matrice_0;
}


int main()
{
    int size = 13;
    int valeur[13] = {6,5,4,8,2,3,1,2,6,7,5,9};
    int capacite_bac = 10;
    int matrice_0 = matrice_de_zero(size);
    int matrice_etat = matrice_de_etat(size);
    int execution = bin_packing_FirstFit(*valeur, size, capacite_bac, matrice_0, matrice_etat);
    int afficher_matrice = affichage(size, matrice_0, matrice_etat);
    return 0;
}


