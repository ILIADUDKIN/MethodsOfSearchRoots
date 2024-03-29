#include "Polinom.h"
pair <double, double> bissection(Polinom& func, double a, double b) //a,b - ������� �������.
{
    double a_k[10], b_k[10], c_k[10];
    a_k[0] = a; b_k[0] = b;
    double a0 = a;
    double b0 = b;
    double c0 = (a0 + b0) / 2;
    c_k[0] = c0;
    if (point(func, a) * point(func, b) < 0) //����� ������ ���������� �� ������� ���� ���� ������ �������� ���������
    {
        for (int k = 1; k < 10; k++)
        {

            if (point(func, a_k[k - 1]) * point(func, c_k[k - 1]) < 0)
            {
                a_k[k] = a_k[k - 1];
                b_k[k] = c_k[k - 1];
                c_k[k] = (a_k[k] + b_k[k]) / 2;
            }
            //��� ��� ����� � ����� ������ �����
            else if (point(func, b_k[k - 1]) * point(func, c_k[k - 1]) < 0)
            {
                a_k[k] = c_k[k - 1];
                b_k[k] = b_k[k - 1];
                c_k[k] = (a_k[k] + b_k[k]) / 2;
            }
            // cout << a_k[k] << " " << b_k[k]<<endl;
        }
        //�� ������ �������� � k-1 ������ ��������� ������� c ����� ������, ������� ����� ����� ������������ � ������ �������
        return { a_k[9],b_k[9] };
    }
    if ( point(func, a) * point(func, b) > 0)
    {
        //���� ���� ������ ����� ������, ���� ������ ��� - ���������� � ��������� ���������� ������, ������ ������ ������ ������ �� ���������
        return { 10000, 10000 };
    }
    if (point(func, a) * point(func, b) == 0)
    {
        if (point(func, a) == 0 && point(func, b) == 0)
        {
            //������� ��������� �� ����� ����� ������
            return { a , b }; //���������� ���������� - �� ���� ������� ��� �������

        }
        if (point(func, a) == 0) return { a , a };
        if (point(func, b) == 0) return { b,  b };

    }
}