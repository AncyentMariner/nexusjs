/*
 * Nexus.js - The next-gen JavaScript platform
 * Copyright (C) 2016  Abdullah A. Hassan <abdullah@webtomizer.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "classes/net/http/request.h"
#include "classes/net/http/response.h"

JSObjectRef NX::Classes::Net::HTTP::Response::attach(JSContextRef ctx, JSObjectRef thisObject, JSObjectRef connection)
{
  return NX::Globals::Promise::resolve(ctx, thisObject);
}

NX::Classes::Net::HTTP::Response::Response(NX::Classes::Net::HTTP::Connection *connection) :
    HTCommon::Response(connection), myConnection(connection),
    myResponse(),
    myResParser(myResponse)
{
  myResponse.version(dynamic_cast<HTTP::Request*>(connection->req())->version());
}
