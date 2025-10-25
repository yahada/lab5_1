#include <iostream>
#include <cstddef>
#include <limits>
bool check_sum(size_t a, size_t b)
{
  size_t max = std::numeric_limits<size_t>::max();
  return a>max-b;
}
bool check_pow(size_t n)
{
  size_t max = std::numeric_limits<size_t>::max();
  return n>(max/n);
}
bool isPyth(size_t a, size_t b, size_t c)
{
  bool p = (a*a == (b*b+c*c));
  p = p || (b*b == (a*a+c*c));
  p = p || (c*c == (a*a+b*b));
  return p;

}

int main()
{
  size_t a = 0, b = 0, c = 0;
  std::cin >> c >> b;
  size_t count = 0;
  while (std::cin >> a)
  {
    bool v = check_pow(a);
    v = v || check_pow(b);
    v = v || check_pow(c);
    if (v){
      std::cout << "out of limits\n";
      return 2;
    }

    bool w = check_sum(a*a, b*b);
    w = w || check_sum(a*a, c*c);
    w = w || check_sum(c*c, b*b);

    if (w){
      std::cout << "out of limits\n";
      return 2;
    }

    count+=isPyth(a,b,c) ? 1:0;
    c = b;
    b = a;

  }

  if (std::cin.eof())
  {
    std::cout << count;
    std::cout << "\n";

  } else if (std::cin.fail()){
    std::cerr << "Error\n";
    return 1;
  }
}