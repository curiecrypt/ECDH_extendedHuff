#ifndef FINITE256_H
#define FINITE256_H

#ifdef COUNT_OPERATIONS
	unsigned long COUNT_MUL;
	unsigned long COUNT_SQR;
	unsigned long COUNT_MLD;
	unsigned long COUNT_ADD;
#endif

#define FIX_FIELD

#ifdef FIX_FIELD
#define FP_LEN (256/UNIT_LEN)
#endif


#include "fp_256x8664.h"

void fp_inv_256_ehuff(uni zn, uni an);
void ec_fp_smul_256h_u_ehuff(uni X1, uni Z1, uni Y1, uni T1, const uni kn, const uni X2, const uni Y2, const uni cn0, const uni dn0);

#define TRIAL (unsigned long)20000
#define IOBASE 10
#endif
