//ovviamente va implementata la lista.

struct cella {
    int r;
    int c;
};

void risolviLabirinto(int labirinto[][5], int x, int y) {
    init();

    cella partenza;
    partenza.r = 0;
    partenza.c = 0;
    push(partenza);

    
    bool visitata[5][5] = {
        { false, false, false, false, false },
        { false, false, false, false, false },
        { false, false, false, false, false },
        { false, false, false, false, false },
        { false, false, false, false, false }
    };
    visitata[0][0] = true;
    
 
    while (!vuota()) {

        cella temp;
        top(temp);
        int coordinataX = temp.r;
        int coordinataY = temp.c;

        if (coordinataX == x && coordinataY == y) {
            while (!vuota()) {
                top(temp);
                cout << "[" << temp.r << "," << temp.c << "], ";
                pop();
            }
            cout << endl;
        } else {
            if (coordinataX - 1 >= 0 && !visitata[coordinataX-1][coordinataY] && labirinto[coordinataX - 1][coordinataY] == 1) {
                cella nuovaCella;
                nuovaCella.r = coordinataX-1;
                nuovaCella.c = coordinataY;
                push(nuovaCella);
                visitata[coordinataX-1][coordinataY] = true;
            } else if (coordinataX + 1 < 5 && !visitata[coordinataX+1][coordinataY] && labirinto[coordinataX + 1][coordinataY] == 1) {
                cella nuovaCella;
                nuovaCella.r = coordinataX+1;
                nuovaCella.c = coordinataY;
                push(nuovaCella);
                visitata[coordinataX+1][coordinataY] = true;
            } else if (coordinataY - 1 >= 0 && !visitata[coordinataX][coordinataY-1] && labirinto[coordinataX][coordinataY-1] == 1) {
                cella nuovaCella;
                nuovaCella.r = coordinataX;
                nuovaCella.c = coordinataY - 1;
                push(nuovaCella);
                visitata[coordinataX][coordinataY-1] = true;
            } else if (coordinataY + 1 < 5 && !visitata[coordinataX][coordinataY+1] && labirinto[coordinataX][coordinataY+1] == 1) {
                cella nuovaCella;
                nuovaCella.r = coordinataX;
                nuovaCella.c = coordinataY + 1;
                push(nuovaCella);
                visitata[coordinataX][coordinataY+1] = true;
            } 
            else {
                pop();
            }
        }
    }
    deinit();
}