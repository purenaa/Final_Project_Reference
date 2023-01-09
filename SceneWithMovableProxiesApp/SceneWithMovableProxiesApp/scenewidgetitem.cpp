#include "scenewidgetitem.h"

// Create a widget with whichever UI components you like
SceneWidgetItem::SceneWidgetItem(QWidget *parent) : QWidget(parent)
{
  layout = new QVBoxLayout(this);
  checkbox = new QCheckBox("Enable proxy", this);
  checkbox->setChecked(true);
  combobox = new QComboBox(this);
  combobox->addItem("---");
  combobox->addItem("Item 1");
  combobox->addItem("Item 2");
  combobox->addItem("Item 3");
  label = new QLabel(this);
  label->setText(combobox->itemText(0));
  resetButton = new QPushButton("Reset", this);

  // Maybe add some signals :P
  connect(checkbox, SIGNAL(toggled(bool)), combobox, SLOT(setEnabled(bool)));
  connect(checkbox, SIGNAL(toggled(bool)), resetButton, SLOT(setEnabled(bool)));
  connect(resetButton, SIGNAL(clicked(bool)), this, SLOT(reset()));
  connect(combobox, SIGNAL(currentIndexChanged(QString)), label, SLOT(setText(QString)));

  layout->addWidget(checkbox);
  layout->addWidget(label);
  layout->addWidget(resetButton);
  layout->addWidget(combobox);

  // Resizing the widget to its layout's content is very important. If
  // you don't do that the parenting graphics item will not visually fit
  // to its child widget and you will get a mess
  resize(layout->sizeHint());
  setLayout(layout);
}

SceneWidgetItem::~SceneWidgetItem()
{

}

void SceneWidgetItem::reset()
{
  combobox->setCurrentIndex(0);
  label->setText("---");
}
