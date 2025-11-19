class node:
	def __init__(self, data):
		self.left = None
		self.right = None
		self.bottom = None
		self.up = None
		self.val = data

x = [2,6,5,9,6,9,7,3,2,3,3,7,8,6,1,5,5,3,7,3,1,1,8,4,4,8,3,7,6,9]

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


head = node(x[0])

for i in range(1, len(x)):
	add_node(head, x[i])

while head:
	print(head.val, end='')
	head = head.bottom

