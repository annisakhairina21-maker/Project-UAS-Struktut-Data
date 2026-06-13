// ============================================================
// PROJECT STRUKTUR DATA
// SISTEM ANTRIAN RUMAH SAKIT
// ============================================================
// Struktur Data:
// 1. Queue (Linked List)
// 2. Stack (Linked List)
//
// Algoritma:
// 1. Linear Search
// 2. Bubble Sort

// ============================================================

#include <iostream>
#include <string>

using namespace std;

// ============================================================
// CLASS NODE
// ============================================================

class Node {
public:
    int nomor;
    string nama;
    string keluhan;
    Node* next;

    Node(int no, string nm, string kel) {
        nomor = no;
        nama = nm;
        keluhan = kel;
        next = NULL;
    }
};

// ============================================================
// CLASS QUEUE
// ============================================================

class Queue {
private:
    Node* front;
    Node* rear;

public:

    // Constructor
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // ========================================================
    // ENQUEUE
    // Menambahkan pasien ke antrian
    // Kompleksitas : O(1)
    // ========================================================

    void enqueue(int nomor, string nama, string keluhan) {

        Node* newNode = new Node(nomor, nama, keluhan);

        // Jika antrian kosong
        if (rear == NULL) {

            front = rear = newNode;
        }

        // Jika antrian sudah ada isi
        else {

            rear->next = newNode;
            rear = newNode;
        }

        cout << "\nPasien " << nama
             << " berhasil masuk antrian.\n";
    }

    // ========================================================
    // DEQUEUE
    // Menghapus pasien dari antrian
    // ========================================================

    Node* dequeue() {

        // Jika antrian kosong
        if (front == NULL) {
            return NULL;
        }

        Node* temp = front;

        front = front->next;

        // Jika antrian menjadi kosong
        if (front == NULL) {
            rear = NULL;
        }

        return temp;
    }

    // ========================================================
    // DISPLAY
    // Menampilkan seluruh antrian
    // ========================================================

    void display() {

        if (front == NULL) {

            cout << "\nAntrian kosong.\n";
            return;
        }

        Node* current = front;

        cout << "\n===================================\n";
        cout << "        DAFTAR ANTRIAN\n";
        cout << "===================================\n";

        while (current != NULL) {

            cout << "No Antrian : "
                 << current->nomor << endl;

            cout << "Nama       : "
                 << current->nama << endl;

            cout << "Keluhan    : "
                 << current->keluhan << endl;

            cout << "-----------------------------------\n";

            current = current->next;
        }
    }

    // ========================================================
    // SEARCH
    // ========================================================

    void search(string keyword) {

        Node* current = front;

        bool ditemukan = false;

        while (current != NULL) {

            if (current->nama == keyword) {

                cout << "\nData ditemukan:\n";

                cout << "No Antrian : "
                     << current->nomor << endl;

                cout << "Nama       : "
                     << current->nama << endl;

                cout << "Keluhan    : "
                     << current->keluhan << endl;

                ditemukan = true;
            }

            current = current->next;
        }

        if (!ditemukan) {

            cout << "\nData tidak ditemukan.\n";
        }
    }

    // ========================================================
    // SORT DATA
    // ========================================================

    void sortData() {

        if (front == NULL) {

            cout << "\nAntrian kosong.\n";
            return;
        }

        bool swapped;

        do {

            swapped = false;

            Node* current = front;

            while (current->next != NULL) {

                if (current->nama >
                    current->next->nama) {

                    // Tukar nomor
                    swap(current->nomor,
                         current->next->nomor);

                    // Tukar nama
                    swap(current->nama,
                         current->next->nama);

                    // Tukar keluhan
                    swap(current->keluhan,
                         current->next->keluhan);

                    swapped = true;
                }

                current = current->next;
            }

        } while (swapped);

        cout << "\nData berhasil diurutkan.\n";
    }
};

// ============================================================
// CLASS STACK
// ============================================================

class Stack {
private:
    Node* top;

public:

    // Constructor
    Stack() {
        top = NULL;
    }

    // ========================================================
    // PUSH
    // Menambahkan riwayat
    // ========================================================

    void push(int nomor,
              string nama,
              string keluhan) {

        Node* newNode =
        new Node(nomor, nama, keluhan);

        newNode->next = top;

        top = newNode;
    }

    // ========================================================
    // POP
    // Menghapus riwayat terakhir
    // ========================================================

    Node* pop() {

        if (top == NULL) {
            return NULL;
        }

        Node* temp = top;

        top = top->next;

        return temp;
    }

    // ========================================================
    // DISPLAY RIWAYAT
    // ========================================================

    void display() {

        if (top == NULL) {

            cout << "\nRiwayat kosong.\n";
            return;
        }

        Node* current = top;

        cout << "\n===================================\n";
        cout << "      RIWAYAT PELAYANAN\n";
        cout << "===================================\n";

        while (current != NULL) {

            cout << "No Antrian : "
                 << current->nomor << endl;

            cout << "Nama       : "
                 << current->nama << endl;

            cout << "Keluhan    : "
                 << current->keluhan << endl;

            cout << "-----------------------------------\n";

            current = current->next;
        }
    }
};

// ============================================================
// PROGRAM UTAMA
// ============================================================

int main() {

    Queue antrian;
    Stack riwayat;

    int nomorAntrian = 1;

    int pilihan;

    do {

        cout << "\n===================================\n";
        cout << "    SISTEM ANTRIAN RUMAH SAKIT\n";
        cout << "===================================\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Panggil Antrian\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Cari Pasien\n";
        cout << "5. Urutkan Data Pasien\n";
        cout << "6. Undo Pemanggilan\n";
        cout << "7. Lihat Riwayat\n";
        cout << "8. Keluar\n";
        cout << "===================================\n";

        cout << "Masukkan pilihan : ";

        // ====================================================
        // VALIDASI INPUT
        // ====================================================

        if (!(cin >> pilihan)) {

            cin.clear();

            cin.ignore(1000, '\n');

            cout << "\nInput harus berupa angka!\n";

            continue;
        }

        cin.ignore();

        // ====================================================
        // MENU 1
        // TAMBAH ANTRIAN
        // ====================================================

        if (pilihan == 1) {

            string nama;
            string keluhan;

            cout << "Masukkan nama pasien : ";
            getline(cin, nama);

            cout << "Masukkan keluhan     : ";
            getline(cin, keluhan);

            // Validasi nama kosong
            if (nama.empty()) {

                cout << "\nNama pasien tidak boleh kosong.\n";
            }

            else {

                antrian.enqueue(
                    nomorAntrian,
                    nama,
                    keluhan
                );

                nomorAntrian++;
            }
        }

        // ====================================================
        // MENU 2
        // PANGGIL ANTRIAN
        // ====================================================

        else if (pilihan == 2) {

            Node* data = antrian.dequeue();

            if (data == NULL) {

                cout << "\nAntrian kosong.\n";
            }

            else {

                cout << "\nPasien dipanggil:\n";

                cout << "No Antrian : "
                     << data->nomor << endl;

                cout << "Nama       : "
                     << data->nama << endl;

                cout << "Keluhan    : "
                     << data->keluhan << endl;

                // Simpan ke stack
                riwayat.push(
                    data->nomor,
                    data->nama,
                    data->keluhan
                );
            }
        }

        // ====================================================
        // MENU 3
        // TAMPILKAN ANTRIAN
        // ====================================================

        else if (pilihan == 3) {

            antrian.display();
        }

        // ====================================================
        // MENU 4
        // CARI PASIEN
        // ====================================================

        else if (pilihan == 4) {

            string keyword;

            cout << "Masukkan nama pasien : ";

            getline(cin, keyword);

            antrian.search(keyword);
        }

        // ====================================================
        // MENU 5
        // SORTING
        // ====================================================

        else if (pilihan == 5) {

            antrian.sortData();
        }

        // ====================================================
        // MENU 6
        // UNDO PEMANGGILAN
        // ====================================================

        else if (pilihan == 6) {

            Node* data = riwayat.pop();

            if (data == NULL) {

                cout << "\nTidak ada data yang bisa di-undo.\n";
            }

            else {

                antrian.enqueue(
                    data->nomor,
                    data->nama,
                    data->keluhan
                );

                cout << "\nUndo berhasil.\n";

                cout << "Pasien "
                     << data->nama
                     << " dikembalikan ke antrian.\n";
            }
        }

        // ====================================================
        // MENU 7
        // LIHAT RIWAYAT
        // ====================================================

        else if (pilihan == 7) {

            riwayat.display();
        }

        // ====================================================
        // MENU 8
        // KELUAR
        // ====================================================

        else if (pilihan == 8) {

            cout << "\nProgram selesai.\n";
        }

        // ====================================================
        // PILIHAN TIDAK VALID
        // ====================================================

        else {

            cout << "\nPilihan tidak valid.\n";
        }

    } while (pilihan != 8);

    return 0;
}