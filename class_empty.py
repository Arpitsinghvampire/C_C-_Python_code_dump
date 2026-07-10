#class_empty.py

class Empty:
	def __getattr__(self  , attrname):
		if attrname == "age":
			return  40 
		else:
			raise AttributeError(attrname)

	def __setattr__(self , attr, value ):
		self.__dict__[attr] = value

X = Empty()
print(X.age)


Y =Empty()
Y.age = 90
print(Y.age)
Y.__setattr__("age" , 40)
print(Y.age)

Y.__setattr__("name" , "arpit")
print(Y.name)