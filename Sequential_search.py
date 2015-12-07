def sequentialSearch(alist, item):
    pos = 0
    found = False
    
    while pos<len(alist) and not found:
        if alist[pos] == item:
            found = True
        else:
            pos = pos + 1
            
    return found

testlist = [2,34,76,1,32,53,57,43,2,34,32]
print(sequentialSearch(testlist, 34))
print(sequentialSearch(testlist, 50))