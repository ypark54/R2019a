#ifndef __pm_math_math3d_h__
#define __pm_math_math3d_h__
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
real_T pm_math_dot3(const real_T*v0,const real_T*v1);void pm_math_cross3(const
real_T*v0,const real_T*v1,real_T*result);void
pm_math_Vector3_compOrthogonalBasis(const real_T*v,real_T*i,real_T*j,real_T*k)
;void pm_math_quatCompose(const real_T*Q0,const real_T*Q1,real_T*result);void
pm_math_quatComposeInverse(const real_T*Q0,const real_T*Q1,real_T*result);void
pm_math_quatInverseCompose(const real_T*Q0,const real_T*Q1,real_T*result);void
pm_math_quatXform(const real_T*Q,const real_T*v,real_T*result);void
pm_math_quatInverseXform(const real_T*Q,const real_T*v,real_T*result);void
pm_math_quatDeriv(const real_T*Q,const real_T*omega,real_T*deriv);void
pm_math_quaternionMatrix3x3Ctor(const real_T*R,real_T*Q);void
pm_math_matrix3x3Compose(const real_T*A0,const real_T*A1,real_T*result);void
pm_math_matrix3x3ComposeTranspose(const real_T*A0,const real_T*A1,real_T*
result);void pm_math_matrix3x3TransposeCompose(const real_T*A0,const real_T*A1
,real_T*result);void pm_math_matrix3x3PreCross(const real_T*A,const real_T*v,
real_T*result);void pm_math_matrix3x3PostCross(const real_T*A,const real_T*v,
real_T*result);void pm_math_matrix3x3Xform(const real_T*A,const real_T*v,
real_T*result);void pm_math_matrix3x3TransposeXform(const real_T*A,const real_T
*v,real_T*result);void pm_math_matrix3x3MinRotation(const real_T*Q,real_T*R,
int perm[3]);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __pm_math_math3d_h__ */
