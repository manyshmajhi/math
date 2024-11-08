// simulating S=(n/2)*(a+l) form of Arithmetic Sum because
// if we arrange it as S=((a+l)/2)*n,
// it can be interpreted as 
// average of first term and last term is being added 'n' times
//
// I don't know about you, but it was looking pretty suspicious to me
// and had to check for satisfaction 🙂

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DEFAULT_ITERATIONS 3

int randomInt(int min, int max) {
    return rand() % (max - min) + min;
}

int isOdd(int num) {
     if (num % 2 == 0) return 0;
     else return 1;
}

void addEachTerm(unsigned int a, unsigned int n, double d ) {
    double sum = 0.0;

    for(int i = 1; i <= n; i++) {
        sum += a + (i - 1.0) * d;
    }

    printf("Adding each term:              %lf\n", sum);
}

void useMainFormula(unsigned int a, unsigned int n, double d ) {
    double sum = (n / 2.0) * (2.0 * a + (n - 1) * d);

    printf("(n/2)*(2a+(n-1)d):             %lf\n", sum);
}
void useDerivedFormula(unsigned int a, unsigned int l, unsigned int n ) {
    double sum = (n / 2.0) * (a + l);

    printf("(n/2)*(a+l):                   %lf\n", sum);
}

int main(int argc, char *argv[]) {
    int iterations = (argc > 1) ? atoi(argv[1]) : DEFAULT_ITERATIONS;

    if(iterations < 1) {
        iterations = DEFAULT_ITERATIONS;
    }

    unsigned int firstTerm, lastTerm, numberOfTerms;
    double commonDifference;
    srand(time(NULL));

    for(int i = 0; i < iterations; i++) {
        firstTerm = randomInt(1, 50);

        do {
            lastTerm = randomInt(firstTerm, 100); 
        } while(!((isOdd(firstTerm) && !isOdd(lastTerm)) || (!isOdd(firstTerm) && isOdd(lastTerm))));
        
        numberOfTerms = randomInt(3, 30);
        commonDifference = (lastTerm - firstTerm) / (numberOfTerms - 1.0);

        printf("\n-----------------------------------------------------\n");
        printf("%d) Using a=%d, l=%d, n=%d, and d=%lf", i+1, firstTerm, lastTerm, numberOfTerms, commonDifference);
        printf("\n-----------------------------------------------------\n");
        addEachTerm(firstTerm, numberOfTerms, commonDifference);
        useMainFormula(firstTerm, numberOfTerms, commonDifference);
        useDerivedFormula(firstTerm, lastTerm, numberOfTerms);
    }

    return 0;
}
