nums = list(map(int,input()))
count = 0

for i in range(len(nums)):
    if nums[i] == 1:
        count = count + 1

print(count)
