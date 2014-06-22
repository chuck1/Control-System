#ifndef __QUADROTOR__
#define __QUADROTOR__

#include <cl/typedef.hpp>

class Telem;
class Plant;
class Brain;

void product(int choices, int repeat, int*& arr, int level = 0);


class Quadrotor {
	public:
		Quadrotor(double dt, int N);
		void			reset();
		void			run();
		
		vec3			angular_accel_to_torque(int, vec3);
		vec4			thrust_torque_to_motor_speed(int, double const &, vec3 const &);
		
		void			write();
		
		void			write_param();
		
		// accessors
		vec3&			x(int);
		vec3&			v(int);
		vec3&			a(int);
		vec3&			jerk(int);
		//vec3&	jounce(int);
		quat&			q(int);
		vec3&			omega(int);
		vec3&			alpha(int);
		
		double		t(int i) const { return dt_ * (double)i; }
	public:
		// physical constants
		double		m_, L_, R_, Asw_, rho_, CD_, A_;
		double		Kv_, Kt_, Ktau_;
		double		k_, b_;
		double		P_max_, gamma_max_;

		mat3		I_;
		mat3		Iinv_;

		vec3		gravity_;

		mat4		A4_;
		mat4		A4inv_;

		

		double		dt_;
		int		N_;
		double*		t_;
		
		// stop criteria
		int		ti_stop_;
		
		int		ti_f_;
		
		Telem*		telem_;
		Plant*		plant_;
		Brain*		brain_;

};


#endif





