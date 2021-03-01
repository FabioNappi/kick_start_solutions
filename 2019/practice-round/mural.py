import sys
from math import ceil

def total_beauty(N, b_values):

	# the number of paintable sectors is the upper integer half
	window_size = ceil(N / 2)

	# the paintable sectors are contiguous so we build a moving window over the wall
	window = b_values[0:window_size]
	max_beauty = sum(window)

	# each iteration the window moves of one sector to the right
	for i in range(window_size, len(b_values)):
		window.pop(0)
		window.append(b_values[i])

		# if the beauty is greater to the max, it becomes the new max
		temp_beauty = sum(window)
		if temp_beauty > max_beauty:
			max_beauty = temp_beauty

	return max_beauty

# read the numebr of test cases
T = int(sys.stdin.readline())
result = ''
for i in range(T):

	# read the values of the test case
	N = int(sys.stdin.readline())
	beauties = list(sys.stdin.readline().rstrip('\n'))
	b_values = [int(value) for value in beauties]
	
	# compute the maximum reachable beauty
	x = i + 1
	y = total_beauty(N, b_values)
	result += f'Case #{x}: {y}\n'

print(result)
