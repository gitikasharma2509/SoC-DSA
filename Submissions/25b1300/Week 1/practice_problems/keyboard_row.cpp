#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
       vector<string> findWords(vector<string>& words) {
        vector<string> result;
        string A="qwertyuiopQWERTYUIOP";
        string B="asdfghjklASDFGHJKL";
        string C="zxcvbnmZXCVBNM";
        for(int i=0;i<words.size();i++){
            int k=0;
            if(A.find(words[i][0])!= string :: npos){
                for(int j=1;j<words[i].size();j++){
                   if(A.find(words[i][j]) == string :: npos){
                    k=1;
                    break;
                   }
                } 
                if(k==1) continue;
                else result.push_back(words[i]);
            }
            else if(B.find(words[i][0])!=string :: npos){
                for(int j=1;j<words[i].size();j++){
                   if(B.find(words[i][j]) == string :: npos){
                     k=2;
                     break;
                   }
                } 
                if(k==2) continue;
                else result.push_back(words[i]);
            }
            if(C.find(words[i][0])!=string :: npos){
                for(int j=1;j<words[i].size();j++){
                   if(C.find(words[i][j]) == string :: npos){
                     k=3;
                     break;
                   }
                } 
                if(k==3) continue;
                else result.push_back(words[i]);
            }
        }
        return result;
    }
};