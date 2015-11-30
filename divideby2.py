import sys

class Stack:
	def __init__(self):
		self.items = []
	
	def push(self, item):
		self.items.append(item)

	def pop(self):
		return self.items.pop()

	def peek(self):
		return self.items[len(self.items)-1]

	def size(self):
		return len(self.items)
        
	def isEmpty(self):
		return self.items == []

def divideby2(number):
	remstack = Stack()
      
	while number > 0:
		rem = number % 2
		remstack.push(rem)
		number = number//2

	binary = ""
	while not remstack.isEmpty():
		binary = binary+str(remstack.pop())
         
        return binary


print divideby2(239)
