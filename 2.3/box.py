Lists = [1,2,4,8,16,32,64,128,256,512]
ListCP = []

# 比正常的重量减轻的重量
weight = int(input("loss weight="))/10
Lists = list(reversed(Lists))

for i in Lists:
	if weight>=i :
		ListCP.append(i)
		weight -= i

print(ListCP)