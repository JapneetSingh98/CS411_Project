"""B+ Tree implementation with insert function and search retrieval. 
Source code:https://github.com/pschafhalter/python-b-plus-tree
Source code:https://www.programiz.com/dsa/b-plus-tree
https://github.com/ayushshivani/B-PLUS-TREE/blob/master/bplus.py
"""



import csv
import sys

class Node(object):
    """This is the base node object that stores keys and values. Since keys are not unique for each value, so that key will contain a list of values.
    Attributes:the max number of slots a node can have is order
    """
    def __init__(self, order):
        """Child nodes can be converted into parent nodes by setting self.leaf = False. Parent nodes
        simply act as a medium to traverse the tree."""
        self.order = order
        self.keys = []
        self.values = []
        self.leaf = True
        self.next = None

    def add(self, key, value):
        """Adds a key value pair to the node."""
        #If empty node just add the key and the value
        if not self.keys:
            self.keys.append(key)
            self.values.append([value])
            return None

        for i, item in enumerate(self.keys):
            # If key match prev key, make val list.
            if key == item:
                self.values[i].append(value)
                break

            # smaller means left insertion else insert to right.
            elif key < item:
                self.keys = self.keys[:i] + [key] + self.keys[i:]
                self.values = self.values[:i] + [[value]] + self.values[i:]
                break

            # right insertion
            elif i + 1 == len(self.keys):
                self.keys.append(key)
                self.values.append([value])

    def split(self):
        """Splits the node into two and stores them as child nodes."""
        left = Node(self.order)
        right = Node(self.order)
        middle = self.order // 2

        right.keys = self.keys[middle:]
        right.values = self.values[middle:]
        right.next = left.next

        left.keys = self.keys[:middle]
        left.values = self.values[:middle]
        left.next = right
        
        self.keys = [left.keys[0]]
        self.values = [left, right]
        self.leaf = False

    def is_full(self):
        """Returns True if full."""
        return len(self.keys) == self.order

    def show(self, counter=0):
        """Prints the keys at each level."""
        print(counter, str(self.keys))

        if not self.leaf:
            for item in self.values:
                item.show(counter + 1)

class BPlusTree(object):
    """B+ tree object, consists of nodes. Contains functions like find, merge, and search
    Attribute: order
    """
    def __init__(self, order=4):
        self.root = Node(order)
        # self.leaves = []

    def _find(self, node, term):
        """ Based on node and term, returns value"""
        for i, key in enumerate(node.keys):
            if term < key:
                return node.values[i], i

        return node.values[i + 1], i + 1

    def _merge(self, parent, child, index):
        """Extract pivot from node to merge, pop value of parent.
        """
        parent.values.pop(index)
        pivot = child.keys[0]

        for i, item in enumerate(parent.keys):
            if pivot < item:
                parent.keys = parent.keys[:i] + [pivot] + parent.keys[i:]
                parent.values = parent.values[:i] + child.values + parent.values[i:]
                break

            elif i + 1 == len(parent.keys):
                parent.keys += [pivot]
                parent.values += child.values
                break

    def insert(self, key, value):
        """Inserts a key and value pair after traversing
        """
        parent = None
        child = self.root

        # Traverse tree until leaf node is reached. 
        while not child.leaf:
            parent = child
            child, index = self._find(child, key)

        child.add(key, value)
        # self.leaves.append(child)
        # If the leaf is full, split.
        if child.is_full():
            child.split()

            # Once a leaf node is split, it must be added into tree again.
            if parent and not parent.is_full():
                self._merge(parent, child, index)

    def retrieve(self, term):
        """Returns a value for a provided key"""
        child = self.root
        while not child.leaf:
            child, index = self._find(child, term)

        found = False
        newdict = {}
        # for x in self.leaves:
            # child = self.root
            #go to next
        while child != None:
            for i, key in enumerate(child.keys):
                if key.startswith(term):
                    found = True
                    child.values[i] = str(child.values[i])[2:-1]
                    wholeRow = child.values[i].split("&&&")
                    val = int(wholeRow[0])
                    newdict[key]=val
                else:
                    if found:
                        return newdict
            child = child.next
        return newdict

    def show(self):
        """Prints keys at all levels"""
        self.root.show()

def runnode():
    node = Node(order=4)



def runbplustree(term):
    bplustree = BPlusTree(order=4)
    dict_recipes = {}

    with open('Recipes.csv','r') as csv_file: #Opens the file in read mode
        csv_reader = csv.reader(csv_file) # Making use of reader method for reading the file
        headers = True
        tmp = ""
        next(csv_reader)
        for row in csv_reader:
            #print(row[0])
            tmp = str(row[0]) + "&&&" + row[2] + "&&&" + str(row[3]) + "&&&"+  str(row[4]) + "&&&" + str(row[5])
            #concatenated = '&&&'.join(tmp)
            dict_recipes.update ( { str(row[1]) : str(tmp) } )
    for key in dict_recipes:
        val = dict_recipes[key]
        # print(key, '->', val)
        bplustree.insert(key, val)

    result = bplustree.retrieve(term)
    print result
    return result




if __name__ == '__main__':
    #main(sys.argv1)
    searchTerm = sys.argv[1]
    runnode()
    #print('\n')
    #searchTerm = input()
    result = runbplustree(searchTerm)
    counter = 0
    arr = ""
    for key in result:
        val = result[key]
        if counter == (len(result)- 1):
            arr += ("search=" + searchTerm + "&id=" + str(val) + "&name=" + key)
        else:
            arr += ("search=" + searchTerm + "&id=" + str(val) + "&name=" + key + "*")
        counter+=1
    print arr
