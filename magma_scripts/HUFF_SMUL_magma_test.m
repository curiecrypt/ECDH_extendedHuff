///SMULL WITH UNIFIED ADD !!!WORKING
clear;
uadd:=function(X1, Z1, Y1, T1, X2, Z2, Y2, T2)
	UU:=X2+Z2;
	VV:=Y2+T2;
	AA:=X1*X2;
	BB:=Y1*Y2;
	CC:=Z1*Z2;
	DD:=T1*T2;
	EE:=X1+Z1;
	FF:=Y1+T1;
	GG:=AA+CC;
	HH:=BB+DD;
	II:=EE*UU;
	JJ:=FF*VV;
	KK:=BB;
	LL:=AA;
	MM:=DD-KK;
	NN:=DD+KK;
	PP:=CC-LL;
	QQ:=CC+LL;
	RR:=II-GG;
	SS:=JJ-HH;
	X3:=RR*MM;
	Z3:=PP*NN;
	Y3:=SS*PP;
	T3:=QQ*MM;
	return X3, Z3, Y3, T3;

end function;
K:=GF(2^256-587);
a:=K!1;
b:=K!1;
c:=K!2843372514693350191555057326962375992036895483176136989686999058312654159918;
d:=K!2365984729494867911035798843067087631836584685670553507882547214869756774841;

P<x,y>:=AffineSpace(K,2);
C<X,Y,Z>:=ProjectiveClosure(Curve(P,[d*y*(1+a*x^2)-c*x*(1+b*y^2)]));
W,CtoW:=EllipticCurve(C,C![0,0,1]);
WtoC:=Inverse(CtoW);

PP:=Random(W);
P:=WtoC(PP);



XP:=P[1];
ZP:=K!1;
YP:=P[2];
TP:=K!1;

XM:=K!0;
ZM:=K!1;
YM:=K!0;
TM:=K!1;

k:=7;
KK := IntegerToSequence(k,2);

for i in [1..#KK] do
	if KK[i] eq 1 then
		XM,ZM,YM,TM:=uadd(XM,ZM,YM,TM,XP,ZP,YP,TP);
	end if;
	XP,ZP,YP,TP:=uadd(XP,ZP,YP,TP,XP,ZP,YP,TP);
end for;

XM/ZM,YM/TM;
WtoC(k*PP);
