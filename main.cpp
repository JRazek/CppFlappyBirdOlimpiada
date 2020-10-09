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
    return (/*p2.getX()+b >= p2.getY() && */(c-b)/2*2 == c-b);
}
class Collection{
private:
    int min;
    int max;
    bool empty;
public:
    Collection(int min, int max){
        if(min > max){
            int buff = min;
            min = max;
            max = buff;
        }
        this->min = min;
        this->max = max;
        this->empty = false;
    }
    Collection(bool empty){
        this->empty = empty;
    }
    bool isEmpty(){
        return empty;
    }
    int getMin(){
        return min;
    }
    int getMax(){
        return max;
    }
    Collection commonPart(Collection c){
        if(abs(min - c.getMin()) > abs(max-min) || abs(min-c.getMin() > abs(c.getMin()-c.getMax()))
            || c.isEmpty() || empty)
            return Collection(true);
        int start = min > c.getMin() ? min : c.getMin();
        int end = max < c.getMax() ? max : c.getMax();
        return Collection(start, end);
    }
};
class Domain{

private:
    int min;
    int max;
    int wallX;
public:
    Domain(int min, int max, int wallX){
        this->min = min;
        this->max = max;
        this->wallX = wallX;
    }
    int getMin(){
        return min;
    }
    int getMax(){
        return max;
    }
    int getWallX(){
        return wallX;
    }
    Vector2I getMinVector(){
        return Vector2I(wallX, min);
    }
    Vector2I getMaxVector(){
        return Vector2I(wallX, max);
    }
};
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
    int end = stoi((args[1].c_str()));
    Vector2I startPos = Vector2I(0,0);
    Domain lastDomain = Domain(startPos.getY(), startPos.getY(), startPos.getX());//should be last domain
    if(wallsCount == 0) {cout<<0;return 0;}

    for (int i = 0; i < wallsCount; i++) {
        getline(cin, line);
        vector<string> args = split(line, ' ');

        int x = stoi(args[0].c_str());
        int down = stoi(args[1].c_str());
        int up = stoi(args[2].c_str());

        int minY = down+1;
        if(!isOKConnection(lastDomain.getMinVector(), Vector2I(x, minY))){
            minY+=1;
        }
        int maxY = up-1;
        if(!isOKConnection(lastDomain.getMaxVector(), Vector2I(x, maxY))){
            maxY-=1;
        }
        if(minY >= up || maxY <= down){
            cout<<"NIE";
            return 0;
        }
        int minYFlight = -x + lastDomain.getMax()+lastDomain.getWallX();

        int maxYFlight = x + lastDomain.getMin()-lastDomain.getWallX();

        Collection coll1 = Collection(minYFlight, maxYFlight);
        Collection coll2 = Collection(minY, maxY);

        Collection result = coll1.commonPart(coll2);
        if(end < x){
            cout.precision(10);
            cout<<getPeak(startPos, Vector2I(lastDomain.getMinVector()));
            return 0;
        }
        if(result.isEmpty()){
            cout<<"NIE";
            return 0;
        }
        lastDomain = Domain(result.getMin(), result.getMax(), x);
        if(i + 1 == wallsCount){
            cout.precision(10);
            cout<<getPeak(startPos, lastDomain.getMinVector());
        }
    }
    return 0;
}
