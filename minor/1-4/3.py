liczby=[int(input("Podaj liczbe:")) for i in range(3)]
#print("Podane liczby w kolejnosci niemalejacej to",liczby if liczby.sort()==None else "")
if liczby[0]>liczby[1]:
    liczby[0],liczby[1]=liczby[1],liczby[0]
if liczby[1]>liczby[2]:
    liczby[1],liczby[2]=liczby[2],liczby[1]
if liczby[0]>liczby[1]:
    liczby[0],liczby[1]=liczby[1],liczby[0]
print(liczby)