/*
Scrivere un programma che prenda in
input un carattere da tastiera,
lo memorizzi in una variabile e lo stampi a video.
*/

#include <iostream>


using namespace std;

int main(){
	char c;
	cout << "Inserisci un carattere: "<<endl;
	cout <<"> ";
	cin >> c;
	cout << "Il carattere che hai inserito e' "<<c<<endl;
	return 0;
}