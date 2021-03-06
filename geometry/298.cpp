/*
http://acmp.ru/index.asp?main=task&id_task=298
Стрелок стоит в центре стрельбища. На стрельбище несколько мишеней. Пули стрелка пробивают мишени насквозь, не теряя скорости, и могут поразить все мишени, стоящие на одной линии.

Будем считать, что стрелок стоит в центре начала координат. Известны координаты всех мишеней (для простоты будем считать их геометрические размеры пренебрежимо малыми). Определите минимальное число выстрелов, необходимых стрелку для поражения всех мишеней.

Входные данные
Первая строка входного файла INPUT.TXT содержит натуральное число N – количество мишеней (N ≤ 20). Далее идет N строк с информацией о координатах каждой мишени, при этом в каждой строке указывается два целых числа через пробел X и Y (-10 ≤ X, Y ≤ 10).

Выходные данные
В выходной файл OUTPUT.TXT выведите одно целое число – наименьшее количество выстрелов, необходимых для поражения всех мишеней.
*/
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
 
int main(){
    ifstream in("INPUT.txt");
    ofstream out("OUTPUT.txt");
    short x,y,N,i,j;
    in>>N;
    double tan, mas[20];
    in>>x>>y;
    mas[0]=atan2((double)y,(double)x);
    for (i=1; i<N; i++) //***
    {
        in>>x>>y;
        tan=atan2((double)y,(double)x);
        j=i-1;
        while (j>=0 && mas[j]>tan)
        {
            mas[j+1]=mas[j];
            j--;
        }
        mas[j+1]=tan;
    }
    int k=1;
    for (i=1; i<N; i++)
    {
        if (mas[i]!=mas[i-1]) k++;
    }
    out<<k;
    in.close();
    out.close();
    return 0;
}