#include <stdio.h>
#include <stdlib.h>

//Support function for the qsort function. This allows the decreasing order
int cmpfunc(const void* a, const void* b) {
    return *(int*) b - *(int*) a;
}

int main() {
    int t;  //number of test cases
    int n;  //total number of students
    int p;  //number of students to pick (team size)

    scanf("%d", &t);    //read the number of test cases from stdin

    for (int counter = 1; counter <= t; counter++) {

        int min = -1;           //initialize the minimum hours of training with an infeasible value
        scanf("%d %d", &n, &p); //read the total number of students and the team size

        int s[n];

        //read the skill value of each student and insert in the array
        for (int i = 0; i < n; i++)
            scanf("%d", &s[i]);

        //order the students in decreasing order
        qsort(s, n, sizeof(int), cmpfunc);

        //Now that the array is in decreasing order, the minimum training team for each upper bounding student
        //is the one composed by the p - 1 following students.
        //Compute the training hours for each one of these teams and save the minimum found
        for (int i = 0; i <= n - p; i++) {
            int tmp = (p - 1) * s[i];
            for (int j = i + 1; j < i + p; j++) {
                tmp -= s[j];
            }
            if (min == -1 || tmp < min)
                min = tmp;
        }

        printf("Case #%d: %d\n", counter, min);
    }
}