#include <iostream>
using namespace std;

int main()
{
    double hargaPerItem;
    int jumlahItem;
    int subTotal, totalDiscount, total;
    float discount = 0.0;
    string discNum = "none";
    string member;
    bool isMember, isSpecialDay;

    cout << "Masukkan harga per item: ";
    cin >> hargaPerItem;
    cout << "Masukkan jumlah item: ";
    cin >> jumlahItem;
    cout << "Apakah member? (1=Ya, 0=Tidak): ";
    cin >> isMember;
    cout << "Apakah hari spesial? (1=Ya, 0=Tidak): ";
    cin >> isSpecialDay;

    subTotal = hargaPerItem * jumlahItem;

    cout << "=== DETAIL PEMBELIAN ===" << endl;
    cout << "Harga per item: " << hargaPerItem << endl;
    cout << "Jumlah item: " << jumlahItem << endl;
    cout << "Subtotal: Rp" << subTotal << "\n" << endl;

    cout << "=== DISKON ===" << endl;
    
    if (isMember == true) {
        discount = 0.10;
        discNum = "10%"; 
        member = "Member discount ( " ;
    } 
    if (isSpecialDay == true) {
        discount = 0.15;
        discNum = "15%";
        member = "Special day discount ( " ;
    }

    cout << member << discNum << " ) : " << subTotal * discount << endl;
    totalDiscount = subTotal * discount;

    if (jumlahItem >= 10) {
        discount = 0.05;
        discNum = "5%";
    } else if (jumlahItem >= 20) {
        discount = 0.1;
        discNum = "10%";
    } else {
        discount = 0;
        discNum = "none";
    }

    cout << "Quantity discount ( " << discNum << " ) : " << subTotal * discount << endl;
    totalDiscount = totalDiscount + (subTotal * discount); 

    if (subTotal >= 500000) {
        discount = 0.05;
        discNum = "5%";
    } else if (subTotal >= 1000000) {
        discount = 0.10;
        discNum = "10%";
    } else {
        discount = 0;
        discNum = "none";
    }

    cout << "Amount discount ( " << discNum << " ) : " << subTotal * discount << "\n" << endl;
    totalDiscount = totalDiscount + (subTotal * discount); 

    total = subTotal - totalDiscount;

    cout << "=== TOTAL ===" << endl;
    cout << "Subtotal : " << subTotal << endl;
    cout << "Total Diskon : " << totalDiscount <<  endl;
    cout << "Total Bayar : " <<  total << endl;
    

    return 0;
}