#include <iostream>
#include <gtest/gtest.h>
#include <boost/filesystem.hpp>
#include <pumlg/compiler/Compiler.h>

using namespace boost::filesystem;

TEST(ComplilerTest, Simple) {

  path p("../../test/models/Modelica.puml");
  ASSERT_TRUE(exists(p));
  std::ifstream fileStream(p.string());
  pumlg::Compiler c(fileStream);
  EXPECT_STREQ("Hello World!", "Hello World!");
}
