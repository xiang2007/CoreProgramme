size = int(input("> "))
board = [0 for _ in range(size)]

def print_solution(board):
	print(board)

def is_valid(row, col):
	for i in range(0, col):
		if board[i] == row or  abs(board[i] - row) == abs(i - col):
			return 0
	return 1

def solve(col):
	if col == size:
		print_solution(board)
		return
	for row in range(size):
		if (is_valid(row, col)):
			board[col] = row;
			solve(col + 1)

if __name__ == "__main__":
	solve(0)