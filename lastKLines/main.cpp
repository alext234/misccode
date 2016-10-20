#include <iostream>
#include <fstream>

using namespace std;

// print out the lastKLines of a file
void printLastKLines (string filename, int k)  {
  
  ifstream f(filename);
  
  if (!f.is_open()) return;
  
  string *kLines{new string[k]};
  int totalLines{0};
  int currentLine{0};
  
  string line;
  // read file line by line
  while (!f.eof()){
    getline(f, line);
    kLines[currentLine] = line;
    currentLine = (currentLine+1)%k;
    ++totalLines;
  }
  f.close();
  
  
  // print the results
  int startLine = (totalLines <k)?0: currentLine;
  if (k>totalLines) k  = totalLines;
  for (int i=0; i<k;i++){
    cout << kLines[(startLine+i)%k]<<endl;
  }
  delete[]  kLines;
  
  
}

int main() {
  printLastKLines("fileNotExist.txt", 3);
  cout <<endl<<endl;
  printLastKLines("../test1.txt", 3);
  cout <<endl<<endl;
  printLastKLines("../test1.txt", 20);
    
  return 0;
    
 }
