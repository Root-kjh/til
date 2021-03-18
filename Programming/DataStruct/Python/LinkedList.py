class List():
    def __init__(self):
        self._first_node = None
        self._size = 0

    def is_empty(self):
        return not self._size
    
    def append(self, obj):
        node = Node(obj)
        if self.is_empty():
            self._first_node = node
        else:
            temp_node = self._first_node
            while temp_node.next!=None:
                temp_node = temp_node.next
            temp_node.next = node
        self._size+=1

    def get(self, index):
        if index>=self.size:
            raise Exception("index out of range")
        else:
            temp_node = self._first_node
            for _ in range(index):
                temp_node = temp_node._next
            return temp_node
            
    def delete(self, index):
        if index>=self.size:
            raise Exception("index out of range")
        else:
            if index==0:
                self._first_node = self._first_node._next
            else:
                temp_node = self._first_node
                for _ in range(index-1):
                    temp_node = temp_node._next
                temp_node._next = temp_node._next._next
            self._size-=1
            
    

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