class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        for (auto it : commands) {
            if (it == "RIGHT") j++;
            else if (it == "DOWN") i++;
            else if (it == "UP")i--;
            else j--;
        }
        return (i * n) + j;
    }
};