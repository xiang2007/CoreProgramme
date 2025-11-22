class node:
	def __init__(self, data):
		self.left = None
		self.right = None
		self.bottom = None
		self.up = None
		self.val = data

data = """1:7,1,9,1,6,9,8,3,7,2
2:6,1,9,2,9,8,8,4,3,1
3:7,1,9,1,6,9,8,3,8,3
4:6,1,9,2,8,8,8,4,3,1
5:7,1,9,1,6,9,8,3,7,3
6:6,1,9,2,8,8,8,4,3,5
7:3,7,2,2,7,4,4,6,3,1
8:3,7,2,2,7,4,4,6,3,7
9:3,7,2,2,7,4,1,6,3,7"""

lines = data.strip().splitlines()
arrays = []
for line in lines:
	_, values = line.split(':', 1)
	arrays.append([int(n) for n in values.split(",")])

def	add_down(node1, value):
	new_node = node(value)
	new_node.up = node1
	node1.bottom = new_node
	return new_node

def add_node(root, value):
	curr = root
	while True:
		if value < curr.val:
			if curr.left is None:
				curr.left = value
				break
		elif value > curr.val:
			if curr.right is None:
				curr.right = value
				break
		if curr.bottom is None:
			new_node = node(value)
			new_node.up = curr
			curr.bottom = new_node
			break
		else:
			curr = curr.bottom

res = []

for i in range(len(arrays)):
	head = node(arrays[i][0])
	for j in range(1, len(arrays[i])):
		add_node(head, arrays[i][j])
	num = 0
	curr = head
	while curr:
		num = num * 10
		num = num + curr.val
		curr = curr.bottom
	res.append(num)

print(max(res) - min(res))
