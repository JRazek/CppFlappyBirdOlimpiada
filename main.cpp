#include <iostream>
#include <vector>
using namespace std;
int splitSize(string str, char c){
    int size = 1;
    for(int i = 0; i < str.size(); i ++){
        if(str[i] == c){
            size ++;
        }
    }
    return size;
}
string *split(string str, char c){
    string split;
    string buff = "";
    int currSplit = 0;
    for(int i = 0; i < str.size(); i ++){
        if(str[i] == c){
            split[currSplit] = buff;
            currSplit ++;
            buff = "";
        }
        buff += str[i];
    }
    return split;
}
int main() {

    cout<<split("duupa, duup, dada", ',');

    const int sizeY = 3;
    int sizeX;
    cin >> sizeX;
    int tiles[sizeX][sizeY];
    for(int y = 0; y < sizeY; y ++){
        for(int x = 0; x < sizeY; x ++){
        }
    }
    return 0;
}
