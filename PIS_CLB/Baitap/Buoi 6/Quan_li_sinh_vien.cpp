#include <bits/stdc++.h>

using namespace std;

struct SinhVien
{
    string name, classes, mssv;
    double math, cpp, java;
    void Nhap_du_lieu(){
        cout << "Nhap Ho va Ten: "; cin.ignore(); getline(cin, name);
        cout << "Nhap MSSV: "; cin >> mssv;
        cout << "Nhap lop: "; cin >> classes;
        cout << "Nhap diem toan: "; cin >> math;
        cout << "Nhap diem c++: "; cin >> cpp;
        cout << "Nhap diem java: "; cin >> java;
    }
    void Xuat_du_lieu(){
        cout << "----------------------------\n";
        cout << "Ho va Ten: " << name << endl;
        cout << "MSSV: " << mssv << endl;
        cout << "Class: " << classes << endl;
        cout << "Diem toan: " << math << endl;
        cout << "Diem c++: " << cpp << endl;
        cout << "Diem java: " << java << endl;
        cout << "----------------------------\n";
    }
    double Diem_trung_binh(){
        double dtb = (math + cpp + java)/3;
        return dtb;
    }
};

void in_danh_sach(SinhVien sv[], int n){
    cout << "Thong tin sinh vien: \n";
    for(int i = 0; i < n; i++){
        sv[i].Xuat_du_lieu();
    }
}

void Xoa(SinhVien sv[], int n){
    string input_delete;
    cout << "Nhap MSSV can xoa: ";
    cin >> input_delete;
    for(int i = 0; i < n; i++){
        if(input_delete == sv[i].mssv){
            for(int j = i; j < n; j++){
                sv[j]=sv[j+1];
            }
        }
    }
}
void Thay_doi_thong_tin(SinhVien sv[], int n){
    string input_change;
    cout << "Nhap MSSV can thay doi: ";
    cin >> input_change;
    for(int i = 0; i < n; i++){
        if(input_change == sv[i].mssv){
            sv[i].Nhap_du_lieu();
        }
    }
}

void Sap_xep_theo_diem(SinhVien sv[], int n){
    cout << "--------------------------------------" << endl;
    cout << "Diem trung binh theo thu tu tang dan" << endl;
    for(int i = 0; i < n; i++){
        for(int j=i+1; j < n; j++){
            if(sv[i].Diem_trung_binh() >= sv[j].Diem_trung_binh()){
                string tmp = sv[i].name;
                sv[i].name = sv[j].name;
                sv[j].name = tmp;
            }
        }
        cout << sv[i].name << ": ";
        cout << fixed <<sv[i].Diem_trung_binh()<< setprecision(1) << endl;
    }
    cout << "--------------------------------------";
}

int main(){
    int n = 0;
    SinhVien sv[1000];
    while(1){
        cout << "------------------------OPTIONS------------------------" << endl;
        cout << "1. Nhap Thong Tin Sinh Vien" << endl;
        cout << "2. In Thong Tin Sinh Vien" << endl;
        cout << "3. Sua Thong Tin Sinh Vien" << endl;
        cout << "4. Xoa Thong Tin Sinh Vien" << endl;
        cout << "5. Diem Trung Binh theo thu tu tang dan: " << endl;
        cout << "0. Thoat!" << endl;
        cout << "-------------------------------------------------------" << endl;
        int option;
        cin >> option;
        switch (option)
        {
        case 0:
            exit(0);
        case 1:
            sv[n].Nhap_du_lieu();
            n++;
            break;
        case 2:
            in_danh_sach(sv, n);
            break;
        case 3:
            Thay_doi_thong_tin(sv, n);
            break;
        case 4:
            Xoa(sv, n);
            n--;
            break;
        case 5:
            Sap_xep_theo_diem(sv, n);
            break;
        default:
            cout << "Khong co su lua chon nay vui long chon lai!" << endl;
            break;
        }
    }
    return 0;
}