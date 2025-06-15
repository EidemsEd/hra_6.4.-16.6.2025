#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
//#include <vector>
using namespace std;

string inv[10]; // inventar
string enst[10][18]; // hraci plocha
string pla[8][1];  // hráč
string zal[10][19]; // zaloha hraci plochy
string obj[1][19]; // plocha pro projektily
string midbos[9];  // midboss textura
string fbos[11];  // final boss textura
string hse[8][3]; // textura domku/vesnice
string zom[8][1]; // textura zombie
string haz[8][1]; // textura hazece
string plz[8][1]; // textura plazice
string ch[8][1]; // textura chesty

int chah = 5; // rozdeleni jedne vesnice

char des='s'; // co chci delat

int ades=1;

int pph=0;
int pph1=0;
int kpdes1=0;  // kontrola pocet rozhodnuti
int kpdes2=0;
int pdes=0; // pocet rozhodnuti
int random; // random spawnovani
int sp;
int phaz=0; // pocet hazecu
int ihaz[3]; // pozice hazecu
int pihaz[3]; // projektila haz
int pv=0; // pocet vesnic
int cv[5]; // místo vesnice
int cpk=1; //pocet kol
int mvpl;

int vminv=2;
int rullete=rand() % 60;


float s1, s2, s3;


int php=20, mhp=10, mbhp=30, bhp=80;  // player hp; mob hp, midboss hp; final boss hp
int mbhp1=mbhp;
int kills=0;  // killy
int inman[10][2]; //mamagment inventare
string wps[7][2]; // zbranì
string fwps[4][2]; //støelné zbranì
string healy[3][3]; //healy
int nab[4][2]; // jednotlivé náboje
int npl;  //náboje plamenomet
int gnab=(rand() % 20)+10;  // random vygenerované náboje
int gph=rand() % 10;
int dnp=2;  //
int gmhp[10][2];  // veikost hp mobu
int poshp[4];  // posouvání velikosti  hp mobu
int aub=1;
int aub1=1;
int pzab=0;  // počet při zabíjení
int pohel=0;  // pozice vybirani healu
int funfuj;
int hehelp;

char anoo;
bool postr=true;
bool jetam;  // zbraò je už v inv
bool helje;  // heal je v inv pri helovani
bool jeheal;  // je heal v inv pro pri sebrani
bool shld;
bool vzdlog;  // jestli se dá střílet
char blivzd;  // bude se útočit na blízko nebo na dálku
int mist;  // vybrat místo na střelu z dálky
int pmb=-1;  // posunuti minibosse


int phvb=3;  // pocez hazecu v casti 2 a 4



//_________________________________________________________________________________________________________________________________________________________________________________inv
void invahp(){
cout << endl << "  ";
for (int u=1; u!=6; u++){
    cout << "|" << inv[u-1] << "| ";
}
cout << endl << "  ";
for (int u=6; u!=11; u++){
    cout << "|" << inv[u-1] << "| " ;
}
cout << endl;
cout << endl << "                                                  hp:  " << php << "  killy:  " << kills << endl;
}


//_________________________________________________________________________________________________________________________________________________________________________________ ubírání pro hazení
void airstrike(){
for(int i=1; i<=3; i++){
    if(ihaz[i-1]>1){
        if(shld!=true)
            php=php-3;
    }
}
}

//_________________________________________________________________________________________________________________________________________________________________________________ defend
void defend(){
for(int i=1; i<=3; i++){
    if(ihaz[i-1]>1){
        shld=true;
        cout << "schoval jsi se pred projektyly. ";
    } if(zal[6][1]==" ||z|| " || zal[6][1]==" ||H|% " || zal[6][1]=="(*=*)_ "){
        shld=true;
        cout << "defendujes se pred zombiky. ";
        break;
    }
}
}


//_________________________________________________________________________________________________________________________________________________________________________________heal
void healnuti(){
helje=false;
for(int i=1; i<=10; i++){
    if(inman[i-1][1]==2){
        helje=true;
    }
}
if(helje==true){
invahp();
do{
cout << "jaky heal (misto) ";
cin >> pohel;
} while(pohel>10 && pohel<1 || inman[pohel-1][1]!=2);
funfuj= inman[pohel-1][0];
php=php+stoi(healy[funfuj][1]);
for(;php>20;php--){
}
healy[funfuj][2]=to_string(stoi(healy[funfuj][2])-1);
hehelp=stoi(healy[funfuj][2])-1;
if(stoi(healy[funfuj][2])>=1){
if(hehelp<10){
    inv[pohel-1]=healy[funfuj][0] + " " + healy[funfuj][2];
} else{
    inv[pohel-1]=healy[funfuj][0] + healy[funfuj][2];
}
} else{
    inv[pohel-1]="                    ";
    inman[pohel-1][0]=10;
    inman[pohel-1][1]=10;
}
cout << endl << "healnul jsi se na " << php << endl;

} else{
pdes=pdes+1;
}
}

//_________________________________________________________________________________________________________________________________________________________________________________útok

void utok(){
blivzd='n';
for (int i=2; i<=18; i++){
    if (enst[6][i-1]==" ||z|| " || enst[6][i-1]==" ||H|% " || enst[6][i-1]=="(*=*)_ "){
        cout << "chcete na dalku a/n ";
        cin >> blivzd;
        break;
    }
}

if(blivzd=='n'){

if(enst[6][2]==" ||z|| " || enst[6][2]==" ||H|% " || enst[6][2]=="(*=*)_ " || enst[6][3]==" ||z|| " || enst[6][3]==" ||H|% " || enst[6][3]=="(*=*)_ "){
    if(aub==1){
        kpdes1=pdes;
    }
    aub++;
}
 if(zal[6][1]==" ||z|| " || zal[6][1]==" ||H|% " || zal[6][1]=="(*=*)_ "){
    cout << endl << "nebezpeci na pozici 1" << endl;
    do{
    cout << "na jakem policku chces vzit zbran? " << stoi(enst[1][1]) << stoi(zal[1][1]);
    cin >> ades;
    } while(ades>10 || ades<1);
    if(inman[ades-1][1]==0){
        cout << "chces " << wps[*inman[ades]][0];
        if(zal[1][1]=="       "){
            gmhp[poshp[0]][0]=mhp - stoi(fwps[*inman[ades]][1]);
        } else{
            gmhp[poshp[0]][0]=stoi(enst[1][1]) - stoi(fwps[*inman[ades]][1]);
        }
    } else if(inman[ades-1][1]==1){
        cout << "chces " << fwps[*inman[ades]][0];
        if(zal[1][1]=="       "){
            gmhp[poshp[0]][0]=mhp - stoi(fwps[*inman[ades]][1]);
        } else{
            gmhp[poshp[0]][0]=stoi(enst[1][1]) - stoi(fwps[*inman[ades]][1]);
        }
    }
    gmhp[poshp[0]][1]=2;
    if(gmhp[poshp[0]][0]<10){
        enst[1][1]="   " + std::to_string(gmhp[poshp[0]][0]-3) + "   ";
    } else if(gmhp[poshp[0]][0]<100){
        enst[1][1]="  " + std::to_string(gmhp[poshp[0]][0]-3) + "   ";
    }
    if (gmhp[poshp[0]][0]<1){
        cout << "zabil jsi nepritele ";
        kills=kills+1;
        for(int i=1; i<=10; i++){
            enst[i-1][1]= "       ";
        }
    }

} else if(enst[6][2]==" ||z|| " || enst[6][2]==" ||H|% " || enst[6][2]=="(*=*)_ "){
    cout << endl << "nebezpeci na pozici 2" << endl;
    do{
    cout << "na jakem policku chces vzit zbran? ";
    cin >> ades;
    } while(ades>10 || ades<1);
    // mvp1 = *inman[ades];
    if(inman[ades-1][1]==0){
        cout << "chces " << wps[*inman[ades]][0];
        if(enst[1][2]=="       "){
            gmhp[poshp[1]][0]=mhp - stoi(fwps[*inman[ades]][1]);
        } else{
            gmhp[poshp[1]][0]=stoi(enst[1][2]) - stoi(fwps[*inman[ades]][1]);
        }
    } else if(inman[ades-1][1]==1){
        cout << "chces " << fwps[*inman[ades]][0];
        if(enst[1][2]=="       "){
            gmhp[poshp[1]][0]=mhp - stoi(fwps[*inman[ades]][1]);
        } else{
            gmhp[poshp[1]][0]=stoi(enst[1][2]) - stoi(fwps[*inman[ades]][1]);
        }
    }
    gmhp[poshp[1]][1]=2;
    enst[1][2]="   " + std::to_string(gmhp[poshp[1]][0]) + "   ";
    if (gmhp[poshp[1]][0]<1){
        kills=kills+1;
        cout << "zabil jsi nepritele ";
        for(int i=1; i<=10; i++){
            enst[i-1][2]= "       ";
        }
    }


} else if(enst[6][3]==" ||z|| " || enst[6][3]==" ||H|% " || enst[6][3]=="(*=*)_ "){
    cout << endl << "nebezpeci na pozici 3" << endl;
    do{
    cout << "na jakem policku chces vzit zbran? ";
    cin >> ades;
    } while(ades>10 || ades<1);
    if(inman[ades-1][1]==0){
        cout << "chces " << wps[*inman[ades]][0];
        if(enst[1][3]=="       "){
            gmhp[poshp[3]][0]=mhp - stoi(fwps[*inman[ades]][1]);
        } else{
            gmhp[poshp[3]][0]=stoi(enst[1][3]) - stoi(fwps[*inman[ades]][1]);
        }
    } else if(inman[ades-1][1]==1){
        cout << "chces " << fwps[*inman[ades]][0];
        if(enst[1][3]=="       "){
            gmhp[poshp[3]][0]=mhp - stoi(fwps[*inman[ades]][1]);
        } else{
            gmhp[poshp[3]][0]=stoi(enst[1][2]) - stoi(fwps[*inman[ades]][1]);
        }
    }
    gmhp[poshp[3]][1]=2;
    if(gmhp[poshp[3]][0]<10){
        enst[1][3]="   " + std::to_string(gmhp[poshp[3]][0]-3) + "   ";
    } else if(gmhp[poshp[3]][0]<100){
        enst[1][3]="  " + std::to_string(gmhp[poshp[3]][0]-3) + "   ";
    }
    if (gmhp[poshp[3]][0]<1){
        cout << "zabil jsi nepritele ";
        kills=kills+1;
        for(int i=1; i<=10; i++){
            enst[i-1][3]= "       ";
        }
    }

} else{
    pdes=pdes+1;
}
for(int i=1; i<=10; i++){
    if(gmhp[i-1][0]<=0){
        for(int i=1; i<=9; i++){
            enst[i-1][gmhp[i-1][1]]="       ";
            gmhp[i-1][1]=0;
            gmhp[i-1][0]=0;
        }
    }
}


} else{
    do{
        cout << "na jake misto to bude ";
        cin >> mist;
    } while(mist<2 || mist>18 || enst[6][mist-1]!=" ||z|| " && enst[6][mist-1]!=" ||H|% " && enst[6][mist-1]!="(*=*)_ ");
    do{
    cout << "na jakem policku chces vzit zbran? ";
    cin >> ades;
    } while(ades>10 || ades<1 && inman[ades-1][1]==1);
    cout << "chces " << fwps[*inman[ades-1]][0] << "|" << enst[1][mist-1] << "|";
    if(enst[1][mist-1]=="       "){
        cout << "1";
        gmhp[poshp[2]][0]=mhp - stoi(fwps[*inman[ades-1]][1]);
    } else{
        cout << "2";
        gmhp[poshp[2]][0]=stoi(enst[1][mist-1]) - stoi(fwps[*inman[ades-1]][1]);
    }

    if(gmhp[poshp[0]][0]<10){
        enst[1][mist-1]="   " + std::to_string(gmhp[poshp[0]][0]) + "   ";
    } else if(gmhp[poshp[0]][0]<100){
        enst[1][mist-1]="  " + std::to_string(gmhp[poshp[0]][0]) + "   ";
    }
    nab[0][0]--;
    inv[ades-1]= fwps[0][0]+ to_string(nab[0][0]);
    if(nab[0][0]<1){
        inv[ades-1]="                    ";
        nab[0][1]=-1;
    }
    if (gmhp[poshp[2]][0]<1){
        cout << "zabil jsi nepritele ";
        kills=kills+1;
        for(int i=1; i<=10; i++){
            enst[i-1][mist-1]= "       ";
        }
    }
}
}



void jetu(){
cout << zal[6][1] << zal[6][2] << zal[6][3] << endl;
postr=true;
if(zal[6][3]==" ||z|| "){
    for(int i=1; i<9; i++){
        zal[i-1][4]=zom[i-1][0];
        zal[i-1][4]=zom[i-1][0];
    }
    if(shld!=true){
            php=php-5;
    }
} if(zal[6][3]==" ||H|% "){
    postr=false;
    for(int i=1; i<9; i++){
        enst[i-1][3]=haz[i-1][0];
    }
    if(shld!=true){
            php=php-3;
    }
} if(zal[6][3]=="(*=*)_ "){
    postr=false;
    for(int i=1; i<9; i++){
        enst[i-1][3]=plz[i-1][0];
    }
    if(shld!=true){
            php=php-2;
    }
}

}


// ______________________________________________________________________________________________________________________________________dům
void raiding() {
anoo='n';
jetam=true;
gnab=(rand() % 20)+10;
npl= gnab*20;
jeheal=false;
if(enst[6][2]==" | | O|" || zal[6][1]==" | | O|" || enst[6][2]=="      |" || zal[6][1]=="      |"){
        if(rullete==60){
            cout << "nasel jsi motorovou pilu" << endl;
            for(int u=1; u!=8;u++){
                if(wps[6][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[6][0];
                    inman[dnp-1][0]=6;
                    inman[dnp-1][1]=0;
                }
            } else{
            inv[dnp-1]=wps[6][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=6;
            inman[dnp-1][1]=0;
            }


        } if(rullete==58 || rullete==59){
            cout << "našel jsi katanu" << endl;
            for(int u=1; u!=8;u++){
                if(wps[5][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[5][0];
                    inman[dnp-1][0]=5;
                    inman[dnp-1][1]=0;
                }
            } else{
            inv[dnp-1]=wps[5][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=5;
            inman[dnp-1][1]=0;
            }

        } if(rullete>52 && rullete<58){
            cout << "nasel jsi kopí" << endl;
            for(int u=1; u!=8;u++){
                if(wps[4][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[4][0];
                    inman[dnp-1][0]=4;
                    inman[dnp-1][1]=0;
                }
            } else{
            inv[dnp-1]=wps[4][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=4;
            inman[dnp-1][1]=0;
            }

        } if(rullete>48 && rullete<53){
            cout << "nasel jsi machetu" << endl;
            for(int u=1; u!=8;u++){
                if(wps[3][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[3][0];
                    inman[dnp-1][0]=3;
                    inman[dnp-1][1]=0;
                }
            } else{
            inv[dnp-1]=wps[3][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=3;
            inman[dnp-1][1]=0;
            }

        } if(rullete>43 && rullete<49){
            cout << "nasel jsi velky kyj" << endl;
            for(int u=1; u!=8;u++){
                if(wps[2][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[2][0];
                    inman[dnp-1][0]=2;
                    inman[dnp-1][1]=0;
                }
            } else{
            inv[dnp-1]=wps[2][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=2;
            inman[dnp-1][1]=0;
            }

        } if(rullete>38 && rullete<44){
            cout << "nasel jsi basebolku";
            for(int u=1; u!=8;u++){
                if(wps[1][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[1][0];
                    inman[dnp-1][0]=1;
                    inman[dnp-1][1]=0;
                }
            } else{
            inv[dnp-1]=wps[1][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=1;
            inman[dnp-1][1]=0;
            }

        } if(rullete==38){
            cout << "nasel jsi plamenomet s naboji " << npl;
            for(int u=1; u!=8;u++){
                if(fwps[3][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=fwps[3][0];
                    inman[dnp-1][0]=3;
                    inman[dnp-1][1]=1;
                }
            } else{
            inv[dnp-1]=fwps[3][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=3;
            inman[dnp-1][1]=1;
            }

        } if(rullete==36 || rullete==37){
            cout << "nasel jsi kus s " << gnab << " sipi" << endl;
            for(int u=1; u!=8;u++){
                if(fwps[2][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=fwps[2][0];
                    inman[dnp-1][0]=2;
                    inman[dnp-1][1]=1;
                }
            } else{
            inv[dnp-1]=fwps[2][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=2;
            inman[dnp-1][1]=1;
            }

        } if(rullete>30 && rullete<36){
            cout << "nasel jsi luk s " << gnab << " sipi" << endl;
            for(int u=1; u!=8;u++){
                if(fwps[1][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=fwps[1][0];
                    inman[dnp-1][0]=1;
                    inman[dnp-1][1]=1;
                }
            } else{
            inv[dnp-1]=fwps[1][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=1;
            inman[dnp-1][1]=1;
            }

        } if(rullete>11 && rullete<16){
            cout << "nasel jsi " << gph << " jablek" << endl;
            for(int u=1; u!=8;u++){
                if(healy[0][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            for(int i=1; i<=10; i++){
                cout << inman[i-1][0];
                if(inman[i-1][1]==2 && inman[i-1][0]==0){
                    jeheal=true;
                }
            }
            if(jeheal==false){
            invahp();
            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    if(gph<10){
                        inv[dnp-1]=healy[0][0] + " " + to_string(gph);
                    } else if(gph<100){
                        inv[dnp-1]=healy[0][0] + to_string(gph);
                    }
                    inman[dnp-1][0]=0;
                    inman[dnp-1][1]=2;
                    healy[0][2]=to_string(gph);
                }
            } else{
            if(gph<10){
                inv[dnp-1]=healy[0][0] + " " + to_string(gph);
            } else if(gph<100){
                inv[dnp-1]=healy[0][0] + to_string(gph);
            }
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=0;
            inman[dnp-1][1]=2;
            healy[0][2]=to_string(gph);
            } else{
                healy[0][2]=to_string(stoi(healy[0][2])+gph);
                if(stoi(healy[0][2])<10){
                    inv[dnp-1]=healy[0][0] + " " + healy[0][2];
                } else{
                    inv[dnp-1]=healy[0][0] + healy[0][2];
                }
                invahp();
            }
            }

        } if(rullete>5 && rullete<12){
            cout << "nasel jsi " << gph << " konzerv" << endl;
            for(int u=1; u<=8;u++){
                if(healy[1][0]==inv[u-1]){
                    jetam=false;
                    cout <<jetam;
                    cout << "tuto vec uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){


            for(int i=1; i<=10; i++){
                if(inman[i-1][1]==2 && inman[i-1][0]==1){
                    jeheal=true;
                }
            }
            if(jeheal==false){
            invahp();
            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    if(gph<10){
                        inv[dnp-1]=healy[1][0] + " " + to_string(gph);
                    } else if(gph<100){
                        inv[dnp-1]=healy[1][0] + to_string(gph);
                    }
                    inman[dnp-1][0]=1;
                    inman[dnp-1][1]=2;
                    healy[1][2]=to_string(gph);
                }
            } else{
            if(gph<10){
                inv[dnp-1]=healy[1][0] + " " + to_string(gph);
            } else if(gph<100){
                inv[dnp-1]=healy[1][0] + to_string(gph);
            }
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=1;
            inman[dnp-1][1]=2;
            healy[1][2]=to_string(gph);
            } else{
                healy[1][2]=to_string(stoi(healy[1][2])+gph);
                if(stoi(healy[1][2])<10){
                    inv[dnp-1]=healy[1][0] + " " + healy[1][2];
                } else{
                    inv[dnp-1]=healy[1][0] + healy[1][2];
                }
                invahp();
            }
            }

        } if(rullete==4 || rullete==5){
            cout << "nasel jsi jeden medkit";
            for(int u=1; u!=8;u++){
                if(healy[2][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){


            for(int i=1; i<=10; i++){
                cout << inman[i-1][0];
                if(inman[i-1][1]==2 && inman[i-1][0]==0){
                    jeheal=true;
                }
            }
            if(jeheal==false){
            invahp();
            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    if(gph<10){
                        inv[dnp-1]=healy[2][0] + " " + to_string(gph);
                    } else if(gph<100){
                        inv[dnp-1]=healy[2][0] + to_string(gph);
                    }
                    inman[dnp-1][0]=2;
                    inman[dnp-1][1]=2;
                    healy[2][2]=to_string(gph);
                }
            } else{
            inv[dnp-1]=healy[2][0] + to_string(gph);
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=2;
            inman[dnp-1][1]=2;
            if(gph<10){
                inv[dnp-1]=healy[2][0] + " " + to_string(gph);
            } else if(gph<100){
                inv[dnp-1]=healy[2][0] + to_string(gph);
            }
            } else{
                healy[2][2]=to_string(stoi(healy[2][2])+gph);
                if(stoi(healy[2][2])<10){
                    inv[dnp-1]=healy[2][0] + " " + healy[2][2];
                } else{
                    inv[dnp-1]=healy[2][0] + healy[2][2];
                }
                invahp();
            }
            }

        } if(rullete==2 || rullete==3){
            cout << "nic jsi nenasel, musis hledat dal " << endl;

        } if(rullete==1 || rullete>15 && rullete<31 || rullete>38 && rullete<39){
            php=php-1;
            cout << "napichl jsi se na past v truhle " << endl << " zivoty: " << php << endl;
        }


        if (enst[6][2]==hse[6][0]){
            for (int u=2; u<=4;u++){
                for(int i=1; i<=9; i++){
                    enst[i-1][u]= "       ";
                }
            }
        } else if (enst[6][3]==hse[6][0]){
            for (int u=3; u<=5;u++){
                for(int i=1; i<=9; i++){
                    enst[i-1][u]= "       ";
                }
            }
        } else if (enst[6][2]==hse[6][1]){
            for (int u=2; u<=4;u++){
                for(int i=1; i<=9; i++){
                    enst[i-1][u-1]= "       ";
                }
            }
        } else if (enst[6][3]==hse[6][1]){
            for (int u=3; u<=5;u++){
                for(int i=1; i<=9; i++){
                    enst[i-1][u-1]= "       ";
                }
            }
        } else{
            cout << "error 404 entity not found";
    }

    } else{
        pdes=pdes+1;
    }

cout << endl;
rullete=rand() % 60+1;
gnab=(rand() % 20)+10;

gph=rand() % 10;
}



// ______________________________________________________________________________________________________________________________________chesta
void otev(){
anoo='n';
jetam=true;
gnab=(rand() % 20)+10;
npl= gnab*20;
jeheal=false;

if(cpk==1){
cout << "nasel jsi kudlu a " << gnab << " hazeci noze ";
inv[0]="       kudla        ";
inv[1]=fwps[0][0]+ to_string(gnab);
nab[0][0]=gnab;
nab[0][1]=1;
inman[0][0]=0;
inman[0][1]=0;
inman[1][0]=0;
inman[1][1]=1;
for(int i=1; i<=9; i++){
    enst[i-1][2]= "       ";
} } else{

    if(zal[6][1]=="| () | " || enst[6][2]=="| () | " || enst[6][3]=="| () | "){
        if(rullete==60){
            cout << "nasel jsi motorovou pilu" << endl;
            for(int u=1; u!=8;u++){
                if(wps[6][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[6][0];
                    inman[dnp-1][0]=6;
                    inman[dnp-1][1]=0;
                }
            } else{
            inv[dnp-1]=wps[6][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=6;
            inman[dnp-1][1]=0;
            }


        } if(rullete==58 || rullete==59){
            cout << "našel jsi katanu" << endl;
            for(int u=1; u!=8;u++){
                if(wps[5][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[5][0];
                    inman[dnp-1][0]=5;
                    inman[dnp-1][1]=0;
                }
            } else{
            inv[dnp-1]=wps[5][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=5;
            inman[dnp-1][1]=0;
            }

        } if(rullete>52 && rullete<58){
            cout << "nasel jsi kopí" << endl;
            for(int u=1; u!=8;u++){
                if(wps[4][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[4][0];
                    inman[dnp-1][0]=4;
                    inman[dnp-1][1]=0;
                }
            } else{
            inv[dnp-1]=wps[4][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=4;
            inman[dnp-1][1]=0;
            }

        } if(rullete>48 && rullete<53){
            cout << "nasel jsi machetu" << endl;
            for(int u=1; u!=8;u++){
                if(wps[3][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[3][0];
                    inman[dnp-1][0]=3;
                    inman[dnp-1][1]=0;
                }
            } else{
            inv[dnp-1]=wps[3][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=3;
            inman[dnp-1][1]=0;
            }

        } if(rullete>43 && rullete<49){
            cout << "nasel jsi velky kyj" << endl;
            for(int u=1; u!=8;u++){
                if(wps[2][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[2][0];
                    inman[dnp-1][0]=2;
                    inman[dnp-1][1]=0;
                }
            } else{
            inv[dnp-1]=wps[2][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=2;
            inman[dnp-1][1]=0;
            }

        } if(rullete>38 && rullete<44){
            cout << "nasel jsi basebolku";
            for(int u=1; u!=8;u++){
                if(wps[1][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=wps[1][0];
                    inman[dnp-1][0]=1;
                    inman[dnp-1][1]=0;
                }
            } else{
            inv[dnp-1]=wps[1][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=1;
            inman[dnp-1][1]=0;
            }

        } if(rullete>38 && rullete<39){
            cout << "kudlu";

        } if(rullete==38){
            cout << "nasel jsi plamenomet s naboji " << npl;
            for(int u=1; u!=8;u++){
                if(fwps[3][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=fwps[3][0];
                    inman[dnp-1][0]=3;
                    inman[dnp-1][1]=1;
                }
            } else{
            inv[dnp-1]=fwps[3][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=3;
            inman[dnp-1][1]=1;
            }

        } if(rullete==36 || rullete==37){
            cout << "nasel jsi kus s " << gnab << " sipi" << endl;
            for(int u=1; u!=8;u++){
                if(fwps[2][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=fwps[2][0];
                    inman[dnp-1][0]=2;
                    inman[dnp-1][1]=1;
                }
            } else{
            inv[dnp-1]=fwps[2][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=2;
            inman[dnp-1][1]=1;
            }

        } if(rullete>30 && rullete<36){
            cout << "nasel jsi luk s " << gnab << " sipi" << endl;
            for(int u=1; u!=8;u++){
                if(fwps[1][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            invahp();

            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    inv[dnp-1]=fwps[1][0];
                    inman[dnp-1][0]=1;
                    inman[dnp-1][1]=1;
                }
            } else{
            inv[dnp-1]=fwps[1][0];
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=1;
            inman[dnp-1][1]=1;
            }

        } if(rullete>15 && rullete<31){
            cout << "nasel jsi " << gph << " ponicenich hazecich nozu nelze je pouzivat";
            cout << "tuto zbran uz mas musis si vzit jinou  ";

        } if(rullete>11 && rullete<16){
            cout << "nasel jsi " << gph << " jablek" << endl;
            for(int u=1; u!=8;u++){
                if(healy[0][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){

            for(int i=1; i<=10; i++){
                cout << inman[i-1][0];
                if(inman[i-1][1]==2 && inman[i-1][0]==0){
                    jeheal=true;
                }
            }
            if(jeheal==false){
            invahp();
            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    if(gph<10){
                        inv[dnp-1]=healy[0][0] + " " + to_string(gph);
                    } else if(gph<100){
                        inv[dnp-1]=healy[0][0] + to_string(gph);
                    }
                    inman[dnp-1][0]=0;
                    inman[dnp-1][1]=2;
                    healy[0][2]=to_string(gph);
                }
            } else{
            if(gph<10){
                inv[dnp-1]=healy[0][0] + " " + to_string(gph);
            } else if(gph<100){
                inv[dnp-1]=healy[0][0] + to_string(gph);
            }
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=0;
            inman[dnp-1][1]=2;
            healy[0][2]=to_string(gph);
            } else{
                healy[0][2]=to_string(stoi(healy[0][2])+gph);
                if(stoi(healy[0][2])<10){
                    inv[dnp-1]=healy[0][0] + " " + healy[0][2];
                } else{
                    inv[dnp-1]=healy[0][0] + healy[0][2];
                }
                invahp();
            }
            }

        } if(rullete>5 && rullete<12){
            cout << "nasel jsi " << gph << " konzerv" << endl;
            for(int u=1; u<=8;u++){
                if(healy[1][0]==inv[u-1]){
                    jetam=false;
                    cout <<jetam;
                    cout << "tuto vec uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){


            for(int i=1; i<=10; i++){
                if(inman[i-1][1]==2 && inman[i-1][0]==1){
                    jeheal=true;
                }
            }
            if(jeheal==false){
            invahp();
            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    if(gph<10){
                        inv[dnp-1]=healy[1][0] + " " + to_string(gph);
                    } else if(gph<100){
                        inv[dnp-1]=healy[1][0] + to_string(gph);
                    }
                    inman[dnp-1][0]=1;
                    inman[dnp-1][1]=2;
                    healy[1][2]=to_string(gph);
                }
            } else{
            if(gph<10){
                inv[dnp-1]=healy[1][0] + " " + to_string(gph);
            } else if(gph<100){
                inv[dnp-1]=healy[1][0] + to_string(gph);
            }
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=1;
            inman[dnp-1][1]=2;
            healy[1][2]=to_string(gph);
            } else{
                healy[1][2]=to_string(stoi(healy[1][2])+gph);
                if(stoi(healy[1][2])<10){
                    inv[dnp-1]=healy[1][0] + " " + healy[1][2];
                } else{
                    inv[dnp-1]=healy[1][0] + healy[1][2];
                }
                invahp();
            }
            }

        } if(rullete==4 || rullete==5){
            cout << "nasel jsi jeden medkit";
            for(int u=1; u!=8;u++){
                if(healy[2][0]==inv[u-1]){
                    jetam=false;
                    cout << "tuto zbran uz mas musis si vzit jinou  ";
                }
            }

            if(jetam==true){


            for(int i=1; i<=10; i++){
                cout << inman[i-1][0];
                if(inman[i-1][1]==2 && inman[i-1][0]==0){
                    jeheal=true;
                }
            }
            if(jeheal==false){
            invahp();
            do{
            cout << "na jake misto ji chtete dat? ";
            cin >> dnp;
            if(inv[dnp-1]!="                    "){
                cout << "chcete vvazne nahradit " << inv[dnp];
                cout << "? (a/n) ";
                cin >> anoo;
                if(anoo=='a'){
                    if(gph<10){
                        inv[dnp-1]=healy[2][0] + " " + to_string(gph);
                    } else if(gph<100){
                        inv[dnp-1]=healy[2][0] + to_string(gph);
                    }
                    inman[dnp-1][0]=2;
                    inman[dnp-1][1]=2;
                    healy[2][2]=to_string(gph);
                }
            } else{
            inv[dnp-1]=healy[2][0] + to_string(gph);
            }
            } while((dnp-1)>9 && anoo!='a');
            inman[dnp-1][0]=2;
            inman[dnp-1][1]=2;
            if(gph<10){
                inv[dnp-1]=healy[2][0] + " " + to_string(gph);
            } else if(gph<100){
                inv[dnp-1]=healy[2][0] + to_string(gph);
            }
            } else{
                healy[2][2]=to_string(stoi(healy[2][2])+gph);
                if(stoi(healy[2][2])<10){
                    inv[dnp-1]=healy[2][0] + " " + healy[2][2];
                } else{
                    inv[dnp-1]=healy[2][0] + healy[2][2];
                }
                invahp();
            }
            }

        } if(rullete==2 || rullete==3){
            cout << "nic jsi nenasel, musis hledat dal " << endl;

        } if(rullete==1){
            php=php-1;
            cout << "napichl jsi se na past v truhle " << endl << " zivoty: " << php << endl;
        }

        if (zal[6][1]=="| () | " || enst[6][1]=="| () | "){
            for(int i=1; i<=9; i++){
                enst[i-1][1]= "       ";
            }
        } else if (enst[6][2]=="| () | "){
            for(int i=1; i<=9; i++){
                enst[i-1][2]= "       ";
            }
        } else if (enst[6][3]=="| () | "){
            for(int i=1; i<=9; i++){
                enst[i-1][3]= "       ";
            }
        } else{
            cout << "error 404 entity not found";
    }

    } else{
        pdes=pdes+1;
    }

cout << endl;
}
rullete=rand() % 60+1;
gnab=(rand() % 20)+10;

gph=rand() % 10;
}

void mibos(){

}

void ahaz(){
    if(phvb>0){

    }
}








int main(){
// ____________________________________________________main

// int = stoi(string);

wps[0][0]="       kudla        ";
wps[1][0]="     basebolka      ";
wps[2][0]="     velky kyj      ";
wps[3][0]="       machetu      ";
wps[4][0]="        kopi        ";
wps[5][0]="       katana       ";
wps[6][0]="    motorová pila   ";

wps[0][1]="5";
wps[1][1]="8";
wps[2][1]="9";
wps[3][1]="12";
wps[4][1]="15";
wps[5][1]="20";
wps[6][1]="28";

fwps[0][0]="    hazeci noze   ";
fwps[1][0]="        luk       ";
fwps[2][0]="        kus       ";
fwps[3][0]="     plamenomet   ";

fwps[0][1]="3";
fwps[1][1]="7";
fwps[2][1]="11";
fwps[3][1]="16";

healy[0][0]="       jablko     ";
healy[1][0]="      konzerva    ";
healy[2][0]="       medkit     ";

healy[0][1]="2";
healy[1][1]="4";
healy[2][1]="12";

sp = rand() % 20;
gnab=(rand() % 20)+10;

for (int u=1; u!=13; u++){
        inv[u-1]="                    ";
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

for (int u=1; u!=11; u++){
    for (int i=1; i!=4; i++){
        inman[u-1][i-1]=10;
    }
}

for (int i=1; i<=10; i++){
    gmhp[i-1][0]=mhp;
    gmhp[i-1][1]=0;
}

poshp[0]=0;
poshp[1]=1;


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

zom[1][0]="       ";
zom[2][0]="  ___  ";
zom[3][0]=" |. x| ";
zom[4][0]=" | = | ";
zom[5][0]="  \\ /  ";
zom[6][0]=" ||z|| ";
zom[7][0]="  |||  ";

haz[1][0]="       ";
haz[2][0]="  ___, ";
haz[3][0]="<|. .|-";
haz[4][0]=" | = | ";
haz[5][0]="  \\ / ;";
haz[6][0]=" ||H|% ";
haz[7][0]="  |||  ";

plz[1][0]="       ";
plz[2][0]="       ";
plz[3][0]="       ";
plz[4][0]="       ";
plz[5][0]=" ___   ";
plz[6][0]="(*=*)_ ";
plz[7][0]=" =\\__/ ";

ch[1][0]="       ";
ch[2][0]="       ";
ch[3][0]="       ";
ch[4][0]="       ";
ch[5][0]=" _____ ";
ch[6][0]="| () | ";
ch[7][0]="|    | ";

pla[0][0]="      ";
pla[1][0]="      ";
pla[2][0]=" .___ ";
pla[3][0]=" |. ,|";
pla[4][0]=" | _ |";
pla[5][0]="  \\ / ";
pla[6][0]=" ||0||";
pla[7][0]="  ||| ";



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
do{

// ___________________________________posouvání_pozadí
cout << "   ";
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
    cout << pla[i-1][0];
    for (int u=3; u!=19; u++){
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
    enst[i][18]= "      ";
}
for (int i=1; i!=9; i++){
    for (int u=2; u!=18; u++){
        if(postr!=false && u!=2){
            enst[i][u]=zal[i][u];
        }
    }
}

// ___________________________________co_pøijde_další_na_scénu_random

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

// ___________________________________info_o_pozici_vìcí

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



// ___________________________________posouvání_projektilù

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

// ___________________________________inventáø

invahp();

// ___________________________________rozhodování

do{
cout << endl << endl << "Co chces podniknout? " << endl;
cout << "- utocit (a), branit (d), healnout se (h); raidnout dum (r), otevrit truhlu(o),skipnout toto a zbyla rozhodnuti(s)        ukoncit (f) -                    ";
cin >> des;
switch(des){
    case 'a':
        utok();
        cout << endl;
        break;
    case 'd':
        defend();
        cout << endl;
        break;
    case 'h':
        healnuti();
        cout << endl;
        break;
    case 'r':
        raiding();
        cout  << endl;
        break;
    case 'o':
        otev();
        cout << endl;
        break;
    case 's':
    case 'f':
    case 'g':
        break;
    default:
        cout << endl << "bro, you good?" << endl;
        pdes=pdes+1;
}
pdes--;

} while(pdes>1 && des!='s' && des!='f');
cout<< endl<< endl << endl << cpk << ". kolo" << endl << endl << endl;
pph=pph+1;
cout << shld << "-" << endl;
if(shld!=true){
    airstrike();
}
jetu();
shld=false;


//_________________________________________________________________________________________________________________________________________________________________________________________________
cpk++;
} while (kills<21 && des!='f' && php>0 && des!='g');

midbos[0]="          ____    _";
midbos[1]="   &/  *=|  / ";
midbos[2]="   |() ()| |  ";
midbos[3]="   |_   _| \\  ";
midbos[4]="   __|  |_/ / ";
midbos[5]="  /  |x|  _/  ";
midbos[6]=" //|  _  |    ";
midbos[7]="   | | | |    ";
midbos[8]="   |x| | |    ";
if(des!='f'){
phvb=3;
do{
pmb = rand() % 4+1;

if(pmb==1){
cout << "       Pripravuje se na utok" << endl;
cout << "                           " << mbhp1 << endl;
cout << "                " << midbos[0] << endl;
for (int i=1; i!=9; i++){
    cout << pla[i-1][0];
    cout << "               ";
    cout << midbos[i];
    cout << "       ";
    if(phvb>0){
    cout << haz[i-1][0];
    if(phvb>1){
    cout << haz[i-1][0];
    if(phvb>2){
    cout << haz[i-1][0];
    }}}
    cout << endl;
}
cout << "----------------------------------------------------------------" << endl <<endl << endl;
} else if(pmb==2){
cout << "       Pozor utoci silne, aby te neomracil" << endl;
cout << "            " << mbhp1 << endl;
cout << " " << midbos[0] << endl;
for (int i=1; i!=9; i++){

    cout << pla[i-1][0];
    cout << midbos[i];
    cout << "               ";
    cout << "       ";
    if(phvb>0){
    cout << haz[i-1][0];
    if(phvb>1){
    cout << haz[i-1][0];
    if(phvb>2){
    cout << haz[i-1][0];
    }}}
    cout << endl;
}
cout << "----------------------------------------------------------------" << endl <<endl << endl;
} else if(pmb==3){
cout << "       Ted do nej utoc blokuje strely na dalku" << endl;
cout << "            " << mbhp1 << endl;
cout << " " << midbos[0] << endl;
for (int i=1; i!=9; i++){

    cout << pla[i-1][0];
    cout << midbos[i];
    cout << "               ";
    cout << "       ";
    if(phvb>0){
    cout << haz[i-1][0];
    if(phvb>1){
    cout << haz[i-1][0];
    if(phvb>2){
    cout << haz[i-1][0];
    }}}
    cout << endl;
}
cout << "----------------------------------------------------------------" << endl <<endl << endl;
} else{
cout << "       Pozor pouziva svuj retez jako bic!" << endl;
cout << "                           " << mbhp1 << endl;
cout << "                " << midbos[0] << endl;
for (int i=1; i!=9; i++){
    cout << pla[i-1][0];
    cout << "               ";
    cout << midbos[i];
    cout << "       ";
    if(phvb>0){
    cout << haz[i-1][0];
    if(phvb>1){
    cout << haz[i-1][0];
    if(phvb>2){
    cout << haz[i-1][0];
    }}}
    cout << endl;
}
cout << "----------------------------------------------------------------" << endl <<endl << endl;
}
do{
cout << "Co udelas budes, utocit do midi bosse (b), utocit na hazece (a), heal (h), skrit/vytahnout stit (d), konec (f) ";
cin >> des;
switch(des){
    case 'b':
        mibos();
        cout << endl;
        break;
    case 'a':
        ahaz();
        cout << endl;
        break;
    case 'd':
        defend();
        cout << endl;
        break;
    case 'h':
        healnuti();
        cout << endl;
        break;
    case 'f':
        break;
    default:
        cout << endl << "bro, you good?" << endl;
        pdes=pdes+1;
}
pdes--;
} while(pdes>1 && des!='s' && des!='f');
mbhp1--;
} while(mbhp1>0 && php>0 && des!='f');
}

cout << "dal jsi to" << endl;
} while(des!='f' && php>0);
cout << "Peace at last";
}
