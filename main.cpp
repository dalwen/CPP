#include "FollowPointer.hpp"
#include "ArrayElement.hpp"
#include "Node.hpp"
#include "RvalueRef.hpp"
#include "RefTest.hpp"
#include "TemplateTest.hpp"

int main()
{
  // FollowPointer();
  // GetGrade();
  // NodeTest();
  // NodeTest1();

  //RvalueRef r;
  //r.RunTest();

  //RefTest t;
  //t.RunTest();

  TemplateTest<float> a; // Bad. 
  TemplateTest<float> t(8.5);
  t.RunTest();

}
