// Given an array containing N integers, you need to find the length of the smallest 
//contiguous subarray that contains atleast KK distinct elements in it. Output "−1" if no such subarray exists.


//Solution ::


    

#include<bits/stdc++.h>
  int main(){
     int n,k;
     cin>>n>>k;
     int l = 0, r = 0, ans = INT_MAX;
     int A[n+1];
     for(int i=0;i<n;i++)
     cin>>A[i];
map <int , int >  cnt;
 set<int> s;
while ( l < n ) {
    while ( r < n && s.size() < k ) {
       s.insert(A[r]);
       cnt[A[r]]++;
       r++;
    }
    if (s.size() >=k) {
		ans = min(ans, r-l);
	}
    if ( cnt[A[l]] == 1 ) s.erase(A[l]); 
    cnt[A[l]]--; 
    l++;
}
if ( ans == INT_MAX ) ans = -1;
 
cout << ans << endl;
return 0;
}
