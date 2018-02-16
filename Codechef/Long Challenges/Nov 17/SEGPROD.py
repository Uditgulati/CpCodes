def inv(a, modu):
	m0, x0, x1 = modu, 0, 1
	temp, q = 0, 0
	while a > 1:
		q = a // modu
		temp = modu
		modu, a = a % modu, temp
		temp = x0
		x0 = x1 - (q * x0)
		x1 = temp
	if x1 < 0:
		x1 += m0
	return x1


t = int(raw_input())
check = [0] * 1000010
prime = []
for i in xrange(2, 1000010):
	if check[i] == 0:
		j = i * i
		while j < 1000010:
			check[j] = 1
			j = j + i
for i in xrange(2, 1000010):
	if check[i] == 0:
		prime.append(i)

while t:
	n, p, q = map(int, raw_input().split(" "))
	arr = map(int, raw_input().split(" "))
	# l = (q // 64) + 2
	ans, p1 = 0, p
	arr2 = map(int, raw_input().split(" "))
	prod1, prod2, factors = [], [], [];
	for x in prime:
		count, val = 0, x
		while p1 % val == 0:
			count = 1
			p1 = p1 // val
		if count:
			factors.append(val)
	if p1 != 1:
		factors.append(p1)
	len1 = len(factors)
	store = [[] for _ in xrange(len1)]
	power = [[] for _ in xrange(len1)]
	tot = [0] * len1
	for i in xrange(n):
		if arr[i] == 0:
			for j in xrange(len1):
				store[j].append(tot[j])
			continue
		for j in xrange(len1):
			count, val = 0, factors[j]
			while arr[i] % val == 0:
				count = count + 1
				arr[i] = arr[i] // val
			tot[j] = tot[j] + count
			store[j].append(tot[j])
	for i in xrange(len1):
		lim = store[i][n - 1]
		val, base = 1, factors[i]
		power[i].append(val)
		for j in xrange(lim + 1):
			val = (val * base) % p
			power[i].append(val)
	x, curr = 1, 1
	x1 = inv(x, p)
	for i in xrange(n):
		curr = arr[i]
		if curr == 0 or curr == 1:
			prod1.append(x)
			prod2.append(x1)
			continue
		x = (x * curr) % p
		x1 = inv(x, p)
		prod1.append(x)
		prod2.append(x1)
	for i in xrange(q):
		if i % 64:
			l = (l + ans) % n
			r = (r + ans) % n
		else:
			ind = i // 64
			l = (arr2[ind] + ans) % n
			r = (arr2[ind + 1] + ans) % n
		if l > r:
			l, r = r, l
		ans = prod1[r]
		if l:
			ans = (ans * prod2[l - 1]) % p
		for i in xrange(len1):
			num = store[i][r]
			if l:
				num = num - store[i][l - 1]
			if num == 0:
				continue
			ans = (ans * power[i][num]) % p
		ans = ans + 1
		if ans == p:
			ans = 0
	print ans
	t -= 1