#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;          //number of test cases
    int n;          //number of sections
    int toBePaint;  //number of sections that will be painted
    int beauty;     //value of beauty score
    int max;        //maximum beauty
    char* wall;     //representation of wall's sections

    scanf("%d", &t);    //read the number of tests from stdin

    //repeat for each test
    for (int counter = 1; counter <= t; counter++) {

        scanf("%d", &n);            //read number of sections of the wall
        wall = (char*)malloc(n);    //allocate as much memory as needed
        scanf("%s", wall);          //read the wall's representation

        //the number of sections to be painted are the half in case of even number of sections, half plus one otherwise
        toBePaint = (n / 2) + (n % 2);
        beauty = 0;
        max = 0;
        
        for (int i = 0; i < n; i++) {
            beauty += (int) wall[i] - 48;   //increment the beauty score by the score of the i-th section
            if (i >= toBePaint)
                beauty -= (int) wall[i - toBePaint] - 48;   //decrease the beauty score by the score of the no-longer-be-painted section
            if (beauty > max)
                max = beauty;   //substitute the maximum beauty score if needed
        }

        printf("Case #%d: %d\n", counter, max);
        free(wall); //free memory for next test case
    }
}
