#ifndef __CONTROL_LAW_JERK__
#define __CONTROL_LAW_JERK__

#include <cl/array.hpp>
#include <cl/fda.hpp>
#include <cl/quadrotor.hpp>
#include <cl/ControlLaw.hpp>
#include <cl/Alpha.hpp>

namespace Jerk {
	class Base: virtual public CL::Thrust, virtual public Alpha1::Omega {
		public:
			Base(Quadrotor*);
			
			virtual void			step(int, double) = 0;
			virtual void			alloc(int) = 0;
			virtual void			write(int);
		public:
			array<vec3>			jerk_;
	};
	class X: virtual public CL::X<4>, virtual public Jerk::Base {
		public:
			X(Quadrotor*);

			void				step(int, double);
			virtual bool			Check(int, vec3);
			virtual void			alloc(int) = 0;
			virtual void			write(int);
		public:
			//mat33	C_[4];

			//Array<vec3>	e_[4];
			//Array<vec3>	x_ref_[4];
	};
}


#endif

