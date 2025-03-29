main:
- iau argumentele date in linia de comanda si le salvez in functie de cerinta.
- aloc celula radacina a arboerlui de sufixe si imi declar pointerul de start si cel de final al cozii (folosita pentru parcurgerea in latime).
- citesc n (numarul de date de intrare ale aroberelui) si pentru cerinta a 3-a citesc m (numarul de sufixe care trbuiesc verificate). de asemenea, citesc caracternul newline de la sfarsitul linii care contine date tip int.
- citesc cele n siruri de caractere, iar la finalul fiecaruia pun caracterul '$'. dupa acestea inserez sirul curent in arbore. (acest lucru il fac inainte sa verific ce cerinta trebuie executata deoarece pentru toate este necesar acest arbore).
- verific ce cerinta am de executat si in functei de acest lucru apelez functiile implementate in fisierul functii.c:
    -c1: apelez parcurgerea/afisarea in latime.
    -c2: apelez functiile care calculeaza numarul de frunze al arborelui, numarul de sufixe de lungime k si de numar maxim de descendenti directi al nodurilor din arbore.
    -c3: citesc cele m sufixe care trebuiesc verificate carora le pul de asemenea la final caracterul '$' (pentru usurinta operatiilor de verificare) si apelez functia care verifica propriu-zis sufixul curent.
    -c4: apelez functia care compreseaza arborele si afisarea in latime.
- in final apelez functia care dezaloca elementele arborelui si dezaloc si radacina.

functii:
- Dezaloc: dezalocare a arborelui
    parcurg in adancime nodurile arborelui, iar la intoarcerea din recursivitate le dezaloc (practic pornesc de la frunze si dezaloc pe rand pana ajung la radacina).
- AllocCellArb: aloca o celula de arbore
    aloc un element de tip Tree si verific daca alocarea a avut succes. initializez campul de informatie utila cu un sir gol, cmapul nivelului cu 0 si fiecare din cei 27 de pointeri spre copii cu NULL. returnez celula nou alocata.
- InsertSufix: insertia unui sufix (dat ca parmetru) in arbore
    salvez caracterul curent din sufix si verific daca este '$'. in caz afirmativ verific daca prima celula este alocata (si o aloc in caz negativ) si copiez caracterul in campul de informatie al celulei de inceput, de asemenea, actualizez nivelul celulei dupa care ies din recursivitate. pentru caracterele diferite de '$' efectuez aceleasi operatii, doar ca tin cont de pozitia din vectorul de copii in functie de cata litera in alfabet este caracterul curent. in final este apelul recursiv al functiei unde trec in elementul din vectorul de copii aferent caracterului curent, avansez in sufix si cresc nivelul.
- InsertArb: insertia fiecarui sufix format din string
    practic parcurg sirul de la final spre inceput si inserez fiecare sufix tip s+i in arbore folosind functia anterioara.
- AllocCellC: aloca o celula a cozii
    alloc o celula tip TCoada si initializez legatura spre celula urmatoare cu NULL si informatia cu arborele dat ca parametru.
- PushC: adaug la sfarsitul cozii
    declar si aloc o celula de coada. in cazul in care coada este goala, fac atat inceputul si finalul egale cu celula inserata. in caz contrar, adaug celula la finalul cozii si recreez legaturile cu pointerul de final al cozii.
- PopC: extrag un element din coada
    salvez informatia in variabila arb. in cazul in care se afla un singur element in coada initializez atat inceputul si finalul cu NULL si eliberez memoria ocupata. in caz contrar salvez adresa celulei de inceput si avansez in coada, dupa care dezaloc celula initiala. in final returnez arb. (valabil pentru ambele cazuri)
- BFS: parcurgerea si afisarea in latime
    adaug la coada copiii radacinii. cat timp coada nu este goala extrag elemente din coada pe care le afisez, iar pentru aceste elemente adaug la sfarsitul cozii copiii. variabila lvl tine cont de nivelul din arbore la care am ajuns in functie de nivelul elemetului extras din coada ultimul, pentru a putea face afisarea pe nivele.
- Frunze: numara cate frunze se gasesc in arbore
    practic numara cate caractere '$' sunt in arbore (deoarece numai acestea pot fi noduri terminale), lucru facut prin intermediul variabilei nr. parcurg fiecare copil al radacinii curente si apelez recursiv functia pentru fiecare din acestea. conditia de oprire este representata de nodul al carui vector de copii este NULL.
- Sufixe_k: numara cate sufixe de lungime k sunt in sir
    similar cu finctia anterioara, numai ca nr este incrementat atunci cand informatia radacinii curente este '$' iar nivelul curent este k+1 (lungimea secventei creste prin adaugarea caracterului '$' la final).
- DescDirecti: numarul maxim de copii al unui nod
    ca si la functiile anterioare. nr numara cati copii are radacina curenta si compara cu numarul maxim intalnit pana in acel moment.
- VerifSufix: verifica daca sufixul dat se afla in arbore
    salvez caracterul curent din sufix. in cazul in care acesta ets diferit cu caracterul curent din arbore (sufixuldat apare in arbore, dar nu este un sufix propriu-zis in arbore), raspunsul este 0. apelul recursiv este acelasi ca la functia de inserare a sufixului in arbore.
- DecLvl: scade nivelul in arbore la totii copiii radacinii
    similar cu functia de numarare frunze, numai ca in loc de incrementarea nr, scad nivelul nodului curent.
- CompressTree: compreseaza arborele original
    in cazul in care nodul curent nu are ca copil nodul '$', calculez numaraul de copii al acestui nod si salvez pozitia acestui nod pentru a nu parcurge de 2 ori. (pot fi compresate numai nodurile care au un singur copil care nu este '$') daca este un singur copil, concatenez informatiile radacinii cu cea a copilului si mut copiii copilului in copiii radacinei dupa care scad nivelul subarborelui cu radacina curenta. dupa ce efectuez compresia, apelez recursiv functia pentru totii copiii radacii curente.

punctaj: 120/120