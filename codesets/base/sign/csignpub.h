#ifndef CSIGNPUB_H
#define CSIGNPUB_H

#include <QString>
#include "signpub.h"

class CSignPub
{
public:
    CSignPub();

    static QString signEnter();
    static QString signEnterNL();
    static QString signRESpace();
};

#endif // CSIGNPUB_H
