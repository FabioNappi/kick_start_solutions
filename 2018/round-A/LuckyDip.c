// PROBLEM
// You are participating in the Grand Kickstart Lucky Dip with many fantastic and amazing prizes (and some not so good ones)!
// In this Lucky Dip, there is a bag with N items. The i-th item in the bag has value Vi. You will put your hand into
// the bag and draw one item at random; all items in the bag have an equal probability of being chosen.
// The organizers want contestants to feel that they have some element of choice, so after you draw an item, you can
// either keep it, or "redip" by returning it to the bag and drawing again.

#include <stdio.h>

int main() {
    int t;              // number of test cases
    scanf("%d", &t);    // read number of test case from stdin

    // do this loop for each test case
    for (int counter = 1; counter <= t ; ++counter) {
        int n;                      // number of items in the bag
        int k;                      // number of possible "redips"
        scanf("%d %d", &n, &k);     // read values from stdin

        long bag[n];
        for (int i = 0; i < n; ++i) {
            scanf("%ld", &bag[i]);  // read the value of each item from stdin
        }

        double expected = -1;       // initialize the expected value with infeasible value (expected is at least 1)

        for (int j = 0; j <= k; ++j) {
            double sum = 0;         // initialize the sum to 0 (sum is computed for the expected value)

            // sum is increased by the max between the expected value with j-1 "redips" and the value of the item
            for (int i = 0; i < n; ++i)
                sum += (expected > bag[i] ? expected : bag[i]);

            expected = sum / n;     // compute the expected value with j possible "redips"
        }

        printf("Case #%d: %lf\n", counter, expected);   // print the answer
    }
}