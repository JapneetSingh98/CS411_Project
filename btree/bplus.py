"""Simple implementation of a B+ tree, a self-balancing tree data structure that (1) maintains sort
data order and (2) allows insertions and access in logarithmic time.
"""




import csv
import sys

class Node(object):
    """Base node object.
    Each node stores keys and values. Keys are not unique to each value, and as such values are
    stored as a list under each key.
    Attributes:
        order (int): The maximum number of keys each node can hold.
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
        """Adds a key-value pair to the node."""
        # If the node is empty, simply insert the key-value pair.
        if not self.keys:
            self.keys.append(key)
            self.values.append([value])
            return None

        for i, item in enumerate(self.keys):
            # If new key matches existing key, add to list of values.
            if key == item:
                self.values[i].append(value)
                break

            # If new key is smaller than existing key, insert new key to the left of existing key.
            elif key < item:
                self.keys = self.keys[:i] + [key] + self.keys[i:]
                self.values = self.values[:i] + [[value]] + self.values[i:]
                break

            # If new key is larger than all existing keys, insert new key to the right of all
            # existing keys.
            elif i + 1 == len(self.keys):
                self.keys.append(key)
                self.values.append([value])

    def split(self):
        """Splits the node into two and stores them as child nodes."""
        left = Node(self.order)
        right = Node(self.order)
        mid = self.order // 2

        right.keys = self.keys[mid:]
        right.values = self.values[mid:]
        right.next = left.next

        left.keys = self.keys[:mid]
        left.values = self.values[:mid]
        left.next = right

        # When the node is split, set the parent key to the left-most key of the left child node.
        self.keys = [left.keys[0]]
        self.values = [left, right]
        self.leaf = False

    def is_full(self):
        """Returns True if the node is full."""
        return len(self.keys) == self.order

    def show(self, counter=0):
        """Prints the keys at each level."""
        print(counter, str(self.keys))

        # Recursively print the key of child nodes (if these exist).
        if not self.leaf:
            for item in self.values:
                item.show(counter + 1)

class BPlusTree(object):
    """B+ tree object, consisting of nodes.
    Nodes will automatically be split into two once it is full. When a split occurs, a key will
    'float' upwards and be inserted into the parent node to act as a pivot.
    Attributes:
        order (int): The maximum number of keys each node can hold.
    """
    def __init__(self, order=4):
        self.root = Node(order)
        # self.leaves = []

    def _find(self, node, term):
        """ For a given node and key, returns the index where the key should be inserted and the
        list of values at that index."""
        for i, key in enumerate(node.keys):
            if term < key:
                return node.values[i], i

        return node.values[i + 1], i + 1

    def _merge(self, parent, child, index):
        """For a parent and child node, extract a pivot from the child to be inserted into the keys
        of the parent. Insert the values from the child into the values of the parent.
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
        """Inserts a key-value pair after traversing to a leaf node. If the leaf node is full, split
        the leaf node into two.
        """
        parent = None
        child = self.root

        # Traverse tree until leaf node is reached.
        while not child.leaf:
            parent = child
            child, index = self._find(child, key)

        child.add(key, value)
        # self.leaves.append(child)
        # If the leaf node is full, split the leaf node into two.
        if child.is_full():
            child.split()

            # Once a leaf node is split, it consists of a internal node and two leaf nodes. These
            # need to be re-inserted back into the tree.
            if parent and not parent.is_full():
                self._merge(parent, child, index)

    def retrieve(self, term):
        """Returns a value for a given key, and None if the key does not exist."""
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
        """Prints the keys at each level."""
        self.root.show()

def demo_node():
    #print('Initializing node...')
    node = Node(order=4)



def demo_bplustree(term):
    #print('Initializing B+ tree...')
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
    demo_node()
    #print('\n')
    #searchTerm = input()
    result = demo_bplustree(searchTerm)
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
