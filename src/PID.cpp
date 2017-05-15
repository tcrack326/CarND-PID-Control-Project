#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  p_error = 0.0;
  i_error = 0.0:
  d_error = 0.0;
  Kp = Kp;
  Ki = Ki;
  Kd = Kd;
}

void PID::UpdateError(double cte) {
  p_error = cte;
  i_error += cte;
  d_error = cte - p_error;
}

double PID::TotalError() {
  return -(p_error * Kp) - (i_error * Ki) - (d_error * Kd);
}
