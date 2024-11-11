print(sum( i != 'b' and int(i)>0 for i in list(bin(list(map(int, input().split()))[1]))))
