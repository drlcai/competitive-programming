#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  set<int> st;
  
  for(int i = 0; i < n; i ++){
    int temp;
    cin >> temp;
    
    if(st.empty()){
      st.insert(temp);
      st.insert(-temp);
    }else{
      set<int> newst;
      set<int>::iterator it;
      for(it = st.begin(); it != st.end(); it++){
        newst.insert(*it + temp);
        newst.insert(*it - temp);
      }
      st = newst;
    }
    
  }
  
  set<int>::iterator it;
  for(it = st.begin(); it != st.end(); it++){
    if(*it % 360 == 0){
      cout << "YES" ;
      return 0;
    }
  }
  
  cout << "NO";
  
  
  return 0;
}
