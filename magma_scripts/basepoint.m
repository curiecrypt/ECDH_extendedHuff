K:=GF(2^256-587);
a:=K!1;
b:=K!1;
repeat
	c:=Random(K);
	d:=Random(K);
until a*b*c*d*(a*d^2-b*c^2) ne 0;

P<x,y>:=AffineSpace(K,2);
C<X,Y,Z>:=ProjectiveClosure(Curve(P,[d*y*(1+a*x^2)-c*x*(1+b*y^2)]));
W,CtoW:=EllipticCurve(C,C![0,0,1]);
WtoC:=Inverse(CtoW);

Point_P_W:=Random(W);
Point_P_C:=WtoC(Point_P_W);
Point_P_W;

/////////////////////////////////////////////////////////////////////////////

K:=GF(2^256-587);
a:=K!1;
b:=K!1;
c:=K!2843372514693350191555057326962375992036895483176136989686999058312654159918;
d:=K!2365984729494867911035798843067087631836584685670553507882547214869756774841;
a*b*c*d*(a*d^2-b*c^2) ne 0;

P<x,y>:=AffineSpace(K,2);
C<X,Y,Z>:=ProjectiveClosure(Curve(P,[d*y*(1+a*x^2)-c*x*(1+b*y^2)]));
W,CtoW:=EllipticCurve(C,C![0,0,1]);
WtoC:=Inverse(CtoW);

Point_P_W:=W![89310789835410412940443039348506686738982786907057132408379926651835281330412, 40017325922747964398513457065616619435549378408568562993757922415768800343674];
Point_P_C:=C![78227782389347043686834279660713384188146473863731300980788090558002942260369, 113605057163999847053892715207189777943571487323768222867518100299887973459392];
WtoC(Point_P_W) eq Point_P_C;
