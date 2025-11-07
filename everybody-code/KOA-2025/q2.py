# A1 = 155
# A2 = 53
# R1 = 0
# R2 = 0
# x = 0
# y = 0

# for i in range(3):
# 	x = (R1 * R1) - (R2 * R2)
# 	y = (R1 * R2) + (R1 * R2)
# 	x = x // 10
# 	y = y // 10
# 	x = A1 + x
# 	y = A2 + y
# 	R1 = x
# 	R2 = y
# print ([R1,R2])

# ax = 35300
# ay = -64910

# for i in range(101):
# 		ax += 10
# 		r1 = 0
# 		r2 = 0
# 		for i in range(101):
# 			ax += 10
# 			for i in range(100):
# 				x = (r1 * r2) - (r2 * r2)
# 				y = (r1 * r2) + (r1 * r2)
# 				x = x // 100000
# 				y = y // 100000
# 				x = ax + x
# 				y = ay + y
# 				r1 = x
# 				r2 = y
# 				if ((r1 > 100000) or (r2 < -100000)):
# 					break
# 				engrave += 1
# 				print("cycle =", cycle, [r1, r2])
# 		print(engrave)
ax = -79077
ay = 14068
tx = ax
ty = ay
cycle = 0
engrave = 0
for i in range(1001):
	ax = tx
	for i in range(1001):
		r1 = 0
		r2 = 0
		inside = True

		for i in range(100):
			x = (r1 * r1) - (r2 * r2)
			y = (r1 * r2) + (r1 * r2)
			x = int(x / 100000)
			y = int(y / 100000)
			x = ax + x
			y = ay + y
			r1 = x
			r2 = y

			if abs(r1) > 1000000 or abs(r2) > 1000000:
				inside = False
				break

		if inside:
			engrave += 1
		ax += 1
	ay += 1
print("engrave is", engrave)