#ifndef __CONTROL_LAW_JOUNCE__
#define __CONTROL_LAW_JOUNCE__

#include <cl/fda.hpp>
#include <cl/ControlLaw.hpp>

namespace Jounce {
	class Base: virtual public CL::Thrust, virtual public CL::Alpha {
		public:
			Base(Quadrotor*);

			virtual void	step(int, double) = 0;
			//virtual bool	Check(int, math::quat) {}
			virtual bool	check(int, vec3) = 0;
			virtual void	alloc(int);
			virtual void	write(int);
		public:
			array<vec3>	jounce_;
	};
	class X: virtual public CL::X<5>, virtual public Base {
		public:
			X(Quadrotor*);
			
			virtual void	step(int, double);
			bool		check(int, vec3);
			virtual void	alloc(int);
			virtual void	write(int);
	};
	class V: virtual public CL::V<4>, virtual public Base {
		public:
			V(Quadrotor* r);

			virtual void	Step(int, double);
			virtual bool	Check(int, vec3);
			virtual void	alloc(int);
			virtual void	write(int);
		public:
			//math::mat33		C_[4];

			//array<vec3>	e_[4];		
	};
}



#endif

