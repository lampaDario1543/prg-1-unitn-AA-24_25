#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int convert(char *, const int base); //convertitore da qualsiasi base a decimale.

int main(){
    //base 18 test:
    char *num = "122222";
    cout << convert(num, 3) << endl;
    return 0;
}

int convert(char *s, const int base){
    int res=0;
    const int len=strlen(s);
    for(int i=0;s[i]!='\0';i++){
        int digit = s[i] - '0';
        if(s[i]>='A' && s[i]<='Z')
            digit = s[i] - 'A' + 10;
        res += digit * pow(base, len-i-1);
    }
    return res;
}