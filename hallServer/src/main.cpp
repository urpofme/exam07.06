#include <QCoreApplication>
#include <iostream>
#include "ServerCore.h"

int32_t main(int32_t argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    ServerCore server;
    if (server.setupSocket() != 0) {
        return 1;
    }

    qInfo("Server is setted up");

    return app.exec();
}
