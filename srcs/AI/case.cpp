#include "../../include/NewAI.hpp"

void NewAI::case0(int i)
{
  std::cout << "case 0" << std::endl;
  take(i);
}

void NewAI::case1(int i)
{
  std::cout << "case 1" << std::endl;
  forward();
  left();
  forward();
  take(i);
}

void NewAI::case2(int i)
{
  std::cout << "case 2" << std::endl;
  forward();
  take(i);
}

void NewAI::case3(int i)
{
  std::cout << "case 3" << std::endl;
  forward();
  right();
  forward();
  take(i);
}

void NewAI::case4(int i)
{
  std::cout << "case 4" << std::endl;
  forward();
  forward();
  left();
  forward();
  forward();
  take(i);
}

void NewAI::case5(int i)
{
  std::cout << "case 5" << std::endl;
  forward();
  forward();
  left();
  forward();
  take(i);
}

void NewAI::case6(int i)
{
  std::cout << "case 6" << std::endl;
  forward();
  forward();
  take(i);
}

void NewAI::case7(int i)
{
  std::cout << "case 7" << std::endl;
  forward();
  forward();
  right();
  forward();
  take(i);
}

void NewAI::case8(int i)
{
  std::cout << "case 8" << std::endl;
  forward();
  forward();
  right();
  forward();
  forward();
  take(i);
}

void NewAI::case9(int i)
{
  std::cout << "case 9" << std::endl;
  forward();
  forward();
  forward();
  left();
  forward();
  forward();
  forward();
  take(i);
}

void NewAI::case10(int i)
{
  std::cout << "case 10" << std::endl;
  forward();
  forward();
  forward();
  left();
  forward();
  forward();
  take(i);
}

void NewAI::case11(int i)
{
  std::cout << "case 11" << std::endl;
  forward();
  forward();
  forward();
  left();
  forward();
  take(i);
}

void NewAI::case12(int i)
{
  forward();
  std::cout << "case 12" << std::endl;
  forward();
  forward();
  take(i);
}

void NewAI::case13(int i)
{
  std::cout << "case 13" << std::endl;
  forward();
  forward();
  forward();
  right();
  forward();
  take(i);
}

void NewAI::case14(int i)
{
  std::cout << "case 14" << std::endl;
  forward();
  forward();
  forward();
  right();
  forward();
  forward();
  take(i);
}

void NewAI::case15(int i)
{
  std::cout << "case 15" << std::endl;
  forward();
  forward();
  forward();
  right();
  forward();
  forward();
  forward();
  take(i);
}
