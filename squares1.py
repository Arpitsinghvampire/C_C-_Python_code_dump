#squares1.py

from squares import Squares

for i in Squares(1,5):
	print(i , end = " ")

X = Squares(1,5)
I = iter(X)
print(next(I))
print(next(I))
print(next(I))
print(next(I))