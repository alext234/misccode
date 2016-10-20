#include "PrintFile.h"

using namespace std;

PrintFile::PrintFile (std::string filename) : f(filename) {
  
}
  
void PrintFile::printKLines (int k){
    if (!f.is_open()) return;
    
    CircularBuffer<string> kLines{k}; //RAII-style buffer
    
    int totalLines{0};
    
    
    string line;
    // read file line by line
    while (!f.eof()){
      getline(f, line);
      kLines.push (line);
      ++totalLines;
    }
    
    
    // print the results
    int startLine = (totalLines <k)?0: kLines.lastIdx();
    if (k>totalLines) k  = totalLines;
    
    for (int i=0; i<k;i++){
      cout << kLines[(startLine+i)%k]<<endl;
    }
    
    
  }
  
