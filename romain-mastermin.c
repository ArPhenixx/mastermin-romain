#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int result = 0;

typedef enum
{
    B, // bleu//
    Y, // jaune//
    G, // vert//
    M, // magenta//
    O, // orange//
    P, // rose//
} Couleur;

// genere une grille de mastermind  //
void genereGrilleCode(int grille[4])
{
    int estUnique = 0;
    while (estUnique == 0)
    {

        srand(time(NULL));
        for (int i = 0; i < 4; i++)
        {

            grille[i] = rand() % 6;
        }
        // verifier si les nombres sont differents  si oui il se relance//
        if (grille[0] == grille[1] || grille[0] == grille[2] || grille[0] == grille[3] || grille[1] == grille[2] || grille[1] == grille[3] || grille[2] == grille[3])
        {
            estUnique = 0;
        }
        else
        {
            estUnique = 1;
        }
    }
}

// genere une grille de mastermind avec des nombres diferent   //

// aficher la grille de mastermind //
void afficherGrille(int grille[4])
{
    for (int i = 0; i < 4; i++)
    {

        printf("%d ", grille[i]);
    }
    printf("\n");
}

// changer chaque chifrre par une couleur//
void afficherCouleur(int grille[4])
{

    for (int i = 0; i < 4; i++)
    {
        switch (grille[i])
        {
        case 0:
            printf("B ");
            break;
        case 1:
            printf("Y ");
            break;
        case 2:
            printf("G ");
            break;
        case 3:
            printf("M ");
            break;
        case 4:
            printf("O ");
            break;
        case 5:
            printf("P ");
            break;
        }
    }
    printf("\n");
}

// saisir une combinaison de 4 lettres et obtenir le nombre de lettres bien placées et mal placées //
void saisir(int grille[4])
{
    char saisie[5];
    int tour = 0;
    while (tour != 10)
    {
        printf("Saisir une combinaison de 4 lettres : ");
        scanf("%s", saisie);
        printf("Vous avez saisi : %s\n", saisie);
        if (strlen(saisie) != 4)
        {
            printf("Le nombre de lettres est invalide.\n");
        }
        else
        {
            Couleur code[4];
            for (int i = 0; i < 4; i++)
            {
                code[i] = (Couleur)grille[i];
            }
            int bienPlaces = 0;
            int malPlaces = 0;
            for (int i = 0; i < 4; i++)
            {
                switch (saisie[i])
                {
                case 'B':
                    grille[i] = B;
                    break;
                case 'Y':
                    grille[i] = Y;
                    break;
                case 'G':
                    grille[i] = G;
                    break;
                case 'M':
                    grille[i] = M;
                    break;
                case 'O':
                    grille[i] = O;
                    break;
                case 'P':
                    grille[i] = P;
                    break;
                default:
                    printf("Une lettre est invalide.\n");
                    return;
                }
            }
            for (int i = 0; i < 4; i++)
            {
                if (grille[i] == code[i])
                {
                    bienPlaces++;
                    code[i] = (Couleur)-1;
                    grille[i] = (int)-2;
                }
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i != j && grille[i] == (int)code[j])
                    {
                        malPlaces++;
                        code[j] = (Couleur)-1;
                        grille[i] = (int)-2;
                        break;
                    }
                }
            }

            if (bienPlaces == 4)
            {
                printf("Vous avez gagne !\n");
                break;
            }
            else
            {
                printf("Vous avez %d lettres bien placee et %d lettres mal placee.\n", bienPlaces, malPlaces);
            }
        }
        tour++;
    }
}

int main()
{
    int grille[4];

    genereGrilleCode(grille);
    // afficherGrille(grille);//
    printf("\n Nous allons jouer au Mastermind\n");
    printf("Voici le mots de passe a trouver :  ");

    afficherCouleur(grille);
    // genereGrilleJoueur(grille);//

    saisir(grille);

    return 0;
}