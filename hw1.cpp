#include <iostream>
#include "numbers.dat"

using namespace std;

bool is_prime( int a)
{
    if (a==1)
    return 0;
    for (int i=2;i*i<=a;i++)
        if (a%i==0)
        return 0;
    return 1;
}

int main(int argc, char* argv[])
{
    int count;
    if (((argc-1) % 2 == 1) || (argc==1))
        return -1;
    for (int i=1;i<argc;i+=2)
   {
        count=0;
        int m1=-1,m2=0;
        if (atoi(argv[i])>atoi(argv[i+1]))
        {
            cout<<0<<" ";
            continue;
        }
        int fl=0, fl2=0;
        for (int j=0;j<Size;j++)
        {
            if (Data[j]>atoi(argv[i+1]))
                break;
            if (m1==-1)
                if (Data[j]==atoi(argv[i]))
                {
                    fl++;
                    m1=j;
                }   
            if (Data[j]==atoi(argv[i+1]))
            {
                fl2=1;
                m2=j;
            }
        }
        if (fl2==1)
        fl++;
        if (fl!=2)
        cout <<0<<" ";           
        else
        {
            for (int j=m1; j<=m2; j++)
                if (is_prime( Data[j]))
                    count++;
            cout <<count<<" ";
        }
    }
    cout << endl;
    return 0;
}