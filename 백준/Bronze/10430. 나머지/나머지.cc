#include <iostream>
using namespace std;

int A, B, C;

int main(){
    cin >> A >> B >> C;
    
    cout << (A + B) % C << endl;
    cout << ((A % C) + ( B % C)) % C << endl;
    cout << (A * B) % C << endl;
    cout << ((A % C) * (B % C)) % C << endl;
}