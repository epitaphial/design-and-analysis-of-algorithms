# 递归函数
def rank(done,undo):
	global dictG
	for i in range(len(undo)):
		# 组合成新的字符串
		done+=undo[i]
		undo = undo[:i]+undo[i+1:]
		if undo == "":
			if done in dictG:
				return
			else:
				dictG[done] = 1
				#print(done)
				return
		rank(done,undo)
		# 还原字符串，送入下一轮循环
		undo = undo[:i]+done[-1]+undo[i:]
		done = done[:-1]

#字典，用于判断字符串是否重复
dictG = {}
Tstr = input("please input the string waiting to rank:\n")
rank("",Tstr)
print("results:")
for key in dictG.keys():
	print(key)