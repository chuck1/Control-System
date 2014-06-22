#ifndef __QUADROTOR_INPUT__
#define __QUADROTOR_INPUT__

#include <cl/typedef.hpp>


double fourier_square(double t, double phase, double L, int n);

namespace Input {
	namespace Vec3 {
		class Base {
			public:
				virtual vec3	f(double) = 0;
		};
		class Const: public Input::Vec3::Base {
			public:
				Const(vec3 v): v_(v) {}
				virtual vec3	f(double) { return v_; }

				vec3	v_;
		};
		class Circle: public Input::Vec3::Base {
			public:
				Circle(double r, double T): r_(r), T_(T) {
					omega_ = 2.0 * M_PI / T_;
				}
				virtual vec3	f(double t) {

					double x = fourier_square(t, 0, T_, 4) * r_;
					double y = fourier_square(t, 0.5 * M_PI, T_, 4) * r_;

					//double x = sin(omega_ * t);
					//double y = cos(omega_ * t);
					return ((float)r_ * vec3(x, y, 0));
				}

				double	r_;
				double	T_;
				double	omega_;
		};
	}


	class Quat {
		public:
			virtual quat	f(double) = 0;
	};
	class QuatConst: public Input::Quat {
		public:
			QuatConst(quat q): q_(q) {}
			virtual quat	f(double) { return q_; }

			quat	q_;
	};
}

#endif

