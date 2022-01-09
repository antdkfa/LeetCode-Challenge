class Solution {
public:
    bool isRobotBounded(string instructions) {
        bool ans = false;
        int lcnt = 0, rcnt = 0, r = 0, c = 0, fr[4] = {-1,0,1,0}, fc[4] = {0,-1,0,1}, cmd = 0;
        for(int j =0;j<4;j++){
            for(int i = 0;i<instructions.size();i++){
                if(instructions[i] == 'L') lcnt++, cmd = (cmd + 1) % 4;
                else if(instructions[i] == 'R') rcnt++, cmd = (cmd + 3) % 4;
                else r += fr[cmd], c += fc[cmd];
            }
        }
        if(!r && !c) return true;
        else return false;
    }
};
