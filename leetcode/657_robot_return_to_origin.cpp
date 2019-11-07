class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal = 0;
        int vertical = 0;
        
        for(int i=0; i<moves.size(); i++){
            if(moves[i] == 'U'){
                vertical++;
            }
            else if(moves[i] == 'D'){
                vertical--;
            }
            else if(moves[i] == 'R'){
                horizontal++;
            }
            else if(moves[i] == 'L'){
                horizontal--;
            }
        }
        
        return (horizontal == 0 && vertical == 0)? true:false;
    }
};