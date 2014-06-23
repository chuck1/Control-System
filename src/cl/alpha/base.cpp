
#include <cl/typedef.hpp>
#include <cl/command.hpp>
#include <cl/fda.hpp>
#include <cl/Input/Input.hpp>
#include <cl/Alpha.hpp>

Alpha1::Base::Base(Quadrotor* r): CL::Base(r), CL::Alpha(r) {
	alloc(r_->N_);
}
void	Alpha1::Base::alloc(int n) {
	printf("%s\n",__PRETTY_FUNCTION__);
	CL::Alpha::alloc(n);
}
void	Alpha1::Base::write(int n) {
	printf("%s\n",__PRETTY_FUNCTION__);
	CL::Alpha::write(n);
}
void			Alpha1::Base::step(int i, double h) {
	CL::Alpha::step(i,h);
}


