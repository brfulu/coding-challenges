if __name__ == '__main__':
    n = int(input())
    phone_book = {}
    for i in range(0, n):
        name, number = [x for x in input().split()]
        phone_book[name] = number

    while True:
        try:
            query_name = input()
            if query_name in phone_book:
                print(query_name + '=' + phone_book[query_name])
            else:
                print('Not found')
        except EOFError:
            break
