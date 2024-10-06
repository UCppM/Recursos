print(len({d for _ in range(int(input())) for d in (lambda ls: range(ls[0],ls[1]+1))(list(map(int,input().split())))}))
