#include <iostream>
#include <array>
#include <limits>
#include "mes_fonc.h"

using namespace std;
//pour l'initialisation de toutes cases a vide
void initialise(Array& grille)
{
    for(auto &ligne : grille)
    {
        for(auto &colone : ligne)
        {
            colone=vide;
        }
    }
}
//pour l'affichage de la grille
void affiche(Array& grille)
{
    cout<<"\n _________________________________________\n";
    for(auto &ligne : grille)
    {
        cout<<"|     |     |     |     |     |     |     |\n";
        cout<<"|";
        for(auto &colone : ligne)
        {
            if(colone==vide)
            {
                cout<<"     |";
            }
            else if(colone==rouge)
            {
                cout<<"  O  |";
            }
            else
            {
                cout<<"  X  |";
            }
        }
        cout<<"\n|_____|_____|_____|_____|_____|_____|_____|\n";
    }
    cout<<"|==1==|==2==|==3==|==4==|==5==|==6==|==7==|\n";
}
//pour prendre la valeur de la colone et bien s'assurer qu'on entre un nbr int
void get(int& a)
{
    cout<<"Entrer le numero de la colone:    ";
        //pour bien s'assurer q'oun entre un nombre
        while(!(cin>>a))
            {
                cout<<"ERRENR DE SAISIE!! Entrer un nombre: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
}
//pour permetre de jouer un tour
bool joue(Array &grille,int colone,couleur color){
  for(size_t i=(grille.size()-1);i>=0;i--)
  {
      if(grille[0][colone-1]!=vide)
      {
          return false;
      }
      if(grille[i][colone-1]!=vide)
      {
        continue;
      }
      else
      {
          grille[i][colone-1]=color;
          return true;
      }
  }
  return false;
}

bool gagne(Array grille, couleur jeux)
{
    for(size_t ligne(0);ligne<grille.size();ligne++)
    {
        for(size_t colone(0);colone<grille[ligne].size();colone++)
        {
            if(grille[ligne][colone]==jeux)
            {
                if(
                   (compter(grille,ligne,colone,-1,+1)>=4)||
                   (compter(grille,ligne,colone,0,+1)>=4)||
                   (compter(grille,ligne,colone,+1,+1)>=4)||
                   (compter(grille,ligne,colone,+1,0)>=4)
                   )
                {
                   return true;
                }
            }
        }
    }
    return false;
}
int compter(Array grille, size_t ligne,size_t colone, int l, int c)
{
    int com(0);
    int i=ligne;
    int j=colone;
    while(grille[i][j]==grille[ligne][colone])
    {
        com++;
        i=i+l;
        j=j+c;
    }
    return com;
}
