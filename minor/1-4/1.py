from math import sqrt,pow
#liczby=[int(input("Podaj dlugosc boku trojkata:")) for i in range(3)]
#czy_trojkat=False not in [liczby[i]<sum(liczby[:i]+liczby[i+1:]) for i in range(3)]
#rodzaj=2*pow(max(liczby),2)-sum(pow(liczby[i],2) for i in range(3))
#if rodzaj>0: rodzaj="rozwartokatny"
#elif rodzaj==0: rodzaj="prostokatny"
#else: rodzaj="ostrokatny"
#print(("Z podanych bokow mozna zbudowac trojkat"+rodzaj+f",\njego obwod jest rowny {sum(liczby)},\na pole jest rowne {sqrt((sum(liczby)/2)*((sum(liczby)/2)-liczby[0])*((sum(liczby)/2)-liczby[1])*((sum(liczby)/2)-liczby[2]))}") if czy_trojkat else "Z podanych liczb nie mozna zbudowac trojkata")

l1=input("Podaj liczbe:")
l2=input("Podaj liczbe:")
l3=input("Podaj liczbe:")

if l1>0 and l2>0 and l3>0:
    if l1<l2+l3 and l2<l1+l3 and l3<l1+l2:
        czy_trojkat=1
    else:
        czy_trojkat=0
    if czy_trojkat:
        print("Z podanych liczb mozna zbudowac trojkat")
        obwod=l1+l2+l3
        p=obwod/2
        pole=sqrt(p*(p-l1)*(p-l2)*(p-l3))
        if l1>l2:
            l1,l2=l2,l1
        if l2>l3:
            l2,l3=l3,l2
        if l1>l2:
            l1,l2=l2,l1
        r=pow(l3,2)-pow(l2,2)-pow(l1,2)
        if r>0:
            rodzaj="rozwartokatny"
        if r==0:
            rodzaj="prostokatny"
        if r<0:
            rodzaj="ostrokatny"
        print("")
    else:
        print("Z podanych liczb nie mozna zbudowac trojkata")
else:
    print("Niepoprawne dane")