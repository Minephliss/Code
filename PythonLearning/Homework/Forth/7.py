botlim = int(input('输入下限：'))
toplim = int(input('输入上限：'))

List = [True] * (toplim + 1)
List[0] = List[1] = False

for i in range(2, toplim + 1):
   j = i
   if List[j]:
       j += i
       while j <= toplim:
           List[j] = False
           j += i
    
for i in range(botlim, len(List)):
    if List[i]: print(i)
