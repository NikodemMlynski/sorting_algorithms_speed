from sort_array_numpy import sort_array_numpy
from sort_array import sort_array

sort_array_numpy_time = sort_array_numpy()
sort_array_time = sort_array()

print(sort_array_numpy_time)
print(sort_array_time)

with open('./stats/stats_python.csv', 'a') as file:
    file.write(f"{sort_array_numpy_time}, {sort_array_time}\n")