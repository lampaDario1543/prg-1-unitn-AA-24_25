/*
Scrivere un programma che prenda in input un testo e generi lo
stesso testo dove ogni separatore (\t,\n, sequenza di piu' blank)
sia convertito in un unico blank.
*/
#include <iostream>

using namespace std;

const int DIM=200;

void removeBlank(char *);

int main(){
    char s[DIM];
    cout << "Testo: ";
    cin.getline(s,DIM);
    removeBlank(s);
    cout << s <<endl;
    return 0;
}
void removeBlank(char *s){ //piccolo bug nel caso in cui ci sia ' '\t lascia due spazi.
    for(int i=0;s[i]!='\0';i++){
        int j=i;
        while(s[j]!='\0' && s[j]==' '){
            ++j;
        }
        if((j-1)>i+1){
            int k=0;
            for(k=i+1;s[k+(j-i-1)]!='\0';k++)
                s[k]=s[k+(j-i-1)];
            s[k]='\0';
        }
        if(s[i]=='\t' || s[i]=='\n'){
            s[i]=' ';
        }
    }
}