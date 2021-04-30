import math

lista = [-352,-297,-242,-187,-132,-77,-22,33,88,33,-22,-77,-132]
probabilidades =[]
media = 0
variancia=0

for n in range(0,12):
    combinacoes = math.factorial(12)/(math.factorial(n)*math.factorial(12-n))
    sucesso = 0.6**n
    insucesso = 0.4**(12-n)
    probabilidades.append(combinacoes*sucesso*insucesso)

for s in range(0,12):
    media += lista[s]*probabilidades[s]

for i in range(0,11):
    variancia += (lista[i]-media)**2*probabilidades[i]
    
desvio = variancia**0.5

print(media)
print(desvio)