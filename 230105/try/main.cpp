#include "tryzoom.h"

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGuiApplication::setApplicationDisplayName(tryzoom::tr("tryzoom Viewer"));

    QCommandLineParser commandLineParser;
    commandLineParser.addHelpOption();
    commandLineParser.addPositionalArgument(tryzoom::tr("[file]"), tryzoom::tr("Image file to open."));
    commandLineParser.process(QCoreApplication::arguments());
    tryzoom tryzoom;
    if (!commandLineParser.positionalArguments().isEmpty()
        && !tryzoom.loadFile(commandLineParser.positionalArguments().constFirst())) {
        return -1;
    }
    tryzoom.show();
    return a.exec();
}
