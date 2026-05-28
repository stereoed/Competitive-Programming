class Solution(object):
    def groupAnagrams(self, strs):
          anagram = {}

          for s in strs:
            sortedS = ' '.join(sorted(s))

            if sortedS in anagram:
                anagram[sortedS].append(s)
            else:
                anagram[sortedS] = [s]

          return list(anagram.values())          
