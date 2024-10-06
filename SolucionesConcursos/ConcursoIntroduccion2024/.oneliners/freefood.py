print(len({d for x,y in zip(*[iter(map(int,open(0).read().split()[1:]))]*2)for d in range(x,y+1)}))
