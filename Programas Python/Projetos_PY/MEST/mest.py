import math

lista = [2,4,6,8,10]
probabilidades =[0.05,0.35,0.35,0.15,0.1]
media = 0
variancia=0

""" for n in range(0,10):
    combinacoes = math.factorial(12)/(math.factorial(n)*math.factorial(12-n))
    sucesso = 0.6**n
    insucesso = 0.4**(12-n)
    probabilidades.append(combinacoes*sucesso*insucesso) """

for s in range(0,5):
    media += lista[s]*probabilidades[s]

for i in range(0,5):
    variancia += (lista[i]-media)**2*probabilidades[i]
    

    
desvio = variancia**0.5

print("     ")
print(media)
print(desvio)
print(variancia)

print(0.3/(desvio/55**0.5))