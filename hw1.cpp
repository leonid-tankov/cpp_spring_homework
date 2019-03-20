#include <iostream>
#include "numbers.dat"

using namespace std;

bool is_prime(int a)
{
    if (a == 1)
    return 0;
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0)
        return 0;
    return 1;
}

int find (int left, int right)
{
    int count = 0;
    for (int j = left; j <= right; j++)
        if (is_prime( Data[j]))
            count++;
    return count;
}

int main(int argc, char* argv[])
{
    int count;
    if (((argc-1) % 2 == 1) || (argc == 1))
        return -1;
    for (int i = 1; i < argc; i += 2)
   {
        int left = -1, right = 0;
        if (atoi(argv[i]) > atoi(argv[i+1]))
        {
            cout << 0 << " ";
            continue;
        }
        int flag = 0, flag2 = 0;
        for (int j = 0; j < Size; j++)
        {
            if (Data[j] > atoi(argv[i+1]))
                break;
            if (left == -1)
                if (Data[j] == atoi(argv[i]))
                {
                    flag++;
                    left = j;
                }   
            if (Data[j] == atoi(argv[i+1]))
            {
                flag2 = 1;
                right = j;
            }
        }
        if ( flag2 == 1 )
            flag++;
        if (flag != 2)
            cout << 0 << " ";           
        else
        {
            count = find(left, right);
            if ((argc-2-i) == 0)
                cout << count;
            else
                cout << count << endl;
        }
    }
    cout << endl;
    return 0;
}