import sys
import math

# read the numebr of test cases
T = int(sys.stdin.readline())
for i in range(T):

	# read the valueS of the test case
	first_line = sys.stdin.readline().split()
	A, B = int(first_line[0]), int(first_line[1])
	N = int(sys.stdin.readline())

	# try at most N guesses
	for _ in range(N):

		# the guess will be the average, ceiled when float
		Q = math.ceil((lower + higher) / 2)
		print(Q, flush=True)

		# according to the response we modify the upper or lower bound
		response = sys.stdin.readline().rstrip('\n')
		if response == 'WRONG_ANSWER':
			exit()
		elif response == 'CORRECT':
			break
		elif response == 'TOO_BIG':
			B = Q
		elif response == 'TOO_SMALL':
			A = Q
			