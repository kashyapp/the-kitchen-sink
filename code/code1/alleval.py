#!/usr/bin/env python
import re
def alleval(s):
    foo = re.findall('\d+|\+|\-', s)
    bazinga(foo)

def goose(lst, pivot):
    bar = []
    for i in range(0, len(lst)):
        if (abs(pivot - i) > 1):
            bar.append(lst[i])
        elif (pivot == i):
            mult = 1 if lst[pivot] == '+' else -1
            bar.append(int(lst[pivot-1]) + mult * int(lst[pivot+1]))
    bazinga(bar)

response = set()
   
def bazinga(lst):
    if (len(lst) == 1):
        response.add(lst[0])
    else:
        for i in range(0, len(lst)/2):
            goose(lst, 2*i+1)


alleval("1 - 112 + 23 - 14 -5")
print response
