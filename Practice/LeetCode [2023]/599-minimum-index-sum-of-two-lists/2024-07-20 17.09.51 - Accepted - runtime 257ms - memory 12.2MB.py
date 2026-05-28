class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        dict = {n:i for i,n in enumerate(list1)}
        words = []
        indexSum = 99999
        for i in range(len(list2)):
            aux = list2[i]
            if aux in dict.keys():
                if (i + dict.get(aux)) < indexSum:
                    indexSum = i + dict.get(aux)
                    words = [aux]
                elif (i + dict.get(aux)) == indexSum:
                    words.append(aux)
        return words