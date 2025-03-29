/*SINTEA Teodora - 314CB*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node { // arbore multicai
    char info[100];
    int lvl; // nivelul pe care este nodul in arbore
    struct node *children[27];
} Node, *Tree;

typedef struct Coada { // lista simplu inlant
    Tree info; // in coada sunt stocate nodurile, nu doar informatia
    struct Coada *urm;
}TCelulaC, *TCoada;

Tree AllocCellArb ();
void InsertArb (Tree r, char *s);
void InsertSufix (Tree r, char *s, int nr);
TCoada AllocCellC (Tree c);
void PushC (TCoada *start, TCoada *fin, Tree c);
Tree PopC (TCoada *start, TCoada *fin);
void BFS (Tree r, TCoada *start, TCoada *fin);
void Frunze (Tree r, int *nr);
void Sufixe_k (Tree r, int *nr, int k);
void DescDirecti(Tree r, int *maxi);
void Dezaloc(Tree r);
void VerifSufix (Tree r, char *s, int *nr);
void CompressTree (Tree r);
void DecLvl (Tree r);