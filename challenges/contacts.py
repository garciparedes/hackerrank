#!/bin/python3

import os
import sys

from typing import Dict, Any, Tuple, List
from collections import defaultdict


class RopeEntry(object):
    """Ropen Entry class."""
    
    def __init__(self):
        self.count = 0
        self.data = defaultdict(RopeEntry)

        
class Rope(object):
    """Rope class"""
    
    def __init__(self):
        self.data = RopeEntry()
        
    def store(self, word: str) -> None:
        """Store given word in the rope."""
        
        def _fn(cur: RopeEntry, chain: str) -> None:
            cur.count += 1
            
            if len(chain) == 0:
                return     
    
            _fn(cur.data[chain[0]], chain[1:])  
        
        _fn(self.data, word)
        
    def count_occurrences(self, word: str) -> int:
        """Count matched occurrences of the given word."""
       
        def _fn(cur: RopeEntry, chain: str) -> int:
            if cur.count == 0:
                return 0
            
            if len(chain) == 0:
                return cur.count
            
            return _fn(cur.data[chain[0]], chain[1:])
            
                
        return _fn(self.data, word)
            
        
def contacts(queries) -> List[int]:
    rope = Rope()
    
    ans = list()
    for query in queries:
        if query[0] == "add":
            rope.store(query[1])
        else:
            count = rope.count_occurrences(query[1])
            ans.append(count)
            
    return ans

    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    queries_rows = int(input())

    queries = []

    for _ in range(queries_rows):
        queries.append(input().rstrip().split())

    result = contacts(queries)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

