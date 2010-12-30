/***************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (directui@nokia.com)
**
** This file is part of applauncherd
**
** If you have questions regarding the use of this file, please contact
** Nokia at directui@nokia.com.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#include "wrtbooster.h"
#include <QtCore>

extern "C" 
{
    // Create a new plugin instance.
    Q_DECL_EXPORT void * create()
    {
        return new WRTBooster;
    }

    Q_DECL_EXPORT char type()
    {
        return WRTBooster::type();
    }

    Q_DECL_EXPORT const char * socketName()
    {
        return WRTBooster::socketName().c_str();
    }

    Q_DECL_EXPORT const char * temporaryProcessName()
    {
        return WRTBooster::temporaryProcessName().c_str();
    }
}