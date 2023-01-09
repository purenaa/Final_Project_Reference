#include "scenewithmovableproxies.h"
#include "ui_scenewithmovableproxies.h"
#include "scenewidgetitem.h"

#include <QGraphicsProxyWidget>

SceneWithMovableProxies::SceneWithMovableProxies(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SceneWithMovableProxies)
{
  ui->setupUi(this);
  ui->graphicsView->setRenderHint(QPainter::Antialiasing);
  ui->graphicsView->setScene(new QGraphicsScene(this));

  // Add widget proxies + their parenting graphics items to scene
  addWidgetToScene(QPoint(10, 10));
  addWidgetToScene(QPoint(300, 100));
  addWidgetToScene(QPoint(200, 200));
}

SceneWithMovableProxies::~SceneWithMovableProxies()
{
  delete ui;
}

void SceneWithMovableProxies::addWidgetToScene(QPoint initPos)
{
  // Create a widget
  SceneWidgetItem *widget = new SceneWidgetItem();
  // Create the graphics item that will be used to move the widget around the screen as well as be selectable (for example in case we want to delete a widget that is in the scene)
  // Depending on the position of the graphics item relative to its widget proxy you can adjust the size and location of both
  QGraphicsRectItem *proxyControl = ui->graphicsView->scene()->addRect(initPos.x(), initPos.y(), widget->width(), 20, QPen(Qt::black), QBrush(Qt::darkGreen)); // widget->width() works properly here because of the resize(layout->sizeHint()) that we have used inside it
  proxyControl->setFlag(QGraphicsItem::ItemIsMovable, true);
  proxyControl->setFlag(QGraphicsItem::ItemIsSelectable, true);
  // Create the proxy by adding the widget to the scene
  QGraphicsProxyWidget * const proxy = ui->graphicsView->scene()->addWidget(widget);
  // In my case the rectangular graphics item is supposed to be above my widget so the position of the widget is shifted along the Y axis based on the height of the rectangle of that graphics item
  proxy->setPos(initPos.x(), initPos.y()+proxyControl->rect().height());
  proxy->setParentItem(proxyControl);

  // proxyControl->setRotation(45); // Because the widget is a child of the graphics item if we do some sort of transformation to it, the change will be propagated to the widget too!
}
