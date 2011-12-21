/*
Copyright (c) 2011 Vladimir Jimenez
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the author may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


*** Flag Reset On Cap Details ***
Author:
Vladimir Jimenez (allejo)

Description:
Plugin will reset all unused flags except for team flags after each capture event.

Slash Commands:
N/A

License:
BSD

Version:
2.0
*/

#include "bzfsAPI.h"
#include <string>

#define TOTAL_CTF_TEAMS 4

// event handler callback
class ONCAPHandler : public bz_Plugin
  {
  public:
	virtual const char* Name (){return "Flag Reset On Cap";}
	virtual void Init ( const char* config);
    virtual void Event ( bz_EventData *eventData );
  };

BZ_PLUGIN(ONCAPHandler);

void ONCAPHandler::Init(const char* commandLine)
{
  bz_debugMessage(4,"flagResetOnCap plugin loaded");
  Register(bz_eCaptureEvent);
}

unsigned int getNumTeams()
{
  return TOTAL_CTF_TEAMS - (!bz_getTeamPlayerLimit(eRedTeam) +
                            !bz_getTeamPlayerLimit(eGreenTeam) +
                            !bz_getTeamPlayerLimit(eBlueTeam) +
                            !bz_getTeamPlayerLimit(ePurpleTeam));
}

void ONCAPHandler::Event(bz_EventData *eventData)
{
  for(int i = getNumTeams(); i < bz_getNumFlags(); i++){
  	if(bz_flagPlayer(i)==-1)
      bz_resetFlag(i);
  }
}
//Why are you reading this? The source is finished.