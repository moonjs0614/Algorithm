n = int(input())
if n <= 2:
    print(n-1)
else:
    binaryZeros = 1
    for i in range(3, n):
        if i % 2 != 0:
            binaryZeros = binaryZeros*2 + 1
            continue
        binaryZeros = binaryZeros*2 - 1
    print(binaryZeros)