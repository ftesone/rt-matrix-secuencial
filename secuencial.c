#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 1024

int main (int argc, char *argv[]) {
    double *a, *b, *c;
    a = (double *) malloc(sizeof(double) * N * N);
    b = (double *) malloc(sizeof(double) * N * N);
    c = (double *) malloc(sizeof(double) * N * N);

    for (int i=0 ; i<N ; i++) {
        for (int j=0 ; j<N ; j++) {
            a[i*N+j] = 1;
            b[j*N+i] = 1;
            c[i*N+j] = 0;
        }
    }

    clock_t begin = clock();

    for (int i=0 ; i<N ; i++) {
        for (int j=0 ; j<N ; j++) {
            for (int k=0 ; k<N ; k++) {
                c[i*N+j] += a[i*N+k] * b[j*N+k];
            }
        }
    }

    clock_t end = clock();
    printf("Tiempo: %.4f\n", ((double)(end-begin)/CLOCKS_PER_SEC));

    free(a);
    free(b);
    free(c);

    return EXIT_SUCCESS;
}
