# Round A (2018)

This directory contains my solutions, written in C and/or python, of the 3 problems in round A.

## 1. Even Digits
### The Problem
Supervin has a unique calculator. This calculator only has a display, a plus button, and a minus button. Currently, the integer `N` is displayed on the calculator display.

Pressing the plus button increases the current number displayed on the calculator display by 1. Similarly, pressing the minus button decreases the current number displayed on the calculator display by 1. The calculator does not display any leading zeros. For example, if 100 is displayed on the calculator display, pressing the minus button once will cause the calculator to display 99.

Supervin does not like odd digits, because he thinks they are "odd". Therefore, he wants to display an integer with only even digits in its decimal representation, using only the calculator buttons. Since the calculator is a bit old and the buttons are hard to press, he wants to use a minimal number of button presses.

Please help Supervin to determine the minimum number of button presses to make the calculator display an integer with no odd digits.

#### Input
The first line of the input gives the number of test cases, `T`. `T` test cases follow. Each begins with one line containing an integer `N`: the integer initially displayed on Supervin's calculator.

#### Output
For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the minimum number of button presses, as described above.

#### Limits
* `1 ≤ T ≤ 100`.
* Time limit: 20 seconds per test set.
* Memory limit: 1GB.
* Small dataset (Test set 1 - Visible)
  - `1 ≤ N ≤ 10^5`.
* Large dataset (Test set 2 - Hidden)
  - `1 ≤ N ≤ 10^16`.

## 2. Lucky Dip
### Problem
You are participating in the Grand Kickstart Lucky Dip with many fantastic and amazing prizes (and some not so good ones)!

In this Lucky Dip, there is a bag with `N` items. The `i-th` item in the bag has value `Vi`. You will put your hand into the bag and draw one item at random; all items in the bag have an equal probability of being chosen. The organizers want contestants to feel that they have some element of choice, so after you draw an item, you can either keep it, or "redip" by returning it to the bag and drawing again. (Note that the returned item is now just as likely to be chosen as any of the other items in the bag.) You may only redip a maximum of `K` times. If you use `K` redips, you must keep the item that you draw on your `(K + 1)-th` draw.

If you play optimally to maximize the value of the item you will end the game with, what is the expected value of that item?

#### Input
The input starts with one line containing one integer `T`: the number of test cases. `T` test cases follow.

Each test case consists of two lines. The first line consists of two integers `N` and `K`: the number of items in the bag, and the maximum number of times you may redip. The second line consists of `N` integers `Vi`, each representing the value of the `i-th` item.

#### Output
For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the expected value described above. Your answer will be considered correct if it is within an absolute or relative error of 10^-6 of the correct answer. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.

#### Limits
* Memory limit: 1GB.
* `1 ≤ T ≤ 100`.
* `1 ≤ Vi ≤ 10^9`.
* `1 ≤ N ≤ 2 * 10^4`.
* Small dataset (Test set 1 - Visible)
  - Time limit: 20 seconds.
  - `0 ≤ K ≤ 1`.
* Large dataset (Test set 2 - Hidden)
  - Time limit: 60 seconds.
  - `0 ≤ K ≤ 5 * 10^4`.

## 3. Scrambled Words
### Problem
Professor Scrmable noticed spelling mistakes in a research paper she was reviewing, but she had no difficulty in reading or understanding the words. Upon doing some research, she found an interesting article as described below:

According to a study at an English University, it doesn't matter in what order the letters in a word are, the only important thing is that the first and last letter be at the correct place. The rest can be a total mess and you can still read it without a problem. This is because the human mind does not read every letter by itself but the word as a whole.

Or rather ...

Aoccdrnig to a study at an Elingsh uinervtisy, it deosn't mttaer in waht oredr the ltteers in a wrod are, the olny iprmoetnt tihng is taht the frist and lsat ltteer be at the corecrt pclae. The rset can be a toatl mses and you can sitll raed it wouthit a porbelm. Tihs is bcuseae the huamn mnid deos not raed ervey lteter by istlef, but the wrod as a wlohe.

Professor Scrmable wants to explore this concept further and starts compiling different sentences containing similarly scrambled words to send to a popular publication. Unfortunately, the space key on the professor's keyboard is not working, so she has produced one long string of characters. She has asked you to determine how many of the words in her dictionary appear (at least once) as substrings in the long string of characters, either in their original or scrambled forms. (A scrambled form consists of the same set of letters with the first and last letters in the same places, and the others in any order.)

Note that a dictionary word can appear multiple times in the string (though it should be counted only once since we only need to know whether it shows up at least once). For example, if we had the word `this` in the dictionary, the possible valid words which would be counted are `this` (original version) and `tihs` (scrambled version), whereas `tsih`, `siht` and other variations are not valid since they do not start with `t` and end with `s`. Also, `tis`, `tiss`, and `thiss` are not scrambled forms, because they are not reorderings of the original set of letters.

Since the professor is extremely busy, she gives this task to you, her favorite and most trusted research assistant. Given a dictionary, can you count the number of words in the dictionary that appear as a substring in the professor's string at least once, in either their scrambled or original forms.

#### Input
The first line of the input gives the number of test cases, `T`. `T` test cases follow. Each testcase contains three lines. The first line contains an integer `L`. The second line contains a list of `L` words made of lowercase English letters; these make up the dictionary. The third line contains two lowercase English letters `S1` and `S2`, and five integers `N`, `A`, `B`, `C` and `D`. `S1` and `S2` are the first two characters of the professor's string `S`, `N` is the length of `S`, and the other four integers are parameters that you should use to generate the characters of `S`, as follows:

First we define `ord(c)` as the decimal value of a character `c` and `char(n)` as the character value of a decimal `n`. For example, `ord('a') = 97` and `char(97) = 'a'`. You can refer to ASCII table for other conversions.

Now, define `x1 = ord(S1)`, `x2 = ord(S2)`. Then, use the recurrence below to generate `xi` for `i = 3 to N`:

`xi = ( A * xi-1 + B * xi-2 + C ) modulo D`.
We define `Si = char(97 + ( xi modulo 26 ))`, for all `i = 3 to N`.

#### Output
For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the number of words from the dictionary that appear (in their original or scrambled forms, as defined above) as substrings of the given string.

#### Limits
* `1 ≤ T ≤ 20`.
* Memory limit: 1 GB.
No two words in the dictionary are the same.
Each word in the dictionary is between 2 and 10^5 letters long, inclusive.
The sum of lengths of all words in the dictionary does not exceed 10^5.
`S1` and `S2` are lowercase English letters.
* `0 ≤ A ≤ 10^9`.
* `0 ≤ B ≤ 10^9`.
* `0 ≤ C ≤ 10^9`.
* `1 ≤ D ≤ 10^9`.
* Small dataset (Test set 1 - Visible)
  - Time limit: 20 seconds.
  - `1 ≤ L ≤ 1000`.
  - `2 ≤ N ≤ 1000`.
* Large dataset (Test set 2 - Hidden)
  - Time limit: 150 seconds.
  - `1 ≤ L ≤ 20000`.
  - `2 ≤ N ≤ 10^6`.

For further information, visit [Round A](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edf).