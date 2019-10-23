def cross(num, array):
    array.sort()
    m = [0 for i in range(num)]
    m[0] = array[0]
    m[1] = array[1]
    for i in range(2, num):
        m[i] = min(m[i-1]+array[i]+array[0], m[i-2]+array[i]+array[0]+array[1]+array[1])
    return m[-1]

num,array = int(input()),[]
for i in range(0,num):
    tempNum = int(input())
    array.append(tempNum)

print(cross(num, array))