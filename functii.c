/*SINTEA Teodora - 314CB*/

#include "functii.h"

void Dezaloc (Tree r) {
    if (r->children == NULL) {
        return;
    }
    int i = 0;
    for (i = 0; i < 27; i++) {
        if (r->children[i]) {
            Dezaloc(r->children[i]);
            free(r->children[i]);
        }
    }
}

Tree AllocCellArb () {
    Tree aux = (Tree)calloc(1, sizeof(Node));
    if (!aux) {
        return NULL;
    }
    strcpy(aux->info, "");
    aux->lvl = 0;
    int i = 0;
    for (i = 0; i < 27; i++) {
        aux->children[i] = NULL;
    }
    return aux;
}

void InsertSufix (Tree r, char *s, int nr) {
    char c = *s;
    if (c == '$') {
        if (r->children[0] == NULL) {
            r->children[0] = AllocCellArb();
        }
        strcpy(r->children[0]->info, "$");
        r->children[0]->lvl = nr;
        return;
    }
    if (r->children[c - 'a' + 1] == NULL) {
        r->children[c - 'a' + 1] = AllocCellArb();
    }
    strcpy(r->children[c - 'a' + 1]->info, &c);
    r->children[c - 'a' + 1]->lvl = nr;
    InsertSufix(r->children[c - 'a' + 1], s + 1, nr+1);
}

void InsertArb (Tree r, char *s) {
    int n = strlen(s), i = 0;
    for (i = n - 1; i >= 0; i--) {
        InsertSufix(r, s + i, 1);
    }
}

TCoada AllocCellC (Tree arb) {
    TCoada aux = (TCoada)calloc(1, sizeof(TCelulaC));
    if (!aux) {
        return NULL;
    }
    aux->urm = NULL;
    aux->info = arb;
    return aux;
}

void PushC (TCoada *start, TCoada *fin, Tree arb) {
    TCoada aux = AllocCellC(arb);
    if (!aux) {
        return;
    }
    if (!(*start)) {
        *start = *fin = aux;
        return;
    }
    (*fin)->urm = aux;
    *fin = (*fin)->urm;
}

Tree PopC (TCoada *start, TCoada *fin) {
    Tree arb = (*start)->info;
    if (*start == *fin) { // un singur elem in coada
        TCoada aux = *start;
        *start = *fin = NULL;
        free(aux);
        return arb;
    }
    TCoada aux = *start;
    *start = (*start)->urm;
    free(aux);
    return arb;
}

void BFS (Tree r, TCoada *start, TCoada *fin) {
    int lvl = 1;
    int i = 0;
    for (i = 0; i < 27; i++) {
        if (r->children[i]) {
            PushC(start, fin, r->children[i]);
        }
    }
    while (*start) {
        Tree nod  = PopC(start, fin);
        if (lvl != nod->lvl) {
            lvl++;
            printf("\n");
        }
        printf("%s ", nod->info);
        for (i = 0; i < 27; i++) {
            if (nod->children[i]) {
                PushC(start, fin, nod->children[i]);
            }
        }
    }
    printf("\n");
}

void Frunze (Tree r, int *nr) {
    if (r->children == NULL) {
        return;
    }
    if (strcmp(r->info, "$") == 0) {
        (*nr)++;
    }
    int i = 0;
    for (i = 0; i < 27; i++) {
        if (r->children[i]) {
            Frunze(r->children[i], nr);
        } 
    }
}

void Sufixe_k (Tree r, int *nr, int k) {
    if (r->children == NULL) {
        return;
    }
    if (r->lvl == k+1 && strcmp(r->info, "$") == 0) {
        (*nr)++;
    }
    int i = 0;
    for (i = 0; i < 27; i++) {
        if (r->children[i]) {
            Sufixe_k(r->children[i], nr, k);
        } 
    }
}

void DescDirecti(Tree r, int *maxi) {
    if (r->children == NULL) {
        return;
    }
    int i = 0, nr = 0;
    for (i = 0; i < 27; i++) {
        if (r->children[i]) {
            nr++;
            DescDirecti(r->children[i], maxi);
        }
        if (nr > *maxi) {
            *maxi = nr;
        }
    }
}

void VerifSufix (Tree r, char *s, int *nr) {
    char c = *s;
    if (r->children == NULL) {
        return;
    }
    if (c == '$') {
        if (r->children[0] == NULL || strcmp(r->children[0]->info, &c)) {
            *nr  = 0;
        }
        return;
    }
    if (r->children[c - 'a' + 1] == NULL || strcmp(r->children[c - 'a' + 1]->info, &c)) {
        *nr  = 0;
        return;
    }
    VerifSufix(r->children[c - 'a' + 1], s + 1, nr);
}

void DecLvl (Tree r) {
    if (r->children == NULL) {
        return;
    }
    int i = 0;
    for (i = 0; i < 27; i++) {
        if (r->children[i]) {
            r->children[i]->lvl--;
            DecLvl(r->children[i]);
        }
    }
}

void CompressTree (Tree r) {
    int nr = 0, poz = 0, i = 0;
    if (r->children[0] == NULL) {
        for (i = 1; i < 27; i++) {
            if (r->children[i]) {
                nr++;
                poz = i;
            }
        }
        if (nr == 1) {
            strcat(r->info, r->children[poz]->info);
            Tree nod = r->children[poz];
            for (i = 0; i < 27; i++) {
                if (r->children[i] || nod->children[i]) {
                    r->children[i] = nod->children[i];
                }
            }
            free(nod);
            DecLvl(r);
            CompressTree(r);
        }
    }
    for (i = 0; i < 27; i++) {
        if (r->children[i]) {
            CompressTree(r->children[i]);
        }
    }
}

