#include <QJsonDocument>
#include <QJsonObject>
#include "Processor/HeapSortProcessor.h"
#include "ClientCore.h"

ClientCore::ClientCore(QTcpSocket *socket, quint64 socketId)
    : socket(socket)
    , socketId(socketId)
{
    connect(
        socket, &QTcpSocket::readyRead,
        this, &ClientCore::slotReadData
    );

    connect(
        socket, &QTcpSocket::disconnected,
        this, &ClientCore::slotDisconnect
    );
}

ClientCore::~ClientCore()
{
    qDebug("Deleting user object %llo", socketId);
    slotDisconnect();
}

QTcpSocket* ClientCore::getSocket()
{
    return socket;
}

quint64 ClientCore::getSocketId()
{
    return socketId;
}

void ClientCore::slotReadData()
{
    QByteArray request, result;

    while(socket->bytesAvailable() > 0) {
        if (request.size() > REQUEST_MAX_SIZE) {
            break;
        }
        request = socket->read(REQUEST_MAX_SIZE);
    }

    if (request.size() == 0) {
        return;
    }

    if (request == "q") {
        slotDisconnect();

        return;
    }
    QStringList rqComponents = QString(request).trimmed().split("&");

    result = "";
    if (rqComponents[0] == "sort") {
        result = HeapSortProcessor::process(rqComponents[2], rqComponents[1].toInt());
    }

    socket->write(result);
}

void ClientCore::slotDisconnect()
{
    if (state == 0) {
        state = 1;
        emit signalClientClose(socketId);

        socket->close();
    }
}
