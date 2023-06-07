#include "mytcpserver-ex.h"
#include <QDebug>
#include <QString>
#include <QStringList>
#include <Processor/HeapSortProcessor.h>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent): QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection()
{
    if(server_status==1){
        mTcpSocket = mTcpServer->nextPendingConnection();

        connect(mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead(){
    QByteArray request;

    while(mTcpSocket->bytesAvailable() > 0) {
        QByteArray request = mTcpSocket->readAll();
    }

    QStringList rqComponents = QString(request).trimmed().split("&");

//    if (rqComponents[0] == "sort") {
//        mTcpSocket->write(
//        )
//        HeapSortProcessor::process(rqComponents[2], rqComponents[1].toInt());
//    }
}

void MyTcpServer::slotClientDisconnected(){
    mTcpSocket->close();
}
