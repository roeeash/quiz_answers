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



if __name__ == '__main__':
   path = input("insert path")
   #list all files in that directory
   list_of_files = os.listdir(path)
   print("previous list of files",list_of_files)
   print("previous length of the list:",len(list_of_files))
   #delete all duplicates
   root, d = sort_by_hash(list_of_files)
   print("new list of files",d)
   print("new length of the list:",len(d.keys()))
   root.print_tree()
