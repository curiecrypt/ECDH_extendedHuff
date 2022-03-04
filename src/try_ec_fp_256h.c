#include <string.h>
#include <stdarg.h>
#include <math.h>

#define SECRETKEY_BYTES 32
#define PUBLICKEY_BYTES 64
#define SHAREDSECRET_BYTES 32

EC_FP_SMULBASE_256H_CACHE


int crypto_dh_keypair(unsigned char* pk, unsigned char *sk)
{
	unsigned char zzn[SECRETKEY_BYTES], ttn[SECRETKEY_BYTES];
	unsigned int i;

	for (i = 0; i < SECRETKEY_BYTES; i++) sk[i] = rand();

	ec_fp_smul_256h_u((uni)pk, (uni)zzn, (uni)(pk + (PUBLICKEY_BYTES/2)), (uni)ttn, (uni)sk, (uni)xn0, (uni)yn0, (uni)cn0, (uni)dn0);

	/*Normalization.*/
	fp_inv_256((uni)zzn, (uni)zzn);
	fp_inv_256((uni)ttn, (uni)ttn);
	fp_mul_256((uni)pk, (uni)pk, (uni)zzn);
	fp_mul_256((uni)(pk + (PUBLICKEY_BYTES/2)), (uni)(pk + (PUBLICKEY_BYTES/2)), (uni)ttn);

	return 0;
}


int crypto_dh(unsigned char *s, const unsigned char* pk, const unsigned char *sk){
	uni_t zzn[FP_LEN], yyn[FP_LEN], ttn[FP_LEN];
	unsigned char result[SECRETKEY_BYTES];

	/*scalar multiplication*/
	ec_fp_smul_256h_u((uni)result, zzn, yyn, ttn, (uni)sk, (uni)pk, (uni)(pk + (PUBLICKEY_BYTES/2)), (uni)cn0, (uni)dn0);

	/*normalization*/
	fp_inv_256((uni)zzn, (uni)zzn);
	fp_mul_256((uni)result, (uni)result, (uni)zzn);

	memcpy(s,result,SECRETKEY_BYTES);

	return 0;
}

void main()
{
	unsigned char pk1[PUBLICKEY_BYTES], sk1[SECRETKEY_BYTES];
	unsigned char pk2[PUBLICKEY_BYTES], sk2[SECRETKEY_BYTES];
	unsigned char ss1[PUBLICKEY_BYTES], ss2[SECRETKEY_BYTES];
	long count, i;

	COUNT_MLD=0;
	COUNT_ADD=0;
	COUNT_MUL=0;
	COUNT_SQR=0;

	printf("\nExtended Huff (a=b=1) H (fixedbase)\n");

	for(count = 0; count < 10000; count++){
		crypto_dh_keypair(pk1, sk1);
		crypto_dh_keypair(pk2, sk2);
		crypto_dh(ss1, pk1, sk2);
		crypto_dh(ss2, pk2, sk1);

		for(i = 0; i < SECRETKEY_BYTES; i++){
			if(ss1[i] != ss2[i]){
				printf("Error! Secret does not match. (@ %lu)\n", count);
				exit(1);
			}
		}
	}

	printf("count_COUNT_MLD %lf\n",(double)COUNT_MLD/40000);
	printf("count_COUNT_ADD %lf\n",(double)COUNT_ADD/40000);
	printf("count_COUNT_MUL %lf\n",(double)COUNT_MUL/40000);
	printf("count_COUNT_SQR %lf\n",(double)COUNT_SQR/40000);

}
