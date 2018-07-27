#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int max(int a,int b){
  if(a>=b) return a;
  else return b;
}
int main(){
    int size,maxVal;
    cin >> size >> maxVal;
    maxVal += 1;
    int v[size][maxVal] = {0};
    map<int,pair<int,int>>indexToWeight;
    for(int i=0;i<size;i++){
      int wt,val;
      cin >> wt >> val;
      pair<int,int> wtVal(wt,val);
      indexToWeight[i] = wtVal;
    }
    for(int i=0;i<size;i++){
      v[i][0] = 0;
    }
    /* i+1 = no of items available
       j = maximum wt value
    */
    for(int i=0;i<size;i++){
      pair<int,int> p = indexToWeight[i];
      int wt = p.first;
      int val = p.second;
      for(int j=1;j<maxVal;j++){
        // corner case when only one element is present.
          if(i==0){
              if(j<wt) v[i][j]=0;
              else v[i][j] = wt;
          }
          else{
              if(j<wt){
                v[i][j] = v[i-1][j];
              }
              else{
                v[i][j] = max((val + v[i-1][j-wt]),v[i-1][j]);
              }
          }
        }
    }
    maxVal--;
    printf("%d",v[size-1][maxVal]);
    return 0;
}
