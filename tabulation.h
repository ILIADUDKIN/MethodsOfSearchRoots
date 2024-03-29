#include "Polinom.h"
#include "bissection.h"
vector <pair<double, double>> tabulation(Polinom& func, double a, double b, int N)
{
    double epsilon = 10e-3;
    double step = (b - a) / N; //��� ����
    vector <pair<double, double >> sections; //��������� ��������
    double a_n = a; double a_stepik = a + step; //������������������ ���� ���������
    while (a_n <= b)
    {
        pair <double, double> tec_section; //������� �������
        tec_section = bissection(func, a_n, a_stepik);
        if (tec_section.first != 10000) //���� ������������ �� > 0
        {
            if (sections.size() != 0)
            {
                int flag = 0;
                for (int i = 0; i < sections.size(); i++)
                {
                    if (abs(sections[i].first - tec_section.first) >= epsilon) //������� ������� �� ����� ���� ���������?
                    {
                        flag +=1;   
                    }
                }
                if (flag == sections.size()) sections.push_back(tec_section);
            }
            else //���� ��� ������ ���
                sections.push_back(tec_section);
        }
        a_n += step; a_stepik += step;
    }
    return sections;

}