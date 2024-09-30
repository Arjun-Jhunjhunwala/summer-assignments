import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt

data = pd.read_csv('AMSCelldata97.csv')

data_tsv = data['TSV']

m = data_tsv.size
x = np.linspace(0,m/10,m)

plt.figure(figsize=(10,5))
plt.plot(x, data_tsv, label = "TSV")

plt.xlabel("Time in s")
plt.title('TSV')
plt.show()
