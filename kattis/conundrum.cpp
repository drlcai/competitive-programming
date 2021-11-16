#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i < s.size() ; i ++){
        if(i % 3 == 0 && s[i] != 'P') count ++;
        if(i % 3 == 1 && s[i] != 'E') count ++;
        if(i % 3 == 2 && s[i] != 'R') count ++;
    } 
    cout << count;
}