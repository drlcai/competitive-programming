#include <iostream>

using namespace std;

int gcd(int a, int b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 

int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i ++){
    int deg;
    cin >> deg;
    deg *= 2;
    int gc = gcd(deg, 360);
    
    int div1 = deg/gc;
    int div2 = 360/gc;
    
    if(div1 <= div2 - 2){
      cout << div2 << endl;
    }
    else{
      cout << div2 * 2 << endl;
    }
  }
  
  
}