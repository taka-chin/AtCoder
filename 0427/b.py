s1 = input()
s2 = input()
flag = False

for i in range(len(s1)):
  if i + len(s2) > len(s1):
    break
  for j in range(len(s2)):
    if s1[i + j ] == '?' or s1[i + j] == s2[j]:
      if j == len(s2) - 1:
        flag = True
    else:
      break

if flag:
  print('Yes')
else:
  print('No') 
