#ifndef TEST_H
#define TEST_H

#include <QWidget>

class test : public QWidget
{
    Q_OBJECT

public:
    test(QWidget *parent = nullptr);
    ~test();
};
#endif // TEST_H
