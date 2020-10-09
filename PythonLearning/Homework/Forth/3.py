Str = input()
Dic = {'number' : 0, 'letter' : 0, 'space' : 0, 'other' : 0}
for i in Str:
    if ord(i) in range(48, 58):
        Dic['number'] += 1
    elif ord(i) in range(65, 91) or ord(i) in range(97, 123):
        Dic['letter'] += 1
    elif ord(i) == 32:
        Dic['space'] += 1
    else:
        Dic['other'] += 1
print('在刚刚输入的语句中，数字有{}个，英文字符有{}个，空格有{}个，其他字符有{}个'.format(Dic['number'], Dic['letter'], Dic['space'], Dic['other']))
