#include <iostream>
#include <fstream>

using namespace std;

class PrintFile {
  
public:
  
  PrintFile () = delete;
  
  PrintFile (string filename) : f(filename) {
  }
  
  void printKLines (int k){
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
    
    
    // print the results
    int startLine = (totalLines <k)?0: currentLine;
    if (k>totalLines) k  = totalLines;
    for (int i=0; i<k;i++){
      cout << kLines[(startLine+i)%k]<<endl;
    }
    delete[]  kLines;
    
    
  }
  
private:
  
  ifstream f;
};

// print out the lastKLines of a file


int main() {
  PrintFile("fileNotExist.txt").printKLines(3);
  cout <<endl<<endl;
  PrintFile("../test1.txt").printKLines(3);
  cout <<endl<<endl;
  PrintFile("../test1.txt").printKLines(20);
    
  return 0;
    
 }
