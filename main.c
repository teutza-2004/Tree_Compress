/*SINTEA Teodora - 314CB*/

#include "functii.h"

int main (int argc, char **argv) {
    int k = 0;
    char cerinta[5] = "";
    strcpy(cerinta, argv[1]);
    if (strcmp(cerinta, "-c2") == 0) {
        k = atoi(argv[2]); //face din string in int
        freopen(argv[3], "r", stdin);
        freopen(argv[4], "w", stdout);
    } else {
        freopen(argv[2], "r", stdin);
        freopen(argv[3], "w", stdout);
    }
    Tree r = AllocCellArb();
    TCoada start = NULL, fin = NULL;

    char s[100];
    int n = 0, i = 0, m = 0;
    scanf("%d", &n);
    if (strcmp(cerinta, "-c3") == 0) {
        scanf("%d", &m);
    }
    fgets(s, 100, stdin);
    for (i = 0; i < n; i++) {
        fgets(s, 100, stdin);
        s[strlen(s)] = '\0';
        s[strlen(s) - 1] = '$';
        InsertArb(r, s);
    }

    if (strcmp(cerinta, "-c1") == 0) {
        BFS(r, &start, &fin);
    } else if (strcmp(cerinta, "-c2") == 0) {
        int nr = 0;
        Frunze(r, &nr);
        printf("%d\n", nr);

        nr = 0;
        Sufixe_k(r, &nr, k);
        printf("%d\n", nr);

        nr = 0;
        DescDirecti(r, &nr);
        printf("%d\n", nr);
    } else if (strcmp(cerinta, "-c3") == 0) {
        for (i = 0; i < m; i++) {
            int nr = 1;
            scanf("%s", s);
            s[strlen(s) + 1] = '\0';
            s[strlen(s)] = '$';
            VerifSufix(r, s, &nr);
            printf("%d\n", nr);
        }
    } else if (strcmp(cerinta, "-c4") == 0) {
        CompressTree(r);
        BFS(r, &start, &fin);
    }

    Dezaloc(r);
    free(r);
    return 0;
}