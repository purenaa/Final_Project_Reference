/********************************************************************************
** Form generated from reading UI file 'scenewithmovableproxies.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENEWITHMOVABLEPROXIES_H
#define UI_SCENEWITHMOVABLEPROXIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SceneWithMovableProxies
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *SceneWithMovableProxies)
    {
        if (SceneWithMovableProxies->objectName().isEmpty())
            SceneWithMovableProxies->setObjectName("SceneWithMovableProxies");
        SceneWithMovableProxies->resize(400, 300);
        gridLayout = new QGridLayout(SceneWithMovableProxies);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        graphicsView = new QGraphicsView(SceneWithMovableProxies);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);


        retranslateUi(SceneWithMovableProxies);

        QMetaObject::connectSlotsByName(SceneWithMovableProxies);
    } // setupUi

    void retranslateUi(QWidget *SceneWithMovableProxies)
    {
        SceneWithMovableProxies->setWindowTitle(QCoreApplication::translate("SceneWithMovableProxies", "SceneWithMovableProxies", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SceneWithMovableProxies: public Ui_SceneWithMovableProxies {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEWITHMOVABLEPROXIES_H
