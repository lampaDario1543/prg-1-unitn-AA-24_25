//Malinverno Tommaso
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
  char *filename_in;
  char *filename_out;
  if (argc != 3)
  {
    cerr << "Usage ./a.out <filename_input> <filename_output" << endl;
    exit(0);
  }
  filename_in = argv[1];
  filename_out = argv[2];
  fstream in, out;
  in.open(filename_in, ios::in);
  if (in.fail())
  {
    cerr << filename_in << " doesn't exists." << endl;
    exit(0);
  }
  out.open(filename_out, ios::out);
  if (out.fail())
  {
    cerr << "Error opening output file." << endl;
    exit(0);
  }

  in >> noskipws;
  char c;
  char prev;
  if(in >> c){
    if(c>='a' && c<='z')
      c=toupper(c);
    out << c;
    prev=c;
  }
  while(in >> c){
    if(prev=='.' || prev=='!' || prev=='?' && (c>='a' && c<='z'))
      c=toupper(c);
    if(c!=' ' && c!='\n')
      prev=c;
    out << c;
  }
  cout << filename_out << " create with success." << endl;
  in.close();
  out.close();
  return 0;
}
