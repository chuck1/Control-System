#ifndef __PLANT__
#define __PLANT__

#include <cl/array.hpp>
#include <cl/typedef.hpp>

class Quadrotor;

class Plant {
	public:
		Plant(Quadrotor* quad);

		vec3		get_tau_body(int ti);
		void		step_rotor_body(int ti);
		
		vec3		get_force_rotor_body(int ti);

		vec3		get_force_drag_body(int ti);
		vec3		get_force_drag(int ti);

		vec3		get_force(int ti);

		void		step(int ti);

		void		write(int n);

	public:
		Quadrotor*	quad_;

		// state variables

		array<double>		gamma0_;
		array<vec4>		gamma1_;
	
		array<double>		gamma0_act_;
		array<vec4>		gamma1_act_;
	
		array<vec3>		tau_RB_;
		
		array<vec3>		f_RB_;
		
		

};




#endif
