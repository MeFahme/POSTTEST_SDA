#include <iostream>
using namespace std;


int main(){

    int nimganjil[3][3];

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            nimganjil[i][j] = i+j;
        }
    }

    cout << "Array 3x3:" <<endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << nimganjil[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    
    int diagonalutama = 0;
    int diagonalsekunder = 0;
    
    for (int i=0; i<3; i++){
        diagonalutama += nimganjil[i][i];
        diagonalsekunder += nimganjil[i][2-i];
    }

    cout << "Diagonal Utama = ";
    for (int i=0; i<3; i++){
        cout << nimganjil[i][i];
        if (i<2) cout << " + ";
    }
    cout << " = " << diagonalutama <<endl;

    cout << "Diagonal Sekunder = ";
    for (int i=0; i<3; i++){
        cout << nimganjil[i][2-i];
        if (i<2) cout << " + ";
    }
    cout << " = " << diagonalsekunder <<endl;

    int hasil = diagonalutama + diagonalsekunder;
    cout << "Jumlah Diagonal Utama + Diagonal Sekunder = " << hasil <<endl;
    
    return 0;
}