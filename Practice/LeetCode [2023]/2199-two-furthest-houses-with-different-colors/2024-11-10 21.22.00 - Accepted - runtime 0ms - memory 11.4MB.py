class Solution(object):
    def maxDistance(self, colors):
        ans=0
        temp=colors[0]
        n=len(colors)
        for j in range(n):
            if temp!=colors[j]:
                diff=abs(0-j)
                ans=max(ans,diff)
        for j in range(n-1,-1,-1):
            if colors[j]!=temp:
                diff=n-1-j
                ans=max(ans,diff)
        return ans
    
        