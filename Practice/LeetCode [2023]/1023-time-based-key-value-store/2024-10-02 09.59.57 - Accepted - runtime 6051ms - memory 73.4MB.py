class TimeMap(object):

    def __init__(self):
        self.dic = dict()

    def set(self, key, value, timestamp):
        if key not in self.dic:
            self.dic[key] = [[value, timestamp]]
        else:
            self.dic[key].append([value, timestamp])

    def get(self, key, timestamp):
        if key not in self.dic:
            return ""
            
        arr = self.dic[key]
        for o in arr[::-1]:
            if o[1] <= timestamp:
                return o[0]
        return ""
