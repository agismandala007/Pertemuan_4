#include <iostream>
#include <string>

using namespace std;

class Tabungan {
public:
  void Total();
  void inputPengeluaran();
  void output();
  void perhitunganperBulan();

private:
  int uangSaku = 1000000, pengeluaran[6], uangKuliah[6], uangJajan[6],
      totalpengeluaran[8], tabungan[8];
  string namaBulan[6] = {"Januari", "Februari", "Maret",
                         "April",   "Mei",      "Juni"};
};

void Tabungan::perhitunganperBulan() {
  for (int i = 0; i < 6; i++) {
    uangSaku = 1000000;
    if(uangKuliah[i]!=6 && uangJajan[i]!=6){
      totalpengeluaran[i] = uangKuliah[i] + uangJajan[i];    
    }else{
      totalpengeluaran[i]=0;
    }
    
    tabungan[i] = uangSaku - totalpengeluaran[i];
  }
}

void Tabungan::output() {
  cout << "Daftar Pengeluaran selama 6 Bulan : " << endl;
  for (int i = 0; i < 6; i++) {
    cout << namaBulan[i] << " : " << endl;
    cout << " -Pengeluaran Keperluan Kuliah  = Rp." << uangKuliah[i]<<endl;
    cout << " -Pengeluaran  Uang Jajan       = Rp." << uangJajan[i]<<endl;
    cout << " -Total Pengeluaran             = Rp." << totalpengeluaran[i]<<endl;
    cout << " -Uang yang ditabung            = Rp." << tabungan[i]<<endl;
    totalpengeluaran[7] += totalpengeluaran[i];
    tabungan[7]+=tabungan[i];
    cout << endl;
  }
  cout << "Jumlah Pengeluaran selama 6 bulan = Rp. " << totalpengeluaran[7]<<endl;
  cout << "Jumlah Tabungan selama 6 bulan    = Rp. " <<tabungan[7];
}

void Tabungan::inputPengeluaran() {
  for (int i = 0; i < 6; i++) {
    cout << "Masukan Pengeluaran Bulan " << namaBulan[i] << " : " << endl;
    cout << "Uang Saku Anda         = Rp." << uangSaku << endl;
    cout << "Pengeluaran Kuliah     = Rp.";
    cin >> uangKuliah[i];
    cout << "Pengeluaran Uang Jajan = Rp.";
    cin >> uangJajan[i];
    cout<<endl;
  }
}

int main() {
  Tabungan x;
  x.inputPengeluaran();
  x.perhitunganperBulan();
  x.output();
}