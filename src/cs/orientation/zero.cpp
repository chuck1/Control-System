
#include <cs/typedef.hpp>
#include <cs/orientation/zero.hpp>

cs::orientation::zero::zero(float c0, float c1):
	c0_(c0),
	c1_(c1)
{

}
vec3		cs::orientation::zero::step(gal::std::timestep const & ts, quat o) {


	//o0_[ts.frame] = o;


	//o1_[ts.frame] = glm::axis(o * glm::conjugate(o0_[ts.frame - 1])) / (float)ts.dt;


	vec3 o1 = glm::axis(o * glm::conjugate(o_prev_)) / (float)ts.dt;


	// error

	vec3 e = glm::axis(ref_ * glm::conjugate(o));

	//e0_[ts.frame] = glm::axis(ref_ * glm::conjugate(o));

	//e1_[ts.frame] = -o1_[ts.frame];


	// control

	/*	o2_[ts.frame] = 
		c0_ * e -
		c1_ * o1;*/


	return (c0_ * e - c1_ * o1);


}







