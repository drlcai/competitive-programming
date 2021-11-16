#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <bits/stdc++.h> 

void computeLPSArray(vector<int> pat, int M, int* lps); 

// Prints occurrences of txt[] in pat[] 
bool KMPSearch(vector<int> pat, vector<int> txt) 
{ 
	int M = pat.size(); 
	int N = txt.size(); 
    bool res = false;

	// create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	int lps[M]; 

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps); 

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { // reached the pattern's last char
			//printf("Found pattern at index %d ", i - j); 
            res = true;
			j = lps[j - 1]; 
		} 

		// mismatch after j matches 
		else if (i < N && pat[j] != txt[i]) { 
			// Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
    
    return res;
} 

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(vector<int> pat, int M, int* lps) 
{ 
	// length of the previous longest prefix suffix 
	int len = 0; 

	lps[0] = 0; // lps[0] is always 0 

	// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else // (pat[i] != pat[len]) 
		{ 
			// This is tricky. Consider the example. 
			// AAACAAAA and i = 7. The idea is similar 
			// to search step. 
			if (len != 0) { 
				len = lps[len - 1]; 

				// Also, note that we do not increment 
				// i here 
			} 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

// Driver program to test above function 
// int main() 
// { 
// 	vector<int> txt = {3,2,3,4,5,6,7,1,2,3,4}; 
// 	vector<int> pat = {1,2,3,4}; 
// 	KMPSearch(pat, txt); 
// 	return 0; 
// } 


int main(){
    long long n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for(int i =0; i <  n; i++){
        cin >> a[i];
    }
    
    for(int i =0; i <  n; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    vector<int> a2(n); vector<int> b2(n); vector<int> a3(2*n);
    
    for(int i = 0; i < n; i ++){
        if(i == n-1){
            a2[i] = a[0] + 360000 - a[i];
            b2[i] = b[0] + 360000 - b[i];
        }else{
            a2[i] = a[i+1] - a[i];
            b2[i] = b[i+1] - b[i];
        }
    }
    // //test
    // for(int i =0; i <  n; i++){
    //     cout << a2[i] << " ";
    // }
    // cout << endl;
    // for(int i =0; i <  n; i++){
    //     cout << b2[i] << " ";
    // }
    copy(a2.begin(), a2.end(), a3.begin());
    copy(a2.begin(), a2.end(), a3.begin()+n);
    //for(int i = 0; i < 2*n; i++) cout << a3[i] << " " ;
    if(KMPSearch(b2, a3)){
        cout << "possible";
    } else{
        cout << "impossible";
    }

}