#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    
    vector<int> as;
    
    bool flag = false;
    int count = 0;
    for(int i = 0; i < s.size(); i++){                
        if(!flag && s[i] != 'a'){
            if(i == s.size() - 1 && as.size() == 0){
                as.push_back(count);
            }
        }else if(!flag && s[i] == 'a'){
            count ++;
            flag = true;
            if(i == s.size() - 1){
                as.push_back(count);
            }
        }else if(flag && s[i] == 'a'){
            count ++;
            if(i == s.size() - 1){
                as.push_back(count);
            }
        }else{// flag && s[i] != 'a'
            if(s[i] == 'b'){
                as.push_back(count);
                count = 0;
                flag = false;
            }else{
                if(i == s.size() - 1){
                    as.push_back(count);
                }
            }
        }
    }
    
    long long sum = 0;   
    sum = as[0];
    for(int i = 1; i < as.size(); i ++){
        sum = (sum + as[i] + sum * as[i]) % 1000000007;
    }
    
    cout << sum;
    
    
}