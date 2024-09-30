import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt

data = pd.read_csv('AMSCelldata97.csv')
x = np.linspace(1,90,90)
y = data.iloc[:,x-1].mean()

plt.bar(x, y)
plt.title('Average Cell Voltage')
plt.ylim(3.4, 3.7)
plt.xticks([1, 16, 31, 46, 61, 76], ["S1", "S2", "S3", "S4", "S5", "S6"])
plt.show()