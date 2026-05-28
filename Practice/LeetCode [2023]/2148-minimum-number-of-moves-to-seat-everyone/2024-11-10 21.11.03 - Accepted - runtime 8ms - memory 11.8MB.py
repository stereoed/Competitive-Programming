class Solution(object):
    def minMovesToSeat(self, seats, students):
        seats.sort()
        students.sort()
        o = 0
        for i in range(len(seats)):
            o += abs(students[i] - seats[i])
        return o
        