#matplotlib库操作
import matplotlib.pyplot as plt

#创建图表1 dpi设置图表大小
plt.figure(1, dpi=50)

#创建子图表 2*2的图标矩阵 绘制的子图为矩阵的3序号
plt.subplot(2, 2, 3)
#显示四个子图
plt.subplot(2, 2, 1)
plt.subplot(2, 2, 2)
plt.subplot(2, 2, 4)

#创建图表2
'''
plt.figure(2, dpi=150)
#3*3矩阵 
plt.subplot(3, 3, 1)
plt.subplot(3, 3, 2)
plt.subplot(3, 3, 3)
plt.subplot(3, 3, 4)
plt.subplot(3, 3, 5)
plt.subplot(3, 3, 6)
plt.subplot(3, 3, 7)
plt.subplot(3, 3, 8)
plt.subplot(3, 3, 9)
'''
#显示所有图表
plt.show()
