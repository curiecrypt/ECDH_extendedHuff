#ifndef MULTIPRECISION256_H
#define MULTIPRECISION256_H
void mi_init_stack(MI new, uni an);
void mi_negate_stack(MI a);
void mi_set_1_stack(MI a, uni_t value);
void mi_clone_stack(MI z, MI a);
void mi_shift_left_stack(MI z, MI a);
void mi_shift_right_stack(MI z, MI a);
void mi_shift_left_nbit_stack(MI z, MI a, uni_t n);
void mi_shift_right_nbit_stack(MI z, MI a, uni_t n);
COMPARE mi_compare_abs_1_stack(MI a, uni_t b);
COMPARE mi_compare_abs_stack(MI a, MI b);
COMPARE mi_compare_stack(MI a, MI b);
void mi_add_1_stack(MI z, MI a, uni_t b);
void mi_add_stack(MI z, MI a, MI b);
void mi_sub_1_stack(MI z, MI a, uni_t b);
void mi_sub_stack(MI z, MI a, MI b);
void mi_mul_1_stack(MI z, MI a, uni_t b);
void mi_mul_stack(MI z, MI a, MI b);
void mi_exp_stack(MI z, MI a, MI b);
void mi_div_q_stack(MI q, MI a, MI b);
void mi_div_qr_stack(MI q, MI r, MI a, MI b);
void mi_div_1_stack(MI q, MI a, uni_t b);
void mi_div_stack(MI q, MI a, MI b);
void mi_gcd_stack(MI d, MI a, MI b);
void mi_gcdx_stack(MI d, MI xd, MI yd, MI x, MI y);
void mi_lcm_stack(MI z, MI a, MI b);
void mi_mod_stack(MI r, MI a, MI n);
void mi_modadd_stack(MI z, MI a, MI b, MI n);
void mi_modsub_stack(MI z, MI a, MI b, MI n);
void mi_modmul_stack(MI z, MI a, MI b, MI n);
void mi_moddiv_stack(MI z, MI a, MI b, MI n);
void mi_modinv_stack_ehuff(MI z, MI a, MI n);
#endif
