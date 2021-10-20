//4ms runtime
class Solution {
    bool isalive(int a) {
        if (a == 1 || a == 2)
            return true;
        else return false;
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        int ymax=board.size();
        int xmax=board[0].size();
        //0=dead 1=alive 2=going to die 3=going to live
        //I'll make two passes over the board one to apply what is going to happen
        //and another to flip everything to permanent states
        //cout << "phase one\n";
        for (int y=0; y < board.size(); y++) {
            for (int x=0; x <board[0].size(); x++) {
                int alive_neigh=0;
                for (int Y=max(0, y-1); Y < min(y+2,ymax); Y+=1) {
                    for (int X= max(x-1, 0); X < min(x+2, xmax); X+=1) {
                        //cout << "YX " << Y << " " << X << " " << board.size() << " " <<board[0].size()<<  endl;

                        if (isalive(board[Y][X])) {
                            alive_neigh++;
                        }
                    }
                }
                if (isalive(board[y][x])) {
                    alive_neigh--;
                }
                if (board[y][x] == 1) {
                    //this spot is alive but might die
                    if (alive_neigh < 2) {
                        board[y][x]=2;
                    } else if (alive_neigh > 3) {
                        board[y][x]=2;
                    }
                } else {
                    //this spot is dead, but might become alive
                    if (alive_neigh == 3) {
                        board[y][x]=3;
                    }
                }
            }
        }
        //cout << "phase two\n";
        for (int y=0; y < board.size(); y++) {
            for (int x=0; x <board[0].size(); x++) {
                if (board[y][x] == 2) {
                    board[y][x] = 0;
                }
                if (board[y][x] == 3) {
                    board[y][x] = 1;
                }
            }
        }
    }
};
