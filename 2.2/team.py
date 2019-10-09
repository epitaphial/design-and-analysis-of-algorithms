import time

def rank(done,undo):
	global listG
	for i in range(len(undo)):
		# 组合成新的字符串
		done+=undo[i]
		undo = undo[:i]+undo[i+1:]
		if undo == "":
			if done in listG:
				return
			else:
				listG.append(done)
				return
		rank(done,undo)
		# 还原字符串，送入下一轮循环
		undo = undo[:i]+done[-1]+undo[i:]
		done = done[:-1]

timeS = time.time()
listG = []
rank("","xyz")
for i in listG:
	if i[0] != 'x' and i[2] != 'x' and i[2] != 'z':
		print("a<->"+i[0]+" b<->"+i[1]+" c<->"+i[2])

print("执行时间："+str(time.time()-timeS))