#include <iostream>
#include <queue>
using namespace std;

int main(){

    int freq[26] = {0};
    queue<char> qu;
    char arr[]={'a','a','b','c'};

    int size=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;i++){
        char ch=arr[i];
        freq[ch-'a']++;
        qu.push(ch);
        while(freq[qu.front()-'a']>1){
            qu.pop();
        }
        if(qu.empty()){
            cout<<-1<<" ";
        }
        else{
        cout<<qu.front()<<" ";
        }
    }
    return 0;
}