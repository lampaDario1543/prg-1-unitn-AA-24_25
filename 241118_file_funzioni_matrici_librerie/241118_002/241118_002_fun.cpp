#include <iostream>
#include "fun002.h"

char * estrai(char *s){
    char *res= new char[80];
    res[0]='\0';
    
    return estrai(s,res,0,0);
}

char * estrai(char *s, char *res, int i, int j){
    if(s[i]=='\0'){
        res[j]='\0';
        return res;
    }
    if(s[i]>='A' && s[i]<='Z')
        res[j++]=s[i];
    return estrai(s,res,i+1,j);
}