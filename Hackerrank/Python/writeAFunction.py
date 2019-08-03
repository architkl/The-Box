import sys

def is_leap(n):
    t, f = 'True', 'False'
    
    if (n % 400 == 0):
		return t

    elif (n % 100 == 0):
		return f

    elif (n % 4 == 0):
		return t

    else:
		return f

y = int(input())

print(is_leap(y))