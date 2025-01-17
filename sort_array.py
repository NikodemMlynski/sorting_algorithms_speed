def sort_array():
    import time
    start_time = time.time()

    with open('./input/array.txt', 'r') as file:
        array = file.readlines()
        array = [float(el[:5]) for el in array]


    array.sort()

    print(array)

    with open('./output/sorted.txt', 'w') as file_sorted:
        for x in array:
            file_sorted.write(f'{x}\n')

    print(f"--- {float(time.time() - start_time)*1000} miliseconds ---" )
    return float(time.time() - start_time)*1000 