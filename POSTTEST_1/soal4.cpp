#include <iostream>
using namespace std;

int tukarVariabel(int **x, int **y){
    
    int z = **x;
    **x = **y;
    **y = z;
    
    return 0;
}

int main(){

    int a,b;

    cout << "Masukkan Bilangan Bulat" <<endl;
    cout << "Nilai a = "; cin >> a;
    cout << "Nilai b = "; cin >> b; cout<<endl;

    int *ptrA = &a;
    int *ptrB = &b;

    cout << "Nilai awal adalah" <<endl;
    cout << "a = " << a << " dan " << "b = " << b <<endl;

    int tukar = tukarVariabel(&ptrA, &ptrB);

    cout << "Nilai setelah ditukar adalah" <<endl;
    cout << "a = " << a << " dan " << "b = " << b <<endl;

    return 0;

}