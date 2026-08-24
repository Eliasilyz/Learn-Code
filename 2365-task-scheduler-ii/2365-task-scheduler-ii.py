class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        
        time = 0
        executions = {}
        
        for task in tasks:
            last = executions.get(task, float('-inf'))
            elapsed = time - last - 1
            if elapsed < space:
                time += space - elapsed
                
            executions[task] = time
            time += 1
            
            
        return time   
        