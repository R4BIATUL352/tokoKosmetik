#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct Kosmetik
{
    string merk, jenis;
    int harga;
    int stok;
};

void masukkanData(Kosmetik *&data, int &jml, stack<Kosmetik> &dataStack, queue<Kosmetik> &dataQueue)
{
    cout << "Jumlah Data : ";
    cin >> jml;
    cin.ignore(); // Membersihkan newline character dari buffer

    // Dealokasi memori jika sudah dialokasikan sebelumnya
    delete[] data;

    // Alokasi memori baru sesuai dengan jumlah yang diminta
    data = new Kosmetik[jml];

    for (int i = 0; i < jml; i++)
    {
        cout << "\nData ke- " << i + 1 << endl;
        cout << "================================================\n"
             << endl;
        cout << "Masukkan Merk Produk     : ";
        getline(cin, data[i].merk);

        cout << "Masukkan Jenis Produk    : ";
        getline(cin, data[i].jenis);

        cout << "Masukkan Harga Produk    : Rp. ";
        cin >> data[i].harga;

        cout << "Masukkan Stok Produk     : ";
        cin >> data[i].stok;

        cin.ignore(); // Membersihkan newline character dari buffer
        cout << "=======================================\n"
             << endl;

        // Menambahkan data ke stack dan queue
        dataStack.push(data[i]);
        dataQueue.push(data[i]);
    }
}

void tampilkanData(stack<Kosmetik> &dataStack, queue<Kosmetik> &dataQueue)
{
    // Menampilkan data dari stack
    cout << "Data dari Stack:\n";
    stack<Kosmetik> tempStack = dataStack; // Salin stack untuk tetap mempertahankan data asli
    while (!tempStack.empty())
    {
        Kosmetik topData = tempStack.top();
        cout << "Merk Produk     : " << topData.merk << endl;
        cout << "Jenis Produk    : " << topData.jenis << endl;
        cout << "Harga Produk    : Rp. " << topData.harga << endl;
        cout << "Stok Produk     : " << topData.stok << endl;
        cout << "=======================================\n"
             << endl;
        tempStack.pop();  }

    // Menampilkan data dari queue
    cout << "Data dari Queue:\n";
    queue<Kosmetik> tempQueue = dataQueue; // Salin queue untuk tetap mempertahankan data asli
    while (!tempQueue.empty())
    {
        Kosmetik frontData = tempQueue.front();
        cout << "Merk Produk     : " << frontData.merk << endl;
        cout << "Jenis Produk    : " << frontData.jenis << endl;
        cout << "Harga Produk    : Rp. " << frontData.harga << endl;
        cout << "Stok Produk     : " << frontData.stok << endl;
        cout << "=======================================\n"
             << endl;
        tempQueue.pop();
    }
}

void bubbleSort(Kosmetik *data, int jml)//DIGUNAKAN UNTUK 
//TERTINGGI KE TERENDAH
{
    for (int i = 0; i < jml - 1; i++)
    {
        for (int j = 0; j < jml - i - 1; j++)
        {
            if (data[j].harga < data[j + 1].harga)
            {
                // Swap entire struct
                Kosmetik temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void bubbleSortLowest(Kosmetik *data, int jml)//TERENDAH KE TERTINGGI
{
    for (int i = 0; i < jml - 1; i++)
    {
        for (int j = 0; j < jml - i - 1; j++)
        {
            if (data[j].harga < data[j + 1].harga)
            {
                // Swap only harga attribute
                int tempHarga = data[j].harga;
                data[j].harga = data[j + 1].harga;
                data[j + 1].harga = tempHarga;
            }
        }
    }
}

void tampilkanHargaTertinggi(Kosmetik *data, int jml)
{
    cout << "Daftar Harga Tertinggi:\n";
    for (int i = 0; i < jml; i++)
    {
        cout << "Merk Produk     : " << data[i].merk << endl;
        cout << "Jenis Produk    : " << data[i].jenis << endl;
        cout << "Harga Produk    : Rp. " << data[i].harga << endl;
        cout << "Stok Produk     : " << data[i].stok << endl;
        cout << "=======================================\n"
             << endl;
    }
}

void tampilkanHargaTerendah(Kosmetik *data, int jml)
{
    cout << "Daftar Harga Terendah:\n";
    for (int i = jml - 1; i >= 0; i--)
    {
        cout << "Merk Produk     : " << data[i].merk << endl;
        cout << "Jenis Produk    : " << data[i].jenis << endl;
        cout << "Harga Produk    : Rp. " << data[i].harga << endl;
        cout << "Stok Produk     : " << data[i].stok << endl;
        cout << "=======================================\n"
             << endl;
    }
}

int cariData(const Kosmetik *data, int jml, const string &merkCari)
{
    for (int i = 0; i < jml; i++)
    {
        if (data[i].merk == merkCari)
        {
            return i; // Mengembalikan indeks data jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}

void hapusData(stack<Kosmetik> &dataStack, queue<Kosmetik> &dataQueue, Kosmetik *data, int &jml)
{
    string merkHapus;
    cout << "Masukkan Merk Produk yang akan dihapus: ";
    getline(cin, merkHapus);

    // Temukan indeks data yang akan dihapus
    int indeks = cariData(data, jml, merkHapus);

    if (indeks != -1)
    {
        // Hapus data dari array
        for (int i = indeks; i < jml - 1; i++)
        {
            data[i] = data[i + 1];
        }

        // Kurangi jumlah data
        jml--;

        // Rebuild stack and queue
        stack<Kosmetik> tempStack;
        queue<Kosmetik> tempQueue;

        for (int i = 0; i < jml; i++)
        {
            tempStack.push(data[i]);
            tempQueue.push(data[i]);
        }

        // Update the original stack and queue
        dataStack = tempStack;
        dataQueue = tempQueue;

        cout << "Data dengan merk " << merkHapus << " berhasil dihapus.\n";
    }
    else
    {
        cout << "Data dengan merk " << merkHapus << " tidak ditemukan.\n";
    }
}

int main()
{
    int pil, jml = 0;
    Kosmetik *data = NULL;

    stack<Kosmetik> dataStack;
    queue<Kosmetik> dataQueue;

    string namaAdmin;
    cout << "\nNama Admin         : ";
    getline(cin, namaAdmin);

    do
    {
        cout << "\t==============================================================\n"
             << endl;
        cout << "\t              SELAMAT DATANG DI TOKO KOSMETIK     	        	 " << endl;
        cout << "\t==============================================================\n"
             << endl;

        cout << "============================================" << endl;
        cout << "       PENDATAAN TOKO KOSMETIK			   " << endl;
        cout << "============================================" << endl;
        cout << "|| 1. || Masukkan Data Kosmetik              " << endl;
        cout << "|| 2. || Tampilkan Data Kosmetik             " << endl;
        cout << "|| 3. || Daftar Harga Tertinggi Kosmetik    " << endl;
        cout << "|| 4. || Daftar Harga Terendah Kosmetik     " << endl;
        cout << "|| 5. || Cari Data Kosmetik                 " << endl;
        cout << "|| 6. || Hapus Data Kosmetik                " << endl;
        cout << "|| 7. || Keluar                             " << endl;
        cout << "================================================\n";
        cout << "\nInput Pilihan	: ";
        cin >> pil;
        cout << "================================================\n";
        cin.ignore(); // Membersihkan newline character dari buffer

        switch (pil)
        {
        case 1:
            masukkanData(data, jml, dataStack, dataQueue);
            break;
        case 2:
            tampilkanData(dataStack, dataQueue);
            break;
        case 3:
            bubbleSort(data, jml);
            tampilkanHargaTertinggi(data, jml);
            break;
        case 4:
            bubbleSortLowest(data, jml);
            tampilkanHargaTerendah(data, jml);
            break;
        case 5:
        {
            string merkCari;
            cout << "Masukkan Merk Produk yang dicari: ";
            getline(cin, merkCari);
            int indeks = cariData(data, jml, merkCari);
            if (indeks != -1)
            {
                cout << "Data ditemukan pada indeks " << indeks + 1 << ":\n";
                cout << "Merk Produk     : " << data[indeks].merk << endl;
                cout << "Jenis Produk    : " << data[indeks].jenis << endl;
                cout << "Harga Produk    : Rp. " << data[indeks].harga << endl;
                cout << "Stok Produk     : " << data[indeks].stok << endl;
            }
            else
            {
                cout << "Data tidak ditemukan.\n";
            }
            break;
        }
        case 6:
            hapusData(dataStack, dataQueue, data, jml);
            break;
        case 7:
            cout << "Terima kasih telah berkunjung.\n"
                 << endl;
            delete[] data; // Dealokasi memori dinamis
            break;
        default:
            cout << "Pilihan tidak valid. Silakan pilih lagi.\n"
                 << endl;
        }
    } while (pil != 7);

    return 0;
}
