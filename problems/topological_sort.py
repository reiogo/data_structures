import sys
from collections import deque

def read_input():
    pairs = []
    for line in sys.stdin:
        if line.rstrip() == 'q':
            break
        pair = tuple((int(token) for token in line.split(' ')))
        pairs.append(pair)
    return pairs


def topsort(pairs):
    if not pairs:
        return 'empty list'
# Create adjacency list.
    adjList = {}
    for pair in pairs:
        if pair[0] not in adjList:
            adjList[pair[0]] = [pair[1]]
        else:
            tmpList = adjList[pair[0]]
            if pair[1] not in tmpList:
                tmpList.append(pair[1])
                adjList[pair[0]] = tmpList
# Take the adjList and run a dfs on it.
    output = []
    visited, cycle = set(), set()
    def dfs(node):
        if node not in visited:
            if node not in adjList:
                return True
            if node in cycle:
                return False
            cycle.add(node)
            for depend in range(adjList[node]):
                if not dfs(depend):
                    return False
            cycle.remove(node)
            visited.add(node)
            output.append(node)
            return True
        
    for node in adjList:
        if not dfs(node):
            return 'failure'
        else:
            return output


def main():
    input = read_input()
    print(topsort(input))


if __name__ == "__main__":
    """ This is executed when run from the command line """
    main()
