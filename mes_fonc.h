#ifndef MES_FONC_H_INCLUDED
#define MES_FONC_H_INCLUDED


using namespace std;

enum couleur { vide, rouge, jaune};
typedef array<array<couleur, 7>, 6> Array;

void initialise(Array& grille);
void affiche(Array& grille);
void get(int& a);
bool joue(Array &grille,int colone,couleur color);
bool gagne(Array grille, couleur jeux);
int compter(Array grille, size_t ligne,size_t colone, int l, int c);

#endif // MES_FONC_H_INCLUDED
