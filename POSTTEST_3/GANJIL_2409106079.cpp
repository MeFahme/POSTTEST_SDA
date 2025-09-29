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
    Node* next;
    Node* prev;
    Node() : next(nullptr), prev(nullptr) {}
};

// === DEKLARASI FUNGSI ===
void tambahItem(Node*& head, Node*& tail);
void sisipItem(Node*& head, Node*& tail);
void hapusItemTerakhir(Node*& head, Node*& tail);
void gunakanItem(Node*& head, Node*& tail);
void tampilkanInventory(Node* head);
void tampilkanDariBelakang(Node* tail); 
void cariItem(Node* head);

Node* getNodeAt(Node* head, int posisi);
int hitungNode(Node* head);

// === MAIN ===
int main() {
    Node* inventoryHead = nullptr;
    Node* inventoryTail = nullptr;
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
        cout << "|| [6] Tampilkan dari Belakang                  ||\n";
        cout << "|| [7] Cari Item                                ||\n";
        cout << "|| [0] Keluar                                   ||\n";
        cout << "==================================================\n";
        cout << "\n   Masukkan Pilihan Anda (0-7): ";

        cin >> input;

        switch (input) {
            case 1:
                tambahItem(inventoryHead, inventoryTail);
                break;
            case 2:
                sisipItem(inventoryHead, inventoryTail);
                break;
            case 3:
                hapusItemTerakhir(inventoryHead, inventoryTail);
                break;
            case 4:
                if (inventoryHead != nullptr) {
                    tampilkanInventory(inventoryHead);
                }
                gunakanItem(inventoryHead, inventoryTail);
                break;
            case 5:
                tampilkanInventory(inventoryHead);
                break;
            case 6:
                tampilkanDariBelakang(inventoryTail); 
                break;
            case 7:
                cariItem(inventoryHead);
                break;
            case 0:
                cout << "\nSayonara!\n";
                loop = false;
                break;
            default:
                cout << "\nPilihan tidak valid! Masukkan angka antara 0-7.\n";
                break;
        }

        if (loop) {
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore(100, '\n');
            cin.get();
        }
    }

    // Bersihkan memori
    while (inventoryHead) {
        Node* temp = inventoryHead;
        inventoryHead = inventoryHead->next;
        delete temp;
    }

    return 0;
}

// === IMPLEMENTASI FUNGSI ===

Node* getNodeAt(Node* head, int posisi) {
    Node* temp = head;
    int index = 0;
    while (temp != nullptr && index < posisi) {
        temp = temp->next;
        index++;
    }
    return temp;
}

int hitungNode(Node* head) {
    int node = 0;
    Node* temp = head;
    while (temp != nullptr) {
        node++;
        temp = temp->next;
    }
    return node;
}

void tambahItem(Node*& head, Node*& tail) {
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

    Node* newNode = new Node();
    newNode->data = itemBaru;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void sisipItem(Node*& head, Node*& tail) {
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

    Node* nodeBaru = new Node();
    nodeBaru->data = itemBaru;

    int totalNode = hitungNode(head);

    if (posisiSisip <= 1 || head == nullptr) {
        nodeBaru->next = head;
        if (head != nullptr) {
            head->prev = nodeBaru;
        }
        head = nodeBaru;
        if (tail == nullptr) tail = head;
        cout << "\n>> Item disisipkan di awal (posisi 1).\n";
    } else if (posisiSisip > totalNode) {
        tail->next = nodeBaru;
        nodeBaru->prev = tail;
        tail = nodeBaru;
        cout << "\n>> Posisi melebihi jumlah item";
        cout << "\n>> item ditambahkan di akhir (posisi " << totalNode + 1 << ").\n";
    } else {
        Node* prevNode = getNodeAt(head, posisiSisip - 2);
        if (prevNode) {
            Node* nextNode = prevNode->next;
            nodeBaru->next = nextNode;
            nodeBaru->prev = prevNode;
            prevNode->next = nodeBaru;
            if (nextNode) {
                nextNode->prev = nodeBaru;
            }
            cout << "\n>> Item berhasil disisipkan di posisi " << posisiSisip << ".\n";
        }
    }
}

void hapusItemTerakhir(Node*& head, Node*& tail) {
    system("cls");
    if (head == nullptr) {
        cout << "\n>> Inventory kosong. Tidak ada item untuk dihapus.\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        cout << "\n>> Item terakhir dihapus. Inventory sekarang kosong.\n";
        return;
    }

    Node* toDelete = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete toDelete;
    cout << "\n>> Item terakhir berhasil dihapus.\n";
}

void gunakanItem(Node*& head, Node*& tail) {
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

    Node* current = head;
    while (current != nullptr) {
        if (current->data.namaItem == nama) {
            cout << ">> Item ditemukan: " << current->data.namaItem << endl;
            current->data.jumlah--;

            if (current->data.jumlah <= 0) {
                cout << ">> " << current->data.namaItem << " dihapus dari inventory.\n";

                if (current == head && current == tail) {
                    delete current;
                    head = tail = nullptr;
                } else if (current == head) {
                    head = current->next;
                    head->prev = nullptr;
                    delete current;
                } else if (current == tail) {
                    tail = current->prev;
                    tail->next = nullptr;
                    delete current;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                }
            } else {
                cout << ">> Jumlah item sekarang: " << current->data.jumlah << endl;
            }

            return;
        }
        current = current->next;
    }

    cout << "\n>> Item \"" << nama << "\" tidak ditemukan dalam inventory.\n";
}

void tampilkanInventory(Node* head) {
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

    Node* temp = head;
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

void tampilkanDariBelakang(Node* tail) {
    system("cls");
    if (tail == nullptr) {
        cout << "\n>> Inventory kosong.\n";
        return;
    }

    cout << "================================================\n";
    cout << "||                                            ||\n";
    cout << "||           BACKPACK (Dari Belakang)         ||\n";
    cout << "||                                            ||\n";
    cout << "================================================\n";
    cout << "|| No | Nama Item            | Tipe     | Jml ||\n";
    cout << "================================================\n";

    Node* temp = tail;
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

        temp = temp->prev;
        no++;
    }

    cout << "================================================\n";
}

void cariItem(Node* head) {
    if (head == nullptr) {
        cout << "\n>> Inventory kosong.\n";
        return;
    }

    string nama;
    cout << "\nMasukkan nama item yang dicari: ";
    cin.ignore(100, '\n');
    getline(cin, nama);

    Node* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->data.namaItem == nama) {
            cout << "\n==================================================\n";
            cout << "||                 ITEM DITEMUKAN               ||\n";
            cout << "==================================================\n";
            cout << "   Nama  : " << temp->data.namaItem << endl;
            cout << "   Tipe  : " << temp->data.tipe << endl;
            cout << "   Jumlah: " << temp->data.jumlah << endl;
            cout << "==================================================\n";
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "\n>> Item \"" << nama << "\" tidak ditemukan.\n";
    }
}