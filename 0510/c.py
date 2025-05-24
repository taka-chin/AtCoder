N = int(input())
nums = list(map(int,input().split()))
total = 0

for _ in range(len(nums)):
    j = 1
    for j in range(len(nums)):
      total= total + nums[0] * nums[j]
    nums.pop(0)

print(total)
