''' PROBLEM
You are participating in the Grand Kickstart Lucky Dip with many fantastic and amazing prizes (and some not so good ones)!
In this Lucky Dip, there is a bag with N items. The i-th item in the bag has value Vi. 
You will put your hand into the bag and draw one item at random; all items in the bag have an equal probability of being chosen. 
The organizers want contestants to feel that they have some element of choice, so after you draw an item, you can either keep it, or "redip" by returning it to the bag and drawing again. 
(Note that the returned item is now just as likely to be chosen as any of the other items in the bag.) 
You may only redip a maximum of K times. If you use K redips, you must keep the item that you draw on your (K + 1)-th draw.
If you play optimally to maximize the value of the item you will end the game with, what is the expected value of that item?
'''

import sys

def expected_value(N, K, V):

	# initialize the expected value with an unfeasible value
	expected_value = -1
	removed_items = 0

	# for each dip compute the newly found expected value
	for _ in range(K + 1):
		sum = 0
		index, f_index = 0, len(V)
		
		while index < f_index:
			
			# remove the items with value less than expected_value to reduce iterations
			if V[index] < expected_value:
				V.pop(index)
				removed_items += 1
				f_index -= 1

			# increment the sum with the value of the other items
			else:
				sum += V[index]
				index += 1

		# increment the sum of expected value for each item we have removed
		sum += expected_value * removed_items

		# compute the expected value of this dip
		expected_value = sum / N

	return expected_value


# read the numebr of test cases
T = int(sys.stdin.readline())
result = ''
for i in range(T):

	# read values of the test case
	first_line = sys.stdin.readline().split()
	second_line = sys.stdin.readline().split()
	N, K = int(first_line[0]), int(first_line[1])
	V = [int(item) for item in second_line]

	# compute the expected value
	x = i + 1
	y = expected_value(N, K, V)
	result += f'Case #{x}: {y}\n'
	
print(result)
