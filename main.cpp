#include <iostream>
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
    cout << "Nama : ";
    cin >> nama;
    cout << "NIM  : ";
    cin >> nim;
    cout << "Jumlah Matkul : ";
    cin >> jumlahmk;
    cout << endl;
    for (int i = 0; i < jumlahmk; i++)
    {
        cout << "Mata kuliahh    " << i + 1 << " : ";
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
    cout << "\n================================" << endl;
    cout << "          KRS MAHASISWA         "<< endl;
    cout << "================================" << endl;
    cout << "Nama               : " << nama << endl;
    cout << "NIM                : " << nim << endl;
    cout << "Jumlah Mata Kuliah : " << jumlahmk << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < jumlahmk; i++)
    {
    cout << "Mata Kuliah    : " << matkul[i] << endl;
    cout << "Banyak SKS     : " << sks[i] << endl;
    }
    cout << "-----------------------------" << endl;
    cout << "Jumlah SKS     : " << jumlahsks << endl;
    cout << "Total Harga    : Rp" << bayar << endl;
    cout << "Diskon         : Rp" << diskon << endl;
    cout << "Total Bayar    : Rp" << totbay << endl;
      
}

int main()
{
    studikasus x; 
    x.input(); 
    x.proses();
    x.output();
}
