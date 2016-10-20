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
  
private:
  
  ifstream f;

  template<typename T>
  class CircularBuffer {
  public:
    
    CircularBuffer ()=delete;
    CircularBuffer (int capacity) :_buf{new T[capacity]},_idx{0}, _capacity(capacity) {}
    
    void push (const T& item){
      _buf[(_idx++)%_capacity] = item;
    }
    
    const T& operator[] (size_t idx) const { return _buf[idx];}
    T& operator[] (size_t idx) { return _buf[idx];}
    
    ~CircularBuffer(){
      delete[]  _buf;
    }
    
    size_t lastIdx () const { return _idx;}
    
    
  private:
    T *_buf;
    int _idx;
    int _capacity;
  };
  
};

// print out the last k lines of a file


int main() {
  PrintFile("fileNotExist.txt").printKLines(3);
  cout <<endl<<endl;
  PrintFile("../test1.txt").printKLines(3);
  cout <<endl<<endl;
  PrintFile("../test1.txt").printKLines(20);
    
  return 0;
    
 }
