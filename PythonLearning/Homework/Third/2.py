qwq = float(input('Your ability:'))
a = 0
for i in range(0, 365):
    a += 1
    if a <= 4:
        continue
    else:
        qwq *= 1.01
    a %= 7

print(qwq)
