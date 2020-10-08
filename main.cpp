#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string str, char divider){
    vector<string> result;

    string currWord = "";
    for(int i = 0; i < str.size(); i ++){
        currWord+=str[i];
        if(str[i] == divider || str.size()-1 == i){
            result.push_back(currWord);
            currWord = "";
        }
    }
    return result;
}
class Vector2I{
private:
    int x;
    int y;
public:
    Vector2I(int x, int y){
        this->x = x;
        this->y = y;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
};
bool isOKConnection(Vector2I p1, Vector2I p2){
    int b = p1.getY() - p1.getX();
    int c = p2.getY() + p2.getX();
    return ((c-b)/2*2 == c-b);
}
float getPeak(Vector2I p1, Vector2I p2){
    float b = p1.getY() - p1.getX();
    float c = p2.getY() + p2.getX();
    return (c-b)/2;
}

int main() {
    string line;
    getline(cin, line);
    vector<string> args = split(line, ' ');
    int wallsCount = stoi(args[0].c_str());
    int end = stoi(args[1]);
    int jumps = 0;
    Vector2I lastPoint = Vector2I(0,0);
    for(int i = 0; i < wallsCount; i++){
        getline(cin, line);
        vector<string> args = split(line, ' ');

        int x = stoi(args[0].c_str());
        int down = stoi(args[1].c_str());
        int up = stoi(args[2].c_str());

        int y;
        if(lastPoint.getY() <= down || lastPoint.getY() >= up){//when it doesnt fit in the bounding
            if(lastPoint.getY() <= down) {
                int currentY = down;
                while (!isOKConnection(lastPoint, Vector2I(x, currentY))) {
                    currentY++;
                }
                if(currentY < up)
                    y = currentY;
            }else if(lastPoint.getY() >= up){
                int currentY = up;
                while (!isOKConnection(lastPoint, Vector2I(x, currentY))) {
                    currentY--;
                }
                if(currentY > down)
                    y = currentY;
            }
        }
        else{
            //in front of...
            //the problem is that i cant find the actual point.
        }
    }
    return 0;
}
