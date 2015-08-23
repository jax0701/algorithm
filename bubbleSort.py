def bubbleSort(alist):
    for  passnum in range(len(alist)-1,0,-1):
        for i in range(passnum):
            if alist[i]>alist[i+1]:
                temp = alist[i]
                alist[i]=alist[i+1]
                alist[i+1]=temp

alist=[1,24,5,7,91,23,11,100,8]
bubbleSort(alist)
print(alist)
