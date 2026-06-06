#introduction.py
#here we will look at the basic introduction to the python loops 

#while else loop 
#else part will be executed if  while was not exited by break 
count = 0
while(count < 10):
	print(count)
	count +=1
else:
	print("THE LOOP WAS EXITED AFTER THE COUNT REACHED  MAX LIMIT ") 

#in the above part the else part will be printed 

#now lets break the loop and then observe what happens 

count1 = 0 
while(count1 <10):
	if(count1 == 4):
		break
	else:
		print(count1)
		count1 +=1 
else:
	print("THE LOOP WAS EXITED AFTER THE COUNT REACHED THE MAX LIMIT")

#HERE THIS STATEMENT IS NOT PRINTED , BECAUSE THE WHILE LOOP WAS EXITED AFTER A BREAK STATEMENT 


#Other categories 
#break -> jumps out of the closest loop 
#continue -> moves onto the next iteration 
#pass ->does nothing at all 
def func():
	pass

def func1():
	...

#they have the same role  ... (ellipsis) is also used as a pass statement 

#NAMED ASSIGNMENT 
#:= stands for the named asignment  here we assign a name to the expression 

'''
num  = 1 
while (tool := input(f"{num}) ENTER YOU PREFERRED CODING LANGUAGE :: ")) != 'stop':  #here whatever input you give , the tool variabel takes it and then compares it with 'stop'
	if(tool.lower() == 'python'):
		print("BRAVO !!")
		break
	else:
		print("try again")
'''
num = int(input("ENTER THE NUMBER YOU WANT TO FIND WHETHER IT IS PRIME OR NOT ::  "))
x = num//2 
while( x>1 ):
	if num%x  == 0:
		print(f" {x}  is  a factor of {num}")
		break
	x -=1
else:
	print("THE NUMBER IS PRIME ") 


#hereif the number is not a prime number then the while loop wont be broken by break statement, and then the else loop will be executed 
#but if the factor is found then the else block will not be executed  

#NOW LETS TALK ABOUT THE ZIP FUNCTION 
l1 = [23,34,45]
l2 = [24,35.46]

#here 45 wont be mapped to anything , every element will be mapped to other element if and only if they have the same length 

print(list(zip(l1,l2)))


l3 = [24,35,46]

print(list(zip(l1,l3)))


for (x,y) in zip(l1,l3):
	print(x+y)


