# ECDH_extendedHuffCurve
This is a crypto_dh application written in C language and runs only on x86-64 architectures.

The implementation uses the multiprecision arithmetic library CRYMPIX ([SUPERCOP-crypto_dh](https://bench.cr.yp.to/supercop.html)).

The elliptic curve scalar multiplication is performed using the extended Huff curve

> E:=dYT(Z^2+aX^2)=cXZ(T^2+bY^2)

with a=d=1.

*magma_scripts* folder includes magma scripts to test the functions in scalar multiplication code.

For more detailed information visit [Faster Point Addition Formulas for Huff Form of Elliptic Curves](https://www.academia.edu/35778370/FASTER_POINT_ADDITION_FORMULAS_FOR_HUFF_FORM_OF_ELLIPTIC_CURVES)


######  TODO:
- [ ] Update Makefile
- [ ] Update Readme
- [ ] Insert comments
