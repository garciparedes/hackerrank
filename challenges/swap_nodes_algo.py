#!/bin/python3

import os
import sys

from typing import List


class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    @staticmethod
    def from_indexes(indexes: List[List[int]]) -> "TreeNode":
        nodes = [TreeNode(i + 1) for i in range(len(indexes))]
        has_parents = [False for _ in range(len(indexes))]
        
        for (value, childs) in enumerate(indexes):
            left, right = childs
            
            if left != -1:
                nodes[value].left = nodes[left - 1]
                has_parents[left - 1] = True
            
            if right != -1:
                nodes[value].right = nodes[right - 1] 
                has_parents[right - 1] = True
                
        parent_idx = next(i for i, cond in enumerate(has_parents) if not cond)
        return nodes[parent_idx]
    
        
    def modular_swap(self, k: int, depth: int = 1) -> None:
        if depth % k == 0:
            self.left, self.right = self.right, self.left
        
        if self.left is not None:
            self.left.modular_swap(k, depth + 1)
    
        if self.right is not None:
            self.right.modular_swap(k, depth + 1)
            
    @property
    def inorder_values(self) -> List[str]:
        ans = list()
        if self.left is not None:
            ans += self.left.inorder_values
        ans += [self.value]
        if self.right is not None:
            ans += self.right.inorder_values
        return ans


#
# Complete the swapNodes function below.
#
def swapNodes(indexes: List[List[int]], queries: List[int]) -> List[str]:
    #
    # Write your code here.
    #
    tree = TreeNode.from_indexes(indexes)
    
    ans = list()
    for k in queries:
        tree.modular_swap(k)
        values = tree.inorder_values
        ans.append(values)
        
    return ans
    
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())
    sys.setrecursionlimit(2 * n)

    indexes = []

    for _ in range(n):
        indexes.append(list(map(int, input().rstrip().split())))


    queries_count = int(input())

    queries = []

    for _ in range(queries_count):
        queries_item = int(input())
        queries.append(queries_item)

    result = swapNodes(indexes, queries)

    fptr.write('\n'.join([' '.join(map(str, x)) for x in result]))
    fptr.write('\n')

    fptr.close()

