#ifndef __ARRAY__
#define __ARRAY__

#include <cstdlib>
#include <cstdio>

#include <cl/typedef.hpp>

void write(FILE* file, vec3 const & v);
void write(FILE* file, vec4 const & v);
void write(FILE* file, quat const & v);
void write(FILE* file, double const & f);

void read(FILE* file, vec3 & v);
void read(FILE* file, vec4 & v);
void read(FILE* file, quat & v);
void read(FILE* file, double & f);


template <typename T> class array {
	public:
		array() {
			n_ = 0;
			v_ = NULL;
		}
		void alloc(int n) {
			if(n <= 1) {
				printf("cant alloc %i\n", n);
				throw;
			}
			
			//printf("allocating %i\n", n);
			
			if(v_ != NULL) {
				delete[] v_;
			}
			
			v_ = new T[n];
			n_ = n;
		}
		T& operator[](int i) {
			if(v_ == NULL) {
				printf("empty array\n");
				throw;
			}
			
			i = (i + n_) % n_;
			
			if(i >= n_) {
				printf("out of bounds\n");
				throw;
			}
			
			return v_[i];
		}
		void write(FILE* file, int n) {
			for(int i = 0; i < n; i++) {
				::write(file, v_[i]);
			}
		}
		void read(FILE* file, int n) {
			for(int i = 0; i < n; i++) {
				::read(file, v_[i]);
			}
		}
		void fill(T const & t) {
			for(int i = 0; i < n_; i++) {
				v_[i] = t;
			}
		}
	public:
		int	n_;
		T*	v_;
};


#endif


