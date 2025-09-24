#include <iostream>
using namespace std;

int main() {
const int PIN_BENAR = 1234;
int saldo = 1500000; 
int pin, pilihan;
int jumlah = 0;
int pinChance = 3;
bool step = false;
string lanjut;


// TODO: Implementasikan ATM simulator


cout << "=== SELAMAT DATANG DI ATM ===" << endl;

while (pinChance > 0) {      
    cout << "Masukkan Pin ATM anda (1234) : " << endl;
    cin >> pin;     

    if (pin == PIN_BENAR) {  
        step = true;
        break;
    } else {
        pinChance--;
        cout << "Pin salah, Silahkan masukkan ulang, sisa kesempatan : " << pinChance << endl;
    }
}

if (!step) {
    cout << "Kesemapatan anda sudah habis" << endl;
    return 0;   //kesempatan habis tidak dapat mengulang
}

cout << "\nPIN Benar! Selamat datang " << endl;
cout << "Saldo anda : " << saldo << endl;

//Menu utama

while (step == true) {

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
            step = false;   
            break;
        } else if (confirm != 'y') {
            cout << "Input error!" << endl;
        }
       
    } else if (pilihan == 2) {

        bool stepTransaksi;
        char confirm;
        stepTransaksi = false;   

        while (stepTransaksi == false) {
            int pajak = 6500;
            int preSaldo = saldo;

            cout << "\nMasukkan nominal penarikan tunai : " << endl;
            cout << "Ketik '1' untuk kembali ke menu utama" << endl;

            cin >> jumlah ;

            if (cin.fail()) {
                cout << "\nHARUS BERUPA ANGKA" << endl;
                cin.clear();              // reset error jika penulisan selain angka
                cin.ignore(1000, '\n');
            } else if (jumlah == 1) {
                stepTransaksi = true;
            } else if (jumlah < 50000) {
                cout << "\nJumlah tarik tunai terlalu kecil, minimal Rp 50.000 " << endl;
            } else if (jumlah > 2500000) {
                cout << "\nJumlah tarik tunai terlalu Besar, maximal Rp 2.500.000 " << endl;
            } else if (saldo < jumlah + pajak) {
                cout << "\nSaldo tidak mencukupi" << endl; 
            } else { 
                preSaldo = saldo - (jumlah + pajak);
            
                cout << "\n=== KONFIRMASI PENARIKAN ===" << endl;
                cout << "Jumlah penarikan : " << jumlah << endl;
                cout << "total debet : " << jumlah + pajak  << endl;
                cout << "Sisa saldo anda : " << preSaldo << "\n" << endl;

                cout << "Konfirmasi? y/n" << endl;
                cin >> confirm;

                if (confirm == 'y') {
                    saldo = preSaldo;

                    cout << "\nTransasksi berhasil" << endl;
                    cout << "Ambil uang anda : " << jumlah << endl;
                    cout << "Sisa saldo anda : " << saldo << "\n" << endl;

                    cout << "lanjut?";
                    cin >> lanjut;

                    stepTransaksi = true;
                } else if (confirm != 'n') {
                    cout << "\nInput Error!" << endl;
                }
            }
        }
    } else if (pilihan == 3) {

        bool stepTransaksi;
        char confirm;
        stepTransaksi = false;

        while (stepTransaksi == false) {
            int pajak = 2500;
            int preSaldo = saldo;

            cout << "\nTransfer ke sesama bank? y/n" << endl;
            cin >> confirm;

            if (confirm == 'n') {
                pajak += 4000;
            } else if (confirm != 'y') {
                cout << "\nInput error";
                continue;
            }

            cout << "\nMasukkan nominal penarikan tunai : " << endl;
            cout << "Ketik '1' untuk kembali ke menu utama" << endl;

            cin >> jumlah ;

            if (cin.fail()) {
                cout << "\nHARUS BERUPA ANGKA" << endl;
                cin.clear();              // reset error state
                cin.ignore(1000, '\n');
            } else if (jumlah == 1) {
                stepTransaksi = true;
            } else if (jumlah < 10000) {
                cout << "\nJumlah tarik tunai terlalu kecil, minimal Rp 10.000 " << endl;
            } else if (saldo < jumlah + pajak) {
                cout << "\nSaldo tidak mencukupi" << endl;
            } else {
                preSaldo = saldo - (jumlah + pajak);

                cout << "\n=== KONFIRMASI PENARIKAN ===" << endl;
                cout << "Jumlah transfer : " << jumlah << endl;
                cout << "total debet : " << jumlah + pajak  << endl;
                cout << "Sisa saldo anda : " << preSaldo << "\n" << endl;

                cout << "Konfirmasi? y/n" << endl;
                cin >> confirm;

                if (confirm == 'y') {
                    saldo = preSaldo;

                    cout << "\nTransasksi berhasil" << endl;
                    cout << "Total transfer : " << jumlah << endl;
                    cout << "Sisa saldo anda : " << saldo << "\n" << endl;

                    cout << "lanjut?";
                    cin >> lanjut;

                    stepTransaksi = true;
                }
                
            }
        }
    } else if (pilihan == 4) {
        step = false;

    }
}


cout << "\nTerimakasih telah menggunakan simulasi ATM saya (Revan Muhammmad Zaki)" << endl;

return 0;
}
