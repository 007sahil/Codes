//Learn Disjoint Sets //
//By Rank
//Path Compression


//Problem Link :: https://www.hackerrank.com/challenges/merging-communities
//Code

#include<bits/stdc++.h>

struct subset{
    int parent;
    int rank;
    int size;
};

int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
  
    if(xroot==yroot)
        return;
    if (subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
        subsets[yroot].size+=subsets[xroot].size;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
         subsets[xroot].size+=subsets[yroot].size;
    }
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {   
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
        subsets[xroot].size+=subsets[yroot].size;
    }
}
 

int main() {
   int n,q;
    cin>>n>>q;
     struct subset *subsets =
        (struct subset*) malloc( (n+1) * sizeof(struct subset) );
    for(int i=0;i<=n;i++){
        subsets[i].parent=i;
        subsets[i].rank=0;
        subsets[i].size=1;
    }
    for(int i=1;i<=q;i++){
        char c;
        cin>>c;
        if(c=='Q'){
            int x;
            cin>>x;
            int par = find(subsets,x);
            cout<<subsets[par].size<<"\n";
        }else{
            int x,y;
            cin>>x>>y;
            Union(subsets,x,y);
        }
    }
   
    return 0;
}


