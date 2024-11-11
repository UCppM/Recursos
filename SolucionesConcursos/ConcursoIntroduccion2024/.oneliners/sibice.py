print("\n".join((lambda n,x,y: ["DA" if int(input())**2 <= x*x + y*y else "NE" for _ in range(n)])(*map(int, input().split()))))
