//You are given a string containing'{' and '}' , you need to find no. of valid balanced substrings 

//Solution ::

#include<bits/stdc++.h>

int main(){
  string s;
  cin>>s;
  
  // In stack (-1,-1) represents opening bracket (0,0) represents not a valid char 
  stack<pair<int,int> > S;
  int count=0;
  
  for(int i=0;i<s.length();i++){
      
      if(s[i]=='{')
      S.push(make_pair(-1,-1));
      else{
          if(S.top().second==-1){
              S.pop();
              S.push(make_pair(1,1));
          }else{
              int first = S.top().first;
              int second = S.top().second;
              S.pop();
              if(!S.empty() && S.top().first==-1 && S.top().first!=0){
                  S.pop();
                  second++;
              S.push(make_pair(1,second));
              }else{
              S.push(make_pair(first,second));
                  S.push(make_pair(0,0));
              }
          }
      }
      
      if(!S.empty() && S.top().first!=-1 && S.top().first!=0){
          int first = S.top().first;
          int second = S.top().second;
          S.pop();
          if(!S.empty() && S.top().first!=-1 && S.top().first!=0){
              int fr = S.top().first;
              int sec = S.top().second;
              S.pop();
              int res_1 = first*fr;
              int res_2 = res_1+second+sec;
              S.push(make_pair(first+fr,res_2));
              
              
          }else{
              S.push(make_pair(first,second));
          }
      }
     /* if(!S.empty())
      cout<<"top="<<S.top().first<<"\t"<<S.top().second<<"\t"<<S.size()<<"\n";*/
  }
  
   if(!S.empty() && S.top().first!=-1 && S.top().first!=0){
       
          int first = S.top().first;
          int second = S.top().second;
       //   cout<<first<<"\t"<<second<<"\n";
          S.pop();
          
          if(!S.empty() && S.top().first!=-1 && S.top().first!=0){
              int fr = S.top().first;
              int sec = S.top().second;
              S.pop();
              cout<<fr<<"\t"<<sec<<"\n";
              int res_1 = first*fr;
              int res_2 = res_1+second+sec;
              S.push(make_pair(first+fr,res_2));
          }
   
      else{ S.push(make_pair(first,second));
          }
}      
           int ans=0;
          while(!S.empty()){
           //   cout<<"In stack"<<S.top().first<<"\t"<<S.top().second<<"\n";
              if(S.top().first!=-1 && S.top().first!=0){
                  ans+=S.top().second;
              }
              S.pop();
          }
          cout<<ans<<"\n";
  return 0;
}
