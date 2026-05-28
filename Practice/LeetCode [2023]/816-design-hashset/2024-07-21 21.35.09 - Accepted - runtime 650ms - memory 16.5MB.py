class MyHashSet(object):
    data = []
    def __init__(self):
        data = []

    def add(self, key):
        """
        :type key: int
        :rtype: None
        """
        left = 0
        right = len(self.data) - 1
        if right == -1:
            self.data = [key]
            return
        while left <= right:
            mid = (left + right) // 2
            if self.data[mid] < key:
                if mid == right:
                    if mid + 1 >= len(self.data):
                        self.data = self.data + [key]
                    else:
                        self.data = self.data[:mid + 1] + [key] + self.data[mid + 1:]
                    break
                else:
                    left = mid + 1
            elif self.data[mid] > key:
                if mid == left:
                    self.data = self.data[:mid] + [key] + self.data[mid:]
                    break
                else:
                    right = mid - 1
            else:
                return


    def remove(self, key):
        """
        :type key: int
        :rtype: None
        """
        left = 0
        right = len(self.data) - 1
        while left <= right:
            mid = (left+right) // 2
            value = self.data[mid]
            if value == key:
                if not mid == len(self.data):
                    self.data = self.data[:mid] + self.data[mid+1:]
                else:
                    self.data = self.data[:mid]
                break
            elif value < key:
                left = mid + 1
            else:
                right = mid - 1
    def contains(self, key):
        """
        :type key: int
        :rtype: bool
        """
        left = 0
        right = len(self.data) - 1
        while left <= right:
            mid = (left + right) // 2
            value = self.data[mid]
            if value == key:
                return True
            elif value < key:
                left = mid + 1
            else:
                right = mid - 1
        return False