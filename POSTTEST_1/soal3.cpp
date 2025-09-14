#include <iostream>
using namespace std;

struct Mahasiswa{
    string nama;
    int nim;
    float ipk;
};

int main(){
    Mahasiswa dataMahasiswa[5];

    cout << "Masukkan Data Mahasiswa" <<endl;
    for (int i=0; i<5; i++){
        cout << "Mahasiswa ke-" << (i+1) <<endl;
        cout << "Nama: ";
        getline(cin, dataMahasiswa[i].nama);

        cout << "NIM: ";
        cin >> dataMahasiswa[i].nim;

        cout << "IPK: ";
        cin >> dataMahasiswa[i].ipk;

        cin.ignore();
        cout<<endl;

    }


    cout << "Daftar Mahasiswa" <<endl;
    cout << "Nama     " << "NIM     " << "IPK     " <<endl;
    for (int i=0; i<5; i++){
        cout <<dataMahasiswa[i].nama << "     " << dataMahasiswa[i].nim << "     " << dataMahasiswa[i].ipk <<endl;
    }
    cout<<endl;

    int ipkTertinggi = 0;
    for (int i=0; i<5; i++){
        if (dataMahasiswa[i].ipk > dataMahasiswa[ipkTertinggi].ipk){
            ipkTertinggi = i;
        }
    }

    cout << "Mahasiswa IPK Tertinggi" <<endl;
    cout << "Nama: " << dataMahasiswa[ipkTertinggi].nama <<endl;
    cout << "NIM: " << dataMahasiswa[ipkTertinggi].nim <<endl;
    cout << "IPK: " << dataMahasiswa[ipkTertinggi].ipk <<endl;


    return 0;

}