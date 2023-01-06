#include "test.h"

#include <QGraphicsLinearLayout>
#include <QGraphicsGridLayout>
#include <QLayout>

test::test(QGraphicsWidget *parent)
    : QGraphicsWidget(parent, Qt::Window)
{
    QGraphicsLinearLayout *windowLayout = new QGraphicsLinearLayout(Qt::Vertical);           // Vertical : 수직 (이 유형은 개체의 방향을 나타내는 데 사용됩니다.)
    QGraphicsLinearLayout *linear = new QGraphicsLinearLayout(windowLayout);
    Layout *item = new Layout;
    linear->addItem(item);
    linear->setStretchFactor(item, 1);              // QGraphicsLayoutItem : 레이아웃 항목 개수 [형식: (*item, int stretch)]

    item = new Layout;
    linear->addItem(item);
    linear->setStretchFactor(item, 3);
    windowLayout->addItem(linear);

    QGraphicsGridLayout *grid = new QGraphicsGridLayout(windowLayout);
    item = new Layout;
    grid->addItem(item, 0, 0, 4, 1);
    item = new Layout;
    item->setMaximumHeight(item->minimumHeight());
    grid->addItem(item, 0, 1, 2, 1, Qt::AlignVCenter);
    item = new Layout;
    item->setMaximumHeight(item->minimumHeight());
    grid->addItem(item, 2, 1, 2, 1, Qt::AlignVCenter);
    item = new Layout;
    grid->addItem(item, 0, 2);
    item = new Layout;
    grid->addItem(item, 1, 2);
    item = new Layout;
    grid->addItem(item, 2, 2);
    item = new Layout;
    grid->addItem(item, 3, 2);
    windowLayout->addItem(grid);

    setLayout(windowLayout);
    setWindowTitle(tr("Basic Graphics Layouts Example"));
}

test::~test()
{
}


