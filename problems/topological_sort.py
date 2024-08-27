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
    if pairs == []:
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
        if node in cycle:
            return False
        if node in visited:
            return True
        if node in adjList:
            cycle.add(node)
            for depend in adjList[node]:
                if dfs(depend) == False:
                    return False
            cycle.remove(node)
        visited.add(node)
        output.append(node)
        return True
        
    for main in adjList:
        if dfs(main) == False:
            return 'There was a cycle or otherwise impossible'
    return output[::-1]


def main():
    # input = read_input()
    # print(topsort(input))
    pairs = [(4,3),(5,3),(6,3),(5,7),(6,7)]
    print(topsort(pairs))


if __name__ == "__main__":
    """ This is executed when run from the command line """
    main()
