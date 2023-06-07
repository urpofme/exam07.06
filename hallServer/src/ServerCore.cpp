#include <memory>
#include <QDebug>
#include <QRandomGenerator>
#include <QTcpServer>
#include "ServerCore.h"

ServerCore::ServerCore(QObject *parent): QObject(parent)
{
}

ServerCore::~ServerCore()
{
    mTcpServer->close();
}

int ServerCore::setupSocket()
{
    mTcpServer = new QTcpServer(this);

    if (!mTcpServer->listen(QHostAddress::Any, 33333)) {
        qDebug() << "Unable to create socket";

        return 1;
    }

    connect(
        mTcpServer, &QTcpServer::newConnection,
        this, &ServerCore::slotAddConnection
    );

    return 0;
}

void ServerCore::slotAddConnection()
{
    quint64 socketId = QRandomGenerator::system()->generate64();
    std::unique_ptr<ClientCore> clientData = std::make_unique<ClientCore>(
        mTcpServer->nextPendingConnection(),
        socketId
    );

    connect(
        clientData.get(), &ClientCore::signalClientClose,
        this, &ServerCore::slotDeleteConnection
    );

    clientData->getSocket()->write("\r\n");

    clientsMap[socketId] = std::move(clientData);

    qDebug("Client connected");
}

void ServerCore::slotDeleteConnection(quint64 id)
{
    if (clientsMap.count(id) != 0) {
        qDebug("Deleting socket");

        clientsMap.erase(id);
    }
}
