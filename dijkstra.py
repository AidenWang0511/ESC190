import numpy as np
class Node:
    def __init__(self, value):
        self.value = value
        self.connections = []
        self.distance_from_start = np.inf

class Con:
    def __init__(self, node, weight):
        self.node = node
        self.weight = weight

def dijkstra(start, end):
    start.distance_from_start = 0
    visited = set([start])
    current = start
    while current != end:
        
        cur_dist = np.inf
        cur_v = None
        for node in visited:
            for con in node.connections:
                if con.node in visited:
                    continue
                if cur_dist > node.distance_from_start + con.weight:
                    cur_dist = node.distance_from_start + con.weight
                    cur_v = con.node
    
        current = cur_v
        current.distance_from_start = cur_dist
        visited.add(current)
    return current.distance_from_start
                                                
if __name__ == '__main__':
    nodes = []
    for i in range(5):
        nodes.append(Node(i))
    
    nodes[0].connections.append(Con(nodes[1], 5))
    nodes[0].connections.append(Con(nodes[2], 5))
    nodes[0].connections.append(Con(nodes[3], 5))
    nodes[0].connections.append(Con(nodes[4], 1000))
    nodes[1].connections.append(Con(nodes[2], 25))
    nodes[1].connections.append(Con(nodes[3], 20))
    nodes[2].connections.append(Con(nodes[3], 0))
    nodes[3].connections.append(Con(nodes[4], 10))

    print(dijkstra(nodes[0], nodes[4]))