// Lab6c++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Company {
    string title;
    double size;
    double price;
};

void WriteFile(Company* companies, int* n) {
    ofstream file("file.txt", ios::binary);
    for (int i = 0; i < *n; i++)
    {
        file.write((char*)&companies[i].title, sizeof companies[i].title);
        file.write((char*)&companies[i].size, sizeof companies[i].size);
        file.write((char*)&companies[i].price, sizeof companies[i].price);
    }
    file.close();
}

void ReadFile(Company* companies, int* n) {
   
    Company* buffer = new Company();
    ifstream file("file.txt", ios::binary);
    for (int i = 0; i < *n; i++)
    {
        file.read((char*)&companies[i].title, sizeof companies[i].title);
        file.read((char*)&companies[i].size, sizeof companies[i].size);
        file.read((char*)&companies[i].price, sizeof companies[i].price);
    }
    file.close();
}

void printInfo(Company* companies, int* n) {
    cout << "\nInfo: " << endl;
    int k = 0;
    for (int i = 0; i < *n; i++)
    {
        if (companies[i].title == "Samsung" && companies[i].size > 32) {
            cout << " Title: " << companies[i].title << " Size: " << companies[i].size << " Price: " << companies[i].price << endl;
            k++;
        }
    }
    cout << "Number: " << k;
    
}

void EasyLevel(Company *companies,int *n) {
    for (int i = 0; i < *n; i++)
    {
        cout << "Input title: ";
        cin >> companies[i].title;
        cout << "Input size: ";
        cin >> companies[i].size;
        cin.ignore();
        cout << "Input price: ";
        cin >> companies[i].price;
        cin.ignore();
    }
        WriteFile(companies, n);
        ReadFile(companies, n);
        printInfo(companies, n);
        
    
}

void WriteFileCharacters(string *str) {
    ofstream file("file2.txt", ios::binary);
    file.write((char*)&str, sizeof str);
    file.close();
    cout << "\n" << "Before reading: " << *str << "\n";
}

void ReWriteFileCharacters(string* str) {
    ifstream file("file2.txt", ios::binary);
    file.read((char*)&str, sizeof str);
    file.close();
    for_each(str->begin(), str->end(), [](char& in) { in = ::toupper(in); });
    cout << "After reading: " << *str;
}

void MediumLevel(string *str){
    WriteFileCharacters(str);
    ReWriteFileCharacters(str);
}

int main()
{
    setlocale(LC_ALL,"");
    int n = 2;
    Company* companies = new Company[n];
    EasyLevel(companies ,&n);
    string str = "ывмвыЫываж";
    MediumLevel(&str);//все символы записываються заглавными буквами
    delete[] companies;
}


