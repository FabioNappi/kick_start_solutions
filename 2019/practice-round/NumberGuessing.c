#include <stdio.h>
#include <string.h>

// PROBLEM
// We are thinking of an integer P within the range (A,B] — that is, A < P ≤ B. You have N tries to guess our number.
// After each guess that is not correct, we will tell you whether P is higher or lower than your guess.

int main() {
    int t;              //number of tests
    int a;              //lower bound
    int b;              //upper bound
    int n;              //available tries
    int q;              //attempt
    char judgement[20]; //response of the judge

    scanf("%d", &t);    //read the number of tests from stdin

    //repeat for each test
    while(t > 0) {

        scanf("%d %d", &a, &b);
        b++;    //increment by one because upper bound is inclusive
        scanf("%d", &n);

        //print the half of the upper bound in stdout
        //if response is TOO_SMALL update the lower bound with the previous attempt
        //if response is TOO_BIG update the upper bound with the previous attempt + 1
        //if response is CORRECT go to the next test if any
        //if response is WRONG_ANSWER exit
        while (n > 0) {
            q = (a + b) / 2;
            printf("%d\n", q);
            fflush(stdout);
            scanf("%s", judgement);
            if (strcmp(judgement, "TOO_SMALL") == 0) {
                a = q;
                n--;
            } else if (strcmp(judgement, "TOO_BIG") == 0) {
                b = q + 1;
                n--;
            } else if (strcmp(judgement, "CORRECT") == 0) {
                t--;
                n = 0;
            } else if (strcmp(judgement, "WRONG_ANSWER") == 0)
                return 1;
        }
    }
}