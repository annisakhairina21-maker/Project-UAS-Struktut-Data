
\\# ============================================================
# PROJECT STRUKTUR DATA
# SISTEM ANTRIAN RUMAH SAKIT

# ============================================================
# CLASS NODE
# ============================================================

class Node:
    def __init__(self, nomor, nama, keluhan):
        self.nomor = nomor
        self.nama = nama
        self.keluhan = keluhan
        self.next = None


# ============================================================
# CLASS QUEUE (ANTRIAN)
# ============================================================

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None

    # Menambahkan data ke antrian
    def enqueue(self, nomor, nama, keluhan):
        new_node = Node(nomor, nama, keluhan)

        if self.rear is None:
            self.front = self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node

        print(f"\nPasien {nama} berhasil masuk antrian.")

    # Menghapus data dari antrian
    def dequeue(self):
        if self.front is None:
            return None

        temp = self.front
        self.front = temp.next

        if self.front is None:
            self.rear = None

        return temp

    # Menampilkan antrian
    def display(self):
        if self.front is None:
            print("\nAntrian kosong.")
            return

        current = self.front

        print("\n===== DAFTAR ANTRIAN =====")
        while current:
            print(f"No Antrian : {current.nomor}")
            print(f"Nama       : {current.nama}")
            print(f"Keluhan    : {current.keluhan}")
            print("----------------------------")
            current = current.next

    # Mencari pasien
    def search(self, keyword):
        current = self.front
        ditemukan = False

        while current:
            if current.nama.lower() == keyword.lower():
                print("\nData ditemukan:")
                print(f"No Antrian : {current.nomor}")
                print(f"Nama       : {current.nama}")
                print(f"Keluhan    : {current.keluhan}")
                ditemukan = True

            current = current.next

        if not ditemukan:
            print("\nData tidak ditemukan.")

    # Mengurutkan nama pasien (Bubble Sort)
    def sort_data(self):
        if self.front is None:
            print("\nAntrian kosong.")
            return

        swapped = True

        while swapped:
            swapped = False
            current = self.front

            while current.next:
                if current.nama.lower() > current.next.nama.lower():

                    # Tukar data
                    current.nomor, current.next.nomor = current.next.nomor, current.nomor
                    current.nama, current.next.nama = current.next.nama, current.nama
                    current.keluhan, current.next.keluhan = current.next.keluhan, current.keluhan

                    swapped = True

                current = current.next

        print("\nData berhasil diurutkan berdasarkan nama.")


# ============================================================
# CLASS STACK (RIWAYAT)
# ============================================================

class Stack:
    def __init__(self):
        self.top = None

    # Menambahkan riwayat
    def push(self, nomor, nama, keluhan):
        new_node = Node(nomor, nama, keluhan)

        new_node.next = self.top
        self.top = new_node

    # Menghapus riwayat terakhir
    def pop(self):
        if self.top is None:
            return None

        temp = self.top
        self.top = self.top.next

        return temp

    # Menampilkan riwayat
    def display(self):
        if self.top is None:
            print("\nRiwayat kosong.")
            return

        current = self.top

        print("\n===== RIWAYAT PELAYANAN =====")

        while current:
            print(f"No Antrian : {current.nomor}")
            print(f"Nama       : {current.nama}")
            print(f"Keluhan    : {current.keluhan}")
            print("----------------------------")

            current = current.next


# ============================================================
# PROGRAM UTAMA
# ============================================================

antrian = Queue()
riwayat = Stack()

nomor_antrian = 1

while True:

    print("\n===================================")
    print(" SISTEM ANTRIAN RUMAH SAKIT")
    print("===================================")
    print("1. Tambah Antrian")
    print("2. Panggil Antrian")
    print("3. Tampilkan Antrian")
    print("4. Cari Pasien")
    print("5. Urutkan Data Pasien")
    print("6. Undo Pemanggilan")
    print("7. Lihat Riwayat")
    print("8. Keluar")
    print("===================================")

    pilihan = input("Masukkan pilihan : ")

    # ========================================================
    # TAMBAH ANTRIAN
    # ========================================================

    if pilihan == "1":

        nama = input("Masukkan nama pasien : ")
        keluhan = input("Masukkan keluhan     : ")

        antrian.enqueue(nomor_antrian, nama, keluhan)

        nomor_antrian += 1

    # ========================================================
    # PANGGIL ANTRIAN
    # ========================================================

    elif pilihan == "2":

        data = antrian.dequeue()

        if data is None:
            print("\nAntrian kosong.")
        else:
            print("\nPasien dipanggil:")
            print(f"No Antrian : {data.nomor}")
            print(f"Nama       : {data.nama}")
            print(f"Keluhan    : {data.keluhan}")

            # Simpan ke stack riwayat
            riwayat.push(data.nomor, data.nama, data.keluhan)

    # ========================================================
    # TAMPILKAN ANTRIAN
    # ========================================================

    elif pilihan == "3":
        antrian.display()

    # ========================================================
    # CARI PASIEN
    # ========================================================

    elif pilihan == "4":

        keyword = input("Masukkan nama pasien yang dicari : ")
        antrian.search(keyword)

    # ========================================================
    # URUTKAN DATA
    # ========================================================

    elif pilihan == "5":

        antrian.sort_data()

    # ========================================================
    # UNDO PEMANGGILAN
    # ========================================================

    elif pilihan == "6":

        data = riwayat.pop()

        if data is None:
            print("\nTidak ada data yang bisa di-undo.")
        else:
            antrian.enqueue(data.nomor, data.nama, data.keluhan)

            print("\nUndo berhasil.")
            print(f"Pasien {data.nama} dikembalikan ke antrian.")

    # ========================================================
    # LIHAT RIWAYAT
    # ========================================================

    elif pilihan == "7":

        riwayat.display()

    # ========================================================
    # KELUAR PROGRAM
    # ========================================================

    elif pilihan == "8":

        print("\nProgram selesai.")
        break

    # ========================================================
    # INPUT SALAH
    # ========================================================

    else:
        print("\nPilihan tidak valid.")