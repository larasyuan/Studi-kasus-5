#include <iostream>
#include <fstream>
using namespace std;

class studikasus
{
private:
    int nim, jumlahmk, bayar, jumlahsks, sks[20], totbay, diskon;
    string nama, matkul[20];

public:
    void input();
    void proses();
    void output();
    int hitung(int s[], int n, int &hasil)
    {
        if (n > 0)
        {
            hasil += s[n - 1];
            hitung(s, n - 1, hasil);
        }
        return 0;
    }
};

void studikasus::input()
{
    cout << "Masukkan Nama : ";
    cin >> nama;
    cout << "Masukkan NIM  : ";
    cin >> nim;
    cout << "Banyak Matkul : ";
    cin >> jumlahmk;
    cout << endl;
    for (int i = 0; i < jumlahmk; i++)
    {
        cout << "Nama Matkul    " << i + 1 << " : ";
        cin >> matkul[i];
        cout << "Banyak SKS       : ";
        cin >> sks[i];
    }
}

void studikasus::proses()
{
    jumlahsks = 0;
    bayar = 0;
    hitung(sks, jumlahmk, jumlahsks);
    bayar = jumlahsks * 150000;
    diskon = bayar * 0.25;
    totbay = bayar - diskon;
}

void studikasus::output()
{
    ofstream hasil;
    hasil.open("hasil.txt", ios::out);
    hasil << "\n=============================" << endl;
    hasil << "Nama               : " << nama << endl;
    hasil << "NIM                : " << nim << endl;
    hasil << "Jumlah Mata Kuliah : " << jumlahmk << endl;
    hasil << "-----------------------------" << endl;
    for (int i = 0; i < jumlahmk; i++)
    {
        hasil << "Mata Kuliah    : " << matkul[i] << endl;
        hasil << "Banyak SKS     : " << sks[i] << endl;
    }
    hasil << "-----------------------------" << endl;
    hasil << "Jumlah SKS     : " << jumlahsks << endl;
    hasil << "Total Harga    : Rp" << bayar << endl;
    hasil << "Diskon         : Rp" << diskon << endl;
    hasil << "Total Bayar    : Rp" << totbay << endl;
    hasil << "=============================" << endl;
    hasil.close();
}

int main()
{
    studikasus x; 
    x.input(); 
    x.proses();
    x.output();
}