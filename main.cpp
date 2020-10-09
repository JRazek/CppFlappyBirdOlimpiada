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
    Vector2I lastPoint = Vector2I(0, 0);//should be last domain
    for (int i = 0; i < wallsCount; i++) {
        getline(cin, line);
        vector<string> args = split(line, ' ');

        int x = stoi(args[0].c_str());
        int down = stoi(args[1].c_str());
        int up = stoi(args[2].c_str());
        for(int i = 0; i < 1; i++) {
            int maxY = lastPoint.getY() + x;//continuation and the common point with the next wall;
            if (maxY >= up) {
                maxY = up - 1;
                while (!isOKConnection(lastPoint, Vector2I(x, maxY))) {
                    maxY--;
                }
            }
            Vector2I maxPoint = Vector2I(x, maxY);
            int mParameter = lastPoint.getY() - lastPoint.getX();
            int minY = -x + mParameter;
            if (minY <= down) {
                minY = down + 1;
                while (!isOKConnection(lastPoint, Vector2I(x, minY))) {
                    minY++;
                }
            }
            if (minY >= up || maxY <= down) {
                cout << "NIE";
                return 0;
            }
           // cout << "\nfrom: " << minY << " to: " << maxY;
        }
    }
    cout<<"end";
    return 0;
}
