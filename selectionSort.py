def selectionSort(alist):
    for fillslot in range(len(alist)-1, 0, -1):
        positionOfMax = 0
        for location in range(1,fillslot+1):
            if alist[location]>alist[positionOfMax]:
                positionOfMax = location

        temp = alist[fillslot]
        alist[fillslot]=alist[positionOfMax]
        alist[positionOfMax]=temp

alist=[54,12,3,45,76,8,78,99,100,11]
selectionSort(alist)
print(alist)

