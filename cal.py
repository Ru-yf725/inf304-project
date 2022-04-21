import math
def f(x):
    return (7*x+7)/(x+7)

def iter(u0,e):
    u1=f(u0)
    n=0
    while abs(u1-u0)>=e:
        u0=u1
        u1=f(u0)
        n+=1
    print(u1)
    print("nb d'iteration:",n)
    return u1

l=iter(2,10**(-8))

def iter_k(u0,k,e):
    u1=f(u0)
    n=0
    while abs(u1-l)>e/(1-k):
        u0=u1
        u1=f(u0)
        n+=1
    print(u1)
    print("nb d'iteration:",n)
    return u1

def arc_tan(x):
    return math.atan(x)+2*math.pi

def arc_tan_derivee(x):
    return 1/(1+x**2)



def iter_tan(u0,e):
    u1=arc_tan(u0)
    n=0
    while abs(u1-u0)>=e:
        u0=u1
        u1=arc_tan(u0)
        n+=1
    print(u1)
    print("nb d'iteration:",n)
    return u1

l=iter_tan(2*math.pi,10**(-6))
k=1/(1+(2*math.pi)**2)
def iter_k_tan(k,u0,e):
    u_initial=u0
    u1=arc_tan(u0)
    n=0
    while abs(u1-l)>((abs(k))**n)*abs(u_initial-l) and ((abs(k))**n)*abs(u_initial-l)>e:
        u0=u1
        u1=arc_tan(u0)
        n+=1
    print(u1)
    print("nb d'iteration:",n)
    return u1

def arc_newton(x):
    return x-(arc_tan(x)-x)/(arc_tan_derivee(x)-1)

def iter_newton(u0,e):
    u1=arc_newton(u0)
    n=0
    while abs(u1-u0)>=e:
        u0=u1
        u1=arc_newton(u0)
        n+=1
    print(u1)
    print("nb d'iteration:",n)
    return u1



