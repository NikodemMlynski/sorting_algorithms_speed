def sort_array_numpy():
    import numpy as np
    import time

    start_time = time.time()

    with open('./input/array.txt', 'r') as file:
        array = file.readlines()

    numpy_array = np.array([float(line.strip()) for line in array])
    print("Original array:", numpy_array)

    numpy_array.sort()

    with open('./output/sorted_numpy.txt', 'w') as file_sorted:
        for value in np.nditer(numpy_array):
            file_sorted.write(f'{value}\n')

    execution_time = (time.time() - start_time) * 1000
    return execution_time
