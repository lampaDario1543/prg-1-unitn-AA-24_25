#include <iostream>
#include "fun003.h"

const int LEN = 256;

int atCtr(char *s){
    int ctr = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == '@')
            ++ctr;
    return ctr;
}

bool checkWord(char *s){
    if (s[0] == '\0') // len >= 1
        return false;
    for (int i = 0; s[i] != '\0'; i++)
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == '_'))
            return false;
    return true;
}

bool isEmail(char *s){
    if (atCtr(s) != 1)
        return false;
    // ottengo utente:
    char *user = new char[253];
    char *dominio = new char[253];
    int i = 0;
    while (s[i] != '@'){
        user[i] = s[i];
        ++i;
    }
    user[i++] = '\0';
    int j;
    for (j = 0; s[i] != '\0'; i++, j++)
        dominio[j] = s[i];
    dominio[j] = '\0';
    bool flag = user[0] != '.' && dominio[j - 1] != '.' && checkWord(user) && checkWord(dominio);
    delete[] user;
    delete[] dominio;
    return flag;
}