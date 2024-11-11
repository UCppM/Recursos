print("\n".join((lambda x: f"{x} is " + ("even" if x%2 == 0 else "odd"))(int(input())) for _ in range(int(input()))))
