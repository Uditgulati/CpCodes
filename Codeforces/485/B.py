import math

x, y = raw_input().split()

x = float(x)
y = float(y)

a1 = float(math.log(x))

b1 = float(math.log(y))

num1 = float(y * a1)
num2 = float(x * b1)

if x == y or math.fabs(num1 - num2) < 0.0000001:
	print('=')
elif num1 < num2:
	print('<')
else:
	print('>')