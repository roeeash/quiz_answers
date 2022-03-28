class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

    def insert(self, data):
        if self.data == data:
            return
        elif self.data > data and self.left is None:
            self.left = Node(data)

        elif self.data < data and self.right is None:
            self.right = Node(data)

        # both are not None and self.data != data
        else:
            if self.data > data:
                self.left.insert(data)
            else:
                self.right.insert(data)

    def print_tree(self):
        if self.left:
            self.left.print_tree()
        print(self.data)
        if self.right:
            self.right.print_tree()


    def search_tree(self, data):
        if self.data == data:
            return 1
        # if smaller and no left
        elif self.data > data and self.left is None:
            return 0
        # if bigger and no right
        elif self.data < data and self.right is None:
            return 0

        # both are not None and self.data != data
        else:
            if self.data > data:
                self.left.search_tree(data)
            else:
                self.right.search_tree(data)
