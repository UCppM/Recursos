print(len({d for _ in range(int(input())) for d in (lambda ls: set(range(ls[0],ls[1]+1)))([int(x) for x in input().split()])}))
