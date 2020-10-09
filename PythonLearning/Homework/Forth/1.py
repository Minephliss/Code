Num = int(5)
key = bool(False)
count = int(0)
while(key == False):
    count+=1
    num = int(input('请输入您的猜想数：'))
    if num > Num:
        print('遗憾，太大了')
    elif num < Num:
        print('遗憾，太小了')
    else:
        print('预测{}次，你猜中了！'.format(count))
        key = True

