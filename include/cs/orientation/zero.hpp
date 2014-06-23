#ifndef CS_ORIENTATION_ZERO_HPP
#define CS_ORIENTATION_ZERO_HPP

#include <gal/std/timestep.hpp>

#include <cs/array.hpp>
#include <cs/typedef.hpp>

namespace cs { namespace orientation {

	/**
	 *
	 * control zeroth derivative of orientation
	 */
	class zero {
		public:	
			zero(float c0, float c1);

			/**
			 * @param o actual orientation at this step
			 */
			vec3		step(gal::std::timestep const & ts, quat o);


			float			c0_;
			float			c1_;

			quat			o_prev_;

			/** @brief orientation previous step
			 */
			//quat			o0_;
			/** @brief first derivative of orientation
			 */
			//array<vec3>		o1_;
			/** @brief reference
			 */
			quat			ref_;

			/** @brief zeroth order error
			 */
			//array<vec3>		e0_;
			/** @brief first order error
			 */
			//array<vec3>		e1_;
			/** @brief output
			 */
			//vec3>		o2_;

	};


}}

#endif
