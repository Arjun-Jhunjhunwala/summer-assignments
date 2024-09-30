import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt

data = pd.read_csv('AMSCelldata97.csv')

data_tsc = data['TSC']
data_tsv = data['TSV']
power = data_tsc*data_tsv
print(abs(power.mean()))