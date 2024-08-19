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


class Node: 
    def __init__(self, value):
        self.value = value;
        self.parent = None;
        self.children = [];

    def addChild(self, child):
        self.children.append(child)

    def removeChild(self, removedChild):
        tmp = self.children 
        self.children = []
        for child in tmp:
            if child == removedChild:
                continue
            self.children.append(child)

    def setParent(self, parent):
        self.parent = parent;
        
def dfs(node, target):
    if not node:
        return False
    elif node == target:
        return True
    for child in node.children:
        return dfs(child, target)

def work_ordering(pairs: list[tuple[int, int]]) -> list[int]:
    madeNodes = {}
    usedAsMain = set()
    for pair in pairs:
        if pair[1] in madeNodes:
            dependent = madeNodes[pair[1]]
        else:
            dependent = Node(pair[1])
            madeNodes[pair[1]] = dependent

        if pair[0] in madeNodes:
            main = madeNodes[pair[0]]
            if main.value in usedAsMain:
                if dfs(main.parent, dependent.value):
                    main.parent.removeChild(main)
                else:
                    continue
        else:
            main = Node(pair[0])
            madeNodes[pair[0]] = main
            usedAsMain.add(main.value)

        main.setParent(dependent)
        dependent.addChild(main)

    root = dependent
    while root.parent != None:
        root = root.parent

 # Do I need to see if there is a cycle
    res = [] 
    myList = deque([root])
    while myList:
        num = myList.pop()
        for child in num.children:
            myList.append(child)
        res.append(num.value)

    res = res[::-1]
    formattedRes = ''
    
    for i in res:
       formattedRes = formattedRes + ' ' + str(i)
    return formattedRes
        
def main():
    input = read_input()
    print(' '.join(work_ordering(input)))


if __name__ == "__main__":
    """ This is executed when run from the command line """
    main()
