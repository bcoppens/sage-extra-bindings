#ifdef __cplusplus
#include <iostream>
#include <NTL/ZZ.h>
#include <NTL/LLL.h>
#include <NTL/mat_ZZ.h>
#include <NTL/vec_ZZ.h>
using namespace NTL;
#endif

#ifdef __cplusplus
#define EXTERN extern "C"
#else 
#define EXTERN
#endif

#include "Python.h"
#include "ccobject.h"

EXTERN void NearVectorWrap(mat_ZZ* x, const mat_ZZ* A, const mat_ZZ* y) {
  vec_ZZ x_vec;
  vec_ZZ y_vec;
  
  int dimension = y->NumRows();
  
  y_vec = (*y)[0];

  NearVector(x_vec, *A, y_vec);
  
  (*x)[0] = x_vec;
}

