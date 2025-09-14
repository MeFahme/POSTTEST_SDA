#include <iostream>
using namespace std;


int balikarray(int *arr, int panjangarr){
    int *awal = arr;
    int *akhir = &arr[panjangarr - 1];

    while (awal < akhir){
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal ++;
        akhir --;
    }
    return 0;
}

int main(){

    int nimganjil[7] = {3, 6, 9, 12, 15, 18, 21};

    cout << "Array sebelum dibalik = ";
    for (int i=0; i < 7; i++){
        cout << nimganjil[i] << " ";
    }cout << endl;

    int hasil = balikarray(nimganjil, 7);
    cout << "Array sesudah dibalik = ";
    for (int i=0; i<7; i++){
        cout << nimganjil[i] << " ";
    }

    return 0;

}