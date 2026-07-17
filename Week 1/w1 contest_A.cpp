#include <iostream>
#include <string>
using namespace std;

int main(){
    int scores[1005];
    string names[1005];

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> names[i] >> scores[i];
    }
    
    int MaxScore = -1e9;

    for (int j = 0; j < n; j++)
    {   int Sum =0;
        for (int k = 0; k < n; k++)
        {   
            if(names[j]==names[k])
            Sum += scores[j];
        }
      if (Sum > MaxScore)
      {
       MaxScore= Sum;
      }
    }
    
    for (int i = 0; i < n; i++)
    {
        int CurrScore =0;
        int FinalScore =0;
        for (int j = 0; j < n; j++)
        {   if (names[i]==names[j]){
            FinalScore += scores[j];
            if(j <= i) CurrScore += scores[j];
            } 
        }
        
        if (CurrScore >= MaxScore && FinalScore == MaxScore)
        {
            cout << names[i] << "\n";
            return 0;
        }
        
    }
    return 0;

}