import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt

data = pd.read_csv('AMSCelldata97.csv')

data_tsc = data['TSC']

m = data_tsc.size
x = np.linspace(0,m/10,m)

plt.figure(figsize = (10,5))
plt.plot(x, data_tsc, label = "TSC")
plt.xlabel("Time in s")
plt.title('TSC')
plt.show()
