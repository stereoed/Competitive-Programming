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
        l = self.dic[key]

        if timestamp < l[0][1]:
            return ""
        if timestamp >= l[-1][1]:
            return l[-1][0]

        left = 0 
        right = len(l)-1
        while left + 1 < right:
            mid = left + (right - left)/2
            if l[mid][1] == timestamp:
                return l[mid][0]
            
            if l[mid][1] < timestamp:
                left = mid 
            else:
                right = mid 
        return l[left][0]
