from collections import defaultdict

class Graph(object):
    """Undirected graph class, internally implemented as an adjacency list.""" 
    
    def __init__(self, n: int) -> None:
        """Class constructor."""
        self.n = n
        self.adj = defaultdict(set)
        
    def connect(self, a: int, b: int) -> None:
        """Create connection from a to b (and from b to a) as this is an undirected graph."""
        self.adj[a].add(b)
        self.adj[b].add(a)
    
    def find_all_distances(self, s: int) -> List[int]:
        """Compute distances from s node to the rest of the nodes in this graph."""
        
        distances = [float("inf") for _ in range(n)]
        explored = [False for _ in range(n)]
        
        distances[s] = 0
        current = s
        
        while True:
            for to in self.adj[current]:
                if explored[to]:
                    continue
                if distances[current] + 6 < distances[to]:
                    distances[to] = distances[current] + 6
            explored[current] = True
            
            available = [new for new in range(n) if not explored[new]]
            if len(available) == 0:
                break
            current = min(available, key=lambda new: distances[new])
        
        return [
            (distance if distance != float("inf") else -1) 
            for current, distance in enumerate(distances) 
            if current != s
        ]
        

        
t = int(input())
for i in range(t):
    n,m = [int(value) for value in input().split()]
    graph = Graph(n)
    for i in range(m):
        x,y = [int(x) for x in input().split()]
        graph.connect(x-1,y-1) 
    s = int(input())
    ans = graph.find_all_distances(s-1)
    print(" ".join(map(str, ans)))

