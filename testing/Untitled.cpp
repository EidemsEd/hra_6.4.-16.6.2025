
#include <iostream>
#include <cstdlib>
using namespace std;

string enst[9][18];
string zal[9][19];
string hse[8][3];
string zom[8][1];
string haz[8][1];
string plz[8][1];
string ch[8][1];
char d;
int chah = 5;
int random = 12;
int main(){
int sp;
sp = rand() % 20;
int poc=1;
int phaz1=1, phaz2=1, phaz3=1;
int s1, s2, s3;

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

haz[1][0]="       ";
haz[2][0]="  ___, ";
haz[3][0]="<|. .|-";
haz[4][0]=" | = | ";
haz[5][0]="  \\ / ;";
haz[6][0]=" ||H|% ";
haz[7][0]="  |||  ";

for (int i=1; i!=9; i++){
    cout << haz[i-1][0];
    cout << endl;
}

cout << endl;
cout << endl;

plz[1][0]="       ";
plz[2][0]="       ";
plz[3][0]="       ";
plz[4][0]=" ___   ";
plz[5][0]="(*=*)  ";
plz[6][0]=" \\ |_  ";
plz[7][0]=" =\\__/´";

for (int i=1; i!=9; i++){
    cout << plz[i-1][0];
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











do{
for (int i=1; i!=9; i++){
    for (int u=2; u!=19; u++){
        cout << enst[i-1][u-1];
    }
    if(i<=8){
    cout << endl;
    }
}
for (int i=1; i!=9; i++){
    for (int u=1; u!=19; u++){
        zal[i][u-1]=enst[i][u];
    }
}
for (int i=1; i!=9; i++){
    enst[i][18]= "       ";
}
for (int i=1; i!=9; i++){
    for (int u=2; u!=18; u++){
        enst[i][u]=zal[i][u];
    }
}
if(random<=5){
    for (int i=1; i!=9; i++){
            enst[i-1][18]=zom[i-1][0];
    }
} else if(random>=6 && random<=7){
    for (int i=1; i!=9; i++){
            enst[i-1][18]=plz[i-1][0];
    }
} else if(random>=8 && random<=9){
    for (int i=1; i!=9; i++){
            enst[i-1][18]=haz[i-1][0];
    }
} else if(random>=10 && random<=11){
    chah=0;
    for (int i=1; i!=9; i++){
            enst[i-1][18]=hse[i-1][chah];
    }
} else if(random==12){
    for (int i=1; i!=9; i++){
            enst[i-1][18]=ch[i-1][0];
            if (phaz1<2){
                phaz1=18;
            } else if (phaz2<2){
                phaz2=18;
            } else if (phaz3<2){
                phaz3=18;
            } else{
                enst[i-1][18]=zom[i-1][0];
            }
    }
}
cout << "------------------------------------------------------------------------------------------------------------------------";
if(chah<=2){
    for (int i=1; i!=9; i++){
            enst[i-1][18]=hse[i-1][chah];
    }
}

random = rand() % 50;
if(chah<=2){
    random=12;
}
poc++;
chah = chah+1;

phaz1--;
phaz2--;
phaz3--;

s1=phaz1/2;
s2=phaz2/2;
s3=phaz3/2;
if(s1>1){
if(s1==s2){
    if(s1==s3){
        enst[0][s1-1]= " *  ,  %";

    } else{
        enst[0][s1-1]= "    ,  %";
    }
} else{
    enst[0][s1-1]= "     %  ";
}
} if(s2>1){
if(s2==s3){
    enst[0][s1-1]= "     <  ";
}
} if(s3>1){
enst[0][s3-1]= "     <  ";
}


cout << endl << "znovu? f/... ";
cin >> d;
} while(d!='f');
cout << "------------------------------------------------------------------------------------------------------------------------";
}
