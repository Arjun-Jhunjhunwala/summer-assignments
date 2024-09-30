import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('file.csv')
data_112 = data[data['ID'] == 112]
data_128 = data[data['ID'] == 128]
time = data_112.loc[:,'Time'].reset_index(drop=True)

yaw_rate = (((data_112.loc[:,'Data 1']*256 + data_112.loc[:,'Data 0']) - 32768)*0.005).reset_index(drop=True)
acc_y = (((data_112.loc[:,'Data 5']*256 + data_112.loc[:,'Data 4']) - 32768)*0.0001274).reset_index(drop=True)
yaw_ang_acc = (((data_128.loc[:,'Data 1']*256 + data_128.loc[:,'Data 0']) - 32768)*0.125).reset_index(drop=True)
acc_x = (((data_128.loc[:,'Data 5']*256 + data_128.loc[:,'Data 4']) - 32768)*0.0001274).reset_index(drop=True)
# plt.plot(data_112.loc[1:,'Time'],acc_x.loc[1:])
# plt.title('Acceleration X-Axis')
# plt.ylabel('Acceleration X-axis (g)')
# plt.xlabel('Time(s)')
# plt.show()

values = pd.DataFrame({'Time':time,'Yaw Rate':yaw_rate,'Acceleration Y': acc_y, 'Yaw Angular Acceleration': yaw_ang_acc, 'Acceleration X': acc_x})
print(values)
values.to_csv('final_values.csv')