
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

string inv[10]; // inventar
string enst[10][18]; // hraci plocha
string zal[10][19]; // zaloha hraci plochy
string obj[1][19]; // plocha pro projektily
string hse[8][3]; // textura domku/vesnice
string zom[8][1]; //textura zombie
string haz[8][1]; // textura hazece
string plz[8][1]; // textura plazice
string ch[8][1]; // textura chesty

int chah = 5; // rozdeleni jedne vesnice

char des='s'; // co chci delat

int pdes=0; // pocet rozhodnuti
int random; // random spawnovani
int sp;
int phaz=0; // pocet hazecu
int ihaz[3]; // pozice hazecu
int pihaz[3]; // projektila haz
int pv=0; // pocet vesnic
int cv[5]; // místo vesnice
int cpk=1; //pocet kol

int vminv=2;
int rullete=rand() % 60;


float s1, s2, s3;


int php=20, mhp=10, mbhp=30, bhp=80;
int prot=1;
string wps[7];
string fwps[4];
string healy[3];
int nab[4][2];
int stat[3];
int npl;
int gnab=(rand() % 20)+10;
int gph=rand() % 10;
int dnp=2;

char anoo;

bool jetam;

void utok(){
for (int t=1;t<9;t++){
    cout << enst[t-1][1];
}
}

// ____________________________________________________chesta
void otev(){
anoo='n';
jetam=false;
gnab=(rand() % 20)+10;
npl= gnab*20;


if(cpk==1){
cout << "nasel jsi kudlu a " << gnab << " hazeci noze ";
inv[0]="       kudla        ";
inv[1]="    hazeci noze   "+ to_string(gnab);
nab[0][0]=gnab;
nab[0][1]=1;

} else{
//for(int i; i<6;i++){ mch[i-1]!=1
    if(enst[7][2]=="|    | "){
        cout << endl << rullete << endl;
        if(rullete==60){
            cout << "nasel jsi motorovou pilu" << endl;
            for(int u=1; u!=8;u++){
                if(wps[6]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            cout << endl << "  ";
            for (int u=1; u!=6; u++){
                cout << "|" << inv[u-1] << "| ";
            }
            cout << endl << "  ";
            for (int u=6; u!=11; u++){
                cout << "|" << inv[u-1] << "| " ;
            }
            cout << endl;

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[6];
                }
            } else{
            inv[dnp-1]=wps[6];
            }
            } while((dnp-1)>9 && anoo!='a');
            }


        } if(rullete==58 || rullete==59){
            cout << "našel jsi katanu" << endl;
            for(int u=1; u!=8;u++){
                if(wps[5]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            cout << endl << "  ";
            for (int u=1; u!=6; u++){
                cout << "|" << inv[u-1] << "| ";
            }
            cout << endl << "  ";
            for (int u=6; u!=11; u++){
                cout << "|" << inv[u-1] << "| " ;
            }
            cout << endl;

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[5];
                }
            } else{
            inv[dnp-1]=wps[5];
            }
            } while((dnp-1)>9 && anoo!='a');
            }

        } if(rullete>52 && rullete<58){
            cout << "nasel jsi kopí" << endl;
            for(int u=1; u!=8;u++){
                if(wps[4]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            cout << endl << "  ";
            for (int u=1; u!=6; u++){
                cout << "|" << inv[u-1] << "| ";
            }
            cout << endl << "  ";
            for (int u=6; u!=11; u++){
                cout << "|" << inv[u-1] << "| " ;
            }
            cout << endl;

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[4];
                }
            } else{
            inv[dnp-1]=wps[4];
            }
            } while((dnp-1)>9 && anoo!='a');
            }

        } if(rullete>48 && rullete<53){
            cout << "nasel jsi machetu" << endl;
            for(int u=1; u!=8;u++){
                if(wps[3]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            cout << endl << "  ";
            for (int u=1; u!=6; u++){
                cout << "|" << inv[u-1] << "| ";
            }
            cout << endl << "  ";
            for (int u=6; u!=11; u++){
                cout << "|" << inv[u-1] << "| " ;
            }
            cout << endl;

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[3];
                }
            } else{
            inv[dnp-1]=wps[3];
            }
            } while((dnp-1)>9 && anoo!='a');
            }

        } if(rullete>43 && rullete<49){
            cout << "nasel jsi velky kyj" << endl;
            for(int u=1; u!=8;u++){
                if(wps[2]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            cout << endl << "  ";
            for (int u=1; u!=6; u++){
                cout << "|" << inv[u-1] << "| ";
            }
            cout << endl << "  ";
            for (int u=6; u!=11; u++){
                cout << "|" << inv[u-1] << "| " ;
            }
            cout << endl;

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[2];
                }
            } else{
            inv[dnp-1]=wps[2];
            }
            } while((dnp-1)>9 && anoo!='a');
            }

        } if(rullete>38 && rullete<44){
            cout << "nasel jsi basebolku";
            for(int u=1; u!=8;u++){
                if(wps[1]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            cout << endl << "  ";
            for (int u=1; u!=6; u++){
                cout << "|" << inv[u-1] << "| ";
            }
            cout << endl << "  ";
            for (int u=6; u!=11; u++){
                cout << "|" << inv[u-1] << "| " ;
            }
            cout << endl;

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[1];
                }
            } else{
            inv[dnp-1]=wps[1];
            }
            } while((dnp-1)>9 && anoo!='a');
            }

        } if(rullete>38 && rullete<39){
            cout << "kudlu";

        } if(rullete==38){
            cout << "nasel jsi plamenomet s naboji " << npl;
            for(int u=1; u!=8;u++){
                if(fwps[3]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            cout << endl << "  ";
            for (int u=1; u!=6; u++){
                cout << "|" << inv[u-1] << "| ";
            }
            cout << endl << "  ";
            for (int u=6; u!=11; u++){
                cout << "|" << inv[u-1] << "| " ;
            }
            cout << endl;

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=fwps[3];
                }
            } else{
            inv[dnp-1]=fwps[3];
            }
            } while((dnp-1)>9 && anoo!='a');
            }

        } if(rullete==36 || rullete==37){
            cout << "nasel jsi kus s " << gnab << " sipi" << endl;
            for(int u=1; u!=8;u++){
                if(fwps[2]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            cout << endl << "  ";
            for (int u=1; u!=6; u++){
                cout << "|" << inv[u-1] << "| ";
            }
            cout << endl << "  ";
            for (int u=6; u!=11; u++){
                cout << "|" << inv[u-1] << "| " ;
            }
            cout << endl;

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=fwps[2];
                }
            } else{
            inv[dnp-1]=fwps[2];
            }
            } while((dnp-1)>9 && anoo!='a');
            }

        } if(rullete>30 && rullete<36){
            cout << "nasel jsi luk s " << gnab << " sipi" << endl;
            for(int u=1; u!=8;u++){
                if(fwps[1]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            cout << endl << "  ";
            for (int u=1; u!=6; u++){
                cout << "|" << inv[u-1] << "| ";
            }
            cout << endl << "  ";
            for (int u=6; u!=11; u++){
                cout << "|" << inv[u-1] << "| " ;
            }
            cout << endl;

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=fwps[1];
                }
            } else{
            inv[dnp-1]=fwps[1];
            }
            } while((dnp-1)>9 && anoo!='a');
            }

        } if(rullete>15 && rullete<31){
            cout << "nasel jsi " << gnab << " hazecich nozu";
            for(int u=1; u!=8;u++){
                if(fwps[0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            cout << endl << "  ";
            for (int u=1; u!=6; u++){
                cout << "|" << inv[u-1] << "| ";
            }
            cout << endl << "  ";
            for (int u=6; u!=11; u++){
                cout << "|" << inv[u-1] << "| " ;
            }
            cout << endl;

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=fwps[0];
                }
            } else{
            inv[dnp-1]=fwps[0];
            }
            } while((dnp-1)>9 && anoo!='a');
            }

        } if(rullete>11 && rullete<16){
            cout << "nasel jsi " << gph << " jablek" << endl;
            for(int u=1; u!=8;u++){
                if(healy[0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            cout << endl << "  ";
            for (int u=1; u!=6; u++){
                cout << "|" << inv[u-1] << "| ";
            }
            cout << endl << "  ";
            for (int u=6; u!=11; u++){
                cout << "|" << inv[u-1] << "| " ;
            }
            cout << endl;

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=healy[0] + to_string(gnab);;
                }
            } else{
            inv[dnp-1]=healy[0]+ to_string(gnab);;
            }
            } while((dnp-1)>9 && anoo!='a');
            }

        } if(rullete>5 && rullete<12){
            cout << "nasel jsi " << gph << " konzerv" << endl;
            for(int u=1; u!=8;u++){
                if(healy[1]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            cout << endl << "  ";
            for (int u=1; u!=6; u++){
                cout << "|" << inv[u-1] << "| ";
            }
            cout << endl << "  ";
            for (int u=6; u!=11; u++){
                cout << "|" << inv[u-1] << "| " ;
            }
            cout << endl;

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=healy[1] + to_string(gnab);;
                }
            } else{
            inv[dnp-1]=healy[1]+ to_string(gnab);;
            }
            } while((dnp-1)>9 && anoo!='a');
            }

        } if(rullete==4 || rullete==5){
            cout << "nasel jsi jeden medkit";
            for(int u=1; u!=8;u++){
                if(healy[2]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            cout << endl << "  ";
            for (int u=1; u!=6; u++){
                cout << "|" << inv[u-1] << "| ";
            }
            cout << endl << "  ";
            for (int u=6; u!=11; u++){
                cout << "|" << inv[u-1] << "| " ;
            }
            cout << endl;

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=healy[2]+ to_string(gnab);;
                }
            } else{
            inv[dnp-1]=healy[2]+ to_string(gnab);;
            }
            } while((dnp-1)>9 && anoo!='a');
            }


        } if(rullete==2 || rullete==3){
            cout << "nic jsi nenasel, musis hledat dal " << endl;

        } if(rullete==1){
            php=php-1;
            cout << "napichl jsi se na past v truhle " << endl << " zivoty: " << php << endl;
        }
    //i=6;
    }
//}
cout << endl;
}
rullete=rand() % 12;
gnab=(rand() % 20)+10;

gph=rand() % 10;
}



int main(){
// ____________________________________________________main

wps[0]="       kudla        ";
wps[1]="     basebolka      ";
wps[2]="     velky kyj      ";
wps[3]="       machetu      ";
wps[4]="        kopi        ";
wps[5]="       katana       ";
wps[6]="    motorová pila   ";

fwps[0]="    hazeci noze   ";
fwps[1]="        luk         ";
fwps[2]="        kus         ";
fwps[3]="     plamenomet     ";

healy[0]="       jablko      ";
healy[1]="      konzerva     ";
healy[2]="       medkit      ";

sp = rand() % 20;
gnab=(rand() % 20)+10;

for (int u=1; u!=13; u++){
        inv[u-1]="                    ";
}
for (int u=1; u!=6; u++){
        stat[u-1]=0;
}
for (int u=1; u!=5; u++){
        ihaz[u-1]=0;
        pihaz[u-1]=0;
        nab[u-1][1]=20;
}
for (int u=1; u!=6; u++){
        cv[u-1]=0;
}
for (int u=1; u!=19; u++){
        obj[0][u-1]="       ";
}

// ____________________________________________textury
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
plz[7][0]=" =\\__/ ";

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








random=12;
for (int i=1; i!=9; i++){
        enst[i-1][2]=ch[i-1][0];
}
// ____________________________________________hlavní_cyklus

do{

// ___________________________________posouvání_pozadí

for (int i=1;i!=19;i++){
    if(i<10){
       cout << "     " << i;
    } else{
        cout << "    " << i;
    }
}
cout << endl;

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

// ___________________________________co_přijde_další_na_scénu_random

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
} else if(random==12){
    for (int i=1; i!=9; i++){
            enst[i-1][18]=ch[i-1][0];
    }
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

// ___________________________________info_o_pozici_věcí

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



// ___________________________________posouvání_projektilů

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

// ___________________________________inventář

cout << endl << "  ";
for (int u=1; u!=6; u++){
        cout << "|" << inv[u-1] << "| ";
}
cout << endl << "  ";
for (int u=6; u!=11; u++){
        cout << "|" << inv[u-1] << "| " ;
}
cout << endl;

// ___________________________________rozhodování

do{
cout << endl << endl << "Co chces podniknout? " << endl;
cout << "- utocit (a), branit (d), healnout se (h); raidnout dum (r), otevrit truhlu(o),skipnout toto a zbyla rozhodnuti(s)        ukoncit (f) -                    ";
cin >> des;
switch(des){
    case 'a':
        utok();
        cout << "utok" << endl << endl;
        break;
    case 'd':
        cout << "stit" << endl << endl;
        break;
    case 'h':
        cout << endl << endl;
        break;
    case 'r':
        cout << "FBI open up" << endl << endl;
        break;
    case 'o':
        otev();
        cout << "truhla" << endl << endl;
        break;
    case 's':
    case 'f':
        break;
    default:
        cout << endl << endl << "bro, you good?" << endl << endl;
}
pdes--;
} while(pdes>1 && des!='s' && des!='f');
cout<< endl<< endl << endl << cpk << ". kolo" << endl << endl << endl;



//_________________________________________________________________________________________________________________________________________________________________________________________________
cpk++;
} while(des!='f');
cout << "------------------------------------------------------------------------------------------------------------------------";
}
