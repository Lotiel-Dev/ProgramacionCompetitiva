from sys import stdin
input = stdin.readline

def sol():
    n = int(input())
    ix, iy, fx, fy = map(int, input().split())
    arr = list(map(int, input().split()))
    
    d = ((ix - fx)**2 + (iy - fy)**2)**0.5
    arr.append(d)
    
    may = max(arr)
    rest = sum(arr) - may
    
    if rest >= may:
        print("Yes")
    else:
        print("No")

for _ in range(int(input())):
    sol()