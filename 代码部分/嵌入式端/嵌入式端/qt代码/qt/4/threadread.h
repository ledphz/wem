#ifndef THREADREAD_H
#define THREADREAD_H
#include <QtCore>


class ThreadRead: public QThread
{
public:
    ThreadRead();
    void run();
    void tty_set(int fd);
    int socket_init();
    int conn_to_sqlite();
    void save_to_sqlite(char sql_insert[]);

private:
    char err[100];
};

#endif // THREADREAD_H
