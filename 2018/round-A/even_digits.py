''' PROBLEM
Supervin has a unique calculator. This calculator only has a display, a plus button, and a minus button. Currently, the integer N is displayed on the calculator display.
Pressing the plus button increases the current number displayed on the calculator display by 1. Similarly, pressing the minus button decreases the current number displayed on the calculator display by 1. 
The calculator does not display any leading zeros. For example, if 100 is displayed on the calculator display, pressing the minus button once will cause the calculator to display 99.
Supervin does not like odd digits, because he thinks they are "odd". Therefore, he wants to display an integer with only even digits in its decimal representation, using only the calculator buttons. 
Since the calculator is a bit old and the buttons are hard to press, he wants to use a minimal number of button presses.
Please help Supervin to determine the minimum number of button presses to make the calculator display an integer with no odd digits.
'''

import sys

# digit is odd when called
def bounds(digit, digits_left):
	
	# complete the number with left digits. 
	# higher is wrong if digit is 9, anyway its value is ignored in that case 
	lower = str(digit - 1)
	higher = str(digit + 1)
	for _ in range(digits_left):
		lower = lower + '8'
		higher = higher + '0'
	return lower, higher

def compute_min_presses(N):
	result = ''
	digits_left = len(N)
	for character in N:
		digits_left -= 1
		digit = int(character)

		# if the digit is odd, then compute the higher and lower even
		if digit % 2 == 1:
			lower_part, higher_part = bounds(digit, digits_left)
			lower_even = int(result + lower_part)
			lower_diff = int(N) - lower_even

			# if the odd digit is 9, then the lower even is closer than the higher for sure
			if digit == 9:
				return lower_diff

			higher_even = int(result + higher_part)
			higher_diff = higher_even - int(N)

			# the minimum button presses reaches the closest even to N
			return min(lower_diff, higher_diff)

		# if this digit is even transcribe the digit to result
		else:
			result = result + character

	# if every digit is even, no button presses should be performed
	return 0
		

# read the numebr of test cases
T = int(sys.stdin.readline())
result = ''
for i in range(T):

	# read the value of the test case
	N = sys.stdin.readline().rstrip('\n')

	# compute minimum button presses
	x = i + 1
	y = compute_min_presses(N)
	result += f'Case #{x}: {y}\n'

print(result)
