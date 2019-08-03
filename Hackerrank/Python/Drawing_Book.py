import sys

n = input()
p = input()

print(min(p / 2, ((n-p) / 2) if (n % 2) else ((n-p+1) / 2) ))