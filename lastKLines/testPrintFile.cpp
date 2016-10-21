#include "gmock/gmock.h"    
#include "PrintFile.h"


TEST(TestPrintFile, InputFileDoesNotExist) {
  std::stringstream ss;
  PrintFile pf ("someFileThatDoesNotExist.txt");
  pf.printKLines(3,ss);
  ASSERT_THAT (ss.gcount(),0);
}


TEST(TestPrintFile, Last3LinesOutOf10) {
  std::ifstream ef("../test1_last3lines.txt");
  std::string expected_str;
  expected_str.assign(std::istreambuf_iterator<char>(ef), std::istreambuf_iterator<char>());
  expected_str+="\n";
  
  std::stringstream ss;
  PrintFile pf ("../test1.txt");
  pf.printKLines(3,ss);
  ASSERT_THAT (ss.str(),expected_str);
}


TEST(TestPrintFile, Last20LinesOutOf10) {
  std::ifstream ef("../test1.txt");
  std::string expected_str;
  expected_str.assign(std::istreambuf_iterator<char>(ef), std::istreambuf_iterator<char>());
  expected_str+="\n";
  
  std::stringstream ss;
  PrintFile pf ("../test1.txt");
  pf.printKLines(20,ss);
  ASSERT_THAT (ss.str(),expected_str);
}

int main(int argc, char** argv) {
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}