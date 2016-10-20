#include "PrintFile.h"

using namespace std;


// print out the last k lines of a file


int main() {
  PrintFile("fileNotExist.txt").printKLines(3);
  cout <<endl<<endl;
  PrintFile("../test1.txt").printKLines(3);
  cout <<endl<<endl;
  PrintFile("../test1.txt").printKLines(20);
    
  return 0;
    
 }
