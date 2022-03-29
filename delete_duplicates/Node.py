class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

def insert(root, data):
        if root.data == data:
            return
        elif root.data > data and root.left is None:
            root.left = Node(data)

        elif root.data < data and root.right is None:
            root.right = Node(data)

        # both are not None and self.data != data
        else:
            if root.data > data:
                insert(root.left,data)
            else:
                insert(root.right,data)


def print_tree(root):
        if root.left:
            print_tree(root.left)
        print(root.data)
        if root.right:
            print_tree(root.right)

def search_tree(root, data):
        if root.data == data:
            return 1
        # if smaller and no left
        elif root.data > data and root.left is None:
            return 0
        # if bigger and no right
        elif root.data < data and root.right is None:
            return 0

        # both are not None and self.data != data
        else:
            if root.data > data:
                search_tree(root.left,data)
            else:
                search_tree(root.right.data)


def delete(root, value):
       #case 1: root is None
        if root is None:
            return root
        elif root.data < value:
            root.right = delete(root.right,value)
        elif root.data > value:
            root.left = delete(root.left,value)
        else:

            if root.right is None:
                return root.left
            elif root.left is None:
                return root.right
            else:
                next = find_successor(root)
                root.data = next.data
                root.right = delete(root.right,next.data)
            return root




def find_successor(root):
    if root is None:
        return None
    elif root.right is None:
        return None
    elif root.right is None and root.left is None:
        return root
    # leftmost node is right subtree
    else:
        next = root.right
        while next.left is not None:
            next = next.left
        return next





