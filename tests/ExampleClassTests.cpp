#include "Example.h"

#include "CppUTest/TestHarness.h"
/* Include the simple string extensions if you're using std::string */
#include "CppUTest/SimpleString.h"

TEST_GROUP(Example)
{
  Example* example;

  void setup()
  {
    example = new Example();
  }

  void teardown()
  {
    delete example;
  }
};

TEST(Example, sensibleNameForTest)
{
  CHECK_EQUAL(0, example->DoSomething(""));
}

