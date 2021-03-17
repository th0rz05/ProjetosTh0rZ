n = input('O que deseja escrever? ')

import turtle
import tartaruga
import letras

dicionario = {'A':letras.A,'B':letras.B,'C':letras.C,'E':letras.E,'L':letras.L,'M':letras.M,'O':letras.O,'R':letras.R,' ':letras.ESPACO}


s = turtle.getscreen()
t = turtle.Turtle()
t.speed(0)
tartaruga.inicializar(s,t)
tartaruga.fazerborda(t)
#t.penup()
tartaruga.dividir_ecra_na_horizontal(t)
tartaruga.dividir_ecra_na_vertical(t)
tartaruga.ir_po_inicio(t)
tartaruga.dividir_em_tres(t)
t.goto(-655,305)
t.goto(-555,305)
t.goto(-555,105)
t.goto(-655,105)
t.penup()
posx = -655
posy = 305
t.goto(posx,posy)
t.speed(3)
t.pensize(2)
for letra in n: 
    dicionario[letra](t)
    posx += 100
    t.goto(posx,posy)


s.mainloop()
