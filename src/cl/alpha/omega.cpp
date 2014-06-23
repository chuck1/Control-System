
#include <cl/typedef.hpp>
#include <cl/command.hpp>
#include <cl/fda.hpp>
#include <cl/Input/Input.hpp>
#include <cl/Alpha.hpp>




void	Alpha1::Omega::step(int i, double h) {

	alpha_[i] = 
		c_[0] * e_[0][i] +
		c_[1] * e_[1][i] +
		omega_ref_[1][i];

}
bool	Alpha1::Omega::check(int, math::vec3) {
	return false;
}
void	Alpha1::Omega::alloc(int n) {
	printf("%s\n",__PRETTY_FUNCTION__);
	Alpha1::Base::alloc(n);
	CL::Omega<2>::alloc(n);
}
void	Alpha1::Omega::write(int n) {
	printf("%s\n",__PRETTY_FUNCTION__);
	Alpha1::Base::write(n);
	CL::Omega<2>::write(n);
}



