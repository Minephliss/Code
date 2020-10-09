N = int(input('您想要输出到第几项：'))
List = [0] * (N + 1)
List[1] = List[2] = 1

def Fibonacci(n):
    if List[n] != 0: return List[n]
    List[n] = Fibonacci(n - 1) + Fibonacci(n - 2)
    return List[n]

Fibonacci(N)
for i in range(1, len(List)):
    print(List[i], end = ' ')
print('')
