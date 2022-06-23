import numpy as np
import seaborn as sn
import pandas as pd
import matplotlib.pyplot as plt
from sklearn import metrics
from sklearn.svm import SVC, LinearSVC
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix

# wine数据集加载
url_wine = 'http://archive.ics.uci.edu/ml/machine-learning-databases/wine/wine.data'
columns = ['category', 'Alcohol', 'Malic acid ', 'Ash', 'Alcalinity of ash',
           'Magnesium', 'Total phenols', 'Flavanoid',
           'Nonflavanoid phenols', 'Proanthocyanins ', 'Color intensity',
           'Hue ', 'OD280/OD315 of diluted wines', 'Proline']
wine_data = pd.read_csv(url_wine, header=None, names=columns)
wine_data = wine_data.sample(frac=1.0)
wine_feature = wine_data.iloc[:, 1:14].values
wine_label = wine_data.iloc[:, 0].values
feature_train, feature_test, label_train, label_test = train_test_split(wine_feature, wine_label, test_size=0.25,
                                                                        random_state=0)
# SVM分类及预测

svc = SVC(kernel='linear').fit(feature_train, label_train)  # 线性
# 非线性
rbf_svc = SVC(kernel='rbf').fit(feature_train, label_train)
poly_svc = SVC(kernel='poly', degree=3).fit(feature_train, label_train)
# 也是核函数为linear的SVC，但是实现方式与前面那个不一样，算是优化过的
linear_svc = LinearSVC().fit(feature_train, label_train)

value_predict = svc.predict(feature_test)
print(metrics.classification_report(value_predict, label_test))

value_predict_rbf = rbf_svc.predict(feature_test)
print(metrics.classification_report(value_predict_rbf, label_test))

value_predict_poly = poly_svc.predict(feature_test)
print(metrics.classification_report(value_predict_poly, label_test))

value_predict_linear_svc = linear_svc.predict(feature_test)
print(metrics.classification_report(value_predict_linear_svc, label_test))

# 热力图可视化
titles = ['SVC', 'Linear SVC(linear kernel)', 'SVC with RBF Kernel', 'SVC with polynomial(degree 3)']
for i, clf in enumerate((svc, linear_svc, rbf_svc, poly_svc)):
    plt.subplot(2, 2, i + 1)
    plt.subplots_adjust(wspace=0.2, hspace=0.4)
    wine_confusion = confusion_matrix(label_test, clf.predict(feature_test))  # 混淆矩阵
    sn.heatmap(wine_confusion, annot=True, fmt='d')
    plt.title(titles[i])
plt.savefig('svm_comparison.png')
plt.show()

Y = wine_data['category'].values
X1 = wine_data[['Proline', 'Color intensity']].values
x_min, x_max = X1[:, 0].min() - 1, X1[:, 0].max() + 1
y_min, y_max = X1[:, 1].min() - 1, X1[:, 1].max() + 1
xx, yy = np.meshgrid(np.arange(x_min, x_max, 0.2),
                     np.arange(y_min, y_max, 0.2))
x_train, x_test, y_train, y_test = train_test_split(X1, Y, test_size=0.25,
                                                    random_state=0)
svc = SVC(kernel='linear').fit(x_train, y_train)  # 线性

Z = svc.predict(np.array([xx.ravel(), yy.ravel()]).T)
Z = Z.reshape(xx.shape)

plt.contour(xx, yy, Z, cmap=plt.cm.coolwarm, alpha=0.8)
plt.scatter(X1[:, 0], X1[:, 1], c=Y, cmap='jet')
# plt.scatter(x_test[:, 0], x_test[:, 1], c=y_test, cmap='jet') #对测试集做决策边界
plt.xlabel("Proline")
plt.ylabel("Colour_intensity")
plt.xlim(xx.min(), xx.max())
plt.ylim(yy.min(), yy.max())
plt.xticks(())
plt.yticks(())
plt.title("Decision Boundary")
plt.savefig("decision_boundary.png")
plt.show()
