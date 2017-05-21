#include "PID.h"
#include <math.h>
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  this -> Kp = Kp;
  this -> Ki = Ki;
  this -> Kd = Kd;

  //Twiddle variables
  dp = .01;
  di = .0001;
  dd = 1;
  best_err = 100;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

void PID::Twiddle(double cte) {

  if( fabs(cte) < fabs(best_err)) {

    best_err = cte;
    dp *= 1.1;
    di *= 1.1;
    dd *= 1.1;

    // std::cout << "Before Kp: " << Kp << std::endl;
    // //Kp += dp;
    // std::cout << "After Kp: " << Kp << std::endl;
    //
    // std::cout << "Before Ki: " << Ki << std::endl;
    // //Ki += di;
    // std::cout << "After Ki: " << Ki << std::endl;
    //
    // std::cout << "Before Kd: " << Kd << std::endl;
    // //Kd += dd;
    // std::cout << "After Kd: " << Kd << std::endl;

  } else {
    dp*= .9;
    di*= .9;
    dd*= .9;

    // std::cout << "Before Kp: " << Kp << std::endl;
    // //Kp -= dp;
    // std::cout << "After Kp: " << Kp << std::endl;
    //
    // std::cout << "Before Ki: " << Ki << std::endl;
    // //Ki -= di;
    // std::cout << "After Ki: " << Ki << std::endl;
    //
    // std::cout << "Before Kd: " << Kd << std::endl;
    // //Kd -= dd;
    // std::cout << "After Kd: " << Kd << std::endl;
  }
}

double PID::TotalError() {
  //reference: steer = -tau_p * cte - tau_d * diff_cte - tau_i * int_cte
  return -(p_error * Kp) - (i_error * Ki) - (d_error * Kd);
}
