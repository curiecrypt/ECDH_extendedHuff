#include <stdio.h>
#include <stdlib.h>
#include "src/API/headers/crympix.h"
#include "src/API/headers/multiprecision256.h"
#include "src/API/headers/finite256.h"
#include "src/API/headers/ec_fp_256h.h"
#include "src/API/headers/multiprecision.h"


#define mi_modinv_stack				mi_modinv_stack_ehuff
#define fp_inv_256						fp_inv_256_ehuff
#define ec_fp_smul_256h_u			ec_fp_smul_256h_u_ehuff
#define fp_cpy_256						fp_cpy_256_ehuff
#define fp_set_1_256					fp_set_1_256_ehuff
#define fp_add_1_256					fp_add_1_256_ehuff
#define fp_sub_1_256					fp_sub_1_256_ehuff
#define fp_sub_2_256					fp_sub_2_256_ehuff
#define fp_add_256						fp_add_256_ehuff
#define fp_sub_256						fp_sub_256_ehuff
#define fp_mul_256						fp_mul_256_ehuff



#include "src/API/fp_256x8664.c"
#include "src/API/integer_hi_stack.c"
#include "src/API/integer_lo.c"
#include "src/API/error.c"
#include "src/API/io.c"
#include "src/API/array_lo.c"
#include "src/API/alloc.c"
#include "src/ec_fp_256h_u.c"
#include "src/try_ec_fp_256h.c"
