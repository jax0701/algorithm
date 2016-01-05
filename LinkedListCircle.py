class Node:
    def __init__(self,initdata):
        self.data = initdata
        self.nextdata = None

    def getData(self):
        return self.data

    def getNext(self):
        return self.nextdata

    def setData(self,newdata):
        self.data = newdata

    def setNext(self,newnext):
        self.nextdata = newnext

class UnorderedList:
    def __init__(self):
        self.head = None

    def isEmpty(self):
        return self.head == None

    def add(self,item):
        temp = Node(item)
        temp.setNext(self.head)
        self.head = temp

    def size(self):
        current = self.head
        count = 0
        while current != None:
            count = count + 1
            current = current.getNext()
        
        return count

    def search(self,item):
        current = self.head
        found = False
        
        while current != None and not found:
            if current.getData() == item:
                found = True
            else:
                current = current.getNext()
        
        return found

    def remove(self,item):
        current = self.head
        previous = None
        found = False
        while not found:
            if current.getData() == item:
                found = True
            else:
                previous = current
                current = current.getNext()

        if previous == None:
            self.head = current.getNext()
        else:
            previous.setNext(current.getNext())

    def hasCycle(self):
        slow = fast = self.head
        
        while fast and fast.getNext():
            fast = fast.getNext().getNext()
            slow = slow.getNext()
            if slow.getData() == fast.getData():
               return True
        return False
        
if __name__ == '__main__':
    mylist = UnorderedList()
    mylist.add(3)
    mylist.add(6)
    mylist.add(1)
    mylist.add(3)
    mylist.add(6) 
    mylist.add(0)
    mylist.add(2)
    
    print mylist.hasCycle()
      
