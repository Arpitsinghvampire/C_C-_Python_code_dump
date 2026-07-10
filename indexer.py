#indexer.py

class Indexer:
	def __getitem__(self , index):
		return index**3

X = Indexer()
print(X[2])

for i in range(5):
	print(X[i])

