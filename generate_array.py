import random
arr = []

for i in range(0, 10000):
    arr.append(i / 100)

random.shuffle(arr)
print(arr)

with open('./input/array.txt', 'w') as file:
    for el in arr:
        file.write(f'{el}\n')