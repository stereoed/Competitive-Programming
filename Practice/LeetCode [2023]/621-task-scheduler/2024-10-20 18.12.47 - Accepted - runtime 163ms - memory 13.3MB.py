import heapq

class Solution(object):
    def leastInterval(self, tasks, n):
        # Step 1: Count the tasks
        task_count = {}
        for task in tasks:
            task_count[task] = task_count.get(task, 0) + 1

        # Step 2: Create a max-heap
        max_heap = [(-count, task) for task, count in task_count.items()]
        heapq.heapify(max_heap)

        intervals = 0
        
        # Step 3: Process the tasks
        while max_heap:
            temp = []
            # Process up to n + 1 tasks
            for _ in range(n + 1):
                if max_heap:
                    temp.append(heapq.heappop(max_heap))
            
            # Update counts and prepare to push back if not finished
            for count, task in temp:
                if count < -1:  # If there's more of this task remaining
                    heapq.heappush(max_heap, (count + 1, task))

            # Step 4: Increment intervals
            intervals += len(temp)

            # Add idle time if necessary
            if max_heap:
                intervals += (n + 1) - len(temp)  # Add idle time for remaining slots

        return intervals