
#include <iostream>
#include <cstdlib>
using namespace std;

string enst[8][18];
string zal[8][19];
string hse[8][3];
string zom[8][1];
string ch[8][1];
char d;
int chah = 5;
int random = 8;
int main(){
int sp;
sp = rand() % 20;




hse[1][0]="       ";
hse[1][1]="  /\\   ";
hse[1][2]="       ";
hse[2][0]="       ";
hse[2][1]=" /  \\  ";
hse[2][2]="       ";
hse[3][0]="       ";
hse[3][1]="/ () \\ ";
hse[3][2]="       ";
hse[4][0]="      /";
hse[4][1]="      \\";
hse[4][2]="       ";
hse[5][0]="      |";
hse[5][1]="  _   |";
hse[5][2]="       ";
hse[6][0]="      |";
hse[6][1]=" | | O|";
hse[6][2]="       ";
hse[7][0]="      |";
hse[7][1]=" | |  |";
hse[7][2]="       ";

for (int i=1; i!=8; i++){
    for (int u=1; u!=4; u++){
        cout << hse[i-1][u-1];
    }
    cout << endl;
}

cout << endl;
cout << endl;

zom[1][0]="       ";
zom[2][0]="  ___  ";
zom[3][0]=" |. .| ";
zom[4][0]=" | = | ";
zom[5][0]="  \\ /  ";
zom[6][0]=" ||z|| ";
zom[7][0]="  |||  ";


for (int i=1; i!=9; i++){
    cout << zom[i-1][0];
    cout << endl;
}
cout << endl;
cout << endl;

ch[1][0]="       ";
ch[2][0]="       ";
ch[3][0]="       ";
ch[4][0]="       ";
ch[5][0]=" _____ ";
ch[6][0]="| () | ";
ch[7][0]="|    | ";


for (int i=1; i!=9; i++){
    cout << ch[i-1][0];
    cout << endl;
}
cout << endl;
cout << endl;

//enst[i-1][u-1]= "|     |";

for (int i=1; i!=9; i++){
    for (int u=2; u!=19; u++){
        enst[i-1][u-1]= "       ";
    }
    cout << endl;
}





enst[0][17]="|    | ";
int poc=1;




do{
for (int i=1; i!=8; i++){
    for (int u=2; u!=19; u++){
        cout << enst[i-1][u-1];
    }
    if(i<=7){
    cout << endl;
    }
}
for (int i=1; i!=9; i++){
    for (int u=1; u!=19; u++){
        zal[i-1][u-1]=enst[i-1][u];
    }
}
for (int i=1; i!=9; i++){
    enst[i-1][18]= "       ";
}
for (int i=1; i!=9; i++){
    for (int u=2; u!=18; u++){
        enst[i-1][u]=zal[i-1][u];
    }
}
if(random<=5){
    for (int i=1; i!=9; i++){
            enst[i-2][18]=zom[i-1][0];
    }
} else if(random>=6 && random<=7){
    chah=0;
    for (int i=1; i!=9; i++){
            enst[i-2][18]=hse[i-1][chah];
    }
} else if(random==8){
    for (int i=1; i!=9; i++){
            enst[i-2][18]=ch[i-1][0];
    }
}
cout << "------------------------------------------------------------------------------------------------------------------------";
if(chah<=2){
    for (int i=1; i!=9; i++){
            enst[i-2][18]=hse[i-1][chah];
    }
}

random = rand() % 50;
if(chah<=2){
    random=120;
}
poc++;
chah = chah+1;
cout << endl << "znovu? f/... ";
cin >> d;
} while(d!='f');
cout << "------------------------------------------------------------------------------------------------------------------------";
}
