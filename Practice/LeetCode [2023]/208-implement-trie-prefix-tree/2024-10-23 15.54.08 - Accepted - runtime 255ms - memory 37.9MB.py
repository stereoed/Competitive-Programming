class Node(object):
    def __init__(self, val):
        self.val = [val, 0]
        self.children = list()

    def end_of_word(self, flag):
        self.val[1] = flag


class Trie(object):

    def __init__(self):
        self.start = Node("_")

    def search_node_in_children(self, node, letter):
        output = None
        for child in node.children:
            if child.val[0] == letter:
                output = child
                break
        return output

    def insert(self, word, pointer=None):
        if not pointer:
            pointer = self.start

        # Example word: [apple]
        letter = word[0] # letter = a
        word = word[1:] # word = [pple]

        # Search for a valid child
        next_node = self.search_node_in_children(pointer, letter)

        # If it doesn't exist, create a new one
        if not next_node:
            next_node = Node(letter)
            pointer.children.append(next_node)

        # If no characters remain next word, mark it as the end of the word
        if not word:
            next_node.end_of_word(True)
            return

        # If it's not the end of the word, call the function once more
        self.insert(word, next_node)

    def search(self, word):
        pointer = self.start
        for char in word:
            pointer = self.search_node_in_children(pointer, char)
            if not pointer:
                return False
        return bool(pointer.val[1])

    def startsWith(self, prefix):
        pointer = self.start
        for char in prefix:
            pointer = self.search_node_in_children(pointer, char)
            if not pointer:
                return False
        return True

