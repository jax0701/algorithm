from queue import Queue

def hotPotato(namelist, num):
	simqueue = Queue()
	for name in namelist:
		simqueue.enqueue(name)
        
	while len(simqueue.items)>1:
		for n in range(num):
			if n < (num-1):
				item = simqueue.dequeue()
		        	simqueue.enqueue(item)
			else:
				simqueue.dequeue()

        print simqueue.items

namelist = ['Jax', 'Brain', 'Edgar', 'James', 'Eddie', 'David', 'Joe', 'Victor', 'Paul', 'Alice', 'Jinah', 'Ryan', 'Jason', 'Nolla', 'Olivia', 'Austin', 'Chelsy']

hotPotato(namelist,7)
