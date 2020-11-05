typedef struct {
    int l;
    int c;
} pos;

typedef pos item;

typedef struct {
    item *v;
    int ini;
    int fim;
    int max;
} fila;

fila * criaFila (int tam);
void destroiFila (fila *f);
int filaVazia (fila *f);
void insereFila (fila *f, item x);
item removeFila (fila *f);
