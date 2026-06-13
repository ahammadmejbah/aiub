#include <iostream>
using namespace std;

int main ()
{
int i, j, a[3][3], b[3][3]={1,3,5,7,9,2,4,6,8};
for(i=0;i<3;i++){
  for(j=0;j<3;j++)
  cin>>a[i][j];
}

for(i=0;i<3;i++){
for(j=0;j<3;j++)
  cout<<a[i][j] + b[j][i]<<" ";//a[0][1]+b[1][0]
}
  return 0;
}
