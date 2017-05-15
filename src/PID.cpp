#include "PID.h"

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
  Kp = Kp;
  Ki = Ki;
  Kd = Kd;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;

}

double PID::TotalError() {
  //reference: steer = -tau_p * cte - tau_d * diff_cte - tau_i * int_cte
  return -(p_error * Kp) - (i_error * Ki) - (d_error * Kd);
}
