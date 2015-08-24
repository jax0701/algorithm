def insertionSort(alist):
    for index in range(1, len(alist)):
        currentValue = alist[index]
        position = index

        while position>0 and alist[position-1]>currentValue:
            alist[position]=alist[position-1]
            position = position - 1

        alist[position]=currentValue

alist= [3,23,312,5,23,43,12,235]
insertionSort(alist)
print(alist)
