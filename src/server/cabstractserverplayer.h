/********************************************************************
    Copyright (c) 2013-2015 - Mogara

    This file is part of Cardirector.

    This game engine is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 3.0
    of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    See the LICENSE file for more details.

    Mogara
    *********************************************************************/

#ifndef CABSTRACTSERVERPLAYER_H
#define CABSTRACTSERVERPLAYER_H

#include "cabstractplayer.h"

#include <QObject>
#include <QHostAddress>

MCD_BEGIN_NAMESPACE

class CTcpSocket;
class CAbstractPacketParser;
class CAbstractServerPlayerPrivate;

class MCD_EXPORT CAbstractServerPlayer : public CAbstractPlayer
{
    Q_OBJECT

public:
    explicit CAbstractServerPlayer(QObject *parent = 0);
    CAbstractServerPlayer(CTcpSocket *socket, QObject *parent = 0);
    ~CAbstractServerPlayer();

    void setSocket(CTcpSocket *socket);
    void setPacketParser(CAbstractPacketParser *parser);

    void kick();
    QHostAddress ip() const;

    void notify(int command, const QVariant &data = QVariant());

signals:
    void disconnected();

protected:
    static void CheckVersionCommand(CAbstractServerPlayer *player, const QVariant &data);
    static void LoginCommand(CAbstractServerPlayer *player, const QVariant &data);
    static void LogoutCommand(CAbstractServerPlayer *player, const QVariant &);
    static void SpeakCommand(CAbstractServerPlayer *player, const QVariant &data);

private:
    void init();
    void initCallbacks();

    C_DISABLE_COPY(CAbstractServerPlayer)
    C_DECLARE_PRIVATE(CAbstractServerPlayer)

    CAbstractServerPlayerPrivate *p_ptr;
};

MCD_END_NAMESPACE

#endif // CABSTRACTSERVERPLAYER_H
