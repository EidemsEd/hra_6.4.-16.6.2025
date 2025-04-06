#include <iostream>
using namespace std;

int main(){
char hh='a';
do{
char hra[3][3];
int v=3,x,y,f=0;
bool h= true;

for (int i=1; i!=v+1; i++){
    for (int u=1; u!=v+1; u++){
        hra[i-1][u-1] = '*';
    }
}

cout << endl;
for (int i=1; i!=v+1; i++){
    for (int u=1; u!=v+1; u++){
        cout << "  " << hra[i-1][u-1];
    }
    cout << endl;
}

do{



cout << endl << "vybere misto v x, y:" << endl;
do{
cout << "hrac s X: " << endl;
cout << "X: ";
cin >> y;
cout << "Y: ";
cin >> x;
} while(hra[x-1][y-1]=='X' || hra[x-1][y-1]=='O' || x>3 || y>3);
hra[x-1][y-1] = 'X';
for (int i=1; i!=v+1; i++){
    for (int u=1; u!=v+1; u++){
        cout << "  " << hra[i-1][u-1];
    }
    cout << endl;
}

for(int i=1; i!=x+1; i++){
    if(hra[i-1][0]==hra[i-1][1] && hra[i-1][1]==hra[i-1][2]){
        if(hra[i-1][0]=='X'){
            cout << "hrac s X vyhral" << endl;
            h=false;
        }else if(hra[i-1][0]=='O'){
            cout << "hrac s O vyhral" << endl;
            h=false;
        } else{
        }

    }
}
for(int i=1; i!=x+1; i++){
    if(hra[0][i-1]==hra[1][i-1] && hra[1][i-1]==hra[2][i-1]){
        if(hra[0][i-1]=='X'){
            cout << "hrac s X vyhral" << endl;
            h=false;
        }else if(hra[0][i-1]=='O'){
            cout << "hrac s O vyhral" << endl;
            h=false;
        } else{
        }

    }
}
if(hra[0][2]==hra[1][1] && hra[1][1]==hra[2][0]){
    if(hra[0][2]=='X'){
            cout << "hrac s X vyhral" << endl;
            h=false;
        }else if(hra[0][2]=='O'){
            cout << "hrac s O vyhral" << endl;
            h=false;
        } else{
        }
}
if(hra[0][0]==hra[1][1] && hra[1][1]==hra[2][2]){
    if(hra[0][0]=='X'){
            cout << "hrac s X vyhral" << endl;
            h=false;
        }else if(hra[0][0]=='O'){
            cout << "hrac s O vyhral" << endl;
            h=false;
        } else{
        }
}

if (f>3){
    h=false;
    cout << "remíza";
}
if(h==true){

do{
cout << endl << "hrac s O si vybere misto v x, y:" << endl;
cout << "X: ";
cin >> y;
cout << "Y: ";
cin >> x;
} while(hra[x-1][y-1]=='X' || hra[x-1][y-1]=='O' || x>3 || y>3);
hra[x-1][y-1] = 'O';

cout << endl;
for (int i=1; i!=v+1; i++){
    for (int u=1; u!=v+1; u++){
        cout << "  " << hra[i-1][u-1];
    }
    cout << endl;
}

for(int i=1; i!=x+1; i++){
    if(hra[i-1][0]==hra[i-1][1] && hra[i-1][1]==hra[i-1][2]){
        if(hra[i-1][0]=='X'){
            cout << "hrac s X vyhral" << endl;
            h=false;
        }else if(hra[i-1][0]=='O'){
            cout << "hrac s O vyhral" << endl;
            h=false;
        } else{
        }

    }
}
for(int i=1; i!=x+1; i++){
    if(hra[0][i-1]==hra[1][i-1] && hra[1][i-1]==hra[2][i-1]){
        if(hra[0][i-1]=='X'){
            cout << "hrac s X vyhral" << endl;
            h=false;
        }else if(hra[0][i-1]=='O'){
            cout << "hrac s O vyhral" << endl;
            h=false;
        } else{
        }

    }
}
if(hra[0][2]==hra[1][1] && hra[1][1]==hra[2][0]){
    if(hra[0][2]=='X'){
            cout << "hrac s X vyhral" << endl;
            h=false;
        }else if(hra[0][2]=='O'){
            cout << "hrac s O vyhral" << endl;
            h=false;
        } else{
        }
}
if(hra[0][0]==hra[1][1] && hra[1][1]==hra[2][2]){
    if(hra[0][0]=='X'){
            cout << "hrac s X vyhral" << endl;
            h=false;
        }else if(hra[0][0]=='O'){
            cout << "hrac s O vyhral" << endl;
            h=false;
        } else{
        }
}

f= f+1;
cout << endl << f << endl;
}
}while(h==true);
cout << endl << "znovu? (a/n)";
cin >> hh;
if(hh=='a'){
    cout << endl << endl << endl << endl << endl << endl << endl << endl << "----------------------------------------------------------------------------------" << endl << endl << endl << endl << endl << endl << endl << endl;
}
}while(hh=='a');
}
