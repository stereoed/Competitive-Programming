class Solution(object):
    def maximumTime(self, time):
        hr, mn = time.split(":")

        # Fixing the hour part
        if hr == "??":
            hr = "23"
        elif hr[0] == "?":
            if hr[1] <= "3":
                hr = "2" + hr[1]
            else:
                hr = "1" + hr[1]
        elif hr[1] == "?":
            if hr[0] == "2":
                hr = "23"
            else:
                hr = hr[0] + "9"

        # Fixing the minute part
        if mn == "??":
            mn = "59"
        elif mn[0] == "?":
            mn = "5" + mn[1]
        elif mn[1] == "?":
            mn = mn[0] + "9"
        
        return hr + ":" + mn
