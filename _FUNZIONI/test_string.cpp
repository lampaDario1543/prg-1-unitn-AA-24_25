#include <iostream>

using namespace std;


int Length_Str(char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
        len++;
    return len;
}
int length(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}
int CountSubstr_Str(char *str, char *find)
    {
        int ctr = 0;
        for (int i = 0; i < length(str); i++)
        {
            bool found = true;
            for (int j = 0; j < length(find); j++)
            {
                if (str[i + j] != find[j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
                ctr++;
        }
        return ctr;
    }
int strToInt(char *str)
    {
        int num = 0;
        int len = length(str);
        for (int i = 0; i < len; i++)
        {
            num = num * 10 + (str[i] - '0');
        }
        return num;
    }

int main(int argc, char *argv[]){
    //cout << CountSubstr_Str(argv[1], argv[2]) << endl;
    int n=strToInt(argv[1]);
    cout << n << endl;
    return 0;
}