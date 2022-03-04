clear;

function MyString(XX,bit)

	XXX :=[];
	for i:=1 to #XX do
		XXX[i] := IntegerToSequence(Integers()!XX[i], 256); /*256 is fixed! Do not change*/
	end for;
	XX := XXX;

	//XX := Reverse(XX);
	Xout := "{ \\\n";
	i := 1;
	while i le #XX do
		s := XX[i];
		j := 1;
		//acc := "    {";
		acc := "    ";
		str := "";
		while j le #s do
			str := Sprintf("%h", s[j]);
			if #str eq 3 then
				str := str[1] cat str[2] cat "0" cat str[3];
			end if;
			if j ne #s then
				str *:= ", ";
			end if;
			acc *:= str;
			j := j + 1;
		end while;
		while j le bit/8 do
			if j eq 1 then
				acc *:= "0x00";
			else
				acc *:= ", 0x00";
			end if;
			j := j + 1;
		end while;
		Xout *:= acc;
		//Xout *:= "}";
		if i ne #XX then
			Xout *:= ", \\\n";
		end if;
		i := i + 1;
	end while;
	Xout *:= " \\\n}";
	return Xout;
end function;


bit := 256;


FF:=[2^256-587];
cc:=[2843372514693350191555057326962375992036895483176136989686999058312654159918];
dd:=[2365984729494867911035798843067087631836584685670553507882547214869756774841];
xx:=[78227782389347043686834279660713384188146473863731300980788090558002942260369];
yy:=[113605057163999847053892715207189777943571487323768222867518100299887973459392];

c:=MyString(cc,bit);
d:=MyString(dd,bit);
FLD:=MyString(FF,bit);
X_crd:=MyString(xx,bit);
Y_crd:=MyString(yy,bit);

FLD;
c;
d;
X_crd;
Y_crd;
