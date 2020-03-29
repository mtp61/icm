#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>

int main() {
    srand(time(0));    
    
    int TRIALS = 10000000;

    int S[] = {300, 300, 200, 200, 100, 100}; // stacks
    int Z[] = {50, 30, 20, 0, 0, 0}; // payouts

    int n = sizeof S / sizeof *S;

    float mean_stack = 0;
    for (int i = 0; i < n; i++) {
        mean_stack += S[i];
    }
    mean_stack /= n;

    float Q[n]; // relative stacks
    for (int i = 0; i < n; i++) {
        Q[i] = S[i] / mean_stack;
    }

    int X[n]; // counts total winnings
    for (int i = 0; i < n; i++) {
        X[i] = 0;
    }

    int tint; // temps
    float tfloat;

    float p[n];
    int a[n];
    for (int t = 0; t < TRIALS; t++) {
        for (int i = 0; i < n; i++) {
            p[i] = pow((float) rand() / RAND_MAX, 1 / Q[i]);
            a[i] = i;
        }

        // shit bubble sort
        int change = 1;
        while (change) {
            change = 0;
            for (int i = 0; i < n - 1; i++) {
                if (p[i + 1] > p[i]) {
                    tfloat = p[i];
                    tint = a[i];
                    p[i] = p[i + 1];
                    a[i] = a[i + 1];
                    p[i + 1] = tfloat;
                    a[i + 1] = tint;

                    change = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) { // update winnings
            X[a[i]] += Z[i];
        }
    }

    float Y[n]; // mean winnings
    for (int i = 0; i < n; i++) {
        Y[i] = (float) X[i] / TRIALS;
    }

    for (int i = 0; i < n; i++) { // output
        printf("%f ", Y[i]);
    }
    printf("\n");
}