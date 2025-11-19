class node:
	def __init__(self, data):
		self.left = None
		self.right = None
		self.bottom = None
		self.up = None
		self.val = data

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

def add_node(root, value):
	curr = root
	while True:
		if value < curr.val:
			if curr.left is None:
				curr.left = add_left(curr, value)
				break
		if value > curr.val:
			if curr.right is None:
				curr.right = add_right(curr, value)
				break


for i in range(1, len(x)):
	curr = head
	while curr is not None:
		if (curr.val < x[i] and curr.left_val != None):
			curr = add_left(curr, x[i])
			break
		elif (curr.val > x[i] and curr.right_val != None):
			curr = add_right(curr, x[i])
			break
		curr = add_down(curr , x[i])
		curr = curr.bottom

while head.bottom != None:
	print(head.val)
	head = head.bottom

