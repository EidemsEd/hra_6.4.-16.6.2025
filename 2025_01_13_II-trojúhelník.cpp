#include <iostream>
using namespace std;

int main(){
int a, b, c;
cout << "strana rovnostraneho trojuhelniku ";
cin >> a;
b = a;
cout << "1-vrchol vlevo, 2-vrchol uprostred, 3-vrchol vpravo ";
cin >> c;
cout << endl;
for (int i = 1; i <= a; i++) {
    if (c == 3){
        for (int z = 1; z <= a - i; z++) {
            cout << "  ";
        }
    } if (c == 2){
        for (int z = 1; z <= a - i; z++) {
            cout << " ";
        }
    }
    for (int u = 1; u <= i; u++) {
        cout << "* ";
    } if (c == 2){
        for (int d = 1; d <= a - i; d++) {
            cout << " ";
        }
    }
    cout << endl;
}
}
