/*
serie di fibonacci per n
*/
#include <iostream>

using namespace std;

void fibonacci(int);

int main()
{
    int n;
    cout << "n? ";
    cin >> n;
    fibonacci(n);
    return 0;
}

void fibonacci(int n)
{
    int t1 = 1;
    int t2 = 1;
    cout << t1 << ", " << t2 << ", ";
    for (int i = 2; i < n; i++)
    {
        int box = t1;
        t1 = t2;
        t2 = box + t2;
        cout << t2 << ", ";
    }
    cout << "\b\b";
}