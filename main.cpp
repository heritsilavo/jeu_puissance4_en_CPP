#include <iostream>
#include <array>
#include <string>
#include <ctime>
#include "mes_fonc.h"

using namespace std;

int main()
{
    Array grille;
    bool stop(false);
    couleur jeux;

    srand((double)time(0));
    if((rand()%2)==0){jeux=rouge;}
    else{jeux=jaune;}

    initialise(grille);
    affiche(grille);

    do
    {
        int colone;
        if(jeux==rouge)
        {
            cout<<"JEUX ROUGE(O)"<<endl;
        }
        else
        {
            cout<<"JEUX JAUNE(X)"<<endl;
        }
        //pour prendre la valeur de la colone et bien s'assurer qu'on entre un nbr in
        get(colone);
        //mettre le pion dans la colone ecrite si possible
        while((colone<1)||(colone>7)||(joue(grille,colone,jeux)==false))
        {
            affiche(grille);
            cout<<"\n!!IMPOSSIBLE DE JOUER DANS CETTE COLONE!!\n\n";
            get(colone);//pour prendre la valeur de la colone et bien s'assurer qu'on entre un nbr in
        }
        //verifier si gagne
        if(gagne(grille,jeux)==true)
        {
            affiche(grille);
            cout<<"GAGNEE!!"<<endl;
            break;
        }
        affiche(grille);
        //pour changer de couleur a la prochaine passage a la boucle si un joueur ne gange pas
        if(jeux==rouge)
        {
            jeux=jaune;
        }
        else
        {
            jeux=rouge;
        }
    }
    while(stop==false);
    return 0;
}
