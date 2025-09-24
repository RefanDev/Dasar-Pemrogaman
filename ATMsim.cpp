#include <iostream>
using namespace std;

int main() {
const int PIN_BENAR = 1234;
int saldo = 1500000; // Saldo awal
int pin, pilihan;
int jumlah = 0;
int pinChance = 3;
bool success = false;
string lanjut;


// TODO: Implementasikan ATM simulator


cout << "=== SELAMAT DATANG DI ATM ===" << endl;

while (pinChance > 0) {
    cout << "Masukkan Pin ATM anda (1234) : " << endl;
    cin >> pin;

    if (pin == PIN_BENAR) {
        pinChance -= 10;
        success = true;
    } else {
        pinChance--;
        cout << "Pin salah, Silahkan masukkan ulang, sisa kesempatan : " << pinChance << endl;
    }
}

if (pinChance == 0) {
    cout << "Kesemapatan anda sudah habis" << endl;
    return 0;
}

cout << "\nPIN Benar! Selamat datang " << endl;
cout << "Saldo anda : " << saldo << endl;

while (success == true) {

    cout << "\nMenu :" << endl;
    cout << "1. Cek Saldo" << endl;
    cout << "2. Tarik Tunai" << endl;
    cout << "3. Transfer" << endl;
    cout << "4. Keluar" << endl;

    cin >> pilihan;
    
    if (pilihan == 1) {
        char confirm;

        cout << "\nSaldo anda : " << saldo << "\n" << endl; 

        cout << "ingin kembali ke menu awal? y/n" << endl;
        cin >> confirm;
        
        if (confirm == 'n') {
            success = false;
        }
       
    } else if (pilihan == 2) {

        char confirm;
        success = false;

        while (success == false) {
            int pajak = 6500;

            cout << "\nMasukkan nominal penarikan tunai : " << endl;
            cout << "Ketik '1' untuk kembali ke menu utama" << endl;

            cin >> jumlah ;

            if (cin.fail()) {
                cout << "\nHARUS BERUPA ANGKA" << endl;
                cin.clear();              // reset error state
                cin.ignore(1000, '\n');
            } else if (jumlah == 1) {
                success = true;
                cout << success;
            } else if (jumlah < 50000) {
                cout << "\nJumlah tarik tunai terlalu kecil, minimal Rp 50.000 " << endl;
            } else if (jumlah > 2500000) {
                cout << "\nJumlah tarik tunai terlalu Besar, maximal Rp 2500000 " << endl;
            } else if (saldo < jumlah) {
                cout << "\nSaldo tidak mencukupi" << endl; 
            } else { 
                saldo -= (jumlah + pajak);
            
                cout << "\n=== KONFIRMASI PENARIKAN ===" << endl;
                cout << "Jumlah penarikan : " << jumlah << endl;
                cout << "total debet : " << jumlah + pajak  << endl;
                cout << "Sisa saldo anda : " << saldo << "\n" << endl;

                cout << "Konfirmasi? y/n" << endl;
                cin >> confirm;

                if (confirm == 'y') {
                    cout << "\nTransasksi berhasil" << endl;
                    cout << "Ambil uang anda : " << jumlah << endl;
                    cout << "Sisa saldo anda : " << saldo << "\n" << endl;

                    cout << "lanjut?";
                    cin >> lanjut;

                    success = true;
                }
            }
            }
        } else if (pilihan == 3) {

        char confirm;
        success = false;

        while (success == false) {
            int pajak = 2500;

            cout << "Transfer ke sesama bank? y/n" << endl;
            cin >> confirm;

            if (confirm == 'n') {
                pajak += 4000;
            } else if (confirm != 'y') {
                cout << "\nsaya anggap sebagai iya";
            }

            cout << "\n\nMasukkan nominal penarikan tunai : " << endl;
            cout << "Ketik '1' untuk kembali ke menu utama" << endl;

            cin >> jumlah ;

            if (cin.fail()) {
                cout << "\nHARUS BERUPA ANGKA" << endl;
                cin.clear();              // reset error state
                cin.ignore(1000, '\n');
            } else if (jumlah == 1) {
                success = true;
            } else if (jumlah < 10000) {
                cout << "\nJumlah tarik tunai terlalu kecil, minimal Rp 10.000 " << endl;
            } else if (saldo <= jumlah) {
                cout << "\nSaldo tidak mencukupi" << endl;
            } else {
                saldo -= (jumlah + pajak);

                cout << "\n=== KONFIRMASI PENARIKAN ===" << endl;
                cout << "Jumlah penarikan : " << jumlah << endl;
                cout << "total debet : " << jumlah + pajak  << endl;
                cout << "Sisa saldo anda : " << saldo << "\n" << endl;

                cout << "Konfirmasi? y/n" << endl;
                cin >> confirm;

                if (confirm == 'y') {
                    cout << "\nTransasksi berhasil" << endl;
                    cout << "Ambil uang anda : " << jumlah << endl;
                    cout << "Sisa saldo anda : " << saldo << "\n" << endl;

                    cout << "lanjut?";
                    cin >> lanjut;

                    success = true;
                }
                
            }
        }
    } else if (pilihan == 4) {
        success = false;

    }
}


cout << "\nTerimakasih telah menggunakan simulasi ATM saya (Revan Muhammmad Zaki)" << endl;

return 0;
}
