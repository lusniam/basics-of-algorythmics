liczby=[int(input('Podaj liczbe:')) for i in range(3)]
liczby.sort()
czy_arytmetyczny,czy_geometryczny,czy_staly=int(liczby[1]-liczby[0]==liczby[2]-liczby[1]),int(liczby[1]/liczby[0]==liczby[2]/liczby[1]),int(liczby[0]==liczby[1]==liczby[2])
print('ciag jest staly' if czy_staly else ('ciag jest geometryczny' if czy_geometryczny else ('ciag jest arytmetyczny' if czy_arytmetyczny else 'podane liczby nie tworza ciagu')))