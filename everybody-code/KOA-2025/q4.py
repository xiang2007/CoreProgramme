class node:
	def __init__(self, data):
		self.left_val = None
		self.right_val = None
		self.bottom = None
		self.up = None
		self.data = data

x = [5,3,7,8,9,10,4,5,7,8,8]

head = node(x[0])

def	add_left(node1, value):
	node1.left = value
	return node1

def	add_right(node1, value):
	node1.right = value
	return node1

def	add_down(node1, value):
	new_node = node(value)
	new_node.up = node1
	node1.bottom = new_node
	return new_node

for i in range(1, len(x)):
	curr = head
	placed = False
	while curr != None

print curr
