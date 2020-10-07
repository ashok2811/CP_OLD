/*
Task Scheduler

Given a characters array tasks, representing the tasks a CPU needs to do, 
where each letter represents a different task. Tasks could be done in any 
order. Each task is done in one unit of time. For each unit of time, the 
CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown 
period between two same tasks (the same letter in the array), that is 
that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to 
finish all the given tasks.
Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.

*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for(auto x : tasks) counts[x]++; // Making frequency array
        
        priority_queue<int> pq;
        for(auto x : counts)
            pq.push(x.second);
        
        int result = 0 ;
        while(!pq.empty()){
            int time = 0 ;
            vector<int> tmp;
            for(int i = 0 ; i<n+1; i++){
                if(!pq.empty()){
                    tmp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            
            for(auto t: tmp){
                if(t) pq.push(t);
            }
            
            result += pq.empty() ? time : n+1;
        }
        
       return result;
        
    }
};