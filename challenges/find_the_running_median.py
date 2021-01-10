#!/bin/python3

import os
import sys

from typing import List
from math import ceil

class OrderedList(object):
    
    def __init__(self):
        self.data = list()
        
    def append(self, value: int) -> None:
        left, right = 0, self.n
        while left < right:
            mid = (left + right) // 2
            if self.data[mid] < value:
                left = mid + 1
            else:
                right = mid
        self.data.insert(left, value)
    
    def median(self) -> float:
        if self.n % 2 == 1:
            return round(self.data[self.n // 2], 1)
        return round((self.data[self.n // 2 - 1] + self.data[self.n // 2]) / 2, 1)
        
    @property
    def n(self) -> int:
        return len(self.data)


#
# Complete the runningMedian function below.
#
def runningMedian(a: List[int]) -> List[int]:
    #
    # Write your code here.
    #
    data = OrderedList()
    ans = list()
    for num in a:
        data.append(num)
        median = data.median()
        ans.append(median)        
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a_count = int(input())

    a = []

    for _ in range(a_count):
        a_item = int(input())
        a.append(a_item)

    result = runningMedian(a)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

