// On an infinite plane, a robot initially stands at (0, 0) and faces north.  
//The robot can receive one of three instructions:

//     "G": go straight 1 unit;
//     "L": turn 90 degrees to the left;
//     "R": turn 90 degress to the right.

// The robot performs the instructions given in order, and repeats them forever.

// Return true if and only if there exists a circle in the plane such that the 
//robot never leaves the circle.

class Solution {
public:
    bool isRobotBounded(string ins) {
       int y = 0, x = 0;
        
        int dx[] = {0 , -1 , 0 , 1};
        int dy[] = {1 , 0 , -1, 0};
        int dir = 0 ; 
        for(char xx : ins){
            if(xx == 'L'){
                dir++;
               if(dir>3){
                    dir =0;
                }
            }
            
            else if (xx == 'R'){
                dir--;
                if(dir<0){
                    dir = 4 + dir;
                }
                
            }
            
            else if (xx == 'G'){
                x = x + dx[dir];
                y = y + dy[dir];
            }
        }
        
        if(dir==0){
            if(x==0 && y==0){
                return true;
            }
            
            return false;
        }
        return true;
        
    }
};