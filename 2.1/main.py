import time

#求最大公因数
def gcd(m,n):
	if n != 0:
		return gcd(n,m%n)
	else:
		return m

#去除2，5
def remove(spn):
	remain2 = spn % 2
	remain5 = spn % 5
	if remain2 == 0 and remain5 == 0:
		return remove(spn/10)
	elif remain2 == 0 :
		return remove(spn/2)
	elif remain5 == 0:
		return remove(spn/5)
	else:
		return spn

#判断循环节
def tellLoop(m,n):
	m,n = int(m),int(n)
	remain,shang = m*10%n,m*10//n
	tp = (remain,shang)
	listS = []
	while True:
		#商和余数同时第一次重复为循环节判断条件
		if tp in listS:
			return listS.index(tp),len(listS)
		else:
			listS.append(tp)
			remain,shang = remain*10%n,remain*10//n
			tp = (remain,shang)


m,n = int(input("m=")),int(input("n="))

timeS = time.time()

Tgcd = gcd(m,n)
spm = m/Tgcd
spn = n/Tgcd

finalNum =  int(remove(spn))
if finalNum == 1:
	print(m/n)
else:
	strN = str(m/n)
	dot = '.'
	place = strN.index(dot)
	#整数部分
	intPart = strN[:place]
	#小数部分
	strX = strN[place+1:]
	#循环节位置
	placeBeg,placeEnd = tellLoop(spm%spn,spn)
	loopstr = strX[int(placeBeg):int(placeEnd)]
	Fistr = intPart+'.'+strX[:placeBeg]+'('+loopstr+')'
	print(Fistr)

print("执行时间："+str(time.time()-timeS))