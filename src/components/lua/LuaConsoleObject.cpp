//
// C++ Implementation: LuaConsoleObject
//
// Description: 
//
//
// Author: Erik Hjortsberg <erik.hjortsberg@gmail.com>, (C) 2005
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.//
//
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "LuaConsoleObject.h"
#include "Connectors_impl.h"
#include "framework/ConsoleBackend.h"

namespace Ember {
namespace Lua {

LuaConsoleObject::LuaConsoleObject(const std::string& command, const std::string& luaMethod, const std::string& description):
mCommand(command), mLuaMethod(luaMethod), mCommandWrapper(command, this, description)
{
	mConnector = new Ember::Lua::TemplatedConnectorBase<Ember::Lua::StringValueAdapter, Ember::Lua::StringValueAdapter>(Ember::Lua::StringValueAdapter(), Ember::Lua::StringValueAdapter());
	mConnector->connect(luaMethod);
}


LuaConsoleObject::~LuaConsoleObject()
{
	delete mConnector;
}

void LuaConsoleObject::runCommand(const std::string &command, const std::string &args)
{
	mConnector->callLuaMethod<const std::string &, const std::string &>(command, args);
}

}
}