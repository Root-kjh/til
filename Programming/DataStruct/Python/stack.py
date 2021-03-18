class Stack():
    def __init__(self):
        self._last_node = None
        self._size = 0

    def is_empty(self):
        return not self._size
    
    def push(self, obj):
        node = Node(obj, self._last_node)
        self._last_node = node
        self._size+=1

    def pop(self):
        if self.is_empty():
            raise Exception("stack is empty")
        else:
            obj = self._last_node.get_obj()
            self._last_node = self._last_node.get_priv()
            self._size-=1
            return obj


    def peek(self):
        if self.is_empty():
            raise Exception("stack is empty")
        else:
            return self._last_node.get_obj()

class Node():
    def __init__(self, obj, priv):
        self._obj = obj
        self._priv = priv

    def get_obj(self):
        return self._obj

    def get_priv(self):
        return self._priv