test_count = int(input())

for t in range(0, test_count):
    S = input()
    even_letters = S[0::2]
    odd_letters = S[1::2]
    print(even_letters + ' ' + odd_letters)
