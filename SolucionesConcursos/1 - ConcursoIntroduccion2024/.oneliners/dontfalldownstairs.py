print((lambda n, l: sum([l[i] - (l[i + 1] + int(l[i] != l[i + 1])) for i in range(len(l)-1)]))(int(input()), list(map(int, input().split()))+[0]))

