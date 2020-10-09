def gcd(a, b):
    if b == 0: return a
    elif a == 0: return b
    if a > b:
        return gcd(a % b, b)
    else:
        return gcd(b % a, a)

Num = input().split()
a = int(Num[0])
b = int(Num[1])
print(gcd(a, b))
