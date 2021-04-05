class Queue():
    def __init__(self):
        self._first_node = None
        self._last_node = None
        self._size = 0

    def is_empty(self):
        return not self._size
    
    def push(self, obj):
        node = Node(obj)
        if self.is_empty():
            self._first_node = node
            self._last_node = node
        else:
            self._last_node.set_next(node)
            self._last_node = node
        self._size+=1

    def pop(self):
        if self.is_empty():
            raise Exception("stack is empty")
        else:
            obj = self._first_node.get_obj()
            self._first_node = self._first_node.get_next()
            self._size-=1
            return obj


    def peek(self):
        if self.is_empty():
            raise Exception("stack is empty")
        else:
            return self._first_node.get_obj()

class Node():
    def __init__(self, obj):
        self._obj = obj
        self._next = None
    
    def set_next(self, next):
        self._next = next

    def get_obj(self):
        return self._obj

    def get_next(self):
        return self._next