
#ifndef __PRINTFILE__
#define __PRINTFILE__

#include <fstream>
#include <iostream>

class PrintFile {
  
public:
  
  PrintFile () = delete;
  
  PrintFile (std::string filename) ;
  

  
  void printKLines (int k);
  
private:
  
  std::ifstream f;
  
  template<typename T>
  class CircularBuffer;

};

#endif //__PRINTFILE__