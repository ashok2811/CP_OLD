/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i 
to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the 
clockwise direction, otherwise return -1.

Note:

    If there exists a solution, it is guaranteed to be unique.
    Both input arrays are non-empty and have the same length.
    Each element in the input arrays is a non-negative integer.

Example 1:

Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int fuel = 0 , start  = 0, total_fuel = 0; 
        
        for(int i = 0 ; i<n ; i++){
            total_fuel += gas[i] - cost[i] ;
            fuel +=  gas[i] - cost[i] ;
            
            if( fuel < 0){
               fuel = 0;
                start = i+1 ;    
            }
        }
        
        if(total_fuel < 0) {
            return -1;
        }
        
        else return start ;
    }
};