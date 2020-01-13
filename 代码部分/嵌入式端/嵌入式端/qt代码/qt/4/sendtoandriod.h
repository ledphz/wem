#ifndef SENDTOANDRIOD_H
#define SENDTOANDRIOD_H
#include <QtCore>


class SendToAndriod: public QThread
{
public:
    SendToAndriod();
    void run();

//private slots:
//    void *thread_recv(void *arg);
};

#endif // SENDTOANDRIOD_H
