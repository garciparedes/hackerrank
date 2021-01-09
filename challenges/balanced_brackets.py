#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the isBalanced function below.
def isBalanced(s: str) -> str:
    stack = list()
    
    for c in s:
        if c == "{":
            stack.append("}")
        elif c == "[":
            stack.append("]")
        elif c == "(":
            stack.append(")")
        else:
            if len(stack) == 0 or c != stack.pop():
                return "NO"
    
    return "YES" if len(stack) == 0 else "NO"
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        s = input()

        result = isBalanced(s)

        fptr.write(result + '\n')

    fptr.close()

