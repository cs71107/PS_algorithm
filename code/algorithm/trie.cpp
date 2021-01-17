#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
char W[31];

struct Trie{
    Trie *go[128];
    int output;
    // 생성자
    Trie(): output(0){ fill(go, go+128, nullptr); }
    // 소멸자
    ~Trie(){
        for(int i=0; i<26; i++)
            if(go[i]) delete go[i];
    }
    // 트라이에 단어를 삽입하는 함수
    void Insert(char *str){
        if(*str == '\0'){
            n++;
            output++;
        }
        else{
            if(!go[*str-' ']){
                go[*str-' '] = new Trie;
            }
            go[*str-' ']->Insert(str+1);
        }
    }
    void pf(int pos=0){
        if(output){
            W[pos] = '\0';
            printf("%s %.4lf\n",W,100.0*output/n);
        }
        for(int i=0;i<128;i++){
            if(go[i]){
                W[pos] = i+' ';
                go[i]->pf(pos+1);
            }
        }
    }

};

int main(){
    int n;
    int cnt = 0;

    Trie *root = new Trie;

    while(gets(W))root->Insert(W);

    root->pf();

    return 0;
}
