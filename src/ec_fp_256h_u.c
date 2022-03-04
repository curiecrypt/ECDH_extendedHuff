/**
 * Scalar multiplication on extended Huff curve with a = b = 1.
 *
 *     d*Y*T*(Z^2+a*X^2)=c*X*Z*(T^2+b*Y^2).
 *
 * Gamze Orhon Kilic.
 * 2017.
 **/

#define WINDOW_SIZE_LTR 5
#define TABLE_SIZE_LTR (1 << (WINDOW_SIZE_LTR - 2))

void InputOutputCheck(const uni X1, const uni Z1, const uni Y1, const uni T1, const uni X2, const uni Z2, const uni Y2, const uni T2, int func_type){
	if(func_type==0)
	{
	  printf("X1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", X1[0], X1[1], X1[2], X1[3]);
	  printf("Y1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", Y1[0], Y1[1], Y1[2], Y1[3]);
	  //printf("X1;\nY1;\n");
	}
	else if(func_type==1)
	{
		printf("X1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", X1[0], X1[1], X1[2], X1[3]);
		printf("Z1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", Z1[0], Z1[1], Z1[2], Z1[3]);
		printf("Y1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", Y1[0], Y1[1], Y1[2], Y1[3]);
		printf("T1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", T1[0], T1[1], T1[2], T1[3]);
		//printf("X1;\nZ1;\nY1;\nT1;\nX2;\nY2;\n");
	}
	else if(func_type==2)
	{
		printf("X1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", X1[0], X1[1], X1[2], X1[3]);
		printf("Z1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", Z1[0], Z1[1], Z1[2], Z1[3]);
		printf("Y1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", Y1[0], Y1[1], Y1[2], Y1[3]);
		printf("T1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", T1[0], T1[1], T1[2], T1[3]);
		printf("X2 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", X2[0], X2[1], X2[2], X2[3]);
		printf("Y2 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", Y2[0], Y2[1], Y2[2], Y2[3]);
		//printf("X1;\nZ1;\nY1;\nT1;\nX2;\nY2;\n");
	}
	else if(func_type==3)
	{
		printf("X1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", X1[0], X1[1], X1[2], X1[3]);
		printf("Z1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", Z1[0], Z1[1], Z1[2], Z1[3]);
		printf("Y1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", Y1[0], Y1[1], Y1[2], Y1[3]);
		printf("T1 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", T1[0], T1[1], T1[2], T1[3]);
		printf("X2 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", X2[0], X2[1], X2[2], X2[3]);
		printf("Z2 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", Z2[0], Z2[1], Z2[2], Z2[3]);
		printf("Y2 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", Y2[0], Y2[1], Y2[2], Y2[3]);
		printf("T2 :=K!(%lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3);\n", T2[0], T2[1], T2[2], T2[3]);
		//printf("X1;\nZ1;\nY1;\nT1;\nX2;\nY2;\n");
	}
	else
	{
		printf("X3 := %lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3;\n", X1[0], X1[1], X1[2], X1[3]);
		printf("Z3 := %lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3;\n", Z1[0], Z1[1], Z1[2], Z1[3]);
		printf("Y3 := %lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3;\n", Y1[0], Y1[1], Y1[2], Y1[3]);
		printf("T3 := %lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3;\n", T1[0], T1[1], T1[2], T1[3]);
		//printf("X1;\nZ1;\nY1;\nT1;\n");
	}
}
static void ec_fp_cpy_256H_u(uni X3, uni Z3, uni Y3,  uni T3, const uni X1, const uni Z1, const uni Y1, const uni T1){
	fp_cpy_256(X3, X1);
	fp_cpy_256(Y3, Y1);
	if(Z1 == NULL && T1 == NULL){
		fp_set_1_256(Z3, 1);
		fp_set_1_256(T3, 1);
	}
	else{
		fp_cpy_256(Z3, Z1);
		fp_cpy_256(T3, T1);
	}
}
static void ec_fp_neg_256H_u(uni X3, uni Z3, uni Y3, uni T3, const uni X1, const uni Z1, const uni Y1, const uni T1){
	fp_sub_2_256(X3, 0, X1);
	fp_sub_2_256(Y3, 0, Y1);
	if(Z1 == NULL && T1 == NULL){
		fp_set_1_256(Z3, 1);
		fp_set_1_256(T3, 1);
	}
	else{
		fp_cpy_256(Z3, Z1);
		fp_cpy_256(T3, T1);
	}
}
inline static void fp_cnt_256_u(int *bc, const uni an, const uni_t al){
	uni_t w, i, j;

	for(i = al - 1; (an[i] == 0) && (i > 0); i--);
	w = an[i];
	for(j = 0; w != 0; j++){
		w >>= 1;
	}
	(*bc) = j + i*UNIT_LEN;
}
inline static void find_nextwindow_u(int *v, int *k, int *wd, const uni en, const int i){
	int t, u2, s, b, sl, sr;
	uni_t n;

	b = i/UNIT_LEN;
	sr = (i + 1) - (b*UNIT_LEN);
	sl = UNIT_LEN - sr;
	if(b < FP_LEN){
		n = en[b] << sl;
	}
	else{
		n = 0;
	}
	if((b != 0) && (sl != 0)){
		n |= (en[b - 1] >> sr);
	}
	t = n >> (UNIT_LEN - 1);
	if(((n >> (UNIT_LEN - 2)) & 0x1) == t){
		*v = 0; *k = i; *wd = 1;
	}
	else{
		if(WINDOW_SIZE_LTR < (i + 1)){
			*wd = WINDOW_SIZE_LTR;
		}
		else{
			*wd = i + 1;
		}
		n <<= 1;
		n >>= (UNIT_LEN - *wd);
		if((i - *wd + 1) < 1){
			u2 = 0;
		}
		else{
			u2 = n & 0x1;
		}
		*v = -(t << (*wd - 1)) + (n >> 1) + u2;
		s = 0;
		for(; (*v & 0x1) == 0; s++, *v = *v >> 1);
		*k = i - (*wd - 1) + s + 1;
	}
}


/*Cost: 5M + 8a.*/
static void ec_fp_mdbl_256H_u(uni X3, uni Z3, uni Y3, uni T3, const uni X1, const uni Y1){

	uni_t r0[FP_LEN], r1[FP_LEN], r2[FP_LEN], r3[FP_LEN], r4[FP_LEN];

	/* Input Check
  printf("//C Input of ec_fp_mdbl_256H_u function(Obtained by Input Check). Used as input of mdbl function.\n");
  InputOutputCheck(X1, NULL, Y1, NULL, NULL, NULL, NULL, NULL, 0);
  // exit(1);
  // */

	fp_mul_256(r4, X1, Y1);
	fp_add_256(X3, X1, Y1);
	fp_sub_256(Y3, X1, Y1);
	fp_sub_2_256(T3, 1, r4);
	fp_add_1_256(Z3, r4, 1);

	fp_mul_256(r0, X3, T3);
	fp_mul_256(r1, Y3, Z3);
	fp_mul_256(r2, T3, Z3);
	fp_mul_256(r3, X3, Y3);

	fp_add_256(X3, r0, r1);
	fp_sub_256(Y3, r0, r1);
	fp_sub_256(Z3, r2, r3);
	fp_add_256(T3, r2, r3);

	/* Output Check
	printf("\n\n//C Output of ec_fp_mdbl_256H_u function(Obtained by Output Check).\n");
  InputOutputCheck(X3, Z3, Y3, T3, NULL, NULL, NULL, NULL, -1);
	exit(1);
	// */

}


/*Cost: 8M + 8a */
inline static void ec_fp_dbl_256H_u(uni X3, uni Z3, uni Y3, uni T3, const uni X1, const uni Z1, const uni Y1, const uni T1){

	uni_t r0[FP_LEN], r1[FP_LEN], r2[FP_LEN], r3[FP_LEN];

	/* Input Check
	printf("//C Input of ec_fp_madd_256H_u ec_fp_dbl_256H_u(Obtained by Input Check). Used as input of dbl function.\n");
	InputOutputCheck(X1, Z1, Y1, T1, NULL, NULL, NULL, NULL, 1);
	// exit(1);
	// */

	fp_mul_256(r0, X1, T1);
	fp_mul_256(r1, Y1, Z1);
	fp_mul_256(r2, T1, Z1);
	fp_mul_256(r3, X1, Y1);

	fp_add_256(X3, r0, r1);
	fp_sub_256(Y3, r0, r1);
	fp_sub_256(T3, r2, r3);
	fp_add_256(Z3, r2, r3);

	fp_mul_256(r0, X3, T3);
	fp_mul_256(r1, Y3, Z3);
	fp_mul_256(r2, T3, Z3);
	fp_mul_256(r3, X3, Y3);

	fp_add_256(X3, r0, r1);
	fp_sub_256(Y3, r0, r1);
	fp_sub_256(Z3, r2, r3);
	fp_add_256(T3, r2, r3);

	/* Output Check
	printf("\n\n//C Output of ec_fp_dbl_256H_u function(Obtained by Output Check).\n");
	InputOutputCheck(X3, Z3, Y3, T3, NULL, NULL, NULL, NULL, -1);
	exit(1);
	// */

}


/*Cost: 8M + 6a. */
static void ec_fp_madd_256H_u(uni X3, uni Z3, uni Y3, uni T3, const uni X1, const uni Z1, const uni Y1, const uni T1, const uni X2, const uni Y2){

	 uni_t r0[FP_LEN], r1[FP_LEN], r2[FP_LEN], r3[FP_LEN], r4[FP_LEN], r5[FP_LEN];

	 /* Input Check
	 printf("//C Input of ec_fp_madd_256H_u function(Obtained by Input Check). Used as input of muadd function.\n");
	 InputOutputCheck(X1, Z1, Y1, T1, X2, NULL, Y2, NULL, 2);
	 // exit(1);
	 // */

	fp_mul_256(r0, X1, X2);//t1=A
	fp_mul_256(r1, Z1, X2);//t3=C
	fp_mul_256(r2, Y1, Y2);//t2=B
	fp_mul_256(r3, T1, Y2);//t4=D

	fp_add_256(r4, Z1, r0);//t5=E
	fp_add_256(r1, X1, r1);//t6=F
	fp_add_256(r5, T1, r2);//t1=G
	fp_add_256(r3, Y1, r3);//t2=H

	fp_sub_256(r0, Z1, r0);//t3=I
	fp_sub_256(r2, T1, r2);//t4=J

	fp_mul_256(Z3, r0, r5);
	fp_mul_256(X3, r1, r2);
	fp_mul_256(T3, r2, r4);
	fp_mul_256(Y3, r3, r0);

	/* Output Check
	printf("\n\n//C Output of ec_fp_madd_256H_u function(Obtained by Output Check).\n");
	InputOutputCheck(X3, Z3, Y3, T3, NULL, NULL, NULL, NULL, -1);
	exit(1);
	// */

}


/*Cost: 8M + 6a. */
static void ec_fp_msub_256H_u(uni X3, uni Z3, uni Y3, uni T3, const uni X1, const uni Z1, const uni Y1, const uni T1, const uni X2, const uni Y2){

	/* Input Check
	printf("//C Input of ec_fp_msub_256H_u function(Obtained by Input Check). Used as input of musub function.\n");
	InputOutputCheck(X1, Z1, Y1, T1, X2, NULL, Y2, NULL, 1);
	// exit(1);
	//*/

	uni_t r0[FP_LEN], r1[FP_LEN], r2[FP_LEN], r3[FP_LEN], r4[FP_LEN], r5[FP_LEN];

	fp_mul_256(r0, X1, X2);//t1=A -
	fp_mul_256(r1, Z1, X2);//t3=C -
	fp_mul_256(r2, Y1, Y2);//t2=B -
	fp_mul_256(r3, T1, Y2);//t4=D -

	fp_sub_256(r4, Z1, r0);//t5=E
	fp_sub_256(r1, X1, r1);//t6=F
	fp_sub_256(r5, T1, r2);//t1=G
	fp_sub_256(r3, Y1, r3);//t2=H

	fp_add_256(r0, Z1, r0);//t3=I
	fp_add_256(r2, T1, r2);//t4=J

	fp_mul_256(Z3, r0, r5);
	fp_mul_256(X3, r1, r2);
	fp_mul_256(T3, r2, r4);
	fp_mul_256(Y3, r3, r0);

	/* Output Check
	printf("\n\n//C Output of ec_fp_msub_256H_u function(Obtained by Output Check).\n");
	InputOutputCheck(X3, Z3, Y3, T3, NULL, NULL, NULL, NULL, -1);
	exit(1);
	// */

}


/*Cost: 10M+10a. */
static void ec_fp_add_256H_u(uni X3, uni Z3, uni Y3, uni T3, const uni X1, const uni Z1, const uni Y1, const uni T1, const uni X2, const uni Z2, const uni Y2, const uni T2){
	uni_t t1[FP_LEN], t2[FP_LEN], t3[FP_LEN], t4[FP_LEN], t5[FP_LEN], t6[FP_LEN], t7[FP_LEN], t8[FP_LEN], t9[FP_LEN], t10[FP_LEN];

	/*Input Check
	printf("//C Input of ec_fp_add_256H_u function(Obtained by Input Check). Used as input of uadd function.\n");
	InputOutputCheck(X1, Z1, Y1, T1, X2, Z2, Y2, T2, 3);
	//exit(1);
	//*/

	fp_add_256(t1, X2, Z2);//t1=U
	fp_add_256(t2, T2, Y2);//t2=V
	fp_mul_256(t3, X1, X2);//t3=A
	fp_mul_256(t4, Y1, Y2);//t4=B
	fp_mul_256(t5, Z1, Z2);//t5=C
	fp_mul_256(t6, T1, T2);//t6=D

	fp_add_256(t7, Z1, X1);//t7=E
	fp_add_256(t8, T1, Y1);//t8=F
	fp_add_256(t9, t3, t5);//t9=G
	fp_add_256(t10, t4, t6);//t12=H

	fp_mul_256(t1, t7, t1);//t1=I
	fp_mul_256(t2, t8, t2);//t2=J
	//fp_cpy_256(t10, t4);//t10=K
	//fp_cpy_256(t11, t3);//t11=L

	fp_sub_256(t8, t6, t4);//t8=M
	fp_add_256(t6, t6, t4);//t6=N
	fp_sub_256(t7, t5, t3);//t7=P
	fp_add_256(t5, t5, t3);//t5=Q
	fp_sub_256(t1, t1, t9);//t1=R
	fp_sub_256(t2, t2, t10);//t2=S

	fp_mul_256(X3, t1, t8);
	fp_mul_256(Z3, t7, t6);
	fp_mul_256(Y3, t2, t7);
	fp_mul_256(T3, t5, t8);

	/*Output Check
	printf("\n\n//C Output of ec_fp_add_256H_u function(Obtained by Output Check).\n");
	InputOutputCheck(X3, Z3, Y3, T3, NULL, NULL, NULL, NULL, -1);
	exit(1);
	//*/

}




void ec_fp_smul_256h_u(uni X1, uni Z1, uni Y1, uni T1, const uni kn, const uni X2, const uni Y2, const uni CC, const uni DD)
{
	uni_t X[TABLE_SIZE_LTR][FP_LEN], Y[TABLE_SIZE_LTR][FP_LEN], Z[TABLE_SIZE_LTR][FP_LEN], T[TABLE_SIZE_LTR][FP_LEN];
	uni_t t1[FP_LEN], t2[FP_LEN], t3[FP_LEN], t4[FP_LEN], t5[FP_LEN], t6[FP_LEN];
	int i, j, ni, k, wd;

	fp_cnt_256_u(&i, kn, FP_LEN);

	if(i == 0)
	{
		fp_set_1_256(X1, 0);
		fp_set_1_256(Z1, 1);
		fp_set_1_256(Y1, 0);
		fp_set_1_256(T1, 1);
	}
	else
	{
		uni_t Zz[FP_LEN], Tt[FP_LEN];
		fp_set_1_256(Zz, 1);
		fp_set_1_256(Tt, 1);

		ec_fp_mdbl_256H_u(X[0], Z[0], Y[0], T[0], X2, Y2); /* 2P. */
		ec_fp_madd_256H_u(X[1], Z[1], Y[1], T[1], X[0], Z[0],Y[0], T[0], X2, Y2); /* 3P. */

		for(j = 2; j < TABLE_SIZE_LTR; j++)
			ec_fp_add_256H_u(X[j], Z[j], Y[j], T[j], X[j - 1], Z[j - 1], Y[j - 1], T[j - 1], X[0], Z[0], Y[0], T[0]);

		find_nextwindow_u(&ni, &k, &wd, kn, i);
		i -= wd;

		if(ni > 0)
		{
			ni >>= 1;
			if(ni == 0)
				ec_fp_cpy_256H_u(X1, Z1, Y1, T1, X2, NULL, Y2, NULL);
			else
				ec_fp_cpy_256H_u(X1, Z1, Y1, T1, X[ni], Z[ni], Y[ni], T[ni]);
		}
		else
		{
			ni = (-ni) >> 1;
			if(ni == 0)
				ec_fp_neg_256H_u(X1, Z1, Y1, T1, X2, NULL, Y2, NULL);
			else
				ec_fp_neg_256H_u(X1, Z1, Y1, T1, X[ni], Z[ni], Y[ni], T[ni]);
		}

		for(j = k - 1; i >= 0; j--)
		{
			find_nextwindow_u(&ni, &k, &wd, kn, i);
			i -= wd;
			if(ni == 0)
			{
				ec_fp_dbl_256H_u(X1, Z1, Y1, T1, X1, Z1, Y1, T1); //DBL1++;
			}
			else
			{
				for(; j > k; j--)
					ec_fp_dbl_256H_u(X1, Z1, Y1, T1, X1, Z1, Y1, T1); //DBL2++;

				ec_fp_dbl_256H_u(X1, Z1, Y1, T1, X1, Z1, Y1, T1); //DBL2++;

				if(ni > 0)
				{
					ni >>= 1;
					if(ni == 0)
						ec_fp_madd_256H_u(X1, Z1, Y1, T1, X1, Z1, Y1, T1, X2, Y2); //DBL3++; ADD++;
					else
						ec_fp_add_256H_u(X1, Z1, Y1, T1, X1, Z1, Y1, T1, X[ni], Z[ni], Y[ni], T[ni]); //DBL3++; ADD++;
				}
				else
				{
					ni = (-ni) >> 1;
					if(ni == 0)
						ec_fp_msub_256H_u(X1, Z1, Y1, T1, X1, Z1, Y1, T1, X2, Y2); //ADD++;
					else
						ec_fp_add_256H_u(X1, Z1, Y1, T1, X1, Z1, Y1, T1, X[ni], Z[ni], Y[ni],  T[ni]); //ADD++;
				}
			}
		}

		for(; j >= 1; j--)
			ec_fp_add_256H_u(X1, Z1, Y1, T1, X1, Z1, Y1, T1, X1, Z1, Y1, T1);

		/* Input Check
		printf("CC := %lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3;\n", CC[0], CC[1], CC[2], CC[3]);
		printf("DD := %lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3;\n", DD[0], DD[1], DD[2], DD[3]);
		printf("X1 := %lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3;\n", X1[0], X1[1], X1[2], X1[3]);
		printf("Z1 := %lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3;\n", Z1[0], Z1[1], Z1[2], Z1[3]);
		printf("Y1 := %lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3;\n", Y1[0], Y1[1], Y1[2], Y1[3]);
		printf("T1 := %lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3;\n", T1[0], T1[1], T1[2], T1[3]);
		exit(1);
		*/

		// d*Y*T*(Z^2+a*X^2)-c*X*Z*(T^2+b*Y^2)

		fp_mul_256(t1, Z1, Z1);//Z^2
		fp_mul_256(t2, X1, X1);//X^2
		fp_mul_256(t3, T1, T1);//T^2
		fp_mul_256(t4, Y1, Y1);//Y^2

		fp_mul_256(t5, Y1, T1);//Y*T
		fp_mul_256(t6, X1, Z1);//X*Z

		fp_add_256(t1, t1, t2);//Z^2+a*X^2
		fp_add_256(t2, t3, t4);//T^2+b*Y^2

		fp_mul_256(t5, t5, DD);//d*Y*T
		fp_mul_256(t6, t6, CC);//c*X*Z

		fp_mul_256(t1, t1, t5);
		fp_mul_256(t2, t2, t6);

		fp_sub_256(t3, t1, t2);

		/*Output Check
		printf("t3 := %lu*(2^64)^0+%lu*(2^64)^1+%lu*(2^64)^2+%lu*(2^64)^3;\n", t3[0], t3[1], t3[2], t3[3]);
		exit(1);
		*/

		/*Magma Code
		X1 := 1986914901791364864*(2^64)^0+10901868963250811062*(2^64)^1+723444746874957292*(2^64)^2+451327294478626390*(2^64)^3;
		Z1 := 1855343747963264777*(2^64)^0+5918607028444678109*(2^64)^1+16980657717832838466*(2^64)^2+11684840260714319836*(2^64)^3;
		Y1 := 1740430006406905446*(2^64)^0+10521429928787905007*(2^64)^1+14401394583775113232*(2^64)^2+15931946225590473078*(2^64)^3;
		T1 := 5758565691218087979*(2^64)^0+18350526050253445484*(2^64)^1+6182538641171151390*(2^64)^2+2279844062074555591*(2^64)^3;
		AA:= 2^256-587;
		c:=2843372514693350191555057326962375992036895483176136989686999058312654159918;
		d:=2365984729494867911035798843067087631836584685670553507882547214869756774841;
		CURVE:= d*Y1*T1*(Z1^2+X1^2)-c*X1*Z1*(T1^2+Y1^2);
		CURVE mod AA;
		*/

	}
}
