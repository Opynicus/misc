import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from scipy.stats import boxcox_normmax
from scipy.special import boxcox1p
train_set_path = "./dataset/train.csv"
test_set_path = "./dataset/test.csv"


# 读取训练集与测试集
def dataProcess(dataset_path):
    return pd.read_csv(dataset_path, index_col=0)


# 显示数据集的散点图
def showScatter(dataset):
    # Utilities与SalePrice
    plt.scatter(x=dataset.Utilities, y=dataset.SalePrice, color='purple')
    plt.grid(c='silver', linestyle='--')
    plt.savefig('Utilities_SalePrice_Scatter.png')
    plt.show()
    # LotArea与SalePrice
    plt.scatter(x=dataset.LotArea, y=dataset.SalePrice, color='darkblue')
    plt.grid(c='silver', linestyle='--')
    plt.savefig('LotArea_SalePrice_Scatter.png')
    plt.show()
    # Neighborhood与SalePrice
    plt.scatter(x=dataset.Neighborhood, y=dataset.SalePrice, color='blueviolet')
    plt.grid(c='silver', linestyle='--')
    plt.savefig('Neighborhood_SalePrice_Scatter.png')
    plt.show()
    # OverallQual与SalePrice
    plt.scatter(x=dataset.OverallQual, y=dataset.SalePrice, color='b')
    plt.grid(c='silver', linestyle='--')
    plt.savefig('OverallQual_SalePrice_Scatter.png')
    plt.show()
    # YearBuilt与SalePrice
    plt.scatter(x=train.YearBuilt, y=train.SalePrice, color='r')
    plt.grid(c='silver', linestyle='--')
    plt.savefig('YearBuilt_SalePrice_Scatter.png')
    plt.show()
    # TotalBsmtSF与SalePrice
    plt.scatter(x=train.TotalBsmtSF, y=train.SalePrice, color='g')
    plt.grid(c='silver', linestyle='--')
    plt.savefig('TotalBsmtSF_SalePrice_Scatter.png')
    plt.show()
    # GrLivArea与SalePrice
    plt.scatter(x=train.GrLivArea, y=train.SalePrice, color='y')
    plt.grid(c='silver', linestyle='--')
    plt.savefig('GrLivArea_SalePrice_Scatter.png')
    plt.show()
    # Heating与SalePrice
    plt.scatter(x=train.Heating, y=train.SalePrice, color='red')
    plt.grid(c='silver', linestyle='--')
    plt.savefig('Heating_SalePrice_Scatter.png')
    plt.show()


def removeScatter():
    train.drop(train[(train['OverallQual'] < 5) & (train['SalePrice'] > 200000)].index, inplace=True)
    train.drop(train[(train['LotArea'] > 100000) & (train['SalePrice'] > 200000)].index, inplace=True)
    train.drop(train[(train['YearBuilt'] < 1900) & (train['SalePrice'] > 400000)].index, inplace=True)
    train.drop(train[(train['YearBuilt'] < 2000) & (train['SalePrice'] > 700000)].index, inplace=True)
    train.drop(train[(train['TotalBsmtSF'] > 6000) & (train['SalePrice'] > 10000)].index, inplace=True)
    train.drop(train[(train['GrLivArea'] > 4000) & (train['SalePrice'] > 100000)].index, inplace=True)


def mergeSet():
    train.reset_index(drop=True, inplace=True)  # 重置索引
    merge_set = pd.concat([train, test])
    merge_set = merge_set.drop_duplicates(keep='first', inplace=False)  # 去重
    nan_count = merge_set.isnull().sum().sort_values(ascending=False)  # 各列缺失值个数
    nan_ratio = nan_count / len(merge_set)  # 计算缺失值占比
    nan_ratio[:36, ]
    print(nan_ratio)
    merge_set.drop('PoolQC', axis=1, inplace=True)
    merge_set.drop('MiscFeature', axis=1, inplace=True)
    merge_set.drop('Alley', axis=1, inplace=True)
    merge_set.drop('Fence', axis=1, inplace=True)
    merge_set.drop('FireplaceQu', axis=1, inplace=True)
    merge_set.drop('LotFrontage', axis=1, inplace=True)

    merge_set.drop('GarageCond', axis=1, inplace=True)
    merge_set.drop('GarageFinish', axis=1, inplace=True)
    merge_set.drop('GarageQual', axis=1, inplace=True)
    merge_set.drop('GarageYrBlt', axis=1, inplace=True)
    merge_set.drop('GarageType', axis=1, inplace=True)

    merge_set.drop('BsmtCond', axis=1, inplace=True)
    merge_set.drop('BsmtExposure', axis=1, inplace=True)
    merge_set.drop('BsmtQual', axis=1, inplace=True)
    merge_set.drop('BsmtFinType2', axis=1, inplace=True)
    merge_set.drop('BsmtFinType1', axis=1, inplace=True)

    merge_set.drop('MasVnrType', axis=1, inplace=True)
    merge_set.drop('MasVnrArea', axis=1, inplace=True)

    merge_set.drop('Utilities', axis=1, inplace=True)
    # 填充数据
    num_cols = ["BsmtUnfSF", "TotalBsmtSF", "BsmtHalfBath", "BsmtFullBath", "GarageArea", "GarageCars",
                "BsmtFinSF1", "BsmtFinSF2", ]
    for col in num_cols:
        merge_set[col].fillna(0, inplace=True)
    # 众数填充
    nan_cols = ["MSZoning", "Electrical", "KitchenQual", "Exterior1st", "Exterior2nd", "SaleType"]
    for col in nan_cols:
        merge_set[col].fillna(merge_set[col].mode()[0], inplace=True)
    # Functional
    merge_set["Functional"] = merge_set["Functional"].fillna("Typ")

    nan_count = merge_set.isnull().sum().sort_values(ascending=False)  # 各列缺失值个数，降序排序
    print(nan_count)
    print(merge_set)

    merge_set.drop('SalePrice', axis=1, inplace=True)
    return merge_set


def predict(merge_set):
    house_price = np.array(train['SalePrice'])
    ms_obj = pd.DataFrame()
    ms_int = pd.DataFrame()
    for i in merge_set.columns.values:
        if merge_set[i].dtypes == 'object':
            ms_obj = pd.concat([ms_obj, merge_set[i]], axis=1)  # object型
        else:
            ms_int = pd.concat([ms_int, merge_set[i]], axis=1)  # 数值型
    ms_obj = pd.get_dummies(ms_obj)  # object型 one hot encode
    for i in list(ms_int.columns):
        lambda_ = boxcox_normmax(ms_int[i] + 1)
        print(lambda_)
        ms_int[i] = boxcox1p(ms_int[i], lambda_)  # scipy.stats.boxcox1使满足正态分布
        # print(scipy.stats.shapiro(ms_int[i]))
    ms_int = pd.DataFrame(ms_int)
    # 合并object型和数值型
    mrg_set = pd.DataFrame()
    mrg_set = pd.concat([ms_obj, merge_set[i]], axis=1)
    # 归一化
    for i in list(mrg_set.columns):
        max_a = np.max(mrg_set[i])
        min_a = np.min(mrg_set[i])
        mrg_set[i] = (mrg_set[i] - min_a) / (max_a - min_a)

    train_arr = mrg_set[:len(train)]
    print(train_arr)
    test_arr = mrg_set[len(train):]
    train_arr['1'] = 1  # 添加一列1
    T_x = np.matrix(train_arr)
    T_y = np.matrix(house_price.reshape(house_price.shape[0], 1))
    T_xx = T_x.T * T_x
    T_xn = np.linalg.pinv(T_xx)
    T_w = T_xn * T_x.T * T_y

    # 回归
    test_arr['1'] = 1
    M_x = np.matrix(test_arr)
    M_y = M_x * T_w
    result = np.array(M_y).flatten()
    print(result)
    pd.DataFrame(data={'Id': range(1461, 1461 + len(result)), 'SalePrice': result}).to_csv("linear_regression_result.csv",
                                                                                     columns=['Id', 'SalePrice'],
                                                                                     index=False)


if __name__ == '__main__':
    train = dataProcess(train_set_path);
    test = dataProcess(test_set_path);
    showScatter(train)
    removeScatter()
    merge_set = mergeSet()
    predict(merge_set)
