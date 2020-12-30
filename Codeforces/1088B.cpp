#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, k;
    
    cin >> n >> k;
    
    vector<int> arr;
     
    for(int i = 0; i < n; i ++){
        int in;
        cin >> in;
        arr.push_back(in);
    }
    
    sort(arr.begin(), arr.end());
    
    vector<int> brr;
    brr.push_back(arr[0]);
    for(int i = 1; i < arr.size(); i++){
        brr.push_back(arr[i] - arr[i - 1]);
    }
    
    int index = 0;
    while(k > 0){
        if (index >= brr.size()){
            cout << 0 << endl;
            k --;
        }else if(brr[index] != 0){
            cout << brr[index] << endl;
            k --;
        }
        
        index ++;
    }
    
    // for(int i =0; i < arr.size(); i++){
    //     cout << arr[i];
    // }
    
}