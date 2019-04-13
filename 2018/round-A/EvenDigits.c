#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// PROBLEM
// Supervin has a unique calculator. This calculator only has a display, a plus button, and a minus button.
// Currently, the integer N is displayed on the calculator display.
// Supervin does not like odd digits, because he thinks they are "odd". Therefore, he wants to display an integer with
// only even digits in its decimal representation, using only the calculator buttons.
// Since the calculator is a bit old and the buttons are hard to press, he wants to use a minimal number of button presses.

int length; // the length of the displayed number

// This functions compares 2 long long integers and returns the minimum
long long minimum(long long a, long long b) {
    return (a > b ? b : a);
}

// This function returns 1 if the parameter is odd, 0 if it's even
int isOdd(int value) {
    return value % 2;
}

// This function writes in the target string the largest lower even number
void lowerEven(char* target, int value, int position) {
    int i;

    // Particular case: the lower even is shorter by 1 digit
    if (value == 1 && position == 0) {
        for (i = 0; i < length - 1; ++i) {
            *(target + i) = '8';
        }
        *(target + i) = '\0';
    }

    // General case: decrease by 1 the odd digit and put the right number of '8's after
    else {
        *(target + position) = (char) value + 47;
        for (i = position + 1; i < length; i++) {
            *(target + i) = '8';
        }
        *(target + i) = '\0';
    }
}

// This function writes in the target string the smallest higher even number
void higherEven(char* target, int value, int position) {
    int i;

    if (value >= 8) {

        // Particular case: if the digit to be increased is '8' or '9' and it's the leftmost digit, then the target
        // string is formed by a '2' followed by as many '0's as the length of the initial number
        if (position == 0) {
            *(target) = '2';
            for (i = 1; i <= length; ++i) {
                *(target + i) = '0';
            }
            *(target + i) = '\0';
        }

        // Particular case: if the digit to be increased is '8' or '9', then we recursively call this function on the
        // previous digit
        else {
            int precedent = (int) *(target + position - 1) - 48;
            return higherEven(target, precedent, position - 1);
        }
    }

    // General case: increase the digit by 1 (if it is odd) or 2 (if it is even) and put the correct number of '0's.
    else {
        *(target + position) = (char) value + (value % 2 ? 49 : 50);
        for (i = position + 1; i < length; ++i) {
            *(target + i) = '0';
        }
        *(target + i) = '\0';
    }
}

int main() {
    int t;              // Number of test cases
    scanf("%d", &t);    // Read the number of test cases from stdin

    for (int counter = 1; counter <= t; ++counter) {

        char* number = (char*) malloc(20);  // The biggest possible number is 10^16 that has 17 digits, so 20 bytes is
        scanf("%s", number);                // more than actually needed

        length = strlen(number);
        char* x = (char*) malloc(length + 1);   // x is the string that will contain the lower even number
        char* y = (char*) malloc(length + 2);   // y is the string that will contain the higher even number

        char digit = *number;
        for (int i = 0; digit != '\0'; i++) {
            int value = (int) digit - 48;

            // when an odd digit is found the lower and higher even numbers are generated
            if (isOdd(value)) {
                lowerEven(x, value, i);
                higherEven(y, value, i);
                break;
            }

            // the original number is transcribed in x and y as long as the digits are even
            else {
                *(x + i) = digit;
                *(y + i) = digit;
            }

            digit = *(number + i + 1);
        }

        // conversions from string to long long
        long long numberValue = atoll(number);
        long long low = atoll(x);
        long long high = atoll(y);

        // compute the closer even number
        long long closer = minimum(llabs(numberValue - low), llabs(numberValue - high));
        printf("Case #%d: %lld\n", counter, closer);
    }
}