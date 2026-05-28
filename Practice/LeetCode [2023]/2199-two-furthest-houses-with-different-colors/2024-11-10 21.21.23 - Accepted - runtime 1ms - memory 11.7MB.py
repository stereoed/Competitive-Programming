class Solution(object):
    def maxDistance(self, colors):
        pos = {n : i for i, n in enumerate(colors)}
        o = 0
        for i in range(len(colors)):
            for color in pos.keys():
                if colors[i] != color:
                    o = max(pos[color] - i, o)
        return o
        