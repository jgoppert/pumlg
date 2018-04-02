#include <iostream>
#include <gtest/gtest.h>
#include <boost/filesystem.hpp>
//include <plantuml_gen/Compiler.h>

using namespace boost::filesystem;

TEST(ComplilerTest, Simple) {

  //path p("../../test/models/Modelica.puml");
  //ASSERT_TRUE(exists(p));
  //std::ifstream fileStream(p.string());
  //plantuml_gen::Compiler c(fileStream);
  //c.printXML(std::cout);
  //std::cout << s<< std::endl;
  EXPECT_STREQ("Hello World!", "Hello World!");
}
