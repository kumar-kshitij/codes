def sort():
    n = int(input())
    a = []
    for i in range(n):
        a.append(int(input()))
    for i in range(n):
        for j in range(i, n):
            if a[i] > a[j]:
                a[i], a[j] = a[j], a[i]
    print(a)
