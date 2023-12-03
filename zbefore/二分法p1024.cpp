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
        if (x1 * x2 < 0)                             //区间内有根。
        {
            while (r - l >= 0.001)                     //二分控制精度。
            {
                m = (l + r) / 2;  //middle
                if (fc(m) * fc(r) <= 0)
                    l = m;
                else
                    r = m;   //这种二分比较简便
            }
            printf("%.2lf ", r);
            //输出右端点。
        }
    }
    return 0;
}