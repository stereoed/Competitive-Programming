class Solution(object):
    def checkValidString(self, s):
        mib, mab = 0, 0
        for c in s:
            if c == "(":
                mib += 1
                mab += 1
            elif c == ")":
                mib -= 1
                mab -= 1
            else:
                mib -= 1 # )
                mab += 1 # (

            if mib < 0:
                mib = 0
            if mab < 0:
                return False
        return mib == 0
                    