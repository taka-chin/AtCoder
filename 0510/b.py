N,M = map(int,input().split())

numbers = list(map(int,input().split()))
count = 0

for _ in range(len(numbers)) - 1:
    nums = set(numbers)
    for j in range(M) : 
        if j + 1 not in nums:
            print(count)
            exit(0)
    numbers.pop(-1)
    count = count + 1
    
print(count)

