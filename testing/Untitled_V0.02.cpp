
#include <iostream>
#include <cstdlib>
using namespace std;

string inv[12];
string enst[10][18];
string zal[10][19];
string obj[1][19];
string hse[8][3];
string zom[8][1];
string haz[8][1];
string plz[8][1];
string ch[8][1];

char des='s';

int pdes=0;
int chah = 5;
int random = 12;
int sp;
int phaz=0;
int ihaz[3];
int pihaz[3];
int pv=0;
int cv[5];
int cpk=1;

float s1, s2, s3;


int php=20, mhp=10, mbhp=30, bhp=80;
int prot=1;
string wps[7];
string fwps[4];
int nab[4];



void otev(){
// ____________________________________________________chesta+
if(cpk==1){

}
}




int main(){
// ____________________________________________________main

wps[0]="       kudla        ";
wps[1]="     basebolka      ";
wps[2]="     velky kyj      ";
wps[3]="        dyka        ";
wps[4]="        kopi        ";
wps[5]="       katana       ";
wps[6]="    motorová pila   ";

fwps[0]="    hazecí nože     ";
fwps[1]="        luk         ";
fwps[2]="polo-automaticka kus";
fwps[3]="     plamenomet     ";

sp = rand() % 20;

for (int u=1; u!=13; u++){
        inv[u-1]="                    ";
}

for (int u=1; u!=5; u++){
        ihaz[u-1]=0;
        pihaz[u-1]=0;
}
for (int u=1; u!=6; u++){
        cv[u-1]=0;
}
for (int u=1; u!=19; u++){
        obj[0][u-1]="       ";
}

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
plz[4][0]="       ";
plz[5][0]=" ___   ";
plz[6][0]="(*=*)_ ";
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
for (int u=1; u!=19; u++){
        cout << obj[0][u-1];
    }
cout << endl;
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
    phaz=phaz+1;
    if(phaz>3){
        for(int i=1; i!=4;i++){
            if(ihaz[i-1]<1){
                phaz=1;
            }
        }
    }
    for (int i=1; i!=9; i++){
            enst[i-1][18]=haz[i-1][0];
    }
    ihaz[phaz-1]=18;
} else if(random>=10 && random<=11){
    chah=0;
    pv=pv+1;
    if(pv>5){
        for(int i=1; i!=4;i++){
            if(cv[i-1]<1){
                pv=1;
            }
        }
    }
    for (int i=1; i!=9; i++){
            enst[i-1][18]=hse[i-1][chah];
    }
    cv[pv-1]=18;
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

chah = chah+1;


obj[0][pihaz[0]]="        ";
obj[0][pihaz[1]]="        ";
obj[0][pihaz[2]]="        ";

ihaz[0]--;
ihaz[1]--;
ihaz[2]--;
cv[0]--;
cv[1]--;
cv[2]--;
cv[3]--;
cv[4]--;

s1=ihaz[0]/2;
s2=ihaz[1]/2;
s3=ihaz[2]/2;

pihaz[0]=int(s1)-1;
pihaz[1]=int(s2)-1;
pihaz[2]=int(s3)-1;

if(s1>1){
if(s1==s2){
    if(s1==s3){
        obj[0][pihaz[0]]= " *  ,  %";

    } else{
        obj[0][pihaz[1]]= "    ,  %";
    }
} else{
    obj[0][pihaz[0]]= "     %  ";
}
} if(s2>1){
if(s2==s3){
    obj[0][pihaz[1]]= "     <  ";
}
} if(s3>1){
obj[0][pihaz[2]]= "     <  ";
}
pdes=4;
do{
cout << "Co chces podniknout? " << endl;
cout << "- utocit (a), branit (d), healnout se (h); raidnout dum (r), otevrit truhlu(o),spipnout toto a zbyla rozhodnuti(s) ukoncit (f) -" << endl << "            ";
cin >> des;
switch(des){
    case 'a':
        cout << "utok" << endl << endl;
        break;
    case 'd':
        cout << "stit" << endl << endl;
        break;
    case 'h':
        cout << "zlate jablko" << endl << endl;
        break;
    case 'r':
        cout << "FBI open up" << endl << endl;
        break;
    case 'o':
        cout << "truhla" << endl << endl;
        break;
    case 's':
    case 'f':
        break;
    default:
        cout << endl << endl << "bro what the fu*k?" << endl << endl;
}
pdes--;
} while(pdes>1 && des!='s' && des!='f');
cout << endl << cpk << ". kolo" <<endl;



//_________________________________________________________________________________________________________________________________________________________________________________________________
cpk++;
} while(des!='f');
cout << "------------------------------------------------------------------------------------------------------------------------";
}
