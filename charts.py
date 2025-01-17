import pandas as pd
import matplotlib.pyplot as plt


df = pd.read_csv('./stats/stats_python.csv', header=None, names=['python(numpy)', 'python'])


with open('./stats/stats_cpp.txt') as cpp_stats:
    cpp_values = [int(line.strip()) for line in cpp_stats.readlines()] 

df['C++'] = pd.Series(cpp_values)

averages = df.mean()
print(averages)

plt.figure(figsize=(8, 5))

averages.plot(kind='bar', color=['#1f77b4', '#ff7f0e', '#2ca02c'])

plt.title('Average sorting speed for each programming language')

plt.xticks(rotation=0)

plt.tight_layout()
plt.show()