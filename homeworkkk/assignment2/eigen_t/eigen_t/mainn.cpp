#include <iostream>
#include <Eigen/Dense>
using Eigen::MatrixXd;
int main()
{
  Eigen::Matrix2f m;
  m(0,0) = 3;
  m(1,0) = 2.5186463516845;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;

  Eigen::Vector3f vec = Eigen::Vector3f(1,2,3);
  std::cout << vec << std::endl;
  Eigen::Matrix3f m3f;
  m3f<<vec,vec,vec;
  std::cout << m3f << std::endl;
  Eigen::MatrixXf m9f(9,1);
  m9f<<vec,vec,vec;
  std::cout << m9f << std::endl;

  char c;std::cin>>c;
}

//includeÄ¿Â¼Ìí¼ÓD:\eigen3.2.2