#include<cstdio>
#include<iostream>
double a, b, c, d;
double fc(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}
int main()
{
    double l, r, m, x1, x2;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);  
    for (int i = -100; i < 100; i++)
    {
        l = i;
        r = i + 1;
        x1 = fc(l);
        x2 = fc(r);
        if (!x1)
        {
            printf("%.2lf ", l);
        }   
        if (x1 * x2 < 0)                             //�������и���
        {
            while (r - l >= 0.001)                     //���ֿ��ƾ��ȡ�
            {
                m = (l + r) / 2;  //middle
                if (fc(m) * fc(r) <= 0)
                    l = m;
                else
                    r = m;   //���ֶ��ֱȽϼ��
            }
            printf("%.2lf ", r);
            //����Ҷ˵㡣
        }
    }
    return 0;
}