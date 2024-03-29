#include "tabulation.h"
#include "NewtonMethod.h"
#include "NewtonMethod_Modification.h"
#include "SECMethod.h"
#include "justiteration.h"
#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <set>
#include <Windows.h>
#include <conio.h> 

using namespace std;
int main()
{
    Polinom func({ monom(-8,1), monom(15,2), monom(-70,3), monom(63,5) }); //функция из задания 1
    vector < pair<double, double> > section = tabulation(func, -5, 5.1, 10); // вектор отрезков
    
    int number_roots = section.size();
    for (int i = 0; i < number_roots; i++)
    {
        cout << section[i].first << " " << section[i].second << endl;
    }
    int key = 0;
    cout << "It was found " << number_roots << " roots" << endl;
    while (key != 27)
    {
        cout << "Dear user, please, input number between 1 and " << number_roots << ".";
        key = _getch();
        switch (key)
        { 
            cout << "\n";
        case 49:
        {
            cout << endl;
            pair <double, double> section_local = section[0];
            pair <double, double> pair_nm = NewtonMethod(func, section_local.first, section_local.second);
            pair <double, double> pair_nm_mod = NewtonMethod_Modification(func, section_local.first, section_local.second);
            pair <double, double> pair_sec = SECMethod(func, section_local.first, section_local.second);
            pair <double, double> pair_itera = JustItera(func, section_local.first, section_local.second);
            cout << "Root\t\tmeaning of Newton\tmeaning of modi Newton\tmeaning of SEC method\t\n";
            cout << "1\t\t\t" << pair_nm.first << "\t\t\t" << pair_nm_mod.first << "\t\t\t" << pair_sec.first << "\t\t\t" << "\n";
            cout << "Numbers of iteration: " << endl << endl;
            cout << "Root\t\titerati of Newton\titerati of modi Newton\titerati of SEC method\t\n";
            cout << "1\t\t\t" << pair_nm.second << "\t\t\t" << pair_nm_mod.second << "\t\t\t" << pair_sec.second << "\t\t\t" << "\n";
            cout << "Difference between exact and our value: " << endl << endl;
            cout << "Root\t\tdiffere of Newton\tdiffere of modi Newton\tdiffere of SEC method\t\n";
            cout << "1\t\t" << abs(pair_nm.first) - 1.184346300250125951492626352150584793020992442401313917937328027 << "\t\t\t" << abs(pair_nm_mod.first) - 1.184346300250125951492626352150584793020992442401313917937328027 << "\t\t" << abs(pair_sec.first) - 1.184346300250125951492626352150584793020992442401313917937328027 << "\t\t\t" << "\n";
            cout << endl << endl;
            cout << "Just itera root: " << pair_itera.first<<endl;
            cout << "Just itera itera " << pair_itera.second << endl;
            break;
        }
        case 50:
        {
            cout << "\n" << endl;
            pair <double, double> section_local = section[1];
            pair <double, double> pair_nm = NewtonMethod(func, section_local.first, section_local.second);
            pair <double, double> pair_nm_mod = NewtonMethod_Modification(func, section_local.first, section_local.second);
            pair <double, double> pair_sec = SECMethod(func, section_local.first, section_local.second);
            pair <double, double> pair_itera = JustItera(func, section_local.first, section_local.second);
            cout << "Root\t\tmeaning of Newton\tmeaning of modi Newton\tmeaning of SEC method\t\n";
            cout << "2\t\t" << pair_nm.first << "\t\t" << pair_nm_mod.first << "\t\t" << pair_sec.first << "\t\t" << "\n";
            cout << "Numbers of iteration: " << endl;
            cout << "Root\t\titerati of Newton\titerati of modi Newton\titerati of SEC method\t\n";
            cout << "2\t\t\t" << pair_nm.second << "\t\t\t" << pair_nm_mod.second << "\t\t\t" << pair_sec.second << "\t\t\t" << "\n";
            cout << "Difference between exact and our value: " << endl << endl;
            cout << "Root\t\tdiffere of Newton\tdiffere of modi Newton\tdiffere of SEC method\t\n";
            cout << "2\t\t" << abs(pair_nm.first) - 0 << "\t\t\t" << abs(pair_nm_mod.first) - 0 << "\t\t" << abs(pair_sec.first) - 0 << "\t\t\t" << "\n";
            cout << endl << endl;
            cout << "Just itera root: " << pair_itera.first << endl;
            cout << "Just itera itera " << pair_itera.second<<endl;
            break;
        }
        case 51:
        {
            cout << "\n" << endl;;
            pair <double, double> section_local = section[2];
            pair <double, double> pair_nm = NewtonMethod(func, section_local.first, section_local.second);
            pair <double, double> pair_nm_mod = NewtonMethod_Modification(func, section_local.first, section_local.second);
            pair <double, double> pair_sec = SECMethod(func, section_local.first, section_local.second);
            pair <double, double> pair_itera = JustItera(func, section_local.first, section_local.second);
            cout << "Root\t\tmeaning of Newton\tmeaning of modi Newton\tmeaning of SEC method\t\n";
            cout << "3\t\t\t" << pair_nm.first << "\t\t\t" << pair_nm_mod.first << "\t\t\t" << pair_sec.first << "\t\t\t" << "\n";
            cout << "Numbers of iteration: " << endl;
            cout << "Root\t\titerati of Newton\titerati of modi Newton\titerati of SEC method\t\n";
            cout << "3\t\t\t" << pair_nm.second << "\t\t\t" << pair_nm_mod.second << "\t\t\t" << pair_sec.second << "\t\t\t" << "\n";
            cout << "Difference between exact and our value: " << endl << endl;
            cout << "Root\t\tdiffere of Newton\tdiffere of modi Newton\tdiffere of SEC method\t\n";
            cout << "3\t\t" << abs(pair_nm.first) - 1 << "\t\t\t" << abs(pair_nm_mod.first) - 1 << "\t\t" << abs(pair_sec.first) - 1 << "\t\t\t" << "\n";
            cout << endl << endl;
            cout << "Just itera root: " << pair_itera.first << endl;
            cout << "Just itera itera " << pair_itera.second << endl;

            break;
        }
        }
    }
}