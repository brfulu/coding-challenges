if __name__ == '__main__':
    n = int(input())
    array = list(map(int, input().rstrip().split()))
    for x in reversed(array):
        print(x, end=' ')
