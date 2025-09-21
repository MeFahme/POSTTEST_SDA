#include <iostream>
#include <string>

using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
};

struct Node {
    Item data;
    Node *next;
};

void tambahItem(Node *&head);
void sisipItem(Node *&head);
void hapusItemTerakhir(Node *&head);
void gunakanItem(Node *&head);
void tampilkanInventory(Node *head);
void cariItem(Node *head);

Node *getNodeAt(Node *head, int posisi);
int hitungNode(Node *head);

int main() {

    Node *inventory = nullptr;
    bool loop = true;
    int input;

    while (loop) {
        system("cls");

        cout << "==================================================\n";
        cout << "||         GAME INVENTORY MANAGEMENT            ||\n";
        cout << "||                 FAHMI 079                    ||\n";
        cout << "==================================================\n";
        cout << "|| [1] Tambah Item Baru                         ||\n";
        cout << "|| [2] Sisipkan Item                            ||\n";
        cout << "|| [3] Hapus Item Terakhir                      ||\n";
        cout << "|| [4] Gunakan Item                             ||\n";
        cout << "|| [5] Tampilkan Inventory                      ||\n";
        cout << "|| [6] Cari Item                                ||\n";
        cout << "|| [0] Keluar                                   ||\n";
        cout << "==================================================\n";
        cout << "\n   Masukkan Pilihan Anda (0-5): ";

        cin >> input;

        switch (input) {
            case 1:
                tambahItem(inventory);
                break;
            case 2:
                sisipItem(inventory);
                break;
            case 3:
                hapusItemTerakhir(inventory);
                break;
            case 4:
                if (inventory != nullptr) {
                    tampilkanInventory(inventory);
                }
                gunakanItem(inventory);
                break;
            case 5:
                tampilkanInventory(inventory);
                break;
            case 6:
                cariItem(inventory);
                break;
            case 0:
                cout << "\nSayonara!\n";
                loop = false;
                break;
            default:
                cout << "\nPilihan tidak valid! Masukkan angka antara 0-5.\n";
                break;
        }

        if (loop) {
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore(100, '\n');
            cin.get();
        }
    }

        while (inventory) {
        Node *temp = inventory;
        inventory = inventory->next;
        delete temp;
    }
    
    return 0;
}

Node *getNodeAt(Node *head, int posisi) {
    Node *temp = head;
    int index = 0;
    while (temp != nullptr && index < posisi) {
        temp = temp->next;
        index++;
    }
    return temp;
}

int hitungNode(Node *head) {
    int node = 0;
    Node *temp = head;
    while (temp != nullptr) {
        node++;
        temp = temp->next;
    }
    return node;
}

void tambahItem(Node *&head) {
    system("cls");
    Item itemBaru;

    cout << "\n==================================================\n";
    cout << "||              PILIH JENIS ITEM                ||\n";
    cout << "==================================================\n";
    cout << "|| [1] Sword                                    ||\n";
    cout << "|| [2] Potion                                   ||\n";
    cout << "|| [3] Armor                                    ||\n";
    cout << "==================================================\n";
    cout << "   Pilih jenis item (1-3): ";

    int pilihan;
    cin >> pilihan;

    while (pilihan < 1 || pilihan > 3) {
        cout << "   Pilihan tidak valid. Masukkan 1-3: ";
        cin >> pilihan;
    }

    if (pilihan == 1) {
        itemBaru.tipe = "Sword";
    } else if (pilihan == 2) {
        itemBaru.tipe = "Potion";
    } else {
        itemBaru.tipe = "Armor";
    }

    cout << "\n   Masukkan nama item (" << itemBaru.tipe << "): ";
    cin.ignore(100, '\n');
    getline(cin, itemBaru.namaItem);

    itemBaru.jumlah = 79;
    cout << "   >> " << itemBaru.jumlah << " " << itemBaru.namaItem << " ditambahkan\n";

    Node *newNode = new Node();
    newNode->data = itemBaru;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void sisipItem(Node *&head) {
    system("cls");
    Item itemBaru;

    cout << "\n==================================================\n";
    cout << "||                 INSERT ITEM                  ||\n";
    cout << "==================================================\n";
    cout << "|| [1] Sword                                    ||\n";
    cout << "|| [2] Potion                                   ||\n";
    cout << "|| [3] Armor                                    ||\n";
    cout << "==================================================\n";
    cout << "   Pilih jenis item (1-3): ";

    int pilihan;
    cin >> pilihan;

    while (pilihan < 1 || pilihan > 3) {
        cout << "   Pilihan tidak valid. Masukkan 1-3: ";
        cin >> pilihan;
    }

    if (pilihan == 1) {
        itemBaru.tipe = "Sword";
    } else if (pilihan == 2) {
        itemBaru.tipe = "Potion";
    } else {
        itemBaru.tipe = "Armor";
    }

    cout << "\n   Masukkan nama item (" << itemBaru.tipe << "): ";
    cin.ignore(100, '\n');
    getline(cin, itemBaru.namaItem);

    int posisiSisip = 10;
    itemBaru.jumlah = 79;
    cout << "   Jumlah: " << itemBaru.jumlah << endl;
    cout << "   Akan disisipkan di posisi: " << posisiSisip << " (NIM 079)\n";

    Node *nodeBaru = new Node();
    nodeBaru->data = itemBaru;
    nodeBaru->next = nullptr;

    int totalNode = hitungNode(head);

    if (posisiSisip <= 1 || head == nullptr) {
        nodeBaru->next = head;
        head = nodeBaru;
        cout << "\n>> Item disisipkan di awal (posisi 1).\n";
    } else if (posisiSisip > totalNode) {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
        cout << "\n>> Posisi melebihi jumlah item";
        cout << "\n>> item ditambahkan di akhir (posisi " << totalNode + 1 << ").\n";
    } else {
        Node *prev = getNodeAt(head, posisiSisip - 2);
        if (prev) {
            nodeBaru->next = prev->next;
            prev->next = nodeBaru;
            cout << "\n>> Item berhasil disisipkan di posisi " << posisiSisip << ".\n";
        }
    }
}

void hapusItemTerakhir(Node *&head) {
    system("cls");
    if (head == nullptr) {
        cout << "\n>> Inventory kosong. Tidak ada item untuk dihapus.\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "\n>> Item terakhir dihapus. Inventory sekarang kosong.\n";
        return;
    }

    Node *temp = head;
    Node *prev = nullptr;

    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = nullptr;
    delete temp;
    cout << "\n>> Item terakhir berhasil dihapus.\n";
}

void gunakanItem(Node *&head) {
    if (head == nullptr) {
        cout << "\n>> Inventory kosong. Tidak ada item untuk digunakan.\n";
        return;
    }

    string nama;
    cout << "\n==================================================\n";
    cout << "||                 USE ITEM                     ||\n";
    cout << "==================================================\n";
    cout << "   Gunakan Item: ";
    cin.ignore(100, '\n');
    getline(cin, nama);

    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr) {
        if (temp->data.namaItem == nama) {
            cout << ">> Item ditemukan: " << temp->data.namaItem << endl;
            temp->data.jumlah--;

            if (temp->data.jumlah <= 0) {
                cout << ">> "<< temp->data.namaItem << " dihapus dari inventory.\n";

                if (prev == nullptr) {
                    head = temp->next;
                    delete temp;
                    temp = head;
                } else {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
            } else {
                cout << ">> Jumlah item sekarang: " << temp->data.jumlah << endl;
            }

            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "\n>> Item \"" << nama << "\" tidak ditemukan dalam inventory.\n";
}

void tampilkanInventory(Node *head) {
    system("cls");
    if (head == nullptr) {
        cout << "\n>> Inventory kosong.\n";
        return;
    }

    cout << "================================================\n";
    cout << "||                                            ||\n";
    cout << "||                 BACKPACK                   ||\n";
    cout << "||                                            ||\n";
    cout << "================================================\n";
    cout << "|| No | Nama Item            | Tipe     | Jml ||\n";
    cout << "================================================\n";

    Node *temp = head;   
    int no = 1;

    while (temp != nullptr) {
        string nama = temp->data.namaItem;
        if (nama.length() > 20) nama = nama.substr(0, 17) + "...";
        string tipe = temp->data.tipe;
        if (tipe.length() > 8) tipe = tipe.substr(0, 7) + ".";

        string jumlahStr = to_string(temp->data.jumlah);
        string paddingJml = string(3 - jumlahStr.length(), ' ');
        string jumlahFormatted = paddingJml + jumlahStr;

        cout << "|| "
             << (no < 10 ? " " : "") << no << " | "
             << nama << string(21 - nama.length(), ' ') << "| "
             << tipe << string(9 - tipe.length(), ' ') << "| "
             << jumlahFormatted << " ||\n";

        temp = temp->next;
        no++;
    }

    cout << "================================================\n";
}

void cariItem(Node *head) {
    if (head == nullptr) {
        cout << "\n>> Inventory kosong.\n";
        return;
    }

    string nama;
    cout << "\nMasukkan nama item yang dicari: ";
    cin.ignore(100, '\n');
    getline(cin, nama);

    Node *temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->data.namaItem == nama) {
            cout << "\n>> Item ditemukan:\n";
            cout << "   Nama  : " << temp->data.namaItem << endl;
            cout << "   Tipe  : " << temp->data.tipe << endl;
            cout << "   Jumlah: " << temp->data.jumlah << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "\n>> Item \"" << nama << "\" tidak ditemukan.\n";
    }
}