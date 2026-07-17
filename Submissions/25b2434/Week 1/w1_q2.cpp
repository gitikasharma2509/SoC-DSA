#include<iostream>
using namespace std; 

int  main(){
    int count = 1 , max_count = 1;
    char ch_alr = ' ';
    while(true){
        char ch_in ;
        cin.get(ch_in);
        if(ch_in == '\n'){
            break;
        }
        if(ch_in == ch_alr){
            count++;
        }
        else{
            if(count > max_count){
                max_count = count;
            }
            count  = 1;
        }
        ch_alr = ch_in; 
    }
    if(count > max_count){
        max_count = count;
    }
    cout << max_count << endl;
    return 0;
}