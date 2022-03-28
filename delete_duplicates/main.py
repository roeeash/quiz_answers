import collections
import math
import os
from Node import *

def sort_by_hash(file_list):
    dictionary = {}
    array = []
    i = 0
    root_node = None
    for file in file_list:
        value = bin(hash(file))
        if i == 0:
            root_node = Node(value)
            dictionary[file] = value
        else:
            if root_node is not None:
                if root_node.search_tree(value) == 0:
                    root_node.insert(value)
                    dictionary[file] = value
        i += 1
    return root_node, dictionary


def get_list_from_path(folder_path):
    return os.system("ls %s", folder_path)


if __name__ == '__main__':
    path = input("insert path")
    list_of_files = ["ola.py", "hello.exe"] + ["hi.txt"] * 1000 + ["hi.txt", "hello.exe", "a.c"]
    root, d = sort_by_hash(list_of_files)
    print(d)
    root.print_tree()
