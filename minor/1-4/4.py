liczby=[int(input("Podaj liczbe:")) for i in range(3)]
#liczby.sort()
if liczby[0]>liczby[1]:
    liczby[0],liczby[1]=liczby[1],liczby[0]
if liczby[1]>liczby[2]:
    liczby[1],liczby[2]=liczby[2],liczby[1]
if liczby[0]>liczby[1]:
    liczby[0],liczby[1]=liczby[1],liczby[0]
min,max=liczby[0],liczby[2]
print(f'min={min}, max={max}')