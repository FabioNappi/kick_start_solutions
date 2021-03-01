# Practice Round (2019)
This directory contains my solutions, written in C and/or Python, of the 3 problems in the practice round.

## 1. Number Guessing
### Problem
This problem is a well-known classic; we present it primarily as an opportunity for you to try out the interactive judging system.

We are thinking of an integer `P` within the range (A,B] — that is, `A < P ≤ B`. You have `N` tries to guess our number. After each guess that is not correct, we will tell you whether `P` is higher or lower than your guess.

#### Input and output
This problem is interactive, which means that the concepts of input and output are different than in standard Code Jam problems. You will interact with a separate process that both provides you with information and evaluates your responses. All information comes into your program via standard input; anything that you need to communicate should be sent via standard output. Remember that many programming languages buffer the output by default, so make sure your output actually goes out (for instance, by flushing the buffer) before blocking to wait for a response. See the FAQ for an explanation of what it means to flush the buffer. Anything your program sends through standard error is ignored, but it might consume some memory and be counted against your memory limit, so do not overflow it. To help you debug, a local testing tool script (in Python) is provided at the very end of the problem statement.

Initially, your program should read a single line containing a single integer `T` indicating the number of test cases. Then, you need to process `T` test cases.

For each test case, your program will read a single line with two integers `A` and `B`, representing the exclusive lower bound and inclusive upper bound, as described above. In the next line, you will read a single integer N, representing the maximum number of guesses you can make. Your program will process up to N exchanges with our judge.

For each exchange, your program needs to use standard output to send a single line with one integer `Q`: your guess. In response to your guess, the judge will print a single line with one word to your input stream, which your program must read through standard input. The word will be `CORRECT` if your guess is correct, `TOO_SMALL` if your guess is less than the correct answer, and `TOO_BIG` if your guess is greater than the correct answer. Then, you can start another exchange.

If your program gets something wrong (e.g., wrong output format, or out-of-bounds values), the judge will send `WRONG_ANSWER` to your input stream and it will not send any other output after that. If your program continues to wait for the judge after receiving `WRONG_ANSWER`, your program will time out, resulting in a Time Limit Exceeded error. Notice that it is your responsibility to have your program exit in time to receive the appropriate verdict (Wrong Answer, Runtime Error, etc.) instead of a Time Limit Exceeded error. As usual, if the total time or memory is exceeded, or your program gets a runtime error, you will receive the appropriate verdict.

If your test case is solved within `N` tries, you will receive the `CORRECT` message from the judge, as mentioned above, and then continue to get input (a new line with two integers `A` and `B`, etc.) for the next test case. After `N` tries, if the test case is not solved, the judge will print `WRONG_ANSWER` and then stop sending output to your input stream.

You should not send additional information to the judge after solving all test cases. In other words, if your program keeps printing to standard output after receiving `CORRECT` for the last test case, you will get a Wrong Answer judgment.

#### Limits
* `1 ≤ T ≤ 20`.
* `A = 0. N = 30`.
* Time limit: 10 seconds per test set.
* Memory limit: 1GB.
* Test set 1 (Visible)
  - `B = 30`.
* Test set 2 (Hidden)
  - `B = 10^9`.

## 2. Mural
### Problem
Thanh wants to paint a wonderful mural on a wall that is `N` sections long. Each section of the wall has a beauty score, which indicates how beautiful it will look if it is painted. Unfortunately, the wall is starting to crumble due to a recent flood, so he will need to work fast!

At the beginning of each day, Thanh will paint one of the sections of the wall. On the first day, he is free to paint any section he likes. On each subsequent day, he must paint a new section that is next to a section he has already painted, since he does not want to split up the mural.

At the end of each day, one section of the wall will be destroyed. It is always a section of wall that is adjacent to only one other section and is unpainted (Thanh is using a waterproof paint, so painted sections can't be destroyed).

The total beauty of Thanh's mural will be equal to the sum of the beauty scores of the sections he has painted. Thanh would like to guarantee that, no matter how the wall is destroyed, he can still achieve a total beauty of at least B. What's the maximum value of B for which he can make this guarantee?

#### Input
The first line of the input gives the number of test cases, `T`. `T` test cases follow. Each test case starts with a line containing an integer `N`. Then, another line follows containing a string of `N` digits from 0 to 9. The `i-th` digit represents the beauty score of the `i-th` section of the wall.

#### Output
For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the maximum beauty score that Thanh can guarantee that he can achieve, as described above.

#### Limits
* `1 ≤ T ≤ 100`.
* Time limit: 20 seconds per test set.
* Memory limit: 1 GB.
* Small dataset (Test set 1 - Visible)
  - `2 ≤ N ≤ 100`.
* Large dataset (Test set 2 - Hidden)
  - For exactly 1 case, `N = 5 × 10^6`; for the other T - 1 cases, `2 ≤ N ≤ 100`.

## 3. Kickstart Alarm
### Problem
Shil has a very hard time waking up in the morning each day, so he decides to buy a powerful alarm clock to Kickstart his day. This Alarm is called a Kickstart Alarm. It comes pre-configured with `K` powerful wakeup calls. Before going to bed, the user programs the clock with a Parameter Array consisting of the values `A1, A2, ..., AN`. In the morning, the clock will ring `K` times, with the `i-th` wakeup call having power `POWERi`.

To calculate `POWERi`, the alarm generates all the contiguous subarrays of the Parameter Array and calculates the summation of the `i-th` exponential-power of all contiguous subarrays. The `i-th` exponential-power of subarray `Aj, Aj+1, ..., Ak` is defined as `Aj × 1^i + Aj+1 × 2^i + Aj+2 × 3^i + ... + Ak × (k-j+1)^i`. So `POWERi` is just the summation of the `i-th` exponential-power of all the contiguous subarrays of the Parameter Array.

For example, if i = 2, and A = [1, 4, 2], then the i-th exponential-power of A would be calculated as follows:
```
2-nd exponential-power of [1] = 1 × 1^2 = 1
2-nd exponential-power of [4] = 4 × 1^2 = 4
2-nd exponential-power of [2] = 2 × 1^2 = 2
2-nd exponential-power of [1, 4] = 1 × 1^2 + 4 × 2^2 = 17
2-nd exponential-power of [4, 2] = 4 × 1^2 + 2 × 2^2 = 12
2-nd exponential-power of [1, 4, 2] = 1 × 1^2 + 4 × 2^2 + 2 × 3^2 = 35
so the total is 71.
```
Tonight, Shil is using his Kickstart Alarm for the first time. Therefore, he is quite worried about the sound the alarm might make in the morning. It may wake up the neighbors, or, worse yet, it may wake up the whole planet! However, calculating the power of each wakeup call is quite difficult for him. Given K and the Parameter Array `A1, A2, ..., AN`, can you help him by calculating the summation of power of each wakeup call: `POWER1 + POWER2 + ... + POWERK`?

#### Input
The first line of the input gives the number of test cases, `T`. `T` test cases follow. Each test case consists of one line with nine integers `N, K, x1, y1, C, D, E1, E2` and `F`. `N` is the length of array `A`, `K` is the number of wakeup calls. Rest of the values are parameters that you should use to generate the elements of the array `A`, as follows.

Use the recurrences below to generate `xi` and `yi` for `i = 2 to N`:
```
xi = ( C × xi-1 + D × yi-1 + E1 ) modulo F.
yi = ( D × xi-1 + C × yi-1 + E2 ) modulo F.
We define Ai = ( xi + yi ) modulo F, for all i = 1 to N.
```
#### Output
For each test case, output one line containing `Case #x: POWER`, where `x` is the test case number (starting from 1) and `POWER` is the summation of `POWERi`, for `i = 1 to K`. Since `POWER` could be huge, print it modulo 1000000007 (10^9 + 7).

#### Limits
* `1 ≤ T ≤ 100`.
* Time limit: 90 seconds per test set.
* Memory limit: 1 GB.
* `1 ≤ x1 ≤ 10^5`.
* `1 ≤ y1 ≤ 10^5`
* `1 ≤ C ≤ 10^5`.
* `1 ≤ D ≤ 10^5`.
* `1 ≤ E1 ≤ 10^5`.
* `1 ≤ E2 ≤ 10^5`.
* `1 ≤ F ≤ 10^5`.
* Small dataset (Test set 1 - Visible)
  - `1 ≤ N ≤ 100`.
  - `1 ≤ K ≤ 20`.
* Large dataset (Test set 2 - Hidden)
  - `1 ≤ N ≤ 10^6`.
  - `1 ≤ K ≤ 10^4`.