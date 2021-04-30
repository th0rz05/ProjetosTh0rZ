import math

lista = [-352,-297,-242,-187,-132,-77,-22,33,88,33,-22,-77,-132]
prob =[]

for n in range(0,12):
    prob.append((math.factorial(12)/(math.factorial(n)*math.factorial(12-n)))*(0.6**n)*(0.4**(12-n)))

variancia=0

for i in range(0,11):
    variancia += (lista[i]-7.64)**2*prob[i]
    
desvio = math.sqrt(variancia)

print(desvio)