#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ppl(n);
    for(int i = 0; i < n; i ++){
        cin >> ppl[i];
    }
    
    int basecost = 0;
    for(int i = 0; i < n; i++){
        basecost += 2 * i * ppl[i];
    }
    
    int mindiffcost = LONG_MAX;
    for(int i = 0; i < n; i ++){
        int tempcost = 0;
        for(int j = 0; j < n; j++){
            tempcost += 2 * (abs(i - j) + i) * ppl[j];
        }
        if (tempcost < mindiffcost) mindiffcost = tempcost;
    }
    
    cout << basecost + mindiffcost;
    
}