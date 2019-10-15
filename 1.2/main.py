# 递归函数
def eat(nextTimeP,day):
	global n,m
	# n天终止
	if day == n:
		print("最初有%d个桃子" %nextTimeP)
		return
	else:
		eat((nextTimeP+m)*2,day+1)

d = int(input("最后一天只剩d:"))
m = int(input("多吃m:"))
n = int(input("n天:"))
eat(d,1)