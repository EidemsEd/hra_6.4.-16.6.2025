#include <iostream>
#include <cstdlib>
using namespace std;

string enst[10][10];


int main(){
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
                enst[i-1][u-1]= " X";
                cout << " X";
                if(i<3){
                    sp = rand() % 20;
                } else{
                    sp = 20;
                }
            } else if (sp==0){
                enst[i-1][u-1]= " O";
                cout << " O";
                if(i<3){
                    sp = rand() % 20;
                } else{
                    sp = 20;
                }
            } else {
                enst[i-1][u-1]= "  ";
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

//for(int i=1; i<=10;i++){
//int x = rand() % 20;
//cout << x << endl;
//}
}
// x=0 je enemy a x=1 box(jídlo/zbraò/nic)
//for (int t=1; t<=30;t++){
      //  cout << endl;
    //}
