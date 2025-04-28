#include <iostream>
#include <cstdlib>
using namespace std;

string enst[7][17];
string zal[7][17];
string hse[7][3];
string zom[7][1];

int main(){
int sp;
sp = rand() % 20;




hse[0][0]="       ";
hse[0][1]="  /\\   ";
hse[0][2]="       ";
hse[1][0]="       ";
hse[1][1]=" /  \\  ";
hse[1][2]="       ";
hse[2][0]="       ";
hse[2][1]="/ () \\ ";
hse[2][2]="       ";
hse[3][0]="      /";
hse[3][1]="      \\";
hse[3][2]="       ";
hse[4][0]="      |";
hse[4][1]="  _   |";
hse[4][2]="       ";
hse[5][0]="      |";
hse[5][1]=" | | O|";
hse[5][2]="       ";
hse[6][0]="      |";
hse[6][1]=" | |  |";
hse[6][2]="       ";

for (int i=1; i!=8; i++){
    for (int u=1; u!=4; u++){
        cout << hse[i-1][u-1];
    }
    cout << endl;
}

cout << endl;
cout << endl;

zom[4][0]="       ";
zom[5][0]="  ___  ";
zom[5][0]=" |. .| ";
zom[5][0]=" | = | ";
zom[6][0]="  \\ /  ";
zom[6][0]=" ||  ||";
zom[6][0]="  |||| ";


for (int i=1; i!=8; i++){
    cout << zom[i-1][0];
    cout << endl;
}
cout << endl;
cout << endl;

for (int i=1; i!=8; i++){
    for (int u=1; u!=18; u++){
        enst[i-1][u-1]= "|     |";
    }
    cout << endl;
}
for (int i=1; i!=8; i++){
    for (int u=1; u!=18; u++){
        cout << enst[i-1][u-1];
    }
    cout << endl;
}
cout << "------------------------------------------------------------------------------------------------------------------------";
}













//for(int i=1; i<=10;i++){
//int x = rand() % 20;
//cout << x << endl;
//}




// x=0 je enemy a x=1 box(jídlo/zbraò/nic)
//for (int t=1; t<=30;t++){
      //  cout << endl;
    //}
