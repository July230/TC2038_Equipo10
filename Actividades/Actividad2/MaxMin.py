import numpy as np
size = 10
arr = [0]*pow(size,2)
arr = np.reshape(arr,(size,size))
for i in range(size):
    for j in range(size):
        arr[i,j] = np.random.randint(1,200)
min = [0]*size
max = [0]*size

def max_min(arr):
    l,r = 0, size-1
    return max_min_b(arr,l,r)

def max_min_b(arr,l,r):
    n = r-l+1
    if n <= 2:
        #print("Left", arr[l], "Right", arr[r])
        if arr[l] <= arr[r]:
            return (arr[l],arr[r])
        else:
            return (arr[r],arr[l])
    mid = (l + r) // 2
    lMin, lMax = max_min_b(arr,l,mid)
    rMin, rMax = max_min_b(arr,mid+1,r)
    min = lMin if lMin < rMin else rMin
    max = rMax if rMax > lMax else lMax
    #print("Min", min, "Max", max)
    return (min,max)

print("Array:\n", arr)
for i in range(size):
    min[i], max[i] = max_min(arr[i])
minimum, notMax = max_min(min)
notMin, maximum = max_min(max)
print("Min", minimum, "\nMax", maximum)