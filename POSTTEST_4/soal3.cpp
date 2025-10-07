#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // --- LENGKAPI DI SINI ---
    if (front == nullptr) {       // 1. Jika queue kosong (front == nullptr), set front dan rear ke newNode
        front = rear = newNode;
    } else {                      // 2. Jika tidak kosong, sambungkan rear->next ke newNode, lalu update rear
        rear->next = newNode;
        rear = newNode;
    }
    
    // --- LENGKAPI DI SINI ---
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    // --- LENGKAPI DI SINI ---
    
    string doc = front->document;  // 1. Simpan data dari front node
    Node* temp = front;            
    front = front->next;          // 2. Geser front ke front->next
    
    if (front == nullptr) rear = nullptr;  // 3. Jika front menjadi nullptr, set rear juga ke nullptr
    
    delete temp;                         // 4. Delete node lama dan return data
    return doc;

    // --- LENGKAPI DI SINI ---
}

void processAllDocuments(Node*& front, Node*& rear) {
    // --- LENGKAPI DI SINI ---
    
    while (front != nullptr) {                   // Loop hingga queue kosong, dequeue dan print setiap dokumen
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;    // Format: "Memproses: [nama_dokumen]"
    }
    
    // --- LENGKAPI DI SINI ---
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}