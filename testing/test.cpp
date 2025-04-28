#include <iostream>
#include <cstdlib>
using namespace std;

string enst[5][21];
string zal[5][21];

int main(){
int sp;
sp = rand() % 20;






for (int i=1; i!=6; i++){
    for (int u=1; u!=22; u++){
        enst[i-1][u-1]= "|     |";
    }
    cout << endl;
}
for (int i=1; i!=6; i++){
    for (int u=1; u!=22; u++){
        cout << enst[i-1][u-1];
    }
    cout << endl;
}
//for(int i=1; i<=10;i++){
//int x = rand() % 20;
//cout << x << endl;
//}
}
// x=0 je enemy a x=1 box(jídlo/zbraò/nic)
//for (int t=1; t<=30;t++){
      //  cout << endl;
    //}
