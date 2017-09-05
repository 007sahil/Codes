#Trie Implementation !1
#this particular solution belongs to Common prefix problem !!


#include<stdio.h>
#include<string.h>
#include<string.h>
#include<iostream>
using namespace std;
struct trie_node{
 bool leaf;
 struct trie_node *child[26];
};

struct trie_node *newnode(){
    struct trie_node *node = new trie_node;
    node->leaf=false;
    for(int i=0;i<26;i++)
        node->child[i]=NULL;
    return node;
}
void insert_into_trie(char *a,struct trie_node *head){
   struct trie_node *temp=head;
   int index=0;
    while(a[index]!='\0'){
        if(!temp->child[a[index]-'a'])
            temp->child[a[index]-'a']=newnode();
        temp=temp->child[a[index]-'a'];
        index++;
    }
    temp->leaf = true;
}
bool is_valid(trie_node *head,int *index){
 int count=0;
    for(int i=0;i<26;i++){
     if(head->child[i]!=NULL){
         count++;
         *index=i;
     }
    }
    if(count>1)
        return false;
    return true;
    
}
string com_prefix(trie_node *head){
    string s;
    int index;
    while(head->leaf==false && is_valid(head,&index)==1){
        head=head->child[index];
        s.push_back('a'+index);
    }
    return s;
}
// Read only region start

char* fhh(int input1,char* input2[])
{
    // Read only region end
	// Write code and remove the below exception.
    struct trie_node *head = newnode();
    for(int i=0;i<input1;i++){
        cout<<input2[i]<<"\n";
        insert_into_trie(input2[i],head);
    }
    string s = com_prefix(head);
    cout<<s<<"\n";
    char * w = new char[s.length()+1];
    int i=0;
    for(;i<s.length();i++){
        w[i]=s[i];
    }
    w[i]='\0';
    return w;
}
