class Solution(object):
    def isAnagram(self, s, t):
        coincide=0
        i=0
        lista=[]
        while i<len(t):
            lista.append(t[i])
            i=i+1

        b=len(lista)
        i=0
        while i<len(s):
            if s[i] in lista:
                a=lista.index(s[i])
                lista.pop(a)
                coincide=coincide+1
            if coincide==len(s) and coincide==b:
                return True
            i=i+1
        return False