#ifndef D_Example_H
#define D_Example_H

#include <string>

class Example {
public:
  explicit Example ();
  virtual ~Example ();

  int DoSomething(std::string);
  
private:
  /* data */
};

#endif // D_Example_H
