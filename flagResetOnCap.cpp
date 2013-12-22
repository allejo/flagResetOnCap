/*
Flag Reset On Cap
    Copyright (C) 2013 Vladimir Jimenez

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "bzfsAPI.h"

class flagResetOnCap : public bz_Plugin
{
public:
    virtual const char* Name (){return "Flag Reset On Cap";}
    virtual void Init(const char* config);
    virtual void Event(bz_EventData *eventData);
};

BZ_PLUGIN(flagResetOnCap)

void flagResetOnCap::Init(const char* commandLine)
{
    bz_debugMessage(4, "flagResetOnCap plugin loaded");

    Register(bz_eCaptureEvent);
}

void lastTankStanding::Event(bz_EventData *eventData)
{
    switch (eventData->eventType)
    {
        case bz_eCaptureEvent:
        {
            bz_resetFlags(true, true);
        }
        break;

        default:
        break;
    }
}