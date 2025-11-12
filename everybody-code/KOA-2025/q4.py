class node:
	def __init__(self, data):
		self.prev = None
		self.data = data
		self.next = None
		self.bottom = None

x = [5,3,7,8,9,10,4,5,7,8,8]

head = node(x[0])
curr = None

# add node2 to left side of node1
def	add_left(node1, value):
	new_node = node(value)
	node1.left = new_node
	node1.prev = node(value)

# add node2 to right side of node1
def	add_right(node1, value):
	node1.next = node(value)

# add a new node below node1
def	add_down(node1, value):
	node1.bottom = node(value)

for i in range(len(x) - 1):
	curr = node[i]
	if (curr.data > x[i + 1]):
		add_left(curr, x[i])
	elif (curr.data < x[i + 1]):
		add_left(curr, x[i])

