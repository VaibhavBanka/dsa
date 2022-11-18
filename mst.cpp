#include<iostream>
#include<cstring>
using namespace std;
int main() {
  int n;
  cin>>n;
  int G[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>G[i][j];
    }
  }
  int no_edge;  
  int selected[n];
  memset(selected, false, sizeof(selected));
  no_edge = 0;
  selected[0] = true;
  int x;  
  int y;  
  int sum=0;
  while (no_edge < n - 1) {
    int min = INT_FAST16_MAX;
    x = 0;
    y = 0;
    for (int i = 0; i < n; i++) {
      if (selected[i]) {
        for (int j = 0; j < n; j++) {
          if (!selected[j] && G[i][j]) { 
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    sum+=G[x][y];
    selected[y] = true;
    no_edge++;
  }
  cout<<sum;
  return 0;
}

