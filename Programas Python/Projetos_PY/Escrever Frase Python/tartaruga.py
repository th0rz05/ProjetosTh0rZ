import turtle
s = turtle.getscreen()
t = turtle.Turtle()

def inicializar(s,t):
    '''inicializa a tartaruga e o ecra'''
    s.setup(1400,700)
    s.bgcolor('#02b5fc')
    turtle.title('Tartaruga')
    turtle.hideturtle()
    t.shapesize(1,1,1)
    t.pensize(1)
    t.color('black','#b8dff0')

def fazerborda(t):
    '''faz uma borda'''
    t.penup()
    t.goto(-675,325)
    t.pendown()
    t.begin_fill()
    for x in [1340,640,1340,640]:
        t.forward(x)
        t.right(90)
    t.end_fill()
    
def dividir_ecra_na_horizontal(t):
    t.forward(20)
    t.right(90)
    t.forward(640)
    t.right(180)
    t.forward(640)
    t.right(90)
    for _ in range(13):
        t.forward(100)
        t.right(90)
        t.forward(640)
        t.right(180)
        t.forward(640)
        t.right(90)

def dividir_ecra_na_vertical(t):
    t.right(180)
    t.forward(1320)
    t.left(90)
    t.forward(20)
    t.left(90)
    t.forward(1340)
    t.left(180)
    t.forward(1340)
    t.left(90)
    for _2 in range(3):
        t.forward(200)
        t.left(90)
        t.forward(1340)
        t.left(180)
        t.forward(1340)
        t.left(90)
        
def ir_po_inicio(t):
    t.penup()
    t.goto(-655,305)
    t.pendown()
    
def dividir_em_tres(t):
    for _3 in range(3):
        t.forward(66)
        t.left(90)
        t.forward(1320)
        t.left(180)
        t.forward(1320)
        t.left(90)
        t.forward(66)
        t.left(90)
        t.forward(1320)
        t.left(180)
        t.forward(1320)
        t.left(90)
        t.forward(68)

if __name__ == '__main__':
    inicializar(s,t)
    fazerborda(t)
    s.mainloop()
    



