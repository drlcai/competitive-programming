#include <iostream>
#include <vector>

using namespace std;

struct interval{
  int x,y;
};

int main(){
  int n,m;
  cin >> n >> m;
  int* loc = new int[n + m];
  int* isdri = new int[n + m];
  for(int i = 0; i < n+m; i++){
    cin >> loc[i];
  }
  
  for(int i = 0; i < n+m; i++){
    cin >> isdri[i];
  }
  
  vector< interval > drivers;
  
  int start = -1;
  bool onzero = true;
  for(int i = 0; i < n + m; i ++){
    if(onzero == true && isdri[i] == 1){ // 000011, 1...
      interval temp = {start, i};
      drivers.push_back(temp);
      start = i;
      onzero = false;
      continue;
    }else if(onzero == true && isdri[i] == 0){ // 1000
      if(i == n + m -1){
        interval temp = {start, n + m};
        drivers.push_back(temp);
      }
      continue;
    }else if(onzero == false && isdri[i] == 1){ // 11...
      start = i;
      continue;
    }else{ //(onzero == false && isdri[i] == 0), 0011100...
      if(i == n + m -1){
        interval temp = {start, n + m};
        drivers.push_back(temp);
      }
      onzero = true;
      continue;
    } 
  }
  
  // test
  // for(int i = 0; i < drivers.size(); i++){
  //   cout << drivers[i].x << " " << drivers[i].y << endl;
  // }
  
  vector<int> res(n + m);
  
  for(int i = 0; i < drivers.size(); i++){
    int s = drivers[i].x;
    int e = drivers[i].y;
    
    if(s == -1){
      res[e] += e;
      continue;
    }
    
    if(e == n + m){
      res[s] += n + m - s - 1;
      continue;
    }
    
    for(int j = s+1; j < e; j ++){
      if(loc[j] - loc[s] <= loc[e] - loc[j]){
        res[s] ++;
      }else{
        res[e] ++;
      }
    }
  }
  
  for(int i = 0; i < res.size();i++){
    if(isdri[i] == 1){
      cout << res[i] << " ";
    }
  }
  
  
  
}