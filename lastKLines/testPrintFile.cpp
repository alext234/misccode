#include "gmock/gmock.h"    
#include "PrintFile.h"


TEST(TestPrintFile, InputFileDoesNotExist) { 
   std::stringstream ss;
   PrintFile pf ("someFileThatDoesNotExist.txt");
   pf.printKLines(3,ss);
   ASSERT_THAT (ss.gcount(),0);
   
}



int main(int argc, char** argv) {
   testing::InitGoogleMock(&argc, argv);
   return RUN_ALL_TESTS();
}