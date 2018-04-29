import math

t = int(input())

for i in range(t):
	a = float(input())
	sq = float(math.sqrt(2.000000))
	a1 = a / sq
	ang = math.acos(a1)
	ff = math.pi / 4.000000
	ang1 = ff - ang
	b1 = 0.500000 * math.cos(ang1)
	p1 = 0.500000 * math.sin(ang1)
	if b1 < 0.0000001:
		b1 = 0.00
	if p1 < 0.0000001:
		p1 = 0.00
	print("Case #{}:".format(i+1))
	print("{} {} 0.0".format(b1, p1))
	print("{} {} 0.0".format(-p1, b1))
	print("0.0 0.0 0.5")