#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>

#include <map>
#include <algorithm>

using namespace std;

class Address
{
public: 
    string city = "";
    string street = "";

    string house_number = "";
    string apartament_numer = "";
};

class Parser
{
    string s; //считанная строка
    int count;  //число адресов


    map <string, Address> address; //словарь <город/прочее>
    vector <string> keys; //вектор с ключами от словаря

    void ReadFile()
    {
        ifstream read("in.txt");

        if (read.is_open())
        {
            read >> s;
            count = stoi(s);

            for (int i = 0; i < count; i++)
            {
                Address newAddress;

                read >> newAddress.city;
                read >> newAddress.street;
                read >> newAddress.house_number;
                read >> newAddress.apartament_numer;

                keys.push_back(newAddress.city + newAddress.street + newAddress.house_number + newAddress.apartament_numer);

                address[keys[i]] = newAddress;
            }

            read.close();
        }
        else
        {
            cout << "Файл не найден :(" << endl;
        }
    }

    //Сортирует вектор keys
    void Sort()
    {
        sort(begin(keys), end(keys));
    }

    void WriteFile()
    {
        ofstream write("out.txt");

        if (write.is_open())
        {
            write << count << endl;

            for (int i = 0; i < count; i++)
            {
                write << address[keys[i]].city << ", " << address[keys[i]].street << ", " << address[keys[i]].house_number << ", " << address[keys[i]].apartament_numer << endl;
            }

            write.close();
        }
        else
        {
            cout << "Что-то пошло не по плану" << endl;
        }
    }
public:
    void Rewrite()
    {
        ReadFile();
        Sort();
        WriteFile();
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Parser parser;
    parser.Rewrite();
}
