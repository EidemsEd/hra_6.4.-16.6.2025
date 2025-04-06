#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int plziv = 100, x, y,v=12;
int r=1, sp=2;
string tof= "ano";
string chd[13][13];
char wtl='a';


void jabko(int u){
    cout << "healovat? (ano/ne) ";
    cin >> tof;
    if(tof=="ano"){
        plziv = plziv + 5;
    }
}
void prPt(string inventar[], int pocet){
    do{
    cout << "kde v x ";
    cin >> x;
    cout << "kde v y ";
    cin >> y;
    } while(chd[x-1][y-1]=="|     |");
    if (chd[x-1][y-1]=="|jabko|"){
        return jabko(1);
    }
}
void odeberPredmet(string inventar[], int &pocet){

}
void pouzijPredmet(string inventar[], int &pocet, int &zivoty, int &utok){

}
void Inv(){
for (int i=1; i!=v+2; i++){
    if(i-1<10){
        cout << i-1 << ")  ";
    } if(i-1>=10){
        cout << i-1 << ") ";
    }
    if(i==1){
        for (int u=1; u!=v+1; u++){
            chd[i-1][u-1] = to_string(u);
            if(u<10){
                cout << "-";
            }
            cout << "---" << chd[i-1][u-1] << "---";

        }
    }
    if(i>1){
        for (int u=1; u!=v+1; u++){
            cout << "-" << chd[i-1][u-1];
        }
    }
    cout << "-" << endl;

}
}
void path(){
for(int i=1; i!=10;i++){
    for (int u=1;u!=10-i; u++){
        cout << " * ";
    }
    cout << endl;
}
}


int main(){
for (int i=1; i!=v+2; i++){
    for (int u=1; u!=v+1; u++){
        chd[i-1][u-1]= "|     |";
    }
    cout << endl;
}


cout << rand() % 2;
//for(int h=0; h<4;h=h+1){
//chd[rand() % 12][rand() % 12]= "|jabko|";
//}


for (int i=1; i!=v+2; i++){
    if(i-1<10){
        cout << i-1 << ")  ";
    } if(i-1>=10){
        cout << i-1 << ") ";
    }
    if(i==1){
        for (int u=1; u!=v+1; u++){
            chd[i-1][u-1] = to_string(u);
            if(u<10){
                cout << "-";
            }
            cout << "---" << chd[i-1][u-1] << "---";

        }
    }
    if(i>1){
        for (int u=1; u!=v+1; u++){
            cout << "-" << chd[i-1][u-1];
        }
    }
    cout << "-" << endl;

}
cout << endl << endl;
cout << "dal? (a/n) ";
cin >> wtl;

do{
if (r<2){


}
    char doo='+';
    cout << "co podniknes (+, -, u, e, -) ";
    cin >> doo;
    switch(doo){
            cout << " + ";
        case '+':
            break;
        case '-':
            cout << "-";
            break;
        case 'u':
            cout << "u";
            break;
        case 'e':
            for (int i=1; i!=v+2; i++){
                if(i-1<10){
                    cout << i-1 << ")  ";
                } if(i-1>=10){
                    cout << i-1 << ") ";
                }
                if(i==1){
                    for (int u=1; u!=v+1; u++){
                        chd[i-1][u-1] = to_string(u);
                        if(u<10){
                            cout << "-";
                        }
                        cout << "---" << chd[i-1][u-1] << "---";

                    }
                }
                if(i>1){
                    for (int u=1; u!=v+1; u++){
                        cout << "-" << chd[i-1][u-1];
                    }
                }
                cout << "-" << endl;

            }
            cout << endl << endl;

            //cout << Inv();
            break;
        default:
            cout << "dal ";
    }

//cout << path()
    sp = rand() % 20;
    for (int t=1; t<=30;t++){
        cout << endl;
    }
int sp;
sp = rand() % 20;

    for(int i=1; i<=10;i++){
        for (int u=1;u<=10-i; u++){
            cout << " ";
        } cout << "//";
        for (int u=1;u<=i; u++){
                cout << "  ";
        } int rr1=1;
        for (int u=1;u<=10; u++){
            //cout << i;
            if (sp==1 || sp==2){
                cout << " z";
                if(i<3){
                    sp = rand() % 20;
                } else{
                    sp = 20;
                }
            } else if (sp==0){
                cout << " O";
                if(i<3){
                    sp = rand() % 20;
                } else{
                    sp = 20;
                }
            } else {
                cout << "  ";
                if(i<3){
                    sp = rand() % 20;
                } else{
                    sp = 20;
                }
            } if(i>2 && rr1==1){
                cout << " ";
                rr1=3;
            }
        }
        for (int k=1;k<=i/32; k++){
                cout << "-";
        }
        if(i<3){
            cout << " \\";
        } if(i>2){
            cout << "\\";
        }
        cout << "\\";
        cout << endl;

    }

    for (int t=1; t<=5;t++){
        cout << endl;
    }

    cout << endl << "-------------------------------------------------------" << endl;
    cout << "dal? (a/n) ";
    cin >> wtl;
} while(plziv>0 && wtl!='n');
if (wtl!='a'){
    cout << endl << "sebsvrazda neni vzdy to spravny reseni " << endl;
}
}
