len = int(input())
s = list(map(int, input().split()))
sum = 0

for i in range(len):
  if i % 2 == 0:
    sum += s[i]
    
print(sum)
