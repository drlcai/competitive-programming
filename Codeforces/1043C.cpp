#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  cin >> s;
  int l = s.size();
  int* table = new int[l];
  
  bool seea = false;
  bool init = false;
  for(int i = l - 1; i >= 0; i --){
    if(s[i] == 'b'){
      if(init){
        if(seea){
          table[i] = 1;
          seea = false;
        }else{
          table[i] = 0;
        }
      }else{ // not init
        table[i] = 0;        
      }
    }else{ // a
      if(init == false){
        init = true;
      }
      if(seea == false){
        table[i] = 1;
        seea = true;
      }else{
        table[i] = 0;
      }
    }
  }
  
  for(int i = 0; i < l; i ++){
    cout << table[i] << " " ;
  }
}