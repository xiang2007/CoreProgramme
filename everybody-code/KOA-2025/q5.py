data = "ABCCBAcCaaaBaAcBbccCBaacaACbBBCAbCcABCaaBAbaaCCCCcaAcaCAcbccACbBCbCCabaCbCCaaACccbbCBabbCCCAbAbbaCCCcaaabABBCbcCCbaAaBaCaAaacACCaabBbCABbAABAcBcCaBaaCBAcbbbBAcababcAacABBAbACACAACAcCAaAaCAcACaBBBAcbccCbAaAAAbAbaBaABbCBbBbabBCabCacaBaABaaaCAcAcCCBAbbAaBbcaACbcbabcCAcAbcbbCaACACCcCbBCbccCCbBACbacAbaAB"
res = 0
def count(alpha):
	out = 0
	l_a = alpha.lower()
	for i in range(len(data)):
		if data[i] == alpha:
			for j in range(len(data) - i):
				if data[i + j] == l_a:
					out = out + 1
	return out

res = res + count('A')
res = res + count('B')
res = res + count('C')
print(res)
