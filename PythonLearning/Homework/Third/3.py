qwq = float(input('Your ability:'))
restT = int(input('Your Rest Cycle:'))
a = 0
for i in range(0, 365):
    a += 1
    if (i + 1) % restT == 0:
        a = 0
        continue
    if a <= 4:
        continue
    else:
        qwq *= 1.01
    a %= 7

print(qwq)
