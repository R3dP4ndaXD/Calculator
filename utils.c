#include"utils.h"

void citnr(float *Vnr, int N) {
    for (int i = 0; i < N; i++) {
        scanf("%f\n", &Vnr[i]);
    }
}
void citop(char *Vop, int N) {
    for (int i = 0; i < N; i++) {
        scanf("%c", &Vop[i]);
    }
    Vop[N-1] = '\0';
}

float task1(float *Vnr, char *Vop, int N) {
    // parcur operatiile in ordinea in care apar
    float result = Vnr[0];
    for (int i = 0; i < N-1; i++) {
        if (Vop[i] == '*') {
            result *= Vnr[i+1];
        } else if (Vop[i] == '/') {
            result /= Vnr[i+1];
        } else if (Vop[i] == '+') {
            result += Vnr[i+1];
        } else {
            result -= Vnr[i+1];
        }
    }
    return result;
}

void elim(float *Vnr, char *Vop, int *len, int poz) {
    int i = 0;
    for (i = poz+1; i < (*len - 1); i++) {
        Vnr[i] = Vnr[i+1];
    }
    Vnr[*len-1] = 0;
    for (i = poz; i < (*len - 2); i++) {
        Vop[i] = Vop[i+1];
    }
    Vop[*len-2] = '\n';
    (*len)--;
}

float task2(float *Vnr, char *Vop, int *len) {
    /* evaluez succesiv expresia tinand cont de precedenta operatorilor si de eventuale cazuri speciale;
       fiecare operator aplicat este eliminata din vector, rezultatul operatiei numerice se salveaza in termenul din stanga, 
       iar al doilea termen se elimina din vector;*/
    int i = 0;
    while (*len >= 2) {
        i = 0;
        while (i < *len -1) {
            if (Vop[i] == '*') {
                Vnr[i] *= Vnr[i+1];
                elim(Vnr, Vop, len, i);
            } else if (Vop[i] == '/') {
                Vnr[i] /= Vnr[i+1];
                elim(Vnr, Vop, len, i);
            } else if (Vop[i] == '+' && !(Vop[i+1] == '*' || Vop[i+1] == '/')) {
                if (i >0 && Vop[i-1] == '-') {
                    // ex: 1'-'2'/'5'+'1'+'7
                    Vnr[i] -= Vnr[i+1];
                } else {
                    Vnr[i] += Vnr[i+1];
                }
                elim(Vnr, Vop, len, i);
            } else if (Vop[i] == '-' && !(Vop[i+1] == '*' || Vop[i+1] == '/')) {
                if (i >0 && Vop[i-1] == '-') {
                    // ex: 1'-'2'*'5'-'2'
                    Vnr[i] += Vnr[i+1];
                } else {
                Vnr[i] -= Vnr[i+1];
                }
                elim(Vnr, Vop, len, i);
            }  else {
                i++;
            }
        }
    }
    return Vnr[0];
}

float task3(float *Vnr, char *Vop, int *len) {
    // asemanator cu taskul 2
    int i = 0;
    while (*len >= 2) {
        i = 0;
        while (i < *len -1) {
            if (Vop[i] == '*') {
                Vnr[i] *= Vnr[i+1];
                elim(Vnr, Vop, len, i);
            } else if (Vop[i] == '/') {
                Vnr[i] /= Vnr[i+1];
                elim(Vnr, Vop, len, i);
            } else if (Vop[i] == '#' && !(Vop[i+1] == '*' || Vop[i+1] == '/')) {
                Vnr[i] = (Vnr[i] + Vnr[i+1]) * (Vnr[i] + Vnr[i+1]);
                elim(Vnr, Vop, len, i);
                i--;
            } else if (Vop[i] == '+' && !(Vop[i+1] == '*' || Vop[i+1] == '/'|| Vop[i+1] == '#' || Vop[i-1] == '#')) {
                // ex petru ultimul || :  2#2*3+1
                if (i >0 && Vop[i-1] == '-') {
                    Vnr[i] -= Vnr[i+1];
                } else {
                    Vnr[i] += Vnr[i+1];
                }
                elim(Vnr, Vop, len, i);
            } else if (Vop[i] == '-' && !(Vop[i+1] == '*' || Vop[i+1] == '/' || Vop[i+1] == '#' || Vop[i-1] == '#')) {
                // ex pentru ultimul || :  2#2*3-1
                if (i >0 && Vop[i-1] == '-') {
                    Vnr[i] += Vnr[i+1];
                } else {
                    Vnr[i] -= Vnr[i+1];
                }
                elim(Vnr, Vop, len, i);
            } else {
                i++;
            }
        }
    }
    return Vnr[0];
}
