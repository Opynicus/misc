import sys

from PyQt5.QtGui import QPixmap, QImage
from PyQt5.QtWidgets import QApplication, QMainWindow, QFileDialog, QMessageBox, QGraphicsPixmapItem, QGraphicsScene
from PyQt5.QtCore import Qt

import numpy as np

import interface

import tensorflow as tf
from keras.models import load_model

labels = [
    'Black-grass',
    'Charlock',
    'Cleavers',
    'Common Chickweed',
    'Common wheat',
    'Fat Hen',
    'Loose Silky-bent',
    'Maize',
    'Scentless Mayweed',
    'Shepherds Purse',
    'Small-flowered Cranesbill',
    'Sugar beet'
]


class Window(QMainWindow, interface.Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.exit_button.clicked.connect(self.close)
        self.exit_button.setToolTip("退出")
        self.exit_button.setCursor(Qt.PointingHandCursor)
        self.select_image_button.clicked.connect(self.select_image)
        self.select_image_button.setToolTip("选择照片以预测")
        self.select_image_button.setCursor(Qt.PointingHandCursor)
        self.setFixedSize(self.width(), self.height())
        self.predict_button.clicked.connect(self.predict)
        self.predict_button.setToolTip("预测结果")
        self.predict_button.setCursor(Qt.PointingHandCursor)
        self.mode_button.clicked.connect(self.change_mode)
        self.mode_button.setToolTip("切换白天/黑夜模式")
        self.mode_button.setCursor(Qt.PointingHandCursor)
        self.clear_button.clicked.connect(self.clear_status)
        self.clear_button.setToolTip("清除当前显示状态")
        self.clear_button.setCursor(Qt.PointingHandCursor)
        self.img_path = ""
        self.model_path = "./model/model20.h5"
        self.model = load_model(self.model_path)
        self.mode = 0

    def select_image(self):
        image_path = QFileDialog.getOpenFileName()
        # print(image_path[0])
        self.img_path = image_path[0]
        # if self.img_path == "":
        #     QMessageBox.information(self, "提示", self.tr("没有选择图片文件！"))
        print(self.img_path)
        self.display_image()

    def predict(self):
        if self.img_path == "":
            QMessageBox.information(self, "提示", self.tr("没有选择图片文件！"))
            return
        img = tf.keras.utils.load_img(self.img_path, target_size=(224, 224))
        x = tf.keras.utils.img_to_array(img)
        x = np.expand_dims(x, axis=0)
        y = self.model.predict(x)

        print(y)
        print(labels[np.argmax(y)])

        self.textBrowser.setText(labels[np.argmax(y)])

    def change_mode(self):
        if self.mode == 0:
            self.label_5.setStyleSheet("background-color: rgba(0, 0, 0,0.8);")
            self.label_2.setStyleSheet("background-color: rgba(0, 0, 0,0.8);")
            self.label_4.setStyleSheet("background-color: rgba(0, 0, 0,0.8);")
            self.sidebar.setStyleSheet("background-color:rgba(0, 0, 0,0.1);")
            self.textBrowser.setStyleSheet("QTextBrowser{\n"
                                           "    color: rgb(255, 255, 255);\n"
                                           "    background-color: rgba(0, 0, 0, 0.3);\n"
                                           "        border-radius: 5px; \n"
                                           "        border: 2px white blueviolet;\n"
                                           "        border-style: outset;\n"
                                           "        text-align: center\n"
                                           "}")
            self.select_image_button.setStyleSheet("QPushButton{\n"
                                                   "    color: rgb(255, 255, 255);\n"
                                                   "background-color:rgba(139,139,122, 0.6);\n"
                                                   "}")
            self.predict_button.setStyleSheet("QPushButton{\n"
                                              "    color: rgb(255, 255, 255);\n"
                                              "background-color: rgba(170, 170, 255, 0.6);\n"
                                              "}")
            self.exit_button.setStyleSheet("QPushButton{\n"
                                           "    color: rgb(255, 255, 255);\n"
                                           "background-color: rgba(205, 51, 51, 0.6);\n"
                                           "}")
            self.image2predict.setStyleSheet("QGraphicsView{\n"
                                             "        border-radius: 5px; \n"
                                             "        border: 2px white blueviolet;\n"
                                             "background-color:rgba(0,0,0, 0.4)\n"
                                             "}")
            self.mode_button.setStyleSheet("QPushButton{\n"
                                           "background-color: rgba(255, 255, 255, 0.5);\n"
                                           "border-radius:35px\n"
                                           "}")
            self.clear_button.setStyleSheet("QPushButton{\n"
                                            "background-color: rgba(147, 112, 219, 0.4);\n"
                                            "border-radius:35px\n"
                                            "}")
            self.avatar.setStyleSheet("border-image: url(:/image/logo2.png);")

            self.mode = 1
        else:
            self.label_5.setStyleSheet("background-color: rgba(255, 255, 255,0.4);")
            self.label_2.setStyleSheet("background-color:rgba(192, 255, 62, 0.7);")
            self.label_4.setStyleSheet("background-color:rgba(192, 255, 62, 0.7);")
            self.sidebar.setStyleSheet("background-color:rgba(192, 255, 62, 0.6);")
            self.textBrowser.setStyleSheet("QTextBrowser{\n"
                                           "        border-radius: 5px; \n"
                                           "        border: 2px black blueviolet;\n"
                                           "        border-style: outset;\n"
                                           "        text-align: center\n"
                                           "}")
            self.select_image_button.setStyleSheet("QPushButton{\n"
                                                   "background-color:rgba(139,139,122, 0.6);\n"
                                                   "}")
            self.predict_button.setStyleSheet("QPushButton{\n"
                                              "background-color: rgba(170, 170, 255, 0.6);\n"
                                              "}")
            self.exit_button.setStyleSheet("QPushButton{\n"
                                           "background-color: rgba(205, 51, 51, 0.6);\n"
                                           "}")
            self.image2predict.setStyleSheet("QGraphicsView{\n"
                                             "        border-radius: 5px; \n"
                                             "        border: 2px white blueviolet;\n"
                                             "background-color:rgba(255,255,255, 0.7)\n"
                                             "}")
            self.mode_button.setStyleSheet("QPushButton{\n"
                                           "background-color: rgba(0, 0, 0, 0.6);\n"
                                           "border-radius:35px\n"
                                           "}")
            self.clear_button.setStyleSheet("QPushButton{\n"
                                            "background-color: rgba(139, 117, 0, 0.5);\n"
                                            "border-radius:35px\n"
                                            "}")
            self.avatar.setStyleSheet("border-image: url(:/image/logo.png);")
            self.mode = 0

    def clear_status(self):
        self.img_path = ""
        self.textBrowser.clear()
        self.display_image()

    def display_image(self):  # 在QgraphicsView中自适应显示图像
        frame = QImage(self.img_path)
        pix = QPixmap.fromImage(frame)
        item = QGraphicsPixmapItem(pix)
        scene = QGraphicsScene()
        scene.addItem(item)
        self.image2predict.setScene(scene)
        self.image2predict.fitInView(QGraphicsPixmapItem(QPixmap(pix)))


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Window()
    ex.show()
    sys.exit(app.exec_())
