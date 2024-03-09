#include"utils.h"

int main() {
    int N = 0, i = 0;
    float result = 0;
    scanf("%i", &N);
    if (N == 1) {
        scanf("%f", &result);
        printf("%f\n", result);
        return 0;
    }
    float Vnr[N];
    char Vop[N];
    for (i = 0; i < N; i++) {
        Vnr[i] = 0;
    }
    for (i = 0; i < N; i++) {
        Vop[i] ='\0';
    }
    citnr(Vnr, N);
    citop(Vop, N);
    int len = N;
    result = task2(Vnr, Vop, &len);
    printf("%f\n", result);
    return 0;
}
