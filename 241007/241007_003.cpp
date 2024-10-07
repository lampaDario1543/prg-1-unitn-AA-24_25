/*
Scrivere un programma che, dato in input un numero
dall’utente, ritorni a video se questo numero possa essere
espresso come la somma di due numeri primi.
Stampare anche i corrispondenti numeri primi a video.
Input: 22 => Output: 17 + 5
*/
#include <iostream>

using namespace std;

int prime(int);
bool isPrime(int);

int main(){
    int n = 0;
    int i = 1;
    int temp = 0;
    int prime_number = 1;
    bool flag = true;
    cout << "n: ";
    cin >> n;
    while (prime_number < n && flag){
        prime_number = prime(i);
        temp = n - prime_number;
        if (isPrime(temp) && temp > 0)
            flag = false;
        i++;
    }
    if (!flag)
        cout << temp << " + " << prime_number << "= " << n << endl;
    else
        cout << "Non esistono numeri primi che sommati dannno " << n << endl;
    return 0;
}

bool isPrime(int n){
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i < n; i++)
        if ((n % i) == 0)
            return false;
    return true;
}
// ritorna l'n-esimo numero primo (inefficiente: ogni volta riparte da 1)
int prime(int n){
    int ctr_prime_numbers = 0;
    int i = 1;
    while (ctr_prime_numbers != n){
        if (isPrime(i))
            ++ctr_prime_numbers;
        i++;
    }
    return i - 1;
}